#include <stdio.h>
#include <stdlib.h>
#include "IntVector.h"
#include <string.h>
#include <ctype.h>

IntVector *int_vector_new(size_t init_capacity) 
{
	IntVector *v = (IntVector *) malloc(sizeof(IntVector));
	if (v != NULL) {
		v->data = calloc(init_capacity, sizeof(size_t));
		if (v->data != NULL) {
			v->size = 0;
			v->capacity = init_capacity;
			return v;
		} else {
			return NULL;
		}
	} else 
		return NULL;
}

IntVector *int_vector_copy(const IntVector *v) 
{
	IntVector *v_copy = malloc(sizeof(IntVector));
	if (v_copy != NULL) {
		v_copy->data = malloc(v->capacity * sizeof(size_t));
		if (v_copy != NULL) {
			memcpy(v_copy->data, v->data, v->capacity * sizeof(size_t));
			v_copy->size = int_vector_get_size(v);
			v_copy->capacity = int_vector_get_capacity(v);
			if(v_copy->data == NULL) {
				int_vector_free(v_copy);
				v_copy = NULL;
			}
		}
	}
	return v_copy;
}

void int_vector_free(IntVector *v) 
{
	free(v->data);
	free(v);
}

size_t int_vector_get_capacity(const IntVector *v) 
{    										
	return v->capacity;
}

size_t int_vector_get_size(const IntVector *v) 
{
	return v->size;
}

int int_vector_push_back(IntVector *v, int item) 
{
	if (v->size == 0) {
		int_vector_reserve(v, 1);
		v->data[v->size] = item;
		v->size++;
		return 0;
	} else 
	if (v->size >= v->capacity) {
        int_vector_reserve(v, int_vector_get_capacity(v) * 2);            							
		v->data[v->size] = item;			
		v->size++;
		return 0;
	} else {
		v->data[v->size] = item;
		v->size++;
		return 0;
	}
}

void int_vector_pop_back(IntVector *v) 
{
	if ((v->size != 0)) {
		v->data[v->size - 1] = 0;
		v->size--;		                                                    
	} else {
		printf("\nERROR! No elements to delete\n");
	}
}

int int_vector_get_item(const IntVector *v, size_t index) 
{
		return v->data[index - 1];
}

void int_vector_set_item(IntVector *v, size_t index, int item) 
{
	v->data[index - 1] = item;
}

int int_vector_shrink_to_fit(IntVector *v) 
{
	if ((v->data = realloc(v->data, v->size * sizeof(int))) != NULL) {
		v->capacity = v->size;
		return 0;
	} if (v->size == 0) {
		v->capacity = v->size;
		return 0;
	} else {
		return -1;
	}
}

int int_vector_resize(IntVector *v, size_t new_size) 
{
	if (new_size >= (v->size)) {
		int increment = 0;
		while (increment < new_size) {
			int_vector_push_back(v, 0);
			++increment;			
		}
		v->size = new_size;
		return 0;
	} else if (new_size < v->size) { 
		int_vector_shrink_to_fit(v);
		return 0;
	} else if (new_size > (v->capacity)) {
		int n_def = int_vector_get_capacity(v) * 2;
		int_vector_reserve(v, n_def);
		int_vector_push_back(v, 0);
		v->size = new_size;
		return 0;
	} else 
		return -1;
}

int int_vector_reserve(IntVector *v, size_t new_capacity) 
{
	if (new_capacity <= int_vector_get_capacity(v)) {
		return -1;
	} else {
		if ((v->data = realloc(v->data, new_capacity * sizeof(int)))) {
			v->capacity = new_capacity; 
			return 0;
		} else {
			return -1;
		}
	}
}

void int_vector_interface(IntVector *v) 
{
	printf("\n");
	int top_facet = 0;
	printf("+");
	while (top_facet < int_vector_get_capacity(v)) {
		printf("---+");
		++top_facet;
	}
	printf("\n");
	int element_setter = 0;
	int element_counter = 1;
	while (element_setter < int_vector_get_size(v)) {
		printf("|%3d", int_vector_get_item(v, element_counter) );
		++element_setter;
		++element_counter;
	}
	int free_cap_setter = 0;
	int diff = int_vector_get_capacity(v) - int_vector_get_size(v);
	while (free_cap_setter <  diff) {
		printf("|   ");
		++free_cap_setter;
	}
	printf("|\n");
	int bottom_facet = 0;
	printf("+");
	while (bottom_facet < int_vector_get_capacity(v)) {
		printf("---+");
		++bottom_facet;
	}
	printf("\n\n");
	printf("Vector capacity: %zu\n", int_vector_get_capacity(v));
	printf("Vector size: %zu\n", int_vector_get_size(v));
}

int menu_sorting(int option)
{
	printf("Options: \n");
	printf("\t1 - Add element\n");
	printf("\t2 - Change element\n");
	printf("\t3 - Delete last element\n");
	printf("\t4 - Change capacity\n");
	printf("\t5 - Change size\n");
	printf("\t6 - Copy vector\n");
	printf("\t7 - Shrink vector to fit current size\n");
	printf("\t8 - Exit\n");
	switch(option) {
		case 1:
			return 1;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 3;
			break;
		case 4:
			return 4;
			break;
		case 5:
			return 5;
			break;
		case 6:
			return 6;
			break;
		case 7:
			return 7;
			break;
		case 8:
			return 8;
			break;
		default:
			return 0;
	}
}