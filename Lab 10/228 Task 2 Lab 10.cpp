#include<bits/stdc++.h>
using namespace std;

class Airport
{
private:
    int seat_count;
    string flight_name;
    int flight_id;
    //Airport operator = (Airport &a){}///restricting a class from copying
    //Airport operator () (Airport &a){}
    //Airport(Airport &a){}
public:
    Airport(int sc,string fn,int id):seat_count(sc),flight_name(fn),flight_id(id)
    {

    }
    int get_seatcount()
    {
        return seat_count;
    }
    int get_flightid()
    {
        return flight_id;
    }
    string get_flightname()
    {
        return flight_name;
    }
    void get_flightdetails()
    {
        cout<<"\n\nFlight name is :"<<get_flightname()<<endl;
        cout<<"Flight ID is :"<<get_flightid()<<endl;
        cout<<"Seat present in that flight :"<<get_seatcount()<<endl;
    }

    Airport operator = (Airport &a)
    {
        //here not assigning the flight id
        seat_count=a.seat_count;
        flight_name=a.flight_name;
        return Airport(seat_count,flight_name,flight_id);
    }
    Airport operator () (Airport &a)
    {
        //here not copying the flight id
        seat_count=a.seat_count;
        flight_name=a.flight_name;
        return Airport(seat_count,flight_name,flight_id);
    }

   /* Airport(Airport &a):seat_count(a.seat_count),flight_name(a.flight_name),flight_id(2288)
    {

    }*/
};


int main()
{
    Airport a1(50,"Novoair",5699);
    Airport a2(60,"Regent",9056);
    Airport a3(100,"Biman",1096);
    Airport a4=a1;//using initialization
    a1.get_flightdetails();
    a2.get_flightdetails();
    a2=a1;
    a2.get_flightdetails();
    a3(a1);//usimg copy constructor
    a3.get_flightdetails();
    a4.get_flightdetails();
}
