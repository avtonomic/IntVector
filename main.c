#include <stdio.h>
#include "IntVector.h"
#include <stdlib.h>

int main() 
{   
    int option;
    int capacity, item;
    int change_number, new_value;
    int new_capacity, new_size;
    int quit = 1;
	printf("\n");
	printf("Enter vector capacity: ");
	scanf("%d", &capacity);
	IntVector *v = int_vector_new(capacity);
	int_vector_interface(v);
	printf("\n");
	menu_sorting(option);
	scanf("%d", &option);
    while(quit != 0) {
        switch (option) {
            case 1:           
                // Add element
		        printf("Enter element: ");
                scanf("%d", &item);
				int_vector_push_back(v, item);
				int_vector_interface(v);
				menu_sorting(option);
				scanf("%d", &option);
                break;
            case 2:
                // Change element
				printf("Enter change number: ");
                scanf("%d", &change_number);
				printf("Enter new value: ");
                scanf("%d", &new_value);
                int_vector_set_item(v, change_number, new_value);
                int_vector_interface(v);
           		menu_sorting(option);
				scanf("%d", &option);
                break;
            case 3:
				// Delete last element
        		int_vector_pop_back(v);
        		int_vector_interface(v);
        		menu_sorting(option);
				scanf("%d", &option);
        		break;
            case 4:
            	// Change capacity
				printf("Enter new capacity: ");
            	scanf("%d", &new_capacity);
            	int_vector_reserve(v, new_capacity);
            	int_vector_interface(v);
                menu_sorting(option);
                scanf("%d", &option);
                break;
            case 5:
        		// Change size
				printf("Enter new size: ");
        		scanf("%d", &new_size);
        		int_vector_resize(v, new_size);
        		int_vector_interface(v);
                menu_sorting(option);
                scanf("%d", &option);
        		break;
            case 6:
				// Copy vector
                printf("Current vector: \n");
                int_vector_interface(v);
                printf("\n");
                printf("Copied vector: \n");
				IntVector *vector_copy = int_vector_copy(v);
                int_vector_interface(vector_copy);
                menu_sorting(option);
                scanf("%d", &option);
                break;
            case 7:
				// Shrink vector to fit current size
                int_vector_shrink_to_fit(v);
                int_vector_interface(v);
                menu_sorting(option);
                scanf("%d", &option);
                break;
            case 8:
				// Exit
                quit = 0;
                break;
            default:
                printf("Wrong option\n\n");
                menu_sorting(option);
                scanf("%d", &option);
                break;
        int_vector_free(vector_copy);
        }  
    }
	int_vector_free(v);
	return 0;
}
