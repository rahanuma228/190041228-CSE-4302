#include<bits/stdc++.h>
using namespace std;

namespace demo
{
    int x=100;
    double d=228.909;
}
float x=77.88;
int main()
{
    int x=90;
    cout<<"From namespace demo: "<<demo::x;
    cout<<endl;
    cout<<demo::d;
    cout<<endl;
    cout<<"From main_function: "<<x;
}
