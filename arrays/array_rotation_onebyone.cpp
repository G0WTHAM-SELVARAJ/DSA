//time complexity for this is O(n*d)
//auxillary space is O(1)
#include<iostream>

using namespace std;
//using the temp array to store the arrays first index element and rotationg all the element in the array left 
//and pushing the value in temp to the last index of array
void rotateByOne(int arr[],int size){
    int temp = arr[0];
    for(int i=0;i<size-1;i++){
        arr[i] = arr[i+1];
    }
    arr[size-1] = temp;
}
//rotating the array one by one using the d number of rotations
void rotateLeft(int arr[], int size, int rotations){
    for(int i=0;i<rotations;i++){
        rotateByOne(arr,size);
    }
}
//printing the array
void printArray(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }
}

int main(){
    int n,r;
    cout<<"enter the array size"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter the array elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"enter the number of rotations"<<endl;
    cin>>r;
    rotateLeft(arr,n,r);
    printArray(arr,n);
    return 0;
}