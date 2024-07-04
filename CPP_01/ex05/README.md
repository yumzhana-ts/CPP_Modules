# Harl 1.0

The goal of this exercise is to use pointers to member functions. This is not a
suggestion. Harl has to complain without using a forest of if/else if/else. It doesn’t think
twice!

## Q1. How to use pointers to memeber functions and why?
A variable that stores the address of a member function of a class. 

- Single Pointer, Multiple Member Functions: 
Using a single function pointer (ptr), 
you can dynamically assign and invoke different member functions of the same class (MyClass).

- Dynamic Behavior: 
This capability allows for runtime selection of which member function to execute, 
based on conditions or inputs known at runtime.

- Flexibility: 
Function pointers to member functions are useful for implementing advanced patterns such as callbacks, 
state machines, or polymorphism, where different behaviors need to be selected dynamically.


## Solution

1. Delare pointer_to_member_function outside the class
2. To an array of pointer_to_member_function add all member functions
3. Use 'this' to call member function based on iterator