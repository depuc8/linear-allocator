#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include "heap.h" // public API 
/* LinearAllocator 
 * la_init
 * la_reset
 * la_alloc
 * la_offset
 * la_capacity
 */

int main(void){

	enum{POOL_SIZE = 1024}; // using enum so we can restrict to only this block 
	uint8_t *pool = malloc(1024);  //malloc returns a void pointer and we are assigning it to pool 
	
	if(!pool){
		fprintf(stderr,"failed to allocate pool");
		return 1;
	}
	
	//initilizing bump pointer
	LinearAllocator la; 
	la_init(&la,pool,POOL_SIZE);

	printf("pool=%p capacity=%zu\n", (void*) pool, la_capacity(&la));

	void* p1 = la_alloc(&la,100,8);
	printf("pool=%p capacity=%zu\n", p1, la_capacity(&la));

	void* p2 = la_alloc(&la,200,16);
	printf("pool=%p capacity=%zu\n", p2, la_capacity(&la));

	void* p3 = la_alloc(&la,500,32);
	printf("pool=%p capacity=%zu\n", p3, la_capacity(&la));

	if (p1) memset(p1,0xAA,100); //writing all the values to 0xAA 
	if (p2) memset(p2,0xBB,200);//writing all the values to 0xBB

	//reseting the bump pointer to base
	la_reset(&la);
	printf("after reset offset=%zu\n", la_offset(&la));

	free(pool);
	return 0;

}

