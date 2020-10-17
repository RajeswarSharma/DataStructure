/*
Q) Given an array of integers A and a sum B, find all unique combinations in A where the sum is equal to B. The same repeated number may be chosen from A unlimited number of times.

Note:
        1. All numbers will be positive integers.
        2. Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
        3. The combinations themselves must be sorted in ascending order.

Input:
First line of input contains number of testcases T. For each testcase, there will be three lines of input, first of which contains N, size of array. Next line contains N space seperated integers, and the last line contains B.

Output:
For each testcase, print the sets enclosing a backet "(" and ")". No space between two sets. If no set can be formed with the given set, then print "Empty" (without quotes).
*/
#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
bool flag=false;
void func(vector<int>&arr,int sum,int i,queue<int>buffer)
{
   if(arr.size()==0||i>=arr.size()||sum<0)
   {
       return;
   }
   if(sum==0)
   {
     cout<<"(";
     while(!buffer.empty())
       {
           flag=true;
           cout<<buffer.front();
           buffer.pop();
           if(buffer.empty()) break;
           cout<<" ";
       }
     cout<<")";
     return;
   }
 
   queue<int>buffer2=buffer;
   buffer.push(arr[i]);
   func(arr,sum-arr[i],i,buffer);
   func(arr,sum,i+1,buffer2); 
   return;
}

int main() {
	int T,N,sum,prev=0;
	queue<int>buffer;
	vector<int>arr;
	cin>>T;
	while(T)
	{
	    flag=false;
	    cin>>N;
	    arr.resize(N);
	    for(int i = 0;i<N;i++) cin>>arr[i];
	    cin>>sum;
	    sort(arr.begin(),arr.end());
	    prev=arr[0];
	    for(int i =1;i<arr.size();i++)
	    {
	        if(prev==arr[i]) {
	            arr.erase(arr.begin()+i);
	            i--;
	        }
	        else prev = arr[i];
	    }
	    func(arr,sum,0,buffer);
	    if(!flag) cout<<"Empty";
	    cout<<endl;
	    T--;
	}
	return 0;
}
