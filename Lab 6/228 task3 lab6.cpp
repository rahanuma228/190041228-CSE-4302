#include<iostream>
#include<math.h>
using namespace std;

class Float
{
private:
    float data;

public:
   Float():data(0.0)
    {

    }
    Float(float d):data(d)
    {

    }
    float get_data()
    {
        return data;
    }
    Float operator + (Float f2) const
    {
     return Float(data+f2.data);
    }
    Float operator - (Float f2) const
    {
     return Float(data-f2.data);
    }
    Float operator * (Float f2) const
    {
     return Float(data*f2.data);
    }
    Float operator / (Float f2) const
    {
     return Float(data/f2.data);
    }
};

int main()
{
    Float F1(2.5);
    Float F2(3.1);
    cout<<"\nF1 = "<<F1.get_data();
    cout<<"\nF2 = "<<F2.get_data();
    cout<<"\nF1+F2 = "<<(F1+F2).get_data();
    cout<<"\nF1-F2 = "<<(F1-F2).get_data();
    cout<<"\nF1*F2 = "<<(F1*F2).get_data();
    cout<<"\nF1/F2 = "<<(F1/F2).get_data();

}
