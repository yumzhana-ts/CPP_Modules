# Zombie on Stack vs Heap

## Zombie creation on stack (static)
Stack allocation places the object directly in the current function's stack frame,
and its lifetime is tied to the scope in which it's defined.

## Zombie creation on heap (dynamic)
Heap allocation allocates memory from the heap, 
and the object's lifetime is managed manually (typically via delete).

## Constructor 
The constructor of a class is responsible for initializing the object's state whenever the object is created, 
regardless of whether it's allocated on the stack or the heap.

## Q1: Determine in what case it’s better to allocate the zombies on the stack or heap?
If zombies must be destroyed when you don’t need them anymore, then zombie has to be allocated on heap. 
If zombie has to be alive during current function's stack frame, then create it on stack.

