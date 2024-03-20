#include "print-array.h"

#include <stdio.h>

#define MAX_ARR_SIZE 100

int main() {
	int arr[MAX_ARR_SIZE];
	int n, temp;
	printf("Enter size of array(MAX=%d): ", MAX_ARR_SIZE);
	scanf("%d", &n);
	printf("Enter the elements: \n");
	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}

	printf("\n---Starting Bubble Sort---\n");
	printf("Initial: ");
	print_array(arr, n);

	for(int i=0; i<n-1; i++) {
		for(int j=0; j<n-i-1; j++) {
			if(arr[j]>arr[j+1]) {
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
			printf("[i=%d, j=%d]: ", i, j);
			print_array(arr, n);
		}
	}

	printf("Sorted array is: \n");
	print_array(arr, n);

	return 0;
}