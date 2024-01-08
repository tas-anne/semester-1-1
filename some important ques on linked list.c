
????why a linked list is called dynamic data structure?
A linked list is a dynamic data structure. The number of nodes in
a list is not fixed and can grow and shrink on demand. Any
application which has to deal with an unknown number of objects will need to use a linked list.

?????why over array
the list elements can be easily inserted or removed without reallocation or reorganization
of the entire structure because the data items need not be
 stored contiguously in memory or on disk, while restructuring an array at run-time is a much more
 convenient than array indexing.
 faster in some cases;

 ?????types
 circular;
 doubly linked list ;
 single linkede list;

?????DMA
Dynamic memory allocation refers to managing system memory at runtime.
which the size of a data structure (like Array) is changed during runtime.


???how can it help in complex program?
Allocating memory dynamically helps us to store data without initially
 knowing the size of the data in the time we wrote the program.

???difference between malloc and calloc?
malloc:
    leaves the memory uninitialized.
    a single large block e memory allocation
    retuns a pointer of type void.
calloc():
    contiguous allocation
    {specified number of blocks}
    initializes at the bits to zero

??????? Advantages of linked list???
Linked List is Dynamic data Structure .
Linked List can grow and shrink during run time.
Insertion and Deletion Operations are Easier.
Efficient Memory Utilization ,i.e no need to pre-allocate memory.
Faster Access time,can be expanded in constant time without memory overhead.

