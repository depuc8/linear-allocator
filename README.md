## Linear-allocator/Arena allocator
A linear allocator (also known as an arena allocator) is a memory allocation strategy that uses a single call to malloc (or a similar function) to reserve a large contiguous block of memory. Memory is then allocated linearly from this block using a bump pointer.

The bump pointer advances as allocations are made, similar to a program break, but it operates entirely within the preallocated memory block rather than the heap itself. Once the allocator reaches the end of the memory pool, no further allocations can be made unless the arena is reset or expanded.

This repository walks through an implementation of a linear allocator. Proper comments have been added to the relevant files to help explain how the allocator works and how it can be implemented

If you are interested you can read more about it on my blog. 