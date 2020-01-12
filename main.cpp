#include <iostream>

using namespace std;
int insertPos(int*,int,int,int);    //Switch:1
int insertEnd(int*,int,int);        //Switch:2
int deletePos(int*,int,int);        //Switch:3
int deletVal(int*,int,int);         //Switch:4
void loc(int*,int,int);             //Switch:5
void Trans(int*,int);               //Switch:6

int main()
{
   int arr[100]={1,2,3,4,5,6,7,8,9};
   int Size=9,option;
   int data=0,pos;

   do{
   cout<<"Choose options:\n(1)Insert at Position\n(2)Insert at End\n(3)Delete at Position\n(4)Delete Value\n(5)Location\n(6)Transverse\n(0)Exit"<<endl;
   cin>>option;
   switch(option)
   {
    case 0: break;
    case 1: cout<<"Enter the data to insert and the position\n";
            cin>>data;cin>>pos;
            Size=insertPos(arr,pos,Size,data);
            cout<<"inserted\n";
            Trans(arr,Size); break;
    case 2: cout<<"Enter the data to insert"<<endl;
            cin>>data;
            Size=insertEnd(arr,Size,data);
            cout<<"inserted\n";
            Trans(arr,Size); break;

    case 3: cout<<"Enter the position"<<endl;
            cin>>pos;
            Size=deletePos(arr,Size,pos);
            cout<<"Deleted\n";
            Trans(arr,Size); break;

    case 4: cout<<"Enter the data"<<endl;
            cin>>data;;
            Size=deletVal(arr,data,Size);
            cout<<"Deleted\n";
            Trans(arr,Size); break;

    case 5: cout<<"Enter the data"<<endl;
            cin>>data;
            loc(arr,Size,data);
            Trans(arr,Size); break;
    case 6: Trans(arr,Size); break;


    default: cout<<"Invalid Option";
   }
} while(option);
}
/**********************************************/
int insertPos(int*a,int pos,int Size,int data)
{
for(int k=Size;k>pos-1;k--)
    {
    a[k]=a[k-1];
    }
a[pos-1]=data;
return ++Size;
}
/**********************************************/
int insertEnd(int*a,int Size,int data)
{
    a[Size]=data;
    return ++Size;
}
/**********************************************/
int deletePos(int*a,int Size,int pos)
{
    for(int k=pos-1;k<Size-1;k++)
    {
        a[k]=a[k+1];
    }
return --Size;
}
/**********************************************/
int deletVal(int*a,int data,int Size)
{
    int pos=-1;
    for(int k=0;k<Size;k++)
    {
        if(a[k]==data)
        {
         pos=k;
         break;
        }
    }
if(pos>=0)
    {
    for(int k=pos;k<Size;k++)
        {
        a[k]=a[k+1];
        }
    return --Size;
    }
else
    {
        cout<<"Element does not Exist\n";
    return Size;
    }
}
/**********************************************/
void loc(int*a,int Size,int data)
{
    int pos=-1;
    for(int k=0;k<Size;k++)
    {
        if(a[k]==data)
        {
            pos=k;
            break;
        }
    }
if(pos>0)
    {
    cout<<"Element is at Location:"<<pos+1<<endl;
    }
else cout<<"Element does not Exist"<<endl;
}
/**********************************************/
void Trans(int *a,int Size)
{
    for(int k=0;k<Size;k++)
    {
        cout<<a[k]<<"  ";
    }
cout<<endl;
}
