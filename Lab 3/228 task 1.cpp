#include<iostream>
using namespace std;

class Counter
{
private:
    int n,count;

public:

    Counter():count(0)
    {
    }
    void setIncrementStep(int step_val)
    {
        n= step_val;
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
};
//main function
int main()
{
    Counter c1;
    int n;
    cin>>n;
    cout<<"Before increment count is : "<<c1.getCount()<<endl;
    c1.setIncrementStep(n);
    c1.increment();
    cout<<"After increment count is  : "<<c1.getCount()<<endl;
    c1.resetCount();
    cout<<"After reset count is      : "<<c1.getCount()<<endl;
}






