

# Namespace jac



[**Namespace List**](namespaces.md) **>** [**jac**](namespacejac.md)




















## Classes

| Type | Name |
| ---: | :--- |
| class | [**Controller**](classjac_1_1Controller.md) <br> |
| class | [**Device**](classjac_1_1Device.md) &lt;class Machine&gt;<br> |
| class | [**LinkReadable**](classjac_1_1LinkReadable.md) &lt;class Machine&gt;<br> |
| class | [**LinkWritable**](classjac_1_1LinkWritable.md) <br> |
| struct | [**Logger**](structjac_1_1Logger.md) <br> |
| class | [**MachineCtrl**](classjac_1_1MachineCtrl.md) <br> |
| class | [**Sha1Hasher**](classjac_1_1Sha1Hasher.md) <br> |
| class | [**Timeout**](classjac_1_1Timeout.md) <br> |
| class | [**TimeoutLock**](classjac_1_1TimeoutLock.md) <br> |
| class | [**Uploader**](classjac_1_1Uploader.md) <br> |












## Public Static Functions

| Type | Name |
| ---: | :--- |
|  bool | [**deleteDir**](#function-deletedir) (std::filesystem::path & path, bool onlyContents) <br> |
|  std::optional&lt; std::filesystem::path &gt; | [**getAbsolute**](#function-getabsolute) (std::string filename, std::filesystem::path & rootDir) <br> |
|  std::optional&lt; std::pair&lt; std::vector&lt; std::string &gt;, size\_t &gt; &gt; | [**listDir**](#function-listdir) (std::filesystem::path & path) <br> |














## Public Static Functions Documentation




### function deleteDir 

```C++
static bool jac::deleteDir (
    std::filesystem::path & path,
    bool onlyContents
) 
```






### function getAbsolute 

```C++
static std::optional< std::filesystem::path > jac::getAbsolute (
    std::string filename,
    std::filesystem::path & rootDir
) 
```






### function listDir 

```C++
static std::optional< std::pair< std::vector< std::string >, size_t > > jac::listDir (
    std::filesystem::path & path
) 
```




------------------------------
The documentation for this class was generated from the following file `src/jac/device/controller.cpp`

