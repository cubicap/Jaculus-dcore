

# Class jac::Timeout



[**ClassList**](annotated.md) **>** [**jac**](namespacejac.md) **>** [**Timeout**](classjac_1_1Timeout.md)










































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Timeout**](#function-timeout-13) (std::chrono::milliseconds duration) <br> |
|   | [**Timeout**](#function-timeout-23) (const [**Timeout**](classjac_1_1Timeout.md) &) = delete<br> |
|   | [**Timeout**](#function-timeout-33) ([**Timeout**](classjac_1_1Timeout.md) &&) = delete<br> |
|  void | [**init**](#function-init) () <br> |
|  [**Timeout**](classjac_1_1Timeout.md) & | [**operator=**](#function-operator) (const [**Timeout**](classjac_1_1Timeout.md) &) = delete<br> |
|  [**Timeout**](classjac_1_1Timeout.md) & | [**operator=**](#function-operator_1) ([**Timeout**](classjac_1_1Timeout.md) &&) = delete<br> |
|  void | [**reset**](#function-reset) () <br> |
|  void | [**start**](#function-start) (std::function&lt; void()&gt; callback) <br> |
|  void | [**stop**](#function-stop) () <br> |
|   | [**~Timeout**](#function-timeout) () <br> |




























## Public Functions Documentation




### function Timeout [1/3]

```C++
inline jac::Timeout::Timeout (
    std::chrono::milliseconds duration
) 
```




<hr>



### function Timeout [2/3]

```C++
jac::Timeout::Timeout (
    const Timeout &
) = delete
```




<hr>



### function Timeout [3/3]

```C++
jac::Timeout::Timeout (
    Timeout &&
) = delete
```




<hr>



### function init 

```C++
inline void jac::Timeout::init () 
```




<hr>



### function operator= 

```C++
Timeout & jac::Timeout::operator= (
    const Timeout &
) = delete
```




<hr>



### function operator= 

```C++
Timeout & jac::Timeout::operator= (
    Timeout &&
) = delete
```




<hr>



### function reset 

```C++
inline void jac::Timeout::reset () 
```




<hr>



### function start 

```C++
inline void jac::Timeout::start (
    std::function< void()> callback
) 
```




<hr>



### function stop 

```C++
inline void jac::Timeout::stop () 
```




<hr>



### function ~Timeout 

```C++
inline jac::Timeout::~Timeout () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/jac/device/util/timeout.h`

