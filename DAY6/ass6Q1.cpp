/*Q1.Write a program to depict Indian Politics.
Consider the politics use cases :
MP: is a person who won from a constituency
getConstituency - return their winning constituency.
getDriver - returns the driver assigned for their vehicle (default car).
exceedsSpendingLimit - returns true or false if Mps exceeds to their spending limit.
PM->Ministers->MP (All of them are MPS) - PM has special permissions such as it can give permission to arrest any minister.
PM enjoys special benefits such as Aircraft (along with car) and its designated driver.
Note: PM spending limit : 1 crore, Ministers: 10 lakhs, MP: 1 lakh.
Need to design in a way  where Commisioner class can arrest MP, Ministers and PM when their expense exceeds their spending limit:
canArrest - can arrest one or many MP.
           Note: If PM  cant arrest.
                 If minister can arrest with PM permission
                if mps they can be arrested without anyones permission.
In Short, If the MP is not PM then he can be arrested by commissioner , If he is minister then can be arrested with PMs permisison.*/

#include<iostream>
using namespace std;

//class vehicle
class Vehicle
{
public:
    string type;
    Vehicle(string type)        //vehicle class constructor
    {
        this->type=type;
        cout<<"Vehicle - "<<type<<"\n";
    }
};

//class car -> derived from vehicle class
class Car: public Vehicle
{
public:
    Car(string type):Vehicle(type)
    {

    }
};

//class aricraft -> derived from vehicle class
class Aircraft : public Vehicle
{
public:
    Aircraft(string type):Vehicle(type)
    {

    }
};

//class Constituency
class Constituency
{
public:
    string area;
    int pincode;
    string state;
    Constituency(string area, int pin, string state)
    {
        this->area=area;
        pincode=pin;
        this->state=state;
    }
};

//class MP
class MP
{
protected:
    //MP has Constituency and Vehicle (aggregation)
    Constituency* constituency;
    Vehicle* vehicle;
public:
    int spendinglimit=100000;
    void getVehicle(Vehicle* vehicle)
    {
        this->vehicle=vehicle;
        cout<<"Vehicle - "<<vehicle->type;
    }
    void getConstituency(Constituency* constituency)
    {
        this->constituency=constituency;
        cout<<"Constituency - "<<constituency->area<<" "<<constituency->pincode<<" "<<constituency->state<<"\n";
    }
    void spendingLimit()
    {
        cout<<"Spending Limit - "<<spendinglimit<<"\n";
    }
    bool exceedSpendingLimit(int spen)
    {
        if(spen>spendinglimit)
            return true;
        else
            return false;
    }
};

//class M inherit MP class and Vehicle clsss
class Minister : public MP
{
};

//class PM inherit MP class and Vehicle class
class PrimeMinister : public MP
{
public:
    int permission;
    PrimeMinister(){}       //default constructor
    PrimeMinister(int permission )         //parameterized contructor
    {
        this->permission=permission;
    }
};

//class Commissioner
class Commissioner
{
public:
    PrimeMinister* primeminister;       //using aggregation-> commissionew has PM permission
    void getPermission(PrimeMinister* primeminister)
    {
        this->primeminister=primeminister;
        if(primeminister->permission==1)
        {
            cout<<"**ARRESTED**\n";
        }
        else
        {
            cout<<"**NOT ARRESTED**\n";
        }
    }
};

//main function
int main()
{
    cout<<"***MP****\n";
    MP mP;
    //Vehicle vehicle=Vehicle("CAR");       //also work but it create vehicle object
    //mP.getVehicle(&vehicle);
    Vehicle* vehicle = new Car("CAR");      //creating car object as vehicle
    mP.spendingLimit();
    Constituency c = Constituency("Pitampura",110042,"Delhi");
    mP.getConstituency(&c);
    int spen;
    cout<<"Enter spending amount ";
    cin>>spen;
    bool sp=mP.exceedSpendingLimit(spen);
    if(sp==true)
       { cout<<"Exceeds Spending Limit\n";
         int per;
         cout<<"Enter PM permission to ARREST(1/0)\n";
         cin>>per;
         PrimeMinister prime(per);
         Commissioner com;
         com.getPermission(&prime);
       }
    else
    {   cout<<"Do Not Exceeds Spending Limit\n";    }


    cout<<"\n***PM****\n";
    MP *p = new PrimeMinister();
    Vehicle* pmvehicle1 = new Car("CAR");
    Vehicle* pmvehicle2 = new Aircraft("AIRCRAFT");
    p->spendinglimit=10000000;
    p->spendingLimit();
    cout<<"Enter spending amount ";
    cin>>spen;
    sp=p->exceedSpendingLimit(spen);
    if(sp==true)
        cout<<"Exceeds Spending Limit\n";
    else
    {   cout<<"Do Not Exceeds Spending Limit\n";    }


    cout<<"\n***M****\n";
    MP *m=new Minister();
    Vehicle* m1vehicle = new Car("CAR");
    m->spendinglimit=1000000;
    m->spendingLimit();
    cout<<"Enter spending amount ";
    cin>>spen;
    sp=m->exceedSpendingLimit(spen);
    if(sp==true)
        {cout<<"Exceeds Spending Limit\n";
         int mper;
         cout<<"Enter PM permission to ARREST(1/0)\n";
         cin>>mper;
         PrimeMinister prime2(mper);
         Commissioner com2;
         com2.getPermission(&prime2);
        }
    else
    {   cout<<"Do Not Exceeds Spending Limit\n";    }


return 0;
}

