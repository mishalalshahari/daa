#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int arr[],int n,int i){
    int parent = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left<n && arr[left]>arr[parent]){
        parent=left;
    }
    if(right<n && arr[right]>arr[parent]){
        parent=right;
    }
    if(parent!=i){
        swap(&arr[i],&arr[parent]);
        heapify(arr,n,parent);
    }
}

void heapSort(int arr[],int n){
    for(int i=n/2;i>=0;i--){
        heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(&arr[i],&arr[0]);
        heapify(arr,i,0);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    heapSort(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}