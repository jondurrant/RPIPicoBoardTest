# RPIPicoBoardTest
Test Framework for a PCB Board using the Pico or Pico-W.

I wanted to build a framework that could test my PCB using the Pico in a standard way. Checking that the connections and electronics are working. Rather than testing the application itself.

Running a large number of test sequencially when you are trying to catch a waveform from a pin on an Osciliscope is painful. So needed the tests to run in parallel, unlike any unit test framework. So designed the tests to run as Tasks within FreeRTOS.

## Clone and Build
Clone with recurse submodules switch as using FreeRTOS Kernel Library.

Build by using steps:
```
mkdir build
cd build
cmake ..
make
```
