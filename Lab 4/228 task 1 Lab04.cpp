#include<iostream>
#include<string.h>
using namespace std;


class BankAccount
{
public:
    int account_number;
    char h_name[1000], account_type[1000];
    float current_balance;
    float minimum_balance;



    BankAccount():current_balance(0.0)
    {

    }
    void BankAccount_assign (int a_no, char *a_name, char* type,float bl,float ml)
    {
        account_number=a_no;
        strcpy(h_name,a_name);
        strcpy(account_type,type);
        current_balance=bl;
        minimum_balance=ml;
    }

    void deposit()
    {
        float amount;
        cout<<"\nEnter amount to be deposited";
        cin>>amount;
        current_balance=current_balance+amount;

    }

    void  withdrawal()
    {
        float w;
        cout<<"\nEnter amount to withdraw";
        cin>>w;
        if(w<minimum_balance && w>current_balance)
        {
            cout<<"Cannot withdraw!!!";
        }
        else
        {
            current_balance=current_balance-w;
        }
    }
     void showBalance()
    {
        cout<<current_balance<<endl;
    }
    void bank_information()
    {
        cout<<"\naccount number "<<account_number;
        cout<<"\naccount holder name"<<h_name;
        cout<<"\naccount type"<<account_type;
        cout<<"\ncurrent balance\n\n"<<current_balance;
    }


    ~BankAccount()
    {
        cout<<"Account of Mr."<<h_name<<"with account no "<<account_number<<" is destroyed with a balance BDT"<<current_balance<<endl;
    }
};


int main()
{
    BankAccount b1;
    b1.BankAccount_assign(1234,"X","Current",5000.00,1289.77);
    b1.deposit();
    cout<<"after deposit balance ";
    b1.showBalance();
    b1.withdrawal();
    cout<<"after withdrawal balance ";
    b1.showBalance();
    cout<<"\n";
    b1.bank_information();
}
