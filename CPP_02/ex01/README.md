## Subject: Towards a more useful fixed-point number class

## Study: 

# Polymorphism or function overloading

- Function Overloading: Multiple functions can have the same name with different parameters
- Operator Overloading: The process of making an operator work for user-defined types

# Fixed-Point Representation 

Fixed-point numbers are a way to represent real numbers using integers. 
In fixed-point representation, a number is stored as an integer, 
but it is implicitly understood to be scaled by some factor, usually a power of two.


# Adding Fractional Part:

To represent a number with a fractional part in fixed-point notation, 
you shift the integer value to the left by the number of bits allocated for the fractional part.
Example: If you have 1234 and want to add 8 bits for the fractional part, 
you compute 1234 << 8, resulting in 1234 * 256 = 316416.

# Removing Fractional Part:

To convert a fixed-point number back to an integer and remove the fractional part, 
use the right shift (>>) operator.
Example: If 316416 represents a fixed-point number with 8 bits allocated for the fractional part, 
316416 >> 8 gives 1234, effectively discarding the fractional bits.

# Std::cout (<<)function overload:

Allows to define member output for specific instance


