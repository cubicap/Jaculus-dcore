

# Class jac::LinkReadable

**template &lt;[**class**](classjac_1_1Device.md) [**Machine**](classjac_1_1Device.md)&gt;**



[**ClassList**](annotated.md) **>** [**jac**](namespacejac.md) **>** [**LinkReadable**](classjac_1_1LinkReadable.md)








Inherits the following classes: Readable


































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**LinkReadable**](#function-linkreadable-13) ([**Machine**](classjac_1_1Device.md) \* machine, [**jac::InputStreamCommunicator**](classjac_1_1Device.md) \* comm) <br> |
|   | [**LinkReadable**](#function-linkreadable-23) ([**LinkReadable**](classjac_1_1LinkReadable.md) &) = delete<br> |
|   | [**LinkReadable**](#function-linkreadable-33) ([**LinkReadable**](classjac_1_1LinkReadable.md) &&) = delete<br> |
|  [**bool**](classjac_1_1Device.md) | [**get**](#function-get) (std::function&lt; [**void**](classjac_1_1Device.md)([**char**](classjac_1_1Device.md))&gt; callback) override<br> |
|  [**bool**](classjac_1_1Device.md) | [**read**](#function-read) (std::function&lt; [**void**](classjac_1_1Device.md)(std::string)&gt; callback) override<br> |
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
    std::function< void ( char )> callback
) override
```




<hr>



### function read 

```C++
inline bool jac::LinkReadable::read (
    std::function< void (std::string)> callback
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

