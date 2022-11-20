#include <iostream>
using namespace std;

int searchElement(int arr[], int size, int x) {
	
	size--;
	if (size < 0) {
		return -1;
	}
	if (arr[size] == x) {
		return size;
	}
	return searchElement(arr, size, x);
}


int main() {
	int arr[] = {17, 15, 11, 8, 13, 19};
	int size = sizeof(arr) / sizeof(arr[0]);
	int x = 11;
	int idx = searchElement(arr, size, x);
	if (idx != -1)
		cout << "Element " << x << " is present at index " <<idx;
	else
		cout << "Element " << x << " is not present in the array";
	return 0;
}
