/* Written by : Rajeswar Sharma 
   UID : 10BCS6051*/
#include<iostream>
using namespace std;
int main()
{
int Arr[50]={0,8,9,7,5,6,4,3,9,2,1};
    int temp,Size=11;
cout<<"Sorting"<<endl;  
 //insertionSort complexity: n*n
for(int i=1;i<Size;i++)
    { temp=Arr[i];
        for(int j=i-1;j+1>=0;j--)
        {
        if(temp>=Arr[j]||j+1==0)
            {
               Arr[j+1]=temp;
               break;
            }
       else
            {
                Arr[j+1]=Arr[j]; 
            }   
         }
    }
//Display
for(int i=0;i<Size;i++)  
 cout<<Arr[i]<<" ";
return 0; 
}
