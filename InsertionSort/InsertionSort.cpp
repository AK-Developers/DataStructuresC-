#include<iostream>
using namespace std;
void insertionSort(int arr[], int size) {
	for (int i = 1; i < size; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j>=0 && arr[j]>key){
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
int main() {
	int myArray[] = { 64,25,36,48,26,95,1002,36548,1526,459 };
	int size = sizeof(myArray) / sizeof(myArray[0]);
	insertionSort(myArray, size);
	cout << "Sorted Array:";
	for (int i = 0; i < size; i++) {
		cout << myArray[i] << " ";
	}
	return 0;
}