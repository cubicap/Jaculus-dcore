# Getting started

## Setup

The first step is to install the Jaculus CLI tool:

```bash
npm install -g jaculus-tools
```

## Installing the runtime

On Windows, this step requires Python 3 and git to be installed.

On Linux, this step requires python3, python3-venv, git, cmake.

The runtime can be installed using the following command:

    jaculus install --port <port> --platform <platform>

The command will also need to install ESP-IDF, which can take a while.
To use an existing ESP-IDF installation, use the `--idf` option.

Verify that the runtime is installed correctly by running:

    jaculus version


## Connecting to the device

All commands interacting with the device require specifying the device connection using either `--port` or `--socket` option.

To connect to the device using serial port, use:

    jac --port <port> <command>

To connect to the device using TCP socket, use:

    jac --socket <host>:<port> <command>

To list available serial ports, use:

    jac list-ports

To tunnel serial port over TCP, use:

    jac serial-socket --port <port> --socket <port>


## Creating and running TypeScript programs

Create a new TypeScript project, from the template provided at ((TODO)).

Compile the project to JavaScript:

    jac build

The output will be written to the `build` directory.

Flash the JavaScript program to the device:

    jac flash

After flashing, the program will be immediately executed on the device.

The entry point of the program is the `index.ts` file at the root of the project.


## Creating and running JavaScript programs

Create a directory for your source files.

Flash the JavaScript program to the device (`<path>` should point to the source directory):

    jac flash --from <path>

After flashing, the program will be immediately executed on the device.

The entry point of the program is the `index.js` file in the source directory.


## Controlling the device and monitoring its output

To control the device, use the following commands:

    jac start
    jac stop
    jac status
    jac monitor
