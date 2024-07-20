# Subject: Exercise 03: Now it’s weird!

## Implementation:

Create DiamondTrap: 
2 classes derived from ScavTrap & FragTrap
- attributes: 
    - give exact variable name (use this?)
    - ClapTrap::name (parameter of the constructor)

Initialize parameters different classes
Q1: Is it is inside the constructor, how to specify it?

## Study

Step 1: Diamond inheritance problem
The diamond problem in multiple inheritance arises when a class inherits from two classes 
that both derive from a common base class, creating a diamond-shaped inheritance diagram. 
This can lead to ambiguity and potential issues in the derived class.


             A (ClapTrap)
            / \
(FragTrap) B   C (ScavTrap)
            \ /
             D (DiamondTrap)

Problems:
- It can be unclear which path (through B or C) should be followed to access the member.
- D would contain two separate instances of A: one through B and another through C. 
This redundancy can lead to increased memory usage and inconsistency.

Solution:
Run-time polymorphism with virtual inheritance
Virtual inheritance can be used to prevent the diamond problem in multiple inheritance scenarios 
by ensuring that only one instance of the base class is present when using a diamond-shaped 
inheritance pattern.


Step 2: Inherited attributes
By explicitly specifying inherited attribues of which base class is used.
Example: value = B::value


Step 3: 
checking git name

