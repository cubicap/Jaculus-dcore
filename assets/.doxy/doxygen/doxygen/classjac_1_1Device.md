

# Class jac::Device

**template &lt;class Machine&gt;**



[**ClassList**](annotated.md) **>** [**jac**](namespacejac.md) **>** [**Device**](classjac_1_1Device.md)








Inherits the following classes: [jac::MachineCtrl](classjac_1_1MachineCtrl.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Device**](#function-device-13) (std::filesystem::path rootDir, std::function&lt; std::string()&gt; getMemoryStats, std::function&lt; std::string()&gt; getStorageStats, std::vector&lt; std::pair&lt; std::string, std::string &gt;&gt; versionInfo, std::function&lt; void(std::filesystem::path)&gt; formatFS, std::unordered\_map&lt; std::string, std::span&lt; const uint8\_t &gt;&gt; resources, KeyValueOpener openKeyValueNamespace) <br> |
|   | [**Device**](#function-device-23) (const [**Device**](classjac_1_1Device.md) &) = delete<br> |
|   | [**Device**](#function-device-33) ([**Device**](classjac_1_1Device.md) &&) = delete<br> |
| virtual void | [**emitKeyValueModified**](#function-emitkeyvaluemodified) (const std::string & nsname, const std::string & key) override<br> |
| virtual std::tuple&lt; bool, int, std::string &gt; | [**getMachineStatus**](#function-getmachinestatus) () override<br> |
|  [**TimeoutLock**](classjac_1_1TimeoutLock.md) & | [**lock**](#function-lock) () <br> |
|  MachineIO & | [**machineIO**](#function-machineio) () <br> |
|  void | [**onConfigureMachine**](#function-onconfiguremachine) (std::function&lt; void(Machine &)&gt; f) <br> |
|  void | [**onKeyValueModified**](#function-onkeyvaluemodified) (std::function&lt; void(const std::string &, const std::string &)&gt; f) <br> |
| virtual std::unique\_ptr&lt; [**KeyValueNamespace**](classjac_1_1KeyValueNamespace.md) &gt; | [**openKeyValue**](#function-openkeyvalue) (const std::string & nsname) override const<br> |
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
| virtual void | [**emitKeyValueModified**](classjac_1_1MachineCtrl.md#function-emitkeyvaluemodified) (const std::string & nsname, const std::string & key) = 0<br> |
| virtual std::tuple&lt; bool, int, std::string &gt; | [**getMachineStatus**](classjac_1_1MachineCtrl.md#function-getmachinestatus) () = 0<br> |
| virtual std::unique\_ptr&lt; [**KeyValueNamespace**](classjac_1_1KeyValueNamespace.md) &gt; | [**openKeyValue**](classjac_1_1MachineCtrl.md#function-openkeyvalue) (const std::string & nsname) const = 0<br> |
| virtual bool | [**startMachine**](classjac_1_1MachineCtrl.md#function-startmachine) (std::string path) = 0<br> |
| virtual bool | [**stopMachine**](classjac_1_1MachineCtrl.md#function-stopmachine) () = 0<br> |






















































## Public Functions Documentation




### function Device [1/3]

```C++
inline jac::Device::Device (
    std::filesystem::path rootDir,
    std::function< std::string()> getMemoryStats,
    std::function< std::string()> getStorageStats,
    std::vector< std::pair< std::string, std::string >> versionInfo,
    std::function< void(std::filesystem::path)> formatFS,
    std::unordered_map< std::string, std::span< const uint8_t >> resources,
    KeyValueOpener openKeyValueNamespace
) 
```




<hr>



### function Device [2/3]

```C++
jac::Device::Device (
    const Device &
) = delete
```




<hr>



### function Device [3/3]

```C++
jac::Device::Device (
    Device &&
) = delete
```




<hr>



### function emitKeyValueModified 

```C++
inline virtual void jac::Device::emitKeyValueModified (
    const std::string & nsname,
    const std::string & key
) override
```



Implements [*jac::MachineCtrl::emitKeyValueModified*](classjac_1_1MachineCtrl.md#function-emitkeyvaluemodified)


<hr>



### function getMachineStatus 

```C++
virtual std::tuple< bool, int, std::string > jac::Device::getMachineStatus () override
```



Implements [*jac::MachineCtrl::getMachineStatus*](classjac_1_1MachineCtrl.md#function-getmachinestatus)


<hr>



### function lock 

```C++
inline TimeoutLock & jac::Device::lock () 
```




<hr>



### function machineIO 

```C++
inline MachineIO & jac::Device::machineIO () 
```




<hr>



### function onConfigureMachine 

```C++
inline void jac::Device::onConfigureMachine (
    std::function< void(Machine &)> f
) 
```




<hr>



### function onKeyValueModified 

```C++
inline void jac::Device::onKeyValueModified (
    std::function< void(const std::string &, const std::string &)> f
) 
```




<hr>



### function openKeyValue 

```C++
inline virtual std::unique_ptr< KeyValueNamespace > jac::Device::openKeyValue (
    const std::string & nsname
) override const
```



Implements [*jac::MachineCtrl::openKeyValue*](classjac_1_1MachineCtrl.md#function-openkeyvalue)


<hr>



### function operator= 

```C++
Device & jac::Device::operator= (
    const Device &
) = delete
```




<hr>



### function operator= 

```C++
Device & jac::Device::operator= (
    Device &&
) = delete
```




<hr>



### function router 

```C++
inline Router & jac::Device::router () 
```




<hr>



### function start 

```C++
inline void jac::Device::start () 
```




<hr>



### function startMachine 

```C++
virtual bool jac::Device::startMachine (
    std::string path
) override
```



Implements [*jac::MachineCtrl::startMachine*](classjac_1_1MachineCtrl.md#function-startmachine)


<hr>



### function stopMachine 

```C++
virtual bool jac::Device::stopMachine () override
```



Implements [*jac::MachineCtrl::stopMachine*](classjac_1_1MachineCtrl.md#function-stopmachine)


<hr>



### function ~Device 

```C++
inline jac::Device::~Device () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/jac/device/device.h`

