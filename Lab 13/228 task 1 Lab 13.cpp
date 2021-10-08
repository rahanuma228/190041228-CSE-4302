#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] ={2,4,6,8,10,12,14,16,18,20};
    set<int>odd_no;
    vector<int>v;
    int i;
    for(i=1;i<20;i=i+2)
    {
        odd_no.insert(i);
    }
    merge(arr,arr+10,odd_no.begin(),odd_no.end(),back_inserter(v));
     for(i=0;i<v.size();i++)
    {
       cout<<v[i]<<" ";
    }
}
