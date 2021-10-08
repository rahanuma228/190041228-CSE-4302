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
    Type& operator [](Type n)
    {
        if( n< 0 || n>=LIMIT )
        {
            cout << "\nIndex out of bounds";
            exit(1);
        }
        return arr[n];
    }
};

int main()
{
    safearay<int> sa1;
    safearay<char>s2;
    for(int j=0; j<LIMIT; j++)
        sa1[j] = j*10;
    for(int j=0; j<LIMIT; j++)
    {
        cout << "Element " << j << " is " << sa1[j] << endl;
    }
    for(int j=0; j<LIMIT; j++)
       s2[j] = j+'a';
    for(int j=0; j<LIMIT; j++)
    {
        cout << "Element " << j << " is " << s2[j] << endl;
    }
    return 0;
}
