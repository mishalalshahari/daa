#include<bits/stdc++.h>
using namespace std;

void merge(int[],int,int,int);

void mergeSort(int arr[],int l,int h){
    
    if(l<h){

        int m=(l+h)/2;

        mergeSort(arr,l,m);
        mergeSort(arr,m+1,h);

        merge(arr,l,m,h);
    }
}

void merge(int arr[],int l,int mid,int h){
    
    int n1=mid-l+1;
    int n2=h-mid;
    
    int L[n1],R[n2];
    int k=l;

    for(int i=0;i<n1;i++){
        L[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++){
        R[j]=arr[mid+1+j];
    }

    int i=0;
    int j=0;

    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}

int main(){
    int n;

    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    mergeSort(arr,0,n-1);

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    
    return 0;
}