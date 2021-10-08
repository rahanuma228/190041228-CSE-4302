#include <iostream>
using namespace std;
#include <process.h>
const int LIMIT = 10;

template<class Type>
class safearay
{
private:
    Type arr[LIMIT];
public:
    class Index_error
    {
    public:
        int index;
        Index_error(int x)
        {
            index=x;
        }
    };
    Type& operator [](Type n)
    {
        if( n< 0 || n>=LIMIT )
        {
            throw Index_error(n);
        }
        return arr[n];
    }
};

int main()
{
    try
    {
        safearay<int> sa1;
        safearay<char>s2;
        for(int j=0; j<LIMIT+10; j++)
            sa1[j] = j*10;
        for(int j=0; j<LIMIT+10; j++)
        {
            cout << "Element " << j << " is " << sa1[j] << endl;
        }
        for(int j=0; j<LIMIT; j++)
            s2[j] = j+'a';
        for(int j=0; j<LIMIT; j++)
        {
            cout << "Element " << j << " is " << s2[j] << endl;
        }
    }
    catch(safearay<int>::Index_error id)
    {
        cout<<"Index that is out of bounds: "<<id.index;
    }
    cout<<endl;

}
