This project contains two simple state machines to compare a c implementation with a c++ implementation.
Both were are usable in Keil uvision4 for C166 und lpcxpresso 6.1 (using gcc 4.6.2) for NXP LPC1347 (arm cortex m3, 72MHz)

##Findings for C167

###C Code
 * small mem modell         Program Size: data=4097(near=4097) const=642(near=634) code=1502
 * huge (HLarge) mem modell Program Size: data=4097(near=4097) const=644(near=0) code=1704

####Runtime for small mem
 * clocks: init call 25 clocks
 *         from init = 'a' to end } 273 to 975 -> 702 clocks for 6 state transitions

###C++ without new and delete.
 * hlarge mem model:  Program Size: data=4109(near=4109) const=802(near=0) code=2104
 * small mem model:   Program Size: data=4103(near=4103) const=764(near=730) code=1672

####Runtime for small mem
 * constructor call 102 clocks
 * from char input = 'a'; to } 2571 - 1174 -> 1397 clocks for 6 state transitions


##Findings for LPC1347

###C code (patched gcc 4.6.2 with -Os)
 text: 2052 data: 0 bss: 156 dec: 2208

####Runtime
 * clocks: init call 19 clocks
 *         from init = 'a' to end } 7746 to 8853 -> 1107 clocks for 6 state transitions

###C++ code (patched gcc 4.6.2 with -Os with newlib none without new, delete, printf etc)
 * gcc -Os text 1264 data 4	bss 40 dec 1308

####Runtime
 * constructor call 85 clocks
 * from char input = 'a'; to } 10363 - 9020 -> 1343 clocks for 6 state transitions
