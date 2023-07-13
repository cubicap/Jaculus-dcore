

# Class jac::TimeoutLock



[**ClassList**](annotated.md) **>** [**jac**](namespacejac.md) **>** [**TimeoutLock**](classjac_1_1TimeoutLock.md)






























## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**TimeoutLock**](#function-timeoutlock-13) (std::chrono::milliseconds duration, std::function&lt; void()&gt; callback) <br> |
|   | [**TimeoutLock**](#function-timeoutlock-23) (const [**TimeoutLock**](classjac_1_1TimeoutLock.md) &) = delete<br> |
|   | [**TimeoutLock**](#function-timeoutlock-33) ([**TimeoutLock**](classjac_1_1TimeoutLock.md) &&) = delete<br> |
|  void | [**forceUnlock**](#function-forceunlock) () <br> |
|  bool | [**lock**](#function-lock) (int who) <br> |
|  [**TimeoutLock**](classjac_1_1TimeoutLock.md) & | [**operator=**](#function-operator) (const [**TimeoutLock**](classjac_1_1TimeoutLock.md) &) = delete<br> |
|  [**TimeoutLock**](classjac_1_1TimeoutLock.md) & | [**operator=**](#function-operator_1) ([**TimeoutLock**](classjac_1_1TimeoutLock.md) &&) = delete<br> |
|  bool | [**ownedBy**](#function-ownedby) (int who) <br> |
|  void | [**resetTimeout**](#function-resettimeout) (int who) <br> |
|  void | [**stopTimeout**](#function-stoptimeout) (int who) <br> |
|  bool | [**unlock**](#function-unlock) (int who) <br> |
|   | [**~TimeoutLock**](#function-timeoutlock) () <br> |
















## Public Functions Documentation




### function TimeoutLock [1/3]

```C++
inline jac::TimeoutLock::TimeoutLock (
    std::chrono::milliseconds duration,
    std::function< void()> callback
) 
```






### function TimeoutLock [2/3]

```C++
jac::TimeoutLock::TimeoutLock (
    const TimeoutLock &
) = delete
```






### function TimeoutLock [3/3]

```C++
jac::TimeoutLock::TimeoutLock (
    TimeoutLock &&
) = delete
```






### function forceUnlock 

```C++
inline void jac::TimeoutLock::forceUnlock () 
```






### function lock 

```C++
inline bool jac::TimeoutLock::lock (
    int who
) 
```






### function operator= 

```C++
TimeoutLock & jac::TimeoutLock::operator= (
    const TimeoutLock &
) = delete
```






### function operator= 

```C++
TimeoutLock & jac::TimeoutLock::operator= (
    TimeoutLock &&
) = delete
```






### function ownedBy 

```C++
inline bool jac::TimeoutLock::ownedBy (
    int who
) 
```






### function resetTimeout 

```C++
inline void jac::TimeoutLock::resetTimeout (
    int who
) 
```






### function stopTimeout 

```C++
inline void jac::TimeoutLock::stopTimeout (
    int who
) 
```






### function unlock 

```C++
inline bool jac::TimeoutLock::unlock (
    int who
) 
```






### function ~TimeoutLock 

```C++
inline jac::TimeoutLock::~TimeoutLock () 
```




------------------------------
The documentation for this class was generated from the following file `src/jac/device/util/lock.h`

