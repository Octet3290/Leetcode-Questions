#include<iostream>
using namespace std;

void InputArray(int[] , int); //Declartion of Function
void PrintArray(int[] , int); //Declartion of Function
void ReveseArray(int[] , int); //Declartion of Function

int main(){
    cout<<"Please Enter the Size of array : ";
    int n;
    cin>>n; // taking user input for the size of array
    int arr[n]; // decalring array
    InputArray(arr , n); // calling function to input in the array
    cout<<"Array Before Reverse : "<<endl;
    PrintArray(arr , n); // calling print array fucntion to prnt array before revesring
    cout<<endl;
    ReveseArray(arr , n); // calling reverse aarry function to reverse the array
    cout<<"Array Array Reverse : "<<endl;
    PrintArray(arr , n); // calling print array fucntion to prnt array after revesring
    return 0;
}

void InputArray(int arr[] , int n){
    for (int i = 0; i < n; i++) // making a for loop to start index of array from it's 0 to last index of element
    {
        cout<<"Please Enter the value of "<<i<<" Index : ";
        cin>>arr[i]; // taking input in that array of ith index
    }
    
}
void PrintArray(int arr[] , int n){
    for (int i = 0; i < n; i++) // making a for loop to start index of array from it's 0 to last index of element
    {
        cout<<arr[i]<<" "; // printing the array value at ith index
    }
    
}
void ReveseArray(int arr[] , int n){ 
    int i = 0; // i = 0 will denote the starting of array
    int j = n-1; // last element of array
    int temp = 0;
    while (i < j)
    {
        temp = arr[i]; // storing the value of arr[i th] value in temp
        arr[i] = arr[j];  //  placing value of j th element in i th  
        arr[j] = temp; // placing the temp in j th value 
        i++; // moving ith index foraward
        j--; // decrementing the jth index
    }
    
}
