#include<iostream>
//time complexity for array rotation using temp O(n)
//auxillary space O(d)

using namespace std;

int main(){
    int n,arr[100],temp[100],d;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    cout<<"Enter the array elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the number of rotations"<<endl;
    cin>>d;
    cout<<"\nStoring in temp array"<<endl;
    for(int i=0;i<d;i++){
        temp[i]=arr[i];
        cout<<temp[i]<<" ";
    }
    cout<<"\nShifting the rest of the array"<<endl;
    for(int i=0;i<n;i++){
        if(i==(n-d)){
            break;
        }
        arr[i]=arr[d+i];
        cout<<arr[i]<<" ";
    }
    cout<<"\nStoring elements from temp"<<endl;
    for(int i=0;i<d;i++){
        arr[n-d+i]=temp[i];
        cout<<arr[n-d+i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}