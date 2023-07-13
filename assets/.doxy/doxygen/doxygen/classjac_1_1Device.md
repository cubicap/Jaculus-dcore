

# Class jac::Device

**template &lt;class Machine class Machine&gt;**



[**ClassList**](annotated.md) **>** [**jac**](namespacejac.md) **>** [**Device**](classjac_1_1Device.md)








Inherits the following classes: [jac::MachineCtrl](classjac_1_1MachineCtrl.md)






























## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Device**](#function-device-13) (std::filesystem::path rootDir, std::function&lt; std::string()&gt; getMemoryStats, std::function&lt; std::string()&gt; getStorageStats, std::vector&lt; std::pair&lt; std::string, std::string &gt;&gt; versionInfo, std::function&lt; void(std::filesystem::path)&gt; formatFS) <br> |
|   | [**Device**](#function-device-23) (const [**Device**](classjac_1_1Device.md) &) = delete<br> |
|   | [**Device**](#function-device-33) ([**Device**](classjac_1_1Device.md) &&) = delete<br> |
| virtual std::tuple&lt; bool, int, std::string &gt; | [**getMachineStatus**](#function-getmachinestatus) () override<br> |
|  [**TimeoutLock**](classjac_1_1TimeoutLock.md) & | [**lock**](#function-lock) () <br> |
|  MachineIO & | [**machineIO**](#function-machineio) () <br> |
|  void | [**onConfigureMachine**](#function-onconfiguremachine) (std::function&lt; void(Machine &)&gt; f) <br> |
|  [**Device**](classjac_1_1Device.md) & | [**operator=**](#function-operator) (const [**Device**](classjac_1_1Device.md) &) = delete<br> |
|  [**Device**](classjac_1_1Device.md) & | [**operator=**](#function-operator_1) ([**Device**](classjac_1_1Device.md) &&) = delete<br> |
|  Router & | [**router**](#function-router) () <br> |
|  void | [**start**](#function-start) () <br> |
| virtual bool | [**startMachine**](#function-startmachine) (std::string path) override<br> |
| virtual bool | [**stopMachine**](#function-stopmachine) () override<br> |
|   | [**~Device**](#function-device) () <br> |


## Public Functions inherited from jac::MachineCtrl

See [jac::MachineCtrl](classjac_1_1MachineCtrl.md)

| Type | Name |
| ---: | :--- |
| virtual std::tuple&lt; bool, int, std::string &gt; | [**getMachineStatus**](#function-getmachinestatus) () = 0<br> |
| virtual bool | [**startMachine**](#function-startmachine) (std::string path) = 0<br> |
| virtual bool | [**stopMachine**](#function-stopmachine) () = 0<br> |






























## Public Functions Documentation




### function Device [1/3]

```C++
inline jac::Device::Device (
    std::filesystem::path rootDir,
    std::function< std::string()> getMemoryStats,
    std::function< std::string()> getStorageStats,
    std::vector< std::pair< std::string, std::string >> versionInfo,
    std::function< void(std::filesystem::path)> formatFS
) 
```






### function Device [2/3]

```C++
jac::Device::Device (
    const Device &
) = delete
```






### function Device [3/3]

```C++
jac::Device::Device (
    Device &&
) = delete
```






### function getMachineStatus 

```C++
virtual std::tuple< bool, int, std::string > jac::Device::getMachineStatus () override
```



Implements [*jac::MachineCtrl::getMachineStatus*](classjac_1_1MachineCtrl.md#function-getmachinestatus)




### function lock 

```C++
inline TimeoutLock & jac::Device::lock () 
```






### function machineIO 

```C++
inline MachineIO & jac::Device::machineIO () 
```






### function onConfigureMachine 

```C++
inline void jac::Device::onConfigureMachine (
    std::function< void(Machine &)> f
) 
```






### function operator= 

```C++
Device & jac::Device::operator= (
    const Device &
) = delete
```






### function operator= 

```C++
Device & jac::Device::operator= (
    Device &&
) = delete
```






### function router 

```C++
inline Router & jac::Device::router () 
```






### function start 

```C++
inline void jac::Device::start () 
```






### function startMachine 

```C++
virtual bool jac::Device::startMachine (
    std::string path
) override
```



Implements [*jac::MachineCtrl::startMachine*](classjac_1_1MachineCtrl.md#function-startmachine)




### function stopMachine 

```C++
virtual bool jac::Device::stopMachine () override
```



Implements [*jac::MachineCtrl::stopMachine*](classjac_1_1MachineCtrl.md#function-stopmachine)




### function ~Device 

```C++
inline jac::Device::~Device () 
```




------------------------------
The documentation for this class was generated from the following file `src/jac/device/device.h`

