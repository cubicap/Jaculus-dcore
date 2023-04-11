# Jaculus-device - Library for creating Jaculus devices.

Jaculus-device is a core library that provides the necessary functionality for
running and uploading JavaScript code on the device.

To create a port of Jaculus for a new device, it is necessary to implement a Duplex
stream interface for controlling the device and write hardware bindings to use
the device peripherals.

See tests/main.cpp for a minimal example of how to set up a Jaculus device.

# License

Everything in this repository, unless otherwise noted, is licensed under the
GNU General Public License, version 3.0.
