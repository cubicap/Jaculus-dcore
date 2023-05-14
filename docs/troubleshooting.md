# Troubleshooting

Some problems that may occur when using Jaculus and how to fix them.


## Command stuck on "Connected" and not doing anything

This means that the device does not respond to the communication. This can be caused by several things:

- The firmware is halted or otherwise not responding
- The device is stuck in a boot loop
- The device is not a Jaculus device
- Jaculus-tools version is incompatible with the device firmware

To fix this, try the following:

- Check that you are connecting to the correct port
- Reset the device by pressing the reset button
- Unplug and replug the device
- Flash the Jaculus firmware again ([Getting started](getting-started.md))
- Update Jaculus-tools and device firmware to the latest version


## Command "flash" stuck on one file

This can be caused by several things:

- The device crashed while uploading the file
- The filesystem on the device is corrupted

To fix this, try the following:

- Reset the device by pressing the reset button
- Unplug and replug the device
- Flash the Jaculus firmware again ([Getting started](getting-started.md))
