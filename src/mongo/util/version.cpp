// @file version.cpp

/*    Copyright 2009 10gen Inc.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#include "mongo/platform/basic.h"

#include "mongo/util/version.h"

#include "mongo/base/parse_number.h"
#include "mongo/db/jsobj.h"
#include "mongo/util/goodies.h"

namespace mongo {

    using std::string;
    using std::stringstream;

    /* Approved formats for versionString:
     *      1.2.3
     *      1.2.3-pre-
     *      1.2.3-rc4 (up to rc9)
     *      1.2.3-rc4-pre-
     * If you really need to do something else you'll need to fix _versionArray()
     */
    const char versionString[] = "2.6.0-rc3";

    // See unit test for example outputs
    BSONArray toVersionArray(const char* version){
        // this is inefficient, but cached so it doesn't matter
        BSONArrayBuilder b;
        string curPart;
        const char* c = version;
        int finalPart = 0; // 0 = final release, -100 = pre, -10 to -1 = -10 + X for rcX
        do { //walks versionString including NUL byte
            if (!(*c == '.' || *c == '-' || *c == '\0')){
                curPart += *c;
                continue;
            }

            int num;
            if ( parseNumberFromString( curPart, &num ).isOK() ) {
                b.append(num);
            }
            else if (curPart.empty()){
                verify(*c == '\0');
                break;
            }
            else if (startsWith(curPart, "rc")){
                num = 0;
                verify( parseNumberFromString( curPart.substr(2), &num ).isOK() );
                finalPart = -10 + num;
                break;
            }
            else if (curPart == "pre"){
                finalPart = -100;
                break;
            }

            curPart = "";
        } while (*c++);

        b.append(finalPart);
        return b.arr();
    }

    bool isSameMajorVersion( const char* version ) {

        BSONArray remoteVersionArray = toVersionArray( version );

        BSONObjIterator remoteIt(remoteVersionArray);
        BSONObjIterator myIt(versionArray);

        // Compare only the first two fields of the version
        int compareLen = 2;
        while (compareLen > 0 && remoteIt.more() && myIt.more()) {
            if (remoteIt.next().numberInt() != myIt.next().numberInt()) break;
            compareLen--;
        }

        return compareLen == 0;
    }

    const BSONArray versionArray = toVersionArray(versionString);

    string mongodVersion() {
        stringstream ss;
        ss << "db version v" << versionString;
        return ss.str();
    }

#ifndef _SCONS
    //
    // The following implementations are provided for use when buildinfo.cpp is not autogenerated.
    //

    const char * gitVersion() { return "not-scons"; }
    const char * compiledJSEngine() { return ""; }
    const char * allocator() { return ""; }
    const char * loaderFlags() { return ""; }
    const char * compilerFlags() { return ""; }

#if defined(_WIN32)
    string sysInfo() {
        stringstream ss;
        ss << "not-scons win";
        ss << " mscver:" << _MSC_FULL_VER << " built:" << __DATE__;
        ss << " boostver:" << BOOST_VERSION;
#if( !defined(_MT) )
#error _MT is not defined
#endif  // !defined(_MT)
        ss << (sizeof(char *) == 8 ? " 64bit" : " 32bit");
        return ss.str();
    }
#else  // defined(_WIN32)
    string sysInfo() { return ""; }

#endif  // defined(_WIN32)
#endif  // !defined(_SCONS)

}  // namespace mongo
