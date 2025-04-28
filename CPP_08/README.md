- Sequence Containers
Store elements in a specific order.
std::vector – dynamic array
std::deque – double-ended queue
std::list – doubly linked list
std::forward_list – singly linked list
std::array – fixed-size array (C++11)
std::string – specialized container for strings

- Associative Containers
Use trees to store elements in sorted order.

std::set – unique elements in sorted order
std::multiset – allows duplicate elements
std::map – key-value dictionary
std::multimap – key-value dictionary allowing duplicate keys

- Unordered Associative Containers
Use hash tables for fast lookup.

std::unordered_set
std::unordered_multiset
std::unordered_map
std::unordered_multimap

- Container Adapters
Work on top of other containers, restricting access to elements.

std::stack – Last In, First Out (LIFO)
std::queue – First In, First Out (FIFO)
std::priority_queue – priority-based queue