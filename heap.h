#ifndef LINEAR_HEAP_H
#define LINEAR_HEAP_H

#include <stddef.h>
#include <stdint.h>

typedef struct {
	uint8_t *buffer;
	size_t capacity;
	size_t offset;
}LinearAllocator;

void la_init(LinearAllocator *la, void* buffer,size_t capacity);
void* la_alloc(LinearAllocator *la, size_t size, size_t alignment);
void la_reset();
size_t la_offset(const LinearAllocator *la);
size_t la_capacity(const LinearAllocator *la);

#endif
