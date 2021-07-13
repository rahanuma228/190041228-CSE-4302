#include<iostream>
#include<math.h>
using namespace std;

class Coordinate
{
private:
    float abcissa;
    float ordinate;

public:
    Coordinate():abcissa(0.0),ordinate(0.0)
    {

    }
    Coordinate(float x,float y):abcissa(x),ordinate(y)
    {

    }
    float getDistance(Coordinate c2)
    {
        float a=fabs(abcissa - c2.abcissa);
        float b=fabs(ordinate - c2.ordinate);
        return sqrt((a*a)+(b*b));
    }
    float getDistance()
    {
        float c=fabs(abcissa - 0);
        float d=fabs(ordinate - 0);
        return sqrt((c*c)+(d*d));
    }
    void move_x(float val)
    {
      abcissa=abcissa+val;
    }
    void move_y(float val)
    {
      ordinate=ordinate+val;
    }
    void move(float val)
    {
        move_x(val);
        move_y(val);
    }
    bool operator > (Coordinate c2)
    {
        return (getDistance()>c2.getDistance());
    }
    bool operator < (Coordinate c2)
    {
        return (getDistance()<c2.getDistance());
    }
    bool operator >= (Coordinate c2)
    {
        return (getDistance()>=c2.getDistance());
    }
    bool operator <= (Coordinate c2)
    {
        return (getDistance()<=c2.getDistance());
    }
    bool operator == (Coordinate c2)
    {
        return (getDistance()==c2.getDistance());
    }
    bool operator != (Coordinate c2)
    {
        return (getDistance()!=c2.getDistance());
    }

    Coordinate operator ++()
    {
        Coordinate temp;
        ++abcissa;
        ++ordinate;
        temp.abcissa=abcissa;
        temp.ordinate=ordinate;
        return temp;
    }
    Coordinate operator ++(int)
    {
        Coordinate temp;
        abcissa++;
        ordinate++;
        temp.abcissa=abcissa;
        temp.ordinate=ordinate;
        return temp;
    }
    Coordinate operator --()
    {
        Coordinate temp;
        --abcissa;
        --ordinate;
        temp.abcissa=abcissa;
        temp.ordinate=ordinate;
        return temp;
    }
    Coordinate operator --(int)
    {
        Coordinate temp;
        abcissa--;
        ordinate--;
        temp.abcissa=abcissa;
        temp.ordinate=ordinate;
        return temp;
    }
    display()
    {
        cout<<abcissa<<","<<ordinate<<endl;

    }
    ~Coordinate()
    {

    }
};

int main()
{
    Coordinate c1(3.0,9.0);
    cout<<"\ncoordinates of c1 is :";
    c1.display();
    Coordinate c2(4.5,9.2);
    cout<<"\ncoordinates of c2 is :";
    c2.display();
    Coordinate c3(2.8,10.2);
    cout<<"\ncoordinates of c3 is :";
    c3.display();
    cout<<"\nDistance between c1 and c2 is :"<<c1.getDistance(c2)<<endl;
    cout<<"\nDistance between c2 and c3 is :"<<c2.getDistance(c3)<<endl;
    cout<<"\nDistance between c1 from origin is :"<<c1.getDistance()<<endl;
    cout<<"\nDistance between c2 from origin is :"<<c2.getDistance()<<endl;
    cout<<"\nDistance between c3 from origin is :"<<c3.getDistance()<<endl;
    cout<<"\nAfter moving coordinates of c1 is :";
    c1.move(28);
    c1.display();
    if(c1>c2)
    {
        cout<<"\nDistance of c1 is greater than c2.";
    }
    else
    {
        cout<<"\nDistance of c2 is greater than c1.";
    }
    if(c1<c2)
    {
        cout<<"\nDistance of c1 is less than c2.";
    }
    else
    {
        cout<<"\nDistance of c2 is less than c1.";
    }
    if(c1>=c2)
    {
        cout<<"\nDistance of c1 is greater equal than c2.";
    }
    else
    {
        cout<<"\nDistance of c2 is greater equal than c1.";
    }
    if(c1<=c2)
    {
        cout<<"\nDistance of c1 is less equal than c2.";
    }
    else
    {
        cout<<"\nDistance of c2 is less equal than c1.";
    }
    if(c1==c2)
    {
        cout<<"\nDistance of c1 is equal to c2.";
    }
    else
    {
        cout<<"\nDistance of c1 is not equal to c1.";
    }
    if(c1!=c2)
    {
        cout<<"\nDistance of c1 is not equal to c2.";
    }
    else
    {
        cout<<"\nDistance of c2 is equal to c1.";
    }

}
