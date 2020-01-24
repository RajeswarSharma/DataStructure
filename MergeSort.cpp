//mergeSort-RajeswarSharma
#include <iostream>
using namespace std;
void merge (int *, int,int, int);
void mergeSort (int *arr, int lb, int ub)
{
  int mid;
  if (lb < ub)
    {
      mid = (lb + ub) / 2;
      mergeSort (arr, lb, mid);
      mergeSort (arr, mid + 1, ub);
      merge (arr, lb,mid, ub);
    }
}

void
merge (int *arr, int lb,int mid, int ub)
{
int temp[100],k=0;
int i=lb;
int j=mid+1;
while(i<=mid&&j<=ub)
    {
        if(arr[i]>arr[j])
        temp[k++]=arr[j++];
        else 
        temp[k++]=arr[i++];
    }
    
while(i<=mid)
{
    temp[k++]=arr[i++];
}
while(j<=ub)
{
    temp[k++]=arr[j++];
}
i=lb;
k=0;
while(i<=ub)
    {
     arr[i++]=temp[k++];   
    }
}

int
main ()
{

int a[10] = { 7, 6, 5, 4, 3, 1, 0, 9, 8, 2 };

cout<<"Sorted"<<endl;

mergeSort (a, 0, 9);
  
for (int i = 0; i < 10; i++)
    
    cout << a[i] << " ";

return 0;
}