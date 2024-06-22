

# File sha1.h



[**FileList**](files.md) **>** [**device**](dir_7dcf813d97a5be213fa89559baaee677.md) **>** [**util**](dir_5f36e4b8294e45bcbbea85a29a4cc9c0.md) **>** [**sha1.h**](sha1_8h.md)

[Go to the source code of this file](sha1_8h_source.md)

_This file contains SHA-1 definitions and functions._ [More...](#detailed-description)

* `#include <stddef.h>`
* `#include <stdint.h>`















## Classes

| Type | Name |
| ---: | :--- |
| struct | [**mbedtls\_sha1\_context**](structmbedtls__sha1__context.md) <br>_The SHA-1 context structure._  |


## Public Types

| Type | Name |
| ---: | :--- |
| typedef struct [**mbedtls\_sha1\_context**](structmbedtls__sha1__context.md) | [**mbedtls\_sha1\_context**](#typedef-mbedtls_sha1_context)  <br>_The SHA-1 context structure._  |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  int | [**mbedtls\_internal\_sha1\_process**](#function-mbedtls_internal_sha1_process) ([**mbedtls\_sha1\_context**](structmbedtls__sha1__context.md) \* ctx, const unsigned char data) <br>_SHA-1 process data block (internal use only)._  |
|  int | [**mbedtls\_sha1**](#function-mbedtls_sha1) (const unsigned char \* input, size\_t ilen, unsigned char output) <br>_This function calculates the SHA-1 checksum of a buffer._  |
|  void | [**mbedtls\_sha1\_clone**](#function-mbedtls_sha1_clone) ([**mbedtls\_sha1\_context**](structmbedtls__sha1__context.md) \* dst, const [**mbedtls\_sha1\_context**](structmbedtls__sha1__context.md) \* src) <br>_This function clones the state of a SHA-1 context._  |
|  int | [**mbedtls\_sha1\_finish**](#function-mbedtls_sha1_finish) ([**mbedtls\_sha1\_context**](structmbedtls__sha1__context.md) \* ctx, unsigned char output) <br>_This function finishes the SHA-1 operation, and writes the result to the output buffer._  |
|  void | [**mbedtls\_sha1\_free**](#function-mbedtls_sha1_free) ([**mbedtls\_sha1\_context**](structmbedtls__sha1__context.md) \* ctx) <br>_This function clears a SHA-1 context._  |
|  void | [**mbedtls\_sha1\_init**](#function-mbedtls_sha1_init) ([**mbedtls\_sha1\_context**](structmbedtls__sha1__context.md) \* ctx) <br>_This function initializes a SHA-1 context._  |
|  int | [**mbedtls\_sha1\_starts**](#function-mbedtls_sha1_starts) ([**mbedtls\_sha1\_context**](structmbedtls__sha1__context.md) \* ctx) <br>_This function starts a SHA-1 checksum calculation._  |
|  int | [**mbedtls\_sha1\_update**](#function-mbedtls_sha1_update) ([**mbedtls\_sha1\_context**](structmbedtls__sha1__context.md) \* ctx, const unsigned char \* input, size\_t ilen) <br>_This function feeds an input buffer into an ongoing SHA-1 checksum calculation._  |



























## Macros

| Type | Name |
| ---: | :--- |
| define  | [**MBEDTLS\_ERR\_ERROR\_CORRUPTION\_DETECTED**](sha1_8h.md#define-mbedtls_err_error_corruption_detected)  -0x006E<br> |
| define  | [**MBEDTLS\_ERR\_SHA1\_BAD\_INPUT\_DATA**](sha1_8h.md#define-mbedtls_err_sha1_bad_input_data)  -0x0073<br> |
| define  | [**MBEDTLS\_PRIVATE**](sha1_8h.md#define-mbedtls_private) (x) x<br> |

# Detailed Description


The Secure Hash Algorithm 1 (SHA-1) cryptographic hash function is defined in _FIPS 180-4: Secure Hash Standard (SHS)_.




**Warning:**

SHA-1 is considered a weak message digest and its use constitutes a security risk. We recommend considering stronger message digests instead. 





    
## Public Types Documentation




### typedef mbedtls\_sha1\_context 

_The SHA-1 context structure._ 
```C++
typedef struct mbedtls_sha1_context mbedtls_sha1_context;
```





**Warning:**

SHA-1 is considered a weak message digest and its use constitutes a security risk. We recommend considering stronger message digests instead. 





        

<hr>
## Public Functions Documentation




### function mbedtls\_internal\_sha1\_process 

_SHA-1 process data block (internal use only)._ 
```C++
int mbedtls_internal_sha1_process (
    mbedtls_sha1_context * ctx,
    const unsigned char data
) 
```





**Warning:**

SHA-1 is considered a weak message digest and its use constitutes a security risk. We recommend considering stronger message digests instead.




**Parameters:**


* `ctx` The SHA-1 context to use. This must be initialized. 
* `data` The data block being processed. This must be a readable buffer of length `64` Bytes.



**Returns:**

`0` on success. 




**Returns:**

A negative error code on failure. 





        

<hr>



### function mbedtls\_sha1 

_This function calculates the SHA-1 checksum of a buffer._ 
```C++
int mbedtls_sha1 (
    const unsigned char * input,
    size_t ilen,
    unsigned char output
) 
```



 

**Warning:**

SHA-1 is considered a weak message digest and its use constitutes a security risk. We recommend considering stronger message digests instead.




**Parameters:**


* `input` The buffer holding the input data. This must be a readable buffer of length `ilen` Bytes. 
* `ilen` The length of the input data `input` in Bytes. 
* `output` The SHA-1 checksum result. This must be a writable buffer of length `20` Bytes.



**Returns:**

`0` on success. 




**Returns:**

A negative error code on failure. 





        

<hr>



### function mbedtls\_sha1\_clone 

_This function clones the state of a SHA-1 context._ 
```C++
void mbedtls_sha1_clone (
    mbedtls_sha1_context * dst,
    const mbedtls_sha1_context * src
) 
```





**Warning:**

SHA-1 is considered a weak message digest and its use constitutes a security risk. We recommend considering stronger message digests instead.




**Parameters:**


* `dst` The SHA-1 context to clone to. This must be initialized. 
* `src` The SHA-1 context to clone from. This must be initialized. 




        

<hr>



### function mbedtls\_sha1\_finish 

_This function finishes the SHA-1 operation, and writes the result to the output buffer._ 
```C++
int mbedtls_sha1_finish (
    mbedtls_sha1_context * ctx,
    unsigned char output
) 
```





**Warning:**

SHA-1 is considered a weak message digest and its use constitutes a security risk. We recommend considering stronger message digests instead.




**Parameters:**


* `ctx` The SHA-1 context to use. This must be initialized and have a hash operation started. 
* `output` The SHA-1 checksum result. This must be a writable buffer of length `20` Bytes.



**Returns:**

`0` on success. 




**Returns:**

A negative error code on failure. 





        

<hr>



### function mbedtls\_sha1\_free 

_This function clears a SHA-1 context._ 
```C++
void mbedtls_sha1_free (
    mbedtls_sha1_context * ctx
) 
```





**Warning:**

SHA-1 is considered a weak message digest and its use constitutes a security risk. We recommend considering stronger message digests instead.




**Parameters:**


* `ctx` The SHA-1 context to clear. This may be `NULL`, in which case this function does nothing. If it is not `NULL`, it must point to an initialized SHA-1 context. 




        

<hr>



### function mbedtls\_sha1\_init 

_This function initializes a SHA-1 context._ 
```C++
void mbedtls_sha1_init (
    mbedtls_sha1_context * ctx
) 
```





**Warning:**

SHA-1 is considered a weak message digest and its use constitutes a security risk. We recommend considering stronger message digests instead.




**Parameters:**


* `ctx` The SHA-1 context to initialize. This must not be `NULL`. 




        

<hr>



### function mbedtls\_sha1\_starts 

_This function starts a SHA-1 checksum calculation._ 
```C++
int mbedtls_sha1_starts (
    mbedtls_sha1_context * ctx
) 
```





**Warning:**

SHA-1 is considered a weak message digest and its use constitutes a security risk. We recommend considering stronger message digests instead.




**Parameters:**


* `ctx` The SHA-1 context to initialize. This must be initialized.



**Returns:**

`0` on success. 




**Returns:**

A negative error code on failure. 





        

<hr>



### function mbedtls\_sha1\_update 

_This function feeds an input buffer into an ongoing SHA-1 checksum calculation._ 
```C++
int mbedtls_sha1_update (
    mbedtls_sha1_context * ctx,
    const unsigned char * input,
    size_t ilen
) 
```





**Warning:**

SHA-1 is considered a weak message digest and its use constitutes a security risk. We recommend considering stronger message digests instead.




**Parameters:**


* `ctx` The SHA-1 context. This must be initialized and have a hash operation started. 
* `input` The buffer holding the input data. This must be a readable buffer of length `ilen` Bytes. 
* `ilen` The length of the input data `input` in Bytes.



**Returns:**

`0` on success. 




**Returns:**

A negative error code on failure. 





        

<hr>
## Macro Definition Documentation





### define MBEDTLS\_ERR\_ERROR\_CORRUPTION\_DETECTED 

```C++
#define MBEDTLS_ERR_ERROR_CORRUPTION_DETECTED -0x006E
```




<hr>



### define MBEDTLS\_ERR\_SHA1\_BAD\_INPUT\_DATA 


```C++
#define MBEDTLS_ERR_SHA1_BAD_INPUT_DATA -0x0073
```



SHA-1 input data was malformed. 


        

<hr>



### define MBEDTLS\_PRIVATE 

```C++
#define MBEDTLS_PRIVATE (
    x
) x
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/jac/device/util/sha1.h`

