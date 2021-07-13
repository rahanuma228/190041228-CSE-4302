#include<iostream>
using namespace std;

class Counter
{
private:
    int count;
    int n;

public:

    Counter():count(0),n(1)
    {
    }
    Counter(int c):count(c)
    {
    }
    Counter(int c,int _n):count(c),n(_n)
    {
    }
    void setIncrementStep(int step_val)
    {
        if(step_val>0)
        {
            n=step_val;
        }
        else
        {
            return;
        }
    }
    int getCount()
    {
        return count;
    }
    void increment()
    {
        count=count+n;
    }
    void resetCount()
    {
        count=0;
    }

    Counter operator + (Counter c2) const
    {
        return Counter(count+c2.count);
    }
     Counter operator + (int var) const
    {
        return Counter(count+var);
    }
    Counter operator +=(Counter c2)
    {
        count+=c2.count;
    }
    Counter operator ++( )
    {
        increment();
        return Counter(count, n);
    }
    Counter operator ++(int)
    {
        Counter temp;
        temp.count=count;
        temp.n=n;
        increment();
        return temp;

    }

    friend Counter operator + (int lop,Counter c2);
};

Counter operator + (int lop,Counter c2)
{
   return Counter(lop+c2.count);
}

int main()

{
    Counter c1,c2,c3;
    cout<<"Before increment count of c1 is : "<<c1.getCount()<<endl;
    c1.setIncrementStep(2);
    c1.increment();
    cout<<"\nAfter increment count of c1 is : "<<c1.getCount()<<endl;
    c1.resetCount();
    cout<<"\nAfter reset count of c1 is : "<<c1.getCount()<<endl;
    c2.setIncrementStep(4);
    c2.increment();
    cout<<"\nAfter increment value of c2 is  : "<<c2.getCount()<<endl;
    c3.setIncrementStep(6);
    c3.increment();
    cout<<"\nAfter increment value of c3 is  : "<<c3.getCount()<<endl;
    c1=c2+c3;
    cout<<"\nValue of c1=c2+c3 is : "<<c1.getCount()<<endl;
    c1=c2+5;
    cout<<"\nValue of c1=c2+var is : "<<c1.getCount()<<endl;
    c1=5+c2;
    cout<<"\nValue of c1=var+c2 is : "<<c1.getCount()<<endl;
    c1+=c2;
    cout<<"\nAfter c1+=c2 value of c1 is : "<<c1.getCount()<<endl;
    c1=c2++;
    cout<<"\nAfter c1=c2++ value of c1 is : "<<c1.getCount()<<endl;
    c1=++c2;
    cout<<"\nAfter c1=++c2 value of c1 is : "<<c1.getCount()<<endl;
}
