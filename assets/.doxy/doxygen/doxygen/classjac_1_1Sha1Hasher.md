

# Class jac::Sha1Hasher



[**ClassList**](annotated.md) **>** [**jac**](namespacejac.md) **>** [**Sha1Hasher**](classjac_1_1Sha1Hasher.md)










































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Sha1Hasher**](#function-sha1hasher-12) () <br> |
|   | [**Sha1Hasher**](#function-sha1hasher-22) (const [**Sha1Hasher**](classjac_1_1Sha1Hasher.md) &) = delete<br> |
|  std::span&lt; const uint8\_t, 20 &gt; | [**processFile**](#function-processfile) (const std::filesystem::path & path) <br> |
|   | [**~Sha1Hasher**](#function-sha1hasher) () <br> |




























## Public Functions Documentation




### function Sha1Hasher [1/2]

```C++
inline jac::Sha1Hasher::Sha1Hasher () 
```




<hr>



### function Sha1Hasher [2/2]

```C++
jac::Sha1Hasher::Sha1Hasher (
    const Sha1Hasher &
) = delete
```




<hr>



### function processFile 

```C++
inline std::span< const uint8_t, 20 > jac::Sha1Hasher::processFile (
    const std::filesystem::path & path
) 
```




<hr>



### function ~Sha1Hasher 

```C++
inline jac::Sha1Hasher::~Sha1Hasher () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/jac/device/uploader.cpp`

