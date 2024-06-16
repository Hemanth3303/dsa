#include "print-array.h"

#include <stdio.h>

#define MAX_ARR_SIZE 100

int main() {
	int arr[MAX_ARR_SIZE];
	int n;
	printf("Enter size of array(MAX=%d): ", MAX_ARR_SIZE);
	scanf("%d", &n);
	printf("Enter the elements: \n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	printf("\n---Starting Selection Sort---\n");
	printf("Initial: ");
	print_array(arr, n);

	for (int i = 0; i < n - 1; i++) {
		int min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
		print_array(arr, n);
	}

	printf("Sorted array is: \n");
	print_array(arr, n);

	return 0;
}