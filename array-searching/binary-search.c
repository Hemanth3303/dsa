#include <stdio.h>

#define MAX_ARR_SIZE 100

int main() {
	int arr[MAX_ARR_SIZE];
	int n, key;
	printf("Enter size of array(MAX=%d): ", MAX_ARR_SIZE);
	scanf("%d", &n);
	printf("Enter the elements in ascending order: \n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	printf("Enter the key to search for: ");
	scanf("%d", &key);

	printf("\n---Starting Binary Search---\n");
	int high = n - 1;
	int low = 0;
	int mid;

	while (low <= high) {
		mid = (low + high) / 2;
		if (arr[mid] == key) {
			printf("Key %d found at index %d\n", key, mid);
			return 0;
		}
		else if (arr[mid] < key) {
			low = mid + 1;
		}
		else { //arr[mid]>=key
			high = mid - 1;
		}
	}

	printf("Key %d not found in array\n", key);
	return 0;
}