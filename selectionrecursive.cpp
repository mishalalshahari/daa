#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void selectionSort(int arr[],int i,int j,int n,bool flag){
    if(i<=n-1){
        if(flag){
            j=i+1;
        }
        if(j<n){
            if(arr[i]>arr[j]) swap(&arr[i],&arr[j]);
            selectionSort(arr,i,j+1,n,0);
        }
        selectionSort(arr,i+1,j,n,1);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    selectionSort(arr,0,0,n,1); //recursive selection sort
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}