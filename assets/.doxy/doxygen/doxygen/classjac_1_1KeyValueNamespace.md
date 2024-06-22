

# Class jac::KeyValueNamespace



[**ClassList**](annotated.md) **>** [**jac**](namespacejac.md) **>** [**KeyValueNamespace**](classjac_1_1KeyValueNamespace.md)






















## Public Types

| Type | Name |
| ---: | :--- |
| enum uint8\_t | [**DataType**](#enum-datatype)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**KeyValueNamespace**](#function-keyvaluenamespace-22) () <br> |
| virtual bool | [**commit**](#function-commit) () = 0<br> |
| virtual bool | [**erase**](#function-erase) (const std::string & name) = 0<br> |
| virtual float | [**getFloat**](#function-getfloat) (const std::string & name, float def\_value=0.f) = 0<br> |
| virtual int64\_t | [**getInt**](#function-getint) (const std::string & name, int64\_t def\_value=0) = 0<br> |
| virtual std::string | [**getString**](#function-getstring) (const std::string & name, std::string def\_value="") = 0<br> |
| virtual void | [**setFloat**](#function-setfloat) (const std::string & name, float value) = 0<br> |
| virtual void | [**setInt**](#function-setint) (const std::string & name, int64\_t value) = 0<br> |
| virtual void | [**setString**](#function-setstring) (const std::string & name, const std::string & value) = 0<br> |
| virtual  | [**~KeyValueNamespace**](#function-keyvaluenamespace) () <br> |




























## Public Types Documentation




### enum DataType 

```C++
enum jac::KeyValueNamespace::DataType {
    INT64 = 0,
    FLOAT32 = 1,
    STRING = 2
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



### function getFloat 

```C++
virtual float jac::KeyValueNamespace::getFloat (
    const std::string & name,
    float def_value=0.f
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

