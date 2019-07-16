# sbmr
An R library for fitting Stochastic Block Models on network data


## Compiling and testing Cpp code

Currently there is no R code in here and I am working from with raw c++ code using the `g++` compiler. 

To run the current 'tests' for the `Node` class you can compile and run with:

```bash
cd cpp/
g++ -o compiled/test_Node test_Node.cpp Node.cpp
 ./compiled/test_Node
```