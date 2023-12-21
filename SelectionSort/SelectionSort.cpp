#include<iostream>
using namespace std;
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        //Swap
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}
int main() {
    int myArray[] = { 10,50,60,300,5,1,90,70,80 };
    int size = sizeof(myArray) / sizeof(myArray[0]);
    selectionSort(myArray, size);
    cout << "Sorted Array:\n";
    for (int i = 0; i < size; i++) {
        cout << myArray[i] << " ";
    }
    return 0;
}