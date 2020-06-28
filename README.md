# Class.cpp demonstrate some functionality of class

# Virtual destructor demo
    $ g++ --std=c++14 Class.cpp
    $ g++ --std=c++14 Class.cpp -DDEMO_VIRTUAL_DESTRUCTOR

# Pure virtual class demo
    $ g++ --std=c++14 Class.cpp -DDEMO_VIRTUAL_DESTRUCTOR
    $ g++ --std=c++14 Class.cpp -DDEMO_VIRTUAL_DESTRUCTOR -DDEMO_PURE_VIRTUAL_CLASS

# Operator over-loading complex number example 
    $ g++ ComplexNumber.cpp --std=c++14
