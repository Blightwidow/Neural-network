# Introduction

This program is a base framework for Neural network that I developed on my spare time. I was curious of the possibility of such programs and quiet amaze by the outcome. It's far from being complete, but I'm planning to continue it soon. [K-fold cross-validation](http://www.csie.ntu.edu.tw/~b92109/course/Machine%20Learning/Cross-Validation.pdf) is the next step.

# Use

The program is well commented, but still a proof of concept. It lacks a lot of error handling and is made for Unix only (thought multi-platform support shouldn't be an issue). 

The _Neuron_ and _Network_ class files (.hcc) are the bases of the framework. _framework_pof.cc_ is just a short program to test the capacity of the _Neuron_ and _Network_ classes. It uses the class _DataReader_ to asses the data and feed it to the network. A small program is also prodided: _create-dataset.cc_ which create to sets of data (a training one and a test one). The data are written with a specific syntax to be readable by the _DataReader_ class. It currently generate data corresponding to a XOR gate.


- make all : Compile _framework.hcc_
- make set : Compile, execute and clean _create-dataset.cc_
- make clean : Clean executable files 

# License

This framework was made based on the following [video](https://vimeo.com/19569529).

As stated in the License file, this project is under the MIT License. Feel free to contribute.