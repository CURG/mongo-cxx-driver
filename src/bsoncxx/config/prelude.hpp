// Copyright 2014 MongoDB Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// src/bsoncxx/b64_ntop.h
#pragma push_macro("BSONCXX_B64_ASSERT")
#undef BSONCXX_B64_ASSERT

// src/bsoncxx/config/config.hpp.in
#pragma push_macro("BSONCXX_INLINE_NAMESPACE_BEGIN")
#undef BSONCXX_INLINE_NAMESPACE_BEGIN
#pragma push_macro("BSONCXX_INLINE_NAMESPACE_END")
#undef BSONCXX_INLINE_NAMESPACE_END
#pragma push_macro("BSONCXX_POLY_USE_MNMLSTC")
#undef BSONCXX_POLY_USE_MNMLSTC
#pragma push_macro("BSONCXX_POLY_USE_STD_EXPERIMENTAL")
#undef BSONCXX_POLY_USE_STD_EXPERIMENTAL
#pragma push_macro("BSONCXX_POLY_USE_SYSTEM_MNMLSTC")
#undef BSONCXX_POLY_USE_SYSTEM_MNMLSTC

// src/bsoncxx/config/version.hpp.in
#pragma push_macro("BSONCXX_VERSION_EXTRA")
#undef BSONCXX_VERSION_EXTRA
#pragma push_macro("BSONCXX_VERSION_MAJOR")
#undef BSONCXX_VERSION_MAJOR
#pragma push_macro("BSONCXX_VERSION_MINOR")
#undef BSONCXX_VERSION_MINOR
#pragma push_macro("BSONCXX_VERSION_PATCH")
#undef BSONCXX_VERSION_PATCH

// export.hpp (generated by cmake)
#pragma push_macro("BSONCXX_API_H")
#undef BSONCXX_API_H
#pragma push_macro("BSONCXX_DEPRECATED")
#undef BSONCXX_DEPRECATED
#pragma push_macro("BSONCXX_DEPRECATED_EXPORT")
#undef BSONCXX_DEPRECATED_EXPORT
#pragma push_macro("BSONCXX_DEPRECATED_NO_EXPORT")
#undef BSONCXX_DEPRECATED_NO_EXPORT
#pragma push_macro("BSONCXX_NO_DEPRECATED")
#undef BSONCXX_NO_DEPRECATED
#pragma push_macro("BSONCXX_PRIVATE")
#undef BSONCXX_PRIVATE

#include <bsoncxx/config/config.hpp>
#include <bsoncxx/config/version.hpp>
#include <bsoncxx/export.hpp>

// TODO to move this to a compiler.hpp header (CXX-733)
#pragma push_macro("BSONCXX_INLINE")
#undef BSONCXX_INLINE
#define BSONCXX_INLINE inline __attribute__((__visibility__("hidden"), __always_inline__))

#pragma push_macro("BSONCXX_UNREACHABLE")
#undef BSONCXX_UNREACHABLE
#define BSONCXX_UNREACHABLE std::abort()