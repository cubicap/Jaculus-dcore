

# Struct jac::Logger



[**ClassList**](annotated.md) **>** [**jac**](namespacejac.md) **>** [**Logger**](structjac_1_1Logger.md)




























## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  std::unique\_ptr&lt; OutputStreamCommunicator &gt; | [**\_debugStream**](#variable-_debugstream)  <br> |
|  std::unique\_ptr&lt; OutputStreamCommunicator &gt; | [**\_errorStream**](#variable-_errorstream)  <br> |
|  std::unique\_ptr&lt; OutputStreamCommunicator &gt; | [**\_logStream**](#variable-_logstream)  <br> |




## Public Static Functions

| Type | Name |
| ---: | :--- |
|  void | [**debug**](#function-debug) (std::string message) <br> |
|  void | [**error**](#function-error) (std::string message) <br> |
|  void | [**log**](#function-log) (std::string message) <br> |














## Public Static Attributes Documentation




### variable \_debugStream 

```C++
std::unique_ptr< OutputStreamCommunicator > jac::Logger::_debugStream;
```






### variable \_errorStream 

```C++
std::unique_ptr< OutputStreamCommunicator > jac::Logger::_errorStream;
```






### variable \_logStream 

```C++
std::unique_ptr< OutputStreamCommunicator > jac::Logger::_logStream;
```



## Public Static Functions Documentation




### function debug 

```C++
static inline void jac::Logger::debug (
    std::string message
) 
```






### function error 

```C++
static inline void jac::Logger::error (
    std::string message
) 
```






### function log 

```C++
static inline void jac::Logger::log (
    std::string message
) 
```




------------------------------
The documentation for this class was generated from the following file `src/jac/device/logger.h`

