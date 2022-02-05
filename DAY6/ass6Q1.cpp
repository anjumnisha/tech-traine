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

//we are creating a class vehicle as an abstract class
class Vehicle
{
public:
    virtual void getVehicle()=0;      //pure virtual function of abstract class vehicle->which is implemented in derived class
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
class MP : public Vehicle
{
protected:
    //MP has Constituency
    Constituency* constituency;
public:
    int spendinglimit=100000;
    void getConstituency(Constituency* constituency)
    {
        this->constituency=constituency;
        cout<<"Constituency - "<<constituency->area<<" "<<constituency->pincode<<" "<<constituency->state<<"\n";
    }
    void spendingLimit()
    {
        cout<<"Spending Limit - "<<spendinglimit<<"\n";
    }
    void getVehicle()       //parent class function
    {
        cout<<"Vehicle - CAR \n";
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
class M : public MP
{
public:
    void getVehicle()       //parent class function
    {
        cout<<"Vehicle - CAR \n";
    }
};

//class PM inherit MP class and Vehicle class
class PM : public MP
{
public:
    bool permission;
    void givePermission(bool permission )
    {
        this->permission=permission;
    }
    void getVehicle()       //parent class function
    {
        cout<<"Vehicle - CAR and AIRCRAFT \n";
    }
};

//class Commissioner
class Commissioner
{
public:
    PM* pm;
    bool getPermission(bool p)
    {
        if(pm->givePermission(p))
        {
         cout<<"Permission - TRUE";
         cout<<"*ARRESTED*\n";      }
    }
};

//main function
int main()
{
    cout<<"***MP****\n";
    MP mP;
    mP.spendingLimit();
    Constituency c = Constituency("Pitampura",110042,"Delhi");
    mP.getConstituency(&c);
    Vehicle *mp = new MP();
    mp->getVehicle();
    int spen;
    cout<<"Enter spending amount ";
    cin>>spen;
    bool sp=mP.exceedSpendingLimit(spen);
    if(sp==true)
       { cout<<"Exceeds Spending Limit\n";
         PM prime;
         bool per;
         cout<<"Enter PM permission to ARREST(true/false)\n";
         cin>>per;
         prime.givePermission(per);
         Commissioner com;
         com.getPermission(&prime);
       }
    else
    {   cout<<"Do Not Exceeds Spending Limit\n";    }


    cout<<"\n***PM****\n";
    MP *p = new PM();
    p->spendinglimit=10000000;
    p->spendingLimit();
    p->getVehicle();
    cout<<"Enter spending amount ";
    cin>>spen;
    sp=p->exceedSpendingLimit(spen);
    if(sp==true)
        cout<<"Exceeds Spending Limit\n";
    else
    {   cout<<"Do Not Exceeds Spending Limit\n";    }


    cout<<"\n***M****\n";
    MP *m=new M();
    m->spendinglimit=1000000;
    m->spendingLimit();
    m->getVehicle();
    cout<<"Enter spending amount ";
    cin>>spen;
    sp=m->exceedSpendingLimit(spen);
    if(sp==true)
        cout<<"Exceeds Spending Limit\n";
    else
    {   cout<<"Do Not Exceeds Spending Limit\n";    }


return 0;
}

