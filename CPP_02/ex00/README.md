# Subject: My First Class in Orthodox Canonical Form

# Study

## Static variable: decl & init
You can declare static constants inside the class definition (static const int).
You must provide a separate definition outside the class to initialize these constants (const int ClassName::constantName = value;).

## Copy constructor

Copy constructor is used to create a new object as a 
copy of an existing object of the same class. 

The primary purpose of the copy constructor is to ensure that 
a new object is initialized with a copy of the data members of 
the existing object. This allows objects to be passed around and 
manipulated safely without affecting the original data.

## Copy assignment operator

The main purpose of the copy assignment operator is 
to manage the assignment of one existing object to another existing object.