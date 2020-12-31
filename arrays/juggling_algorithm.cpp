//juggling algorithm for array rotation

//using gcd to separate into sets and rotating it using temp with each set values


#include<iostream>

using namespace std;

int gcd(int a, int b){
    return b?gcd(b,a%b):a;
}
void juggler(int arr[],int size, int rotations){
    //if d >=n check condition
    int gcd_val = (size>rotations)? gcd(rotations,size):gcd(size,rotations);
    cout<<gcd_val<<endl<<size<<endl<<rotations<<endl;
    for(int i=0;i<gcd_val;i++){
        int temp = arr[i];
        int j = i;
        while(0){
            int set_position = j+rotations;
            if(set_position>size)  set_position = set_position-size;
            if(set_position ==i){
                break;
            } 
            arr[j] = arr[set_position];
            j = set_position;
            cout<<set_position<<endl<<i<<endl;
        }
        arr[j] = temp;
    }
}

int main(){
    int n,r;
    cout<<"Enter the array size"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the no of rotations"<<endl;
    cin>>r;
    juggler(arr,n,r);    
    return 0;
}