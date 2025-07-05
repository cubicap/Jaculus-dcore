

# Class jac::Controller



[**ClassList**](annotated.md) **>** [**jac**](namespacejac.md) **>** [**Controller**](classjac_1_1Controller.md)










































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Controller**](#function-controller) (std::unique\_ptr&lt; [**InputPacketCommunicator**](classjac_1_1Device.md) &gt; input, std::unique\_ptr&lt; [**OutputPacketCommunicator**](classjac_1_1Device.md) &gt; output, [**TimeoutLock**](classjac_1_1TimeoutLock.md) & lock, [**MachineCtrl**](classjac_1_1MachineCtrl.md) & machineCtrl, std::vector&lt; std::pair&lt; std::string, std::string &gt; &gt; & versionInfo) <br> |
|  [**void**](classjac_1_1Device.md) | [**start**](#function-start) () <br> |
|   | [**~Controller**](#function-controller) () <br> |




























## Public Functions Documentation




### function Controller 

```C++
inline jac::Controller::Controller (
    std::unique_ptr< InputPacketCommunicator > input,
    std::unique_ptr< OutputPacketCommunicator > output,
    TimeoutLock & lock,
    MachineCtrl & machineCtrl,
    std::vector< std::pair< std::string, std::string > > & versionInfo
) 
```




<hr>



### function start 

```C++
inline void jac::Controller::start () 
```




<hr>



### function ~Controller 

```C++
inline jac::Controller::~Controller () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/jac/device/controller.h`

