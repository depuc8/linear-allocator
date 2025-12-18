## Linear-allocator/Arena allocator
A linear allocator is a derivative of maloc where we use malloc to assign us 
a block of memory and then use this block of memory linearly with the help of 
a bump pointer techinaclly a break not for the heap but for or linear block 
which expands on demand and no further expansion of the bump pointer takes place 
once we hit the break of out heap 

This repoitory walks you through on implementation of the linear allocator 
I have added proer comments in the respective files which should help on how this
can be implemented 
