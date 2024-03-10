#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

enum CHOICES {
	UNDEFINED = 0,
	INSERT,
	DELETE,
	SEARCH,
	TRAVERSE,
	UPDATE,
	CLEAR_ARRAY,
	EXIT
};

void insert(int arr[], int *curr_index, int value);
void delete(int arr[], int *curr_index, int value);
// use normal linear search
bool search(int arr[], int *curr_index, int key);
// use normal linear search
void traverse(int arr[], int *curr_index);
// return old value, or INT_MAX if index out of bounds
int update(int arr[], int *curr_index, int value, int index_to_update);
void clear_array(int arr[], int *curr_index);

#define MAX_ARR_SIZE 100

int main(void) {
	enum CHOICES ch = UNDEFINED;
	// [0-99]
	int array[MAX_ARR_SIZE] = { 0 };
	int curr_index = -1, value, update_ind;

	while(ch != EXIT) {
		printf("---Menu---\n");
		printf("MAX Array Size is 100\n");
		printf("1.Insert\n2.Delete\n3.Search\n4.Traverse\n5.Update\n6.Clear Array\n7.Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);

		switch(ch) {
			case INSERT:
				printf("Enter value to insert: ");
				scanf("%d", &value);
				insert(array, &curr_index, value);
				break;
			case DELETE:
				printf("Enter value to delete: ");
				scanf("%d", &value);
				delete(array, &curr_index, value);
				break;
			case SEARCH:
				printf("Enter value to search for: ");
				scanf("%d", &value);
				search(array, &curr_index, value);
				break;
			case TRAVERSE:
				traverse(array, &curr_index);
				break;
			case UPDATE:
				printf("Enter which index to update: ");
				scanf("%d", &update_ind);
				printf("Enter new value for that index position: ");
				scanf("%d", &value);
				update(array, &curr_index, value, update_ind);
				break;
			case CLEAR_ARRAY:
				clear_array(array, &curr_index);
			case EXIT:
				printf("Exiting.....\n");
				break;
			default:
				printf("Option not in menu, try again\n");
				break;
		}
	}

	return 0;
}

void insert(int arr[], int *curr_index, int value) {
	if(*curr_index>=MAX_ARR_SIZE) {
		printf("no more space in array\n");
		return;
	}
	// dereference the ptr, then increment the value
	(*curr_index)++;
	arr[*curr_index] = value;
}

void delete(int arr[], int *curr_index, int value) {
	for(int i = 0; i <= *curr_index; i++) {
		if(arr[i] == value) {
			// move following elements one over to the left
			int temp;
			// dereference the ptr, then decrement the value
			(*curr_index)--;
			for(int x = i; x <= *curr_index; x++) {
				arr[x] = temp;
				arr[x] = arr[x + 1];
				arr[x + 1] = temp;
			}
			return;
		}
	}
	printf("Element not in array\n");
}

bool search(int arr[], int *curr_index, int key) {
	for(int i = 0; i <= *curr_index; i++) {
		if(arr[i] == key) {
			printf("Found key %d at index %d\n", key, i);
			return true;
		}
	}
	printf("Key %d not found in array\n", key);
	return false;
}

void traverse(int arr[], int *curr_index) {
	printf("Array: ");
	for(int i = 0; i <= *curr_index; i++) {
		printf("%d, ", arr[i]);
	}
	printf("\n");
}

int update(int arr[], int *curr_index, int value, int index_to_update) {
	if(index_to_update > *curr_index) {
		printf("index value out of bounds of current array\n");
		return INT_MAX;
	}
	int old_val = arr[index_to_update];
	arr[index_to_update] = value;
	return old_val;
}

void clear_array(int arr[], int *curr_index) {
	memset(arr, 0, *curr_index);
	*curr_index = -1;	
}