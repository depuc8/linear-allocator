#include "heap.h"
#include<stddef.h>
#include<stdint.h>
#include<assert.h>

void la_init(LinearAllocator *la, void* buffer, size_t capacity){
	la->buffer = (uint8_t *) buffer; //starting of the address pool
	la->capacity = capacity;
	la->offset = 0;
}

void la_reset(LinearAllocator *la){
    	la->offset = 0;//setting the bump pointer to 0
}

void *la_alloc(LinearAllocator *la, size_t size, size_t allignment){//returns a pointer for the process 
	if (size == 0) return NULL;
	if (allignment == 0) allignment = 1;//error handeling

	uintptr_t base = (uintptr_t)la->buffer; 
	uintptr_t cur_ptr = base + la->offset;
	uintptr_t alligned = allignment(cur_ptr,allignment);//returns the address of the alligned pointer
	size_t adjustment = (size_t)(alligned - cur_ptr);//padding 

	if(la->offset + adjustment + size > la->capacity){//current+padding+required > capacity
		return NULL;
	}

	la->offset += adjustment + size;//update offset
	return (void* ) alligned;

}

size_t la_capacity(LinearAllocator* la) { return la->capacity; }
size_t la_offset(LinearAllocator* la) { return la->offset; }
