## Subject: I don’t want to set the world on fire

# Study:

            +----------------+
            |    AAnimal      |  <--- Base Class
            +----------------+
            |std::string type|
            +----------------+
                   / \
                    |
         +----------+-----------+
         |                      |
+----------------+    +----------------+
|      Dog       |    |      Cat       | <--- Derived Class
+----------------+    +----------------+
| - Brain* brain |    | - Brain* brain |
+----------------+    +----------------+
                   / \
                    |
         +----------------+
         |     Brain      | <--- Member object
         +----------------+ 
         |std::string idea|
         +----------------+

# Implementation : 

Potential Issues Without using an Abstract Base Class

1. Inability to Access Derived Class-Specific Methods

Problem: If methods are only defined in derived classes and not in the base class, you can't access these methods through a base class pointer or reference.
Consequences: This limits the usability of the base class pointer for operations specific to derived classes, such as setting and getting ideas in Brain that are only relevant to Dog or Cat.
Example: Methods specific to Brain can’t be invoked through a base class AAnimal pointer.

2. Difficulty in Implementing Copy Constructors

Problem: If AAnimal is not an abstract base class and lacks virtual destructors, correctly implementing copy constructors in derived classes can be challenging. 
The base class might not manage resources in a way that supports deep copying or resource-specific copying.
Consequences: This can lead to shallow copies, resource leaks, or undefined behavior if derived classes depend on the proper management of complex resources like Brain.
Example: The copy constructor of Dog might need to allocate a new Brain object, but if AAnimal does not handle copying properly, it can lead to incorrect behavior.

