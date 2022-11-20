#include<bits/stdc++.h>
using namespace std;

void countingSort(int arr[],int n,int exp){
    int output[n];
    int i, count[10]={0};
    for(i=0;i<n;i++){
        count[(arr[i]/exp)%10]++;
    }
    for(i=1;i<10;i++){
        count[i]=count[i]+count[i-1];
    }
    for(i=n-1;i>=0;i--){
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(i=0;i<n;i++){
        arr[i]=output[i];
    }
}

void radixSort(int arr[],int n,int maximum){
    for(int exp=1;maximum/exp>0;exp*=10){
        countingSort(arr,n,exp);
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
    radixSort(arr,n,maximum);

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}