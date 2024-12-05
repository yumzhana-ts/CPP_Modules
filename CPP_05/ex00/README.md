## Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!

# Study:

std::exception Class
	Base class for standard exceptions in the C++ Standard Library.
	Provides a virtual what() method to retrieve a description of the exception.
	Can be inherited to define custom exception classes.
2. throw Statement
	Used to signal an error or exceptional situation.
	Can throw objects of any type, though std::exception or derived types are recommended.
	Cannot be used without enclosing code in a try-catch block.
3. try and catch Blocks
	try Block:
	Encapsulates code that might throw an exception.
	Must be followed by one or more catch blocks.
	catch Block:
	Handles exceptions thrown in the corresponding try block.
	Can specify the type of exception it handles (e.g., std::exception).
	Multiple catch blocks can handle different exception types.
4. Using Try-Catch Inside a Function
	try and catch blocks can be included inside a function to handle exceptions locally.

# Implementation : 

