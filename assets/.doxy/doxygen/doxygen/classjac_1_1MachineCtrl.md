

# Class jac::MachineCtrl



[**ClassList**](annotated.md) **>** [**jac**](namespacejac.md) **>** [**MachineCtrl**](classjac_1_1MachineCtrl.md)










Inherited by the following classes: [jac::Device](classjac_1_1Device.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual [**void**](classjac_1_1Device.md) | [**emitKeyValueModified**](#function-emitkeyvaluemodified) ([**const**](classjac_1_1Device.md) std::string & nsname, [**const**](classjac_1_1Device.md) std::string & key) = 0<br> |
| virtual std::tuple&lt; [**bool**](classjac_1_1Device.md), [**int**](classjac_1_1Device.md), std::string &gt; | [**getMachineStatus**](#function-getmachinestatus) () = 0<br> |
| virtual std::unique\_ptr&lt; [**KeyValueNamespace**](classjac_1_1KeyValueNamespace.md) &gt; | [**openKeyValue**](#function-openkeyvalue) ([**const**](classjac_1_1Device.md) std::string & nsname) const = 0<br> |
| virtual [**bool**](classjac_1_1Device.md) | [**startMachine**](#function-startmachine) (std::string path) = 0<br> |
| virtual [**bool**](classjac_1_1Device.md) | [**stopMachine**](#function-stopmachine) () = 0<br> |




























## Public Functions Documentation




### function emitKeyValueModified 

```C++
virtual void jac::MachineCtrl::emitKeyValueModified (
    const std::string & nsname,
    const std::string & key
) = 0
```




<hr>



### function getMachineStatus 

```C++
virtual std::tuple< bool , int , std::string > jac::MachineCtrl::getMachineStatus () = 0
```




<hr>



### function openKeyValue 

```C++
virtual std::unique_ptr< KeyValueNamespace > jac::MachineCtrl::openKeyValue (
    const std::string & nsname
) const = 0
```




<hr>



### function startMachine 

```C++
virtual bool jac::MachineCtrl::startMachine (
    std::string path
) = 0
```




<hr>



### function stopMachine 

```C++
virtual bool jac::MachineCtrl::stopMachine () = 0
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/jac/device/util/machineCtrl.h`

