# Summary on Floating Point Computation Errors and Mitigation Techniques

## Floating Point Equality:
Directly comparing floating point numbers for equality can be unreliable due to limited precision.
Instead, use a method that checks if the numbers are close enough within a defined tolerance (EPSILON).

## Overflow of Numbers:
When integers overflow, the result can reset to zero, making it hard to detect overflow.
For floating point numbers, overflow results in ±∞, which is easier to detect.
Be cautious when converting between integers and floating point numbers to avoid precision loss.

## Loss of Significance:
Loss of significance occurs when subtracting two close numbers, potentially causing significant errors.
To avoid this, reorganize computations to minimize the subtraction of nearly equal numbers.

## Incremental vs. Stable Updates:
Incremental updates can accumulate rounding errors, especially over long loops.
For numerical stability, use updates based on stable quantities, even if they are slower.

## Using Integers for Rational Numbers:
Integers can offer greater precision compared to floating point numbers when dealing with rational numbers.

# Fixed point 

Fixed-point numbers are used internally in a class or library to perform efficient and 
precise arithmetic operations. Users interact with familiar number formats 
(integers or floating-point numbers), 
while the class handles the conversions to and from the fixed-point representation. 
This approach leverages the advantages of fixed-point arithmetic, 
such as increased efficiency and predictability, 
especially in resource-constrained environments or applications requiring precise numerical behavior.

# Advantages
- Efficiency: Integer arithmetic operations are typically faster than floating-point operations, 
making fixed-point arithmetic more efficient in resource-constrained environments.

- Predictability: Fixed-point representation provides predictable precision and range, which is crucial 
in applications requiring consistent numerical behavior, such as financial calculations.

- Resource Constraints: In systems with limited computational power or without hardware support for 
floating-point arithmetic, fixed-point numbers provide a viable alternative