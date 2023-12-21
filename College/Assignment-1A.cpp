//WAP to calculate the average of 1-D array
#include<iostream>
using namespace std;
int main(){
    int size, sum=0;
    cout<<"Enter the Size of the Array : ";
    cin>>size;

    //Array Declaration
    int array1[size];

    //Entering the Elements of the Array
    cout<<endl;
    for(int i = 0; i<size; i++){
        cout<<"Enter the Element : ";
        cin>>array1[i];
    }

    //Printing the Array
    cout<<endl<<"Array :"<<endl;
    for(int i = 0; i<size; i++){
        cout<<array1[i]<<" ";
    }

    //Calculating the Average
    cout<<endl;
    for(int i = 0; i<size; i++){
        sum += array1[i];
    }

    cout<<endl<<"Average : "<<sum/size;
    return 0;
}