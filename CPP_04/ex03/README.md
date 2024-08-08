## Subject: 

Imagine a role-playing game where characters can learn and use magical abilities, represented as "Materia". 
The MateriaSource class is responsible for storing and creating these magical abilities. 
Characters can equip these Materia to use them in battle.

# Study: 
Q1: What is concrete class?
In C++, a concrete class is a class that can be instantiated, 
meaning you can create objects of that class. 
It has implementations for all its member functions and does not contain any pure virtual functions. 
This is in contrast to an abstract class, which cannot be instantiated because it contains at least one pure virtual function 
(a function declared with the syntax = 0).

Q2: How to properly create clone function?
Q3: Handle type?



# Implementation : 

1. Implement a character

+-------------------+
|     ICharacter    |
|-------------------|
| + equip()         |
| + use()           |
+-------------------+
        ▲
        |
        |
+-------------------+
|     Character     |
|-------------------|
| + equip()         |
| + use()           |
+-------------------+

2. Implement a Materia

            +----------------+
            |    AMateria    |  <--- Abstract Base Class
            +----------------+
            |std::string type|
            +----------------+
                   / \
                    |
         +----------+-----------+
         |                      |
+----------------+    +----------------+
|     Ice        |    |      Cure      | <--- Derived Class
+----------------+    +----------------+
| -  clone()     |    | - clone()      |
+----------------+    +----------------+

3. Implement MateriaSource

+-------------------+
|  IMateriaSource   |
|-------------------|
|                   |
|                   |
+-------------------+
        ▲
        |
        |
+-------------------+
|   MateriaSource   |
|-------------------|
|                   |
|                   |
+-------------------+


            +----------------+
            |    AMateria    |  <--- Abstract Base Class
            +----------------+
            |?               |
            +----------------+
                   / \
                    |
         +----------+-----------+
         |                      |
+----------------+    +----------------+
|     Ice        |    |      Cure      | <--- Derived Class
+----------------+    +----------------+
| - Brain* brain |    | - Brain* brain |
+----------------+    +----------------+
               

         +----------------+
         |   ICharacter   | <--- Member object
         +----------------+ 
         |std::string idea|
         +----------------+
