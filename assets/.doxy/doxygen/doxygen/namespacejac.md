

# Namespace jac



[**Namespace List**](namespaces.md) **>** [**jac**](namespacejac.md)


















## Namespaces

| Type | Name |
| ---: | :--- |
| namespace | [**ProtoBuilder**](namespacejac_1_1ProtoBuilder.md) <br> |


## Classes

| Type | Name |
| ---: | :--- |
| class | [**Controller**](classjac_1_1Controller.md) <br> |
| class | [**Device**](classjac_1_1Device.md) &lt;[**class**](classjac_1_1Device.md) [**Machine**](classjac_1_1Device.md)&gt;<br> |
| class | [**KeyValueFeature**](classjac_1_1KeyValueFeature.md) &lt;[**class**](classjac_1_1Device.md) Next&gt;<br> |
| class | [**KeyValueNamespace**](classjac_1_1KeyValueNamespace.md) <br> |
| struct | [**KeyValueNamespaceProtoBuilder**](structjac_1_1KeyValueNamespaceProtoBuilder.md) <br> |
| class | [**LinkReadable**](classjac_1_1LinkReadable.md) &lt;[**class**](classjac_1_1Device.md) [**Machine**](classjac_1_1Device.md)&gt;<br> |
| class | [**LinkWritable**](classjac_1_1LinkWritable.md) <br> |
| struct | [**Logger**](structjac_1_1Logger.md) <br> |
| class | [**MachineCtrl**](classjac_1_1MachineCtrl.md) <br> |
| class | [**Sha1Hasher**](classjac_1_1Sha1Hasher.md) <br> |
| class | [**Timeout**](classjac_1_1Timeout.md) <br> |
| class | [**TimeoutLock**](classjac_1_1TimeoutLock.md) <br> |
| class | [**Uploader**](classjac_1_1Uploader.md) <br> |


## Public Types

| Type | Name |
| ---: | :--- |
| typedef std::function&lt; std::unique\_ptr&lt; [**KeyValueNamespace**](classjac_1_1KeyValueNamespace.md) &gt;([**const**](classjac_1_1Device.md) std::string &)&gt; | [**KeyValueOpener**](#typedef-keyvalueopener)  <br> |






















## Public Static Functions

| Type | Name |
| ---: | :--- |
|  [**bool**](classjac_1_1Device.md) | [**deleteDir**](#function-deletedir) (std::filesystem::path & path, [**bool**](classjac_1_1Device.md) onlyContents) <br> |
|  std::optional&lt; std::filesystem::path &gt; | [**getAbsolute**](#function-getabsolute) (std::string filename, std::filesystem::path & rootDir) <br> |
|  std::optional&lt; std::pair&lt; std::vector&lt; std::string &gt;, [**size\_t**](classjac_1_1Device.md) &gt; &gt; | [**listDir**](#function-listdir) (std::filesystem::path & path) <br> |


























## Public Types Documentation




### typedef KeyValueOpener 

```C++
using jac::KeyValueOpener = typedef std::function<std::unique_ptr<KeyValueNamespace>(const std::string&)>;
```




<hr>
## Public Static Functions Documentation




### function deleteDir 

```C++
static bool jac::deleteDir (
    std::filesystem::path & path,
    bool onlyContents
) 
```




<hr>



### function getAbsolute 

```C++
static std::optional< std::filesystem::path > jac::getAbsolute (
    std::string filename,
    std::filesystem::path & rootDir
) 
```




<hr>



### function listDir 

```C++
static std::optional< std::pair< std::vector< std::string >, size_t > > jac::listDir (
    std::filesystem::path & path
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/jac/device/controller.cpp`

