#include <iostream>
#include <string>
using namespace std;

enum class Material {Wood,Board,Steel,foam};
class Furniture
{
protected:
    double price;
    double discount;
    Material madeof;
public:

    Furniture(double p,double d,Material m):price(0),discount(0),madeof(Material::Wood)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
    }
    void setPrice(double val)
    {
        if(val>0)
            price=val;
    }
    void setDiscount(double val)
    {
        if(val<=price)
            discount=val;
    }
    void setMadeof(Material val)
    {
        madeof=val;

    }
    string getMadeof()
    {
        if(madeof==Material::Wood)
            return string("Wood");
        else if(madeof==Material::Board)
            return string("Board");
        else if(madeof==Material::Steel)
            return string("Steel");
        else
            return string("");
    }
    virtual void productDetails()
    {
        cout<<"-----------------------------------";
        cout<<"\nRegular Price: "<<price;
        cout<<"\nDiscounted Price: "<<price-discount;
        cout<<"\nMaterial: "<<getMadeof();
    }

};



enum class BedSize {Single,SemiDouble,Double};

class Bed:public Furniture
{
protected:
    BedSize bsize;

public:

    Bed(double p,double d,Material m,BedSize b):Furniture(p,d,m)
    {
        setbedsize(b);
    }
    void setbedsize(BedSize val)
    {
        bsize=val;
    }
    string getbedsize()
    {
        if(bsize==BedSize::Single)
            return string("Single");
        else if(bsize==BedSize::SemiDouble)
            return string("SemiDouble");
        else if(bsize==BedSize::Double)
            return string("Double");
        else
            return string("");
    }
    void productDetails()
    {
        Furniture::productDetails();
        cout<<"\nBed Size: "<<getbedsize();
        cout<<"\n###################################################\n";
    }
};
enum class SeatNumber {One, Two, Three, Four, Five};

class Sofa:public Furniture
{
protected:
    double _price;
    double _discount;
    Material _madeof;
    SeatNumber seat;
public:
    Sofa(double p,double d,Material m,SeatNumber s):Furniture(p,d,m)
    {
        _price=p;
        _discount=d;
        _madeof=m;
        setseatno(s);
    }
    void setseatno(SeatNumber val)
    {
        seat=val;
    }
    string getseano()
    {
        if(seat==SeatNumber::One)
            return string("One");
        else if(seat==SeatNumber::Two)
            return string("Two");
        else if(seat==SeatNumber::Three)
            return string("Three");
        else if(seat==SeatNumber::Four)
            return string("Four");
        else if(seat==SeatNumber::Five)
            return string("Five");
        else
            return string("");
    }
    void productDetails()
    {
        Furniture::productDetails();
        cout<<"\nSeat Number: "<<getseano();
        cout<<"\n###################################################\n";
    }
};
enum class ChairCount {Two,Four,Six};
class DiningTable:public Furniture
{
protected:
    ChairCount ccount;

public:

    DiningTable(double p,double d,Material m,ChairCount cc):Furniture(p,d,m)
    {
        setchaircount(cc);
    }
    void setchaircount(ChairCount val)
    {
        ccount=val;
    }
    string getchaircount()
    {
        if(ccount==ChairCount::Two)
            return string("Two");
        else if(ccount==ChairCount::Four)
            return string("Four");
        else if(ccount==ChairCount::Six)
            return string("Six");
        else
            return string("");
    }
    void productDetails()
    {
        Furniture::productDetails();
        cout<<"\nChair Count: "<<getchaircount();
        cout<<"\n###################################################\n";
    }
};

int main()
{
    Furniture* f_list[100];

    f_list[0] = new Bed(10000,123,Material::Wood,BedSize::Single);
    f_list[1] = new Sofa(11000,234,Material::Steel,SeatNumber::Five);
    f_list[2] = new DiningTable(13000,345,Material::Wood,ChairCount::Two);
    f_list[3] = new Bed(10090,123,Material::Wood,BedSize::Single);


    f_list[2]->setDiscount(30);//need to use -> for pointing
    for(int i=0; i<4; i++)
    {
        f_list[i]->productDetails();
    }

}
