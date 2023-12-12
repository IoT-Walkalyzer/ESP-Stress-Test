# ESP Stress Test
## Description
This is a two-part repository containing C++ code for the sender and Python code for the receiver. 
This code is used to test the limits of the sender (in this case the ESP-WROOM-32) to see at what frequency we would be able to send a 40x40 `uint8_t` (1600 bytes) matrix (2D-array). 

## Use-Case
The use-case of this project is to find the limits of the sender. With this information we know the max frequency at which we can send our data. 
It also gives us insight in the best protocol to use and if in the future any upgrades need to be applied, where they should be applied.
