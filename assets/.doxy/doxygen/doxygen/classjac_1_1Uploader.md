

# Class jac::Uploader



[**ClassList**](annotated.md) **>** [**jac**](namespacejac.md) **>** [**Uploader**](classjac_1_1Uploader.md)






















## Public Types

| Type | Name |
| ---: | :--- |
| enum uint8\_t | [**Command**](#enum-command)  <br> |
| enum uint8\_t | [**Error**](#enum-error)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Uploader**](#function-uploader-13) (std::unique\_ptr&lt; InputPacketCommunicator &gt; input, std::unique\_ptr&lt; OutputPacketCommunicator &gt; output, [**TimeoutLock**](classjac_1_1TimeoutLock.md) & lock, std::filesystem::path rootDir, std::function&lt; void(std::filesystem::path)&gt; formatFS, std::unordered\_map&lt; std::string, std::span&lt; const uint8\_t &gt;&gt; resources) <br> |
|   | [**Uploader**](#function-uploader-23) (const [**Uploader**](classjac_1_1Uploader.md) &) = delete<br> |
|   | [**Uploader**](#function-uploader-33) ([**Uploader**](classjac_1_1Uploader.md) &&) = delete<br> |
|  void | [**lockTimeout**](#function-locktimeout) () <br> |
|  [**Uploader**](classjac_1_1Uploader.md) & | [**operator=**](#function-operator) (const [**Uploader**](classjac_1_1Uploader.md) &) = delete<br> |
|  [**Uploader**](classjac_1_1Uploader.md) & | [**operator=**](#function-operator_1) ([**Uploader**](classjac_1_1Uploader.md) &&) = delete<br> |
|  void | [**start**](#function-start) () <br> |
|   | [**~Uploader**](#function-uploader) () <br> |




























## Public Types Documentation




### enum Command 

```C++
enum jac::Uploader::Command {
    READ_FILE = 0x01,
    WRITE_FILE = 0x02,
    DELETE_FILE = 0x03,
    LIST_DIR = 0x04,
    CREATE_DIR = 0x05,
    DELETE_DIR = 0x06,
    FORMAT_STORAGE = 0x07,
    LIST_RESOURCES = 0x08,
    READ_RESOURCE = 0x09,
    HAS_MORE_DATA = 0x10,
    LAST_DATA = 0x11,
    OK = 0x20,
    ERROR = 0x21,
    NOT_FOUND = 0x22,
    CONTINUE = 0x23,
    LOCK_NOT_OWNED = 0x24,
    GET_DIR_HASHES = 0x25
};
```




<hr>



### enum Error 

```C++
enum jac::Uploader::Error {
    UNKNOWN_COMMAND = 0x01,
    FILE_OPEN_FAILED = 0x02,
    FILE_DELETE_FAILED = 0x03,
    DIR_OPEN_FAILED = 0x04,
    DIR_CREATE_FAILED = 0x05,
    DIR_DELETE_FAILED = 0x06,
    INVALID_FILENAME = 0x07
};
```




<hr>
## Public Functions Documentation




### function Uploader [1/3]

```C++
inline jac::Uploader::Uploader (
    std::unique_ptr< InputPacketCommunicator > input,
    std::unique_ptr< OutputPacketCommunicator > output,
    TimeoutLock & lock,
    std::filesystem::path rootDir,
    std::function< void(std::filesystem::path)> formatFS,
    std::unordered_map< std::string, std::span< const uint8_t >> resources
) 
```




<hr>



### function Uploader [2/3]

```C++
jac::Uploader::Uploader (
    const Uploader &
) = delete
```




<hr>



### function Uploader [3/3]

```C++
jac::Uploader::Uploader (
    Uploader &&
) = delete
```




<hr>



### function lockTimeout 

```C++
void jac::Uploader::lockTimeout () 
```




<hr>



### function operator= 

```C++
Uploader & jac::Uploader::operator= (
    const Uploader &
) = delete
```




<hr>



### function operator= 

```C++
Uploader & jac::Uploader::operator= (
    Uploader &&
) = delete
```




<hr>



### function start 

```C++
inline void jac::Uploader::start () 
```




<hr>



### function ~Uploader 

```C++
inline jac::Uploader::~Uploader () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/jac/device/uploader.h`

