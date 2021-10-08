#include <iostream>
using namespace std;
#include <process.h>
const int LIMIT = 10;

template<typename Type>
Type amax(Type* arr,int SIZE)
{
    Type m= arr[0];
    int i;
    for(i=0; i<SIZE; i++)
    {
        if(arr[i]>m)
        {
            m=arr[i];
        }
    }
    return m;
}

int main()
{
    float fl[LIMIT];
    for(int j=0; j<LIMIT; j++)
    {
        fl[j] = j*28.2;
    }
    cout<<amax(fl,10);
    cout<<endl;
    int ia[LIMIT];
    for(int j=0; j<LIMIT; j++)
    {
        ia[j] = j*10;
    }
    cout<<amax(ia,10);
}

