#include "heap.h"
#include<stddef.h>
#include<stdint.h>
#include<assert.h>

static inline uintptr_t allign_forward_uintptr(uintptr_t ptr, size_t alignmenet){
	if(alignment <= 1) return ptr;
	assert((alignment & (alignment-1)) == 0 && "alignment must be power of two");
	uintptr_t mask = (uintptr_t)alignment - 1;
	return (ptr + mask) & ~mask;
}

void la_init(LinearAllocator *la, void* buffer, size_t capacity){
	la->buffer = (uint8_t *) buffer;  //starting of the address pool
	la->capacity = capacity;
	la->offset = 0;
}

void la_reset(LinearAllocator *la){
    	la->offset = 0;//setting the bump pointer to 0
}

void *la_alloc(LinearAllocator *la, size_t size, size_t alignment){//returns a pointer for the process 
	if (size == 0) return NULL;
	if (alignment == 0) alignment = 1;//error handeling

	uintptr_t base = (uintptr_t)la->buffer; 
	uintptr_t cur_ptr = base + la->offset;
	uintptr_t aligned = align_forward_unintptr(cur_ptr,alignment);//returns the address of the aligned pointer
	size_t adjustment = (size_t)(aligned - cur_ptr);//padding 

	if(la->offset + adjustment + size > la->capacity){//current+padding+required > capacity
		return NULL;
	}

	la->offset += adjustment + size;//update offset
	return (void* ) aligned;

}

size_t la_capacity(LinearAllocator* la) { return la->capacity; }
size_t la_offset(LinearAllocator* la) { return la->offset; }
