#include "print-array.h"

#include <stdio.h>

#define MAX_ARR_SIZE 100

int main() {
	int arr[MAX_ARR_SIZE];
	int n, temp;
	printf("Enter size of array(MAX=%d): ", MAX_ARR_SIZE);
	scanf("%d", &n);
	printf("Enter the elements: \n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	printf("\n---Starting Insertion Sort---\n");
	printf("Initial: ");
	print_array(arr, n);

	for (int i = 1; i < n; i++) {
		int key = arr[i];
		int j = i;
		while (j > 0 && arr[j - 1] > key) {
			arr[j] = arr[j - 1];
			j = j - 1;
		}
		arr[j] = key;
		print_array(arr, n);
	}

	printf("Sorted array is: \n");
	print_array(arr, n);

	return 0;
}