# Constructors:

## Q1: What is the syntax of constructors?

Constructor Declaration and Definition:
- Constructors have the same name as the class.
- They do not have a return type, not even void.

Types of Constructors:
Default Constructor: A constructor that takes no arguments.
Parameterized Constructor: A constructor that takes one or more arguments.
Copy Constructor: A constructor that takes a reference to an object of the same class as an argument.


## Q2: Why to use them?

Their primary purpose is to initialize the object's member variables and perform any setup or allocation required when the object is instantiated.

## Q3: Where to declare?
They can be defined inside the class declaration or outside the class using the scope resolution operator ::.


# Class: 

## Q1: Difference between private vs protected?

Encapsulation protects the internal state of an object by preventing 
outside code from directly accessing and modifying it. 
By making data members private and controlling access through public methods, 
you ensure that the data can only be changed in a controlled and intended manner. This helps prevent unintended interference and errors

## Q2: Differnce between std:: string vs char str[]?

- The std::string class in C++ provides a robust, flexible, and convenient way to handle strings.
It abstracts away the complexities of memory management, 
supports dynamic resizing, and offers a rich set of functions for various string operations. 
Whether you're working on basic string manipulations or complex text processing, 
std::string is a powerful tool in the C++ Standard Library.

- Use char str[] when you need low-level control over memory, 
need to interact with C code, or are working in environments with very limited resources 
where performance and memory usage are critical.

