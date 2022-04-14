The program searches for a gradient in the picture and replaces it with white colors.
The entrance requires a folder with pictures. At the output, the program will generate new images in the same folder with the gradients found.

# How to run the program? # 
You need to write the following lines:

Linux:
1. mkdir build
2. cd build
3. cmake ../
4. make
5. ./Gradient-Parser
6. Select the folder with pictures where we want to find the gradient. \
* For tests, we write at this stage ../tests

# Examples: #

## Before: ##
![alt text](./examples/redgr.png)

## After: ##
![alt text](./examples/redgr_grad.png)


## Before: ##
![alt text](./examples/many.png)

## After: ##
![alt text](./examples/many_grad.png)



## Before: ##
![alt text](./examples/soft.png)

## After: ##
![alt text](./examples/soft_grad.png)