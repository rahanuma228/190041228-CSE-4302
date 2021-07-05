#include<iostream>
using namespace std;

class Medicine
{
private:
    char *name1;
    char *genericName1;
    double discountPercent;
    double unitPrice;
public:
    Medicine():unitPrice(0),discountPercent(5)
    {
    }
    void assignName(char* name, char* genericName)
    {
        name1=name;
        genericName1=genericName;
    }
    void assignPrice(double price)
    {
        if(price>=0)
        {
            unitPrice=price;
        }
    }
    void setDiscountPercent(double percent)
    {
        if(percent>=0 && percent<=45)
        {
            discountPercent=percent;
        }
    }
    double getSellingPrice(int nos)
    {
        double sellingprice=unitPrice-((unitPrice*discountPercent)/100);
        sellingprice=sellingprice*(double)nos;
        return sellingprice;
    }
    void display()
    {
        cout<<name1<<" ("<<genericName1<<") "<<"has a unit price BDT "<<unitPrice<<". Current discount "<<discountPercent<<"% ."<<endl;
    }

};

int main()
{
    Medicine m1;
    m1.assignName("Napa","Paracetamol");
    m1.assignPrice(0.80);
    m1.setDiscountPercent(10);
    m1.display();
    cout<<"Selling price is : ";
    cout<<m1.getSellingPrice(2)<<endl;
}





