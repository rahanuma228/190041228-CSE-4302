#include<iostream>
using namespace std;

class RationalNumber
{
private:
    int num;
    int denom;
    int z=0;
public:
    void assign(int numerator,int denominator)
    {

        if(denominator==0)
        {
            cout<<"Error in denominator value!!!"<<endl;
            z=1;
        }
        else
        {
            num=numerator;
            denom=denominator;
        }

    }
    double convert()
    {
        if(z==1)
        {
            cout<<"Error"<<endl;
        }
        else
            return (double)num /(double)denom;
    }
    void invert()
    {
        if(num==0)
        {
            cout<<"Mathematical error!!!"<<endl;
            z=1;
        }
        else
            swap(num,denom);
    }
    void print()
    {
        if(z==1)
        {
            cout<<"Invalid number"<<endl;
        }
        else
            cout<<"\nThe Rational Number is    : "<<num<<"/"<<denom<<endl;
    }

};

int main()
{
    RationalNumber r1;
    cout<<"Enter the value of numerator and denominator :"<<endl;
    int x,y;
    cin>>x>>y;
    r1.assign(x,y);
    cout<<"\nBefore inverting we get"<<endl;
    r1.print();
    cout<<"\nThe decimal equivalent is : "<<r1.convert()<<endl;
    r1.invert();
    cout<<"\n\nAfter inverting we get"<<endl;
    r1.print();
    cout<<"\nThe decimal equivalent is : "<<r1.convert()<<endl;

}

