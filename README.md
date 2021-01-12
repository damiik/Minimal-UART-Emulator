# Minimal-UART-Emulator - Linux version

This is linux version of code from Slu4 video https://www.youtube.com/watch?v=DvOO3WtUuvE
After 2 days of fun, experiments and even hard work sometimes I found out good replace code for old Borland/Windows library ````conio.h````. Meanwhile I checked two linux versions of this library, but no one works properly. Finally I found out solution on stackoverflow.com and few functions in ````myio.h```` file fixed my linux-specyfic problems with user input in ````main.cpp````. 

## In my version:

* All time calculations are in [ns] unit - instead of windows ````GetTickCount()```` I used ````GetTickCountNs()````.
* No GettingHigh method.
* Combination ESC+ESC for reset.

------------------------------------------------------------------------------------------

## Original description:

Emulate the Minimal UART CPU in real-time in under 250 lines of C++ code.

I write a cycle exact real-time emulator for a real CPU system in C++ in about 250 lines of code and explain things along the way as good as I can. I am sure there are bugs or improvements to find. Please let me know if you have any suggestions. Watch my other videos about the Minimal UART CPU and minimal 8-bit CPU design on my YouTube channel

https://studio.youtube.com/channel/UCXYQcMpUBT3aaQKfmAVJNow

Cheers,
Slu4
