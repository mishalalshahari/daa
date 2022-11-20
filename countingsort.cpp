#include<bits/stdc++.h>
using namespace std;

void countingSort(int arr[],int n,int maximum){
    int output[n+1];
    int count[maximum+1];
    for(int i=0;i<maximum+1;i++){
        count[i]=0; //initialize count array with all zeroes
    }
    for(int i=0;i<n;i++){
        count[arr[i]]++; // store the count of each element
    }
    for(int i=1;i<=maximum;i++){
        count[i]=count[i]+count[i-1]; // find cumulative frequency
    }
    for(int i=n-1;i>=0;i--){
        output[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i]; // store the sorted element in main array
    }
}

int main(){
    int n;

    cin>>n;

    int arr[n];
    int maximum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        maximum=max(maximum,arr[i]);
    }
    countingSort(arr,n,maximum);

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}