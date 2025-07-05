

# Class jac::KeyValueNamespace



[**ClassList**](annotated.md) **>** [**jac**](namespacejac.md) **>** [**KeyValueNamespace**](classjac_1_1KeyValueNamespace.md)






















## Public Types

| Type | Name |
| ---: | :--- |
| enum [**uint8\_t**](classjac_1_1Device.md) | [**DataType**](#enum-datatype)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**KeyValueNamespace**](#function-keyvaluenamespace-22) () <br> |
| virtual [**bool**](classjac_1_1Device.md) | [**commit**](#function-commit) () = 0<br> |
| virtual [**bool**](classjac_1_1Device.md) | [**erase**](#function-erase) ([**const**](classjac_1_1Device.md) std::string & name) = 0<br> |
|  [**bool**](classjac_1_1Device.md) | [**exists**](#function-exists) ([**const**](classjac_1_1Device.md) std::string & name) <br> |
| virtual [**float**](classjac_1_1Device.md) | [**getFloat**](#function-getfloat) ([**const**](classjac_1_1Device.md) std::string & name, [**float**](classjac_1_1Device.md) def\_value=0.[**f**](classjac_1_1Device.md)) = 0<br> |
| virtual [**int64\_t**](classjac_1_1Device.md) | [**getInt**](#function-getint) ([**const**](classjac_1_1Device.md) std::string & name, [**int64\_t**](classjac_1_1Device.md) def\_value=0) = 0<br> |
| virtual std::string | [**getString**](#function-getstring) ([**const**](classjac_1_1Device.md) std::string & name, std::string def\_value="") = 0<br> |
| virtual DataType | [**getType**](#function-gettype) ([**const**](classjac_1_1Device.md) std::string & name) = 0<br> |
| virtual std::vector&lt; std::string &gt; | [**keys**](#function-keys) () = 0<br> |
| virtual [**void**](classjac_1_1Device.md) | [**setFloat**](#function-setfloat) ([**const**](classjac_1_1Device.md) std::string & name, [**float**](classjac_1_1Device.md) value) = 0<br> |
| virtual [**void**](classjac_1_1Device.md) | [**setInt**](#function-setint) ([**const**](classjac_1_1Device.md) std::string & name, [**int64\_t**](classjac_1_1Device.md) value) = 0<br> |
| virtual [**void**](classjac_1_1Device.md) | [**setString**](#function-setstring) ([**const**](classjac_1_1Device.md) std::string & name, [**const**](classjac_1_1Device.md) std::string & value) = 0<br> |
| virtual  | [**~KeyValueNamespace**](#function-keyvaluenamespace) () <br> |




























## Public Types Documentation




### enum DataType 

```C++
enum jac::KeyValueNamespace::DataType {
    INT64 = 0,
    FLOAT32 = 1,
    STRING = 2,
    NOT_FOUND = 0xFF
};
```




<hr>
## Public Functions Documentation




### function KeyValueNamespace [2/2]

```C++
inline jac::KeyValueNamespace::KeyValueNamespace () 
```




<hr>



### function commit 

```C++
virtual bool jac::KeyValueNamespace::commit () = 0
```




<hr>



### function erase 

```C++
virtual bool jac::KeyValueNamespace::erase (
    const std::string & name
) = 0
```




<hr>



### function exists 

```C++
inline bool jac::KeyValueNamespace::exists (
    const std::string & name
) 
```




<hr>



### function getFloat 

```C++
virtual float jac::KeyValueNamespace::getFloat (
    const std::string & name,
    float def_value=0. f
) = 0
```




<hr>



### function getInt 

```C++
virtual int64_t jac::KeyValueNamespace::getInt (
    const std::string & name,
    int64_t def_value=0
) = 0
```




<hr>



### function getString 

```C++
virtual std::string jac::KeyValueNamespace::getString (
    const std::string & name,
    std::string def_value=""
) = 0
```




<hr>



### function getType 

```C++
virtual DataType jac::KeyValueNamespace::getType (
    const std::string & name
) = 0
```




<hr>



### function keys 

```C++
virtual std::vector< std::string > jac::KeyValueNamespace::keys () = 0
```




<hr>



### function setFloat 

```C++
virtual void jac::KeyValueNamespace::setFloat (
    const std::string & name,
    float value
) = 0
```




<hr>



### function setInt 

```C++
virtual void jac::KeyValueNamespace::setInt (
    const std::string & name,
    int64_t value
) = 0
```




<hr>



### function setString 

```C++
virtual void jac::KeyValueNamespace::setString (
    const std::string & name,
    const std::string & value
) = 0
```




<hr>



### function ~KeyValueNamespace 

```C++
inline virtual jac::KeyValueNamespace::~KeyValueNamespace () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/jac/device/keyvalue.h`

