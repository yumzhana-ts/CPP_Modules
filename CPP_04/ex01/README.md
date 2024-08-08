## Subject: I don’t want to set the world on fire

# Study:

            +----------------+
            |    Animal      |  <--- Base Class
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
Example: Methods specific to Brain can’t be invoked through a base class Animal pointer.

