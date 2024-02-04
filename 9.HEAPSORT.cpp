#include<iostream>
using namespace std;
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void heapify(int arr[],int n,int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest])
    {
        largest=left;
    }
    if(right<n && arr[right]>arr[largest])
    {
        largest=right;
    }
    if(largest!=i)
    {
        swap(&arr[i],&arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapsort(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--)
    {
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}
void printarray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\n";
    }
}


int main()
{
    int arr[]={2,4,1,3,10,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    clock_t start=clock();
    heapsort(arr,n);
    clock_t end=clock();
    printarray(arr,n);
    double execution_time=double(end-start)/double(CLOCKS_PER_SEC);
    cout<<"the time req to execute te function is "<<fixed<<execution_time<<"in seconds";
    return 0;
    
    
}
