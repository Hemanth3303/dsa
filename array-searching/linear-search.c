#include <stdio.h>

#define MAX_ARR_SIZE 100

int main() {
	int arr[MAX_ARR_SIZE];
	int n, key;
	printf("Enter size of array(MAX=%d): ", MAX_ARR_SIZE);
	scanf("%d", &n);
	printf("Enter the elements: \n");
	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}
	printf("Enter the key to search for: ");
	scanf("%d", &key);
	
	printf("\n---Starting Linear Search---\n");
	for(int i=0; i<n; i++) {
		if(arr[i]==key) {
			printf("Key %d found at index %d\n", key, i);
			return 0;
		}
	}
	printf("Key %d not found in array\n", key);
	return 0;
}