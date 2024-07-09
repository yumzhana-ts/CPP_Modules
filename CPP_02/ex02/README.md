# Subject: Now we’re talking

# Study: 

## Arithmetic operator overload

Make operation on raw bits and make conversion to float value that is passed to function.
For multiplication and division scale fractional bits, these methods ensure accurate arithmetic operations for fixed-point numbers.

- Scaling for Multiplication:

When multiplying two fixed-point numbers, the result can have twice the number of 
fractional bits, which can distort the fractional part.
To handle this, the result needs to be scaled back by shifting it right by the 
number of fractional bits.

- Scaling for Division:

When dividing fixed-point numbers, the numerator needs to be increased first to 
preserve the precision of the fractional part.
This is done by scaling the numerator left by the number of fractional bits before 
performing the division.

## Static member function 

A static member function is a function that belongs to the class 
rather than to instances (objects) of the class.

- Access: Static member functions can be called directly 
using the class name, without needing an instance of the class.

- Access to Members: Static member functions cannot access non-static
members (variables or functions) directly using this, 
because they do not operate on a specific object instance.

- Utility: They are useful for providing class-wide functionality, 
utility functions, or operations that do not require access to instance-specific data.