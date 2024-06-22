

# Struct mbedtls\_sha1\_context



[**ClassList**](annotated.md) **>** [**mbedtls\_sha1\_context**](structmbedtls__sha1__context.md)



_The SHA-1 context structure._ [More...](#detailed-description)

* `#include <sha1.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|  uint32\_t | [**MBEDTLS\_PRIVATE**](#function-mbedtls_private-13) (total) <br> |
|  uint32\_t | [**MBEDTLS\_PRIVATE**](#function-mbedtls_private-23) (state) <br> |
|  unsigned char | [**MBEDTLS\_PRIVATE**](#function-mbedtls_private-33) (buffer) <br> |




























# Detailed Description




**Warning:**

SHA-1 is considered a weak message digest and its use constitutes a security risk. We recommend considering stronger message digests instead. 





    
## Public Functions Documentation




### function MBEDTLS\_PRIVATE [1/3]


```C++
uint32_t mbedtls_sha1_context::MBEDTLS_PRIVATE (
    total
) 
```



The number of Bytes processed. 
 


        

<hr>



### function MBEDTLS\_PRIVATE [2/3]


```C++
uint32_t mbedtls_sha1_context::MBEDTLS_PRIVATE (
    state
) 
```



The intermediate digest state. 
 


        

<hr>



### function MBEDTLS\_PRIVATE [3/3]


```C++
unsigned char mbedtls_sha1_context::MBEDTLS_PRIVATE (
    buffer
) 
```



The data block being processed. 


        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/jac/device/util/sha1.h`

