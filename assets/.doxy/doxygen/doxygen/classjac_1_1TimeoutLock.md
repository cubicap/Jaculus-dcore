

# Class jac::TimeoutLock



[**ClassList**](annotated.md) **>** [**jac**](namespacejac.md) **>** [**TimeoutLock**](classjac_1_1TimeoutLock.md)










































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**TimeoutLock**](#function-timeoutlock-13) (std::chrono::milliseconds duration, std::function&lt; [**void**](classjac_1_1Device.md)()&gt; callback) <br> |
|   | [**TimeoutLock**](#function-timeoutlock-23) ([**const**](classjac_1_1Device.md) [**TimeoutLock**](classjac_1_1TimeoutLock.md) &) = delete<br> |
|   | [**TimeoutLock**](#function-timeoutlock-33) ([**TimeoutLock**](classjac_1_1TimeoutLock.md) &&) = delete<br> |
|  [**void**](classjac_1_1Device.md) | [**forceUnlock**](#function-forceunlock) () <br> |
|  [**void**](classjac_1_1Device.md) | [**init**](#function-init) () <br> |
|  [**bool**](classjac_1_1Device.md) | [**lock**](#function-lock) ([**int**](classjac_1_1Device.md) who) <br> |
|  [**TimeoutLock**](classjac_1_1TimeoutLock.md) & | [**operator=**](#function-operator) ([**const**](classjac_1_1Device.md) [**TimeoutLock**](classjac_1_1TimeoutLock.md) &) = delete<br> |
|  [**TimeoutLock**](classjac_1_1TimeoutLock.md) & | [**operator=**](#function-operator_1) ([**TimeoutLock**](classjac_1_1TimeoutLock.md) &&) = delete<br> |
|  [**bool**](classjac_1_1Device.md) | [**ownedBy**](#function-ownedby) ([**int**](classjac_1_1Device.md) who) <br> |
|  [**void**](classjac_1_1Device.md) | [**resetTimeout**](#function-resettimeout) ([**int**](classjac_1_1Device.md) who) <br> |
|  [**void**](classjac_1_1Device.md) | [**stopTimeout**](#function-stoptimeout) ([**int**](classjac_1_1Device.md) who) <br> |
|  [**bool**](classjac_1_1Device.md) | [**unlock**](#function-unlock) ([**int**](classjac_1_1Device.md) who) <br> |
|   | [**~TimeoutLock**](#function-timeoutlock) () <br> |




























## Public Functions Documentation




### function TimeoutLock [1/3]

```C++
inline jac::TimeoutLock::TimeoutLock (
    std::chrono::milliseconds duration,
    std::function< void ()> callback
) 
```




<hr>



### function TimeoutLock [2/3]

```C++
jac::TimeoutLock::TimeoutLock (
    const  TimeoutLock &
) = delete
```




<hr>



### function TimeoutLock [3/3]

```C++
jac::TimeoutLock::TimeoutLock (
    TimeoutLock &&
) = delete
```




<hr>



### function forceUnlock 

```C++
inline void jac::TimeoutLock::forceUnlock () 
```




<hr>



### function init 

```C++
inline void jac::TimeoutLock::init () 
```




<hr>



### function lock 

```C++
inline bool jac::TimeoutLock::lock (
    int who
) 
```




<hr>



### function operator= 

```C++
TimeoutLock & jac::TimeoutLock::operator= (
    const  TimeoutLock &
) = delete
```




<hr>



### function operator= 

```C++
TimeoutLock & jac::TimeoutLock::operator= (
    TimeoutLock &&
) = delete
```




<hr>



### function ownedBy 

```C++
inline bool jac::TimeoutLock::ownedBy (
    int who
) 
```




<hr>



### function resetTimeout 

```C++
inline void jac::TimeoutLock::resetTimeout (
    int who
) 
```




<hr>



### function stopTimeout 

```C++
inline void jac::TimeoutLock::stopTimeout (
    int who
) 
```




<hr>



### function unlock 

```C++
inline bool jac::TimeoutLock::unlock (
    int who
) 
```




<hr>



### function ~TimeoutLock 

```C++
inline jac::TimeoutLock::~TimeoutLock () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/jac/device/util/lock.h`

