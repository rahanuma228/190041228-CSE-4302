#include<iostream>
#include<math.h>
using namespace std;


class Rectangle
{
private:
    float length,width;

public:
    Rectangle():length(1),width(1)
    {

    }
    Rectangle(float l,float w):length(l),width(w)
    {

    }

    void get_data()
    {
        cout<<"Enter length  ";
        cin>>length;
        if(set_data(length)!=true)
        {
            length=1;
        }
        cout<<"Enter width  ";
        cin>>width;
        if(set_data(width)!=true)
        {
            width=1;
        }

    }
    bool set_data(float n)
    {
        if(n>=1.0 && n<20.0)
        {
            return true;
        }
    }

    float area()
    {

        return length*width;
    }
    float parameter()
    {
        return 2*(length+width);
    }
    float diagonal()
    {
     return sqrt((length*length)+(width*width));

    }
    float angle()
    {
       return acos(length/sqrt((length*length)+(width*width)));
    }

};


int main()
{
    Rectangle r1;
    r1.get_data();
    cout<<"\nArea of rectangle is "<<r1.area()<<endl;
    cout<<"\nParameter of rectangle is "<<r1.parameter()<<endl;
    cout<<"\nLength of diagonal of rectangle is "<<r1.diagonal()<<endl;
    cout<<"\nangle between diagonal and a length of the rectangle "<<r1.angle()<<endl;
}
