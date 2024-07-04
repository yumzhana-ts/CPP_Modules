# Array of zombies on Heap 

## Memory Management:
- Allocation: New + Zombie[n] - allocates memory for an array of N Zombie objects.
- Deallocation: delete [] - ensures that the destructor of each Zombie object in the array is called, 
and then the memory is deallocated.

## Creating Array with Parameterized Constructor: 
In C++, the language syntax and semantics around dynamic memory allocation and object construction 
do not support directly passing constructor arguments to each element of an array when using new[]. 