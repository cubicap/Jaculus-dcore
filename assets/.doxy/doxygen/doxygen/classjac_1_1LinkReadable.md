

# Class jac::LinkReadable

**template &lt;class Machine&gt;**



[**ClassList**](annotated.md) **>** [**jac**](namespacejac.md) **>** [**LinkReadable**](classjac_1_1LinkReadable.md)








Inherits the following classes: Readable


































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**LinkReadable**](#function-linkreadable-13) (Machine \* machine, jac::InputStreamCommunicator \* comm) <br> |
|   | [**LinkReadable**](#function-linkreadable-23) ([**LinkReadable**](classjac_1_1LinkReadable.md) &) = delete<br> |
|   | [**LinkReadable**](#function-linkreadable-33) ([**LinkReadable**](classjac_1_1LinkReadable.md) &&) = delete<br> |
|  bool | [**get**](#function-get) (std::function&lt; void(char)&gt; callback) override<br> |
|  bool | [**read**](#function-read) (std::function&lt; void(std::string)&gt; callback) override<br> |
|   | [**~LinkReadable**](#function-linkreadable) () override<br> |




























## Public Functions Documentation




### function LinkReadable [1/3]

```C++
inline jac::LinkReadable::LinkReadable (
    Machine * machine,
    jac::InputStreamCommunicator * comm
) 
```




<hr>



### function LinkReadable [2/3]

```C++
jac::LinkReadable::LinkReadable (
    LinkReadable &
) = delete
```




<hr>



### function LinkReadable [3/3]

```C++
jac::LinkReadable::LinkReadable (
    LinkReadable &&
) = delete
```




<hr>



### function get 

```C++
inline bool jac::LinkReadable::get (
    std::function< void(char)> callback
) override
```




<hr>



### function read 

```C++
inline bool jac::LinkReadable::read (
    std::function< void(std::string)> callback
) override
```




<hr>



### function ~LinkReadable 

```C++
inline jac::LinkReadable::~LinkReadable () override
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/jac/features/util/linkIo.h`

