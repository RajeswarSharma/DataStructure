#include<iostream>
using namespace std;
int main()
{
    int arr[100]={6,9,3,1,0,4,5,8,7,2};
    int j,temp,Size=10;
    for(int i = 1;i<Size;i++)
        {
            temp=arr[i];

            for( j=i-1 ; j + 1 >= 0 && temp < arr[j] ; j--)
            {
                arr[j+1]=arr[j];
            }
        arr[j+1]=temp;
        }
for(int i=0;i<Size;i++)
    cout<<arr[i]<<" ";
}
