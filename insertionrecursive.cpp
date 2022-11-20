#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[],int n){
    if(n<0){
        return;
    }
    insertionSort(arr,n-1);
    int temp=arr[n-1];
    int j=n-2;
    while(temp<arr[j] && j>=0){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=temp;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    insertionSort(arr,n); //recursive insertion sort
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}