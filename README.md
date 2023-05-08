# Jaculus-dcore - Core library for creating new Jaculus devices

Jaculus-dcore provides the core functionality necessary for defining a new Jaculus device.

To create a port of Jaculus for a new device, it is necessary to implement a Duplex
stream interface for controlling the device and write hardware bindings to use
the device peripherals.

See [Jaculus-esp32](https://github.com/cubicap/Jaculus-esp32) for an example of
how to set up a new Jaculus device.

# License

Everything in this repository, unless otherwise noted, is licensed under the
GNU General Public License, version 3.0.
