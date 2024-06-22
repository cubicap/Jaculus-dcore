

# File sha1.h

[**File List**](files.md) **>** [**device**](dir_7dcf813d97a5be213fa89559baaee677.md) **>** [**util**](dir_5f36e4b8294e45bcbbea85a29a4cc9c0.md) **>** [**sha1.h**](sha1_8h.md)

[Go to the documentation of this file](sha1_8h.md)


```C++
#ifdef JAC_DCORE_USE_MBEDTLS
#include <mbedtls/sha1.h>
#else

/*
 *  Copyright The Mbed TLS Contributors
 *  SPDX-License-Identifier: Apache-2.0
 *
 *  Licensed under the Apache License, Version 2.0 (the "License"); you may
 *  not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 *  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */
#ifndef MBEDTLS_SHA1_H
#define MBEDTLS_SHA1_H

#include <stddef.h>
#include <stdint.h>

#define MBEDTLS_ERR_SHA1_BAD_INPUT_DATA                   -0x0073
#define MBEDTLS_ERR_ERROR_CORRUPTION_DETECTED -0x006E

#define MBEDTLS_PRIVATE(x) x

#ifdef __cplusplus
extern "C" {
#endif

// Regular implementation
//

typedef struct mbedtls_sha1_context {
    uint32_t MBEDTLS_PRIVATE(total)[2];          
    uint32_t MBEDTLS_PRIVATE(state)[5];          
    unsigned char MBEDTLS_PRIVATE(buffer)[64];   
}
mbedtls_sha1_context;

void mbedtls_sha1_init(mbedtls_sha1_context *ctx);

void mbedtls_sha1_free(mbedtls_sha1_context *ctx);

void mbedtls_sha1_clone(mbedtls_sha1_context *dst,
                        const mbedtls_sha1_context *src);

int mbedtls_sha1_starts(mbedtls_sha1_context *ctx);

int mbedtls_sha1_update(mbedtls_sha1_context *ctx,
                        const unsigned char *input,
                        size_t ilen);

int mbedtls_sha1_finish(mbedtls_sha1_context *ctx,
                        unsigned char output[20]);

int mbedtls_internal_sha1_process(mbedtls_sha1_context *ctx,
                                  const unsigned char data[64]);

int mbedtls_sha1(const unsigned char *input,
                 size_t ilen,
                 unsigned char output[20]);

#ifdef __cplusplus
}
#endif

#endif /* mbedtls_sha1.h */

#endif /* !JAC_DCORE_USE_MBEDTLS */
```


