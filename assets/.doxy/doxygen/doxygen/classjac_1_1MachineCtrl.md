

# Class jac::MachineCtrl



[**ClassList**](annotated.md) **>** [**jac**](namespacejac.md) **>** [**MachineCtrl**](classjac_1_1MachineCtrl.md)










Inherited by the following classes: [jac::Device](classjac_1_1Device.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual std::tuple&lt; bool, int, std::string &gt; | [**getMachineStatus**](#function-getmachinestatus) () = 0<br> |
| virtual bool | [**startMachine**](#function-startmachine) (std::string path) = 0<br> |
| virtual bool | [**stopMachine**](#function-stopmachine) () = 0<br> |




























## Public Functions Documentation




### function getMachineStatus 

```C++
virtual std::tuple< bool, int, std::string > jac::MachineCtrl::getMachineStatus () = 0
```






### function startMachine 

```C++
virtual bool jac::MachineCtrl::startMachine (
    std::string path
) = 0
```






### function stopMachine 

```C++
virtual bool jac::MachineCtrl::stopMachine () = 0
```




------------------------------
The documentation for this class was generated from the following file `src/jac/device/util/machineCtrl.h`

