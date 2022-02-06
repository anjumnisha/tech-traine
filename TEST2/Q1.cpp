/*Question 1 :
Suppose a class VegetableBill keeps track of a list of vegetable being purchased at a market:
Method/Constructor    Description
public VegetableBill(Employee clerk)    constructs a VegetableBill object for the given clerk
public void add(Item i)    adds i to this bill's total
public double getTotal()    returns the cost of these items
public void printReceipt()    prints a list of items
class Item objects. An Item has the following public methods:
Method/Constructor    Description
public double getPrice()    returns the price for this item
public double getDiscount()    returns the discount for this ite
Define a class DiscountBill
Method/Constructor    Description
public DiscountBill(Employee clerk, boolean preferred)    constructs bill for given clerk
public int getDiscountCount()    returns the number of items that were discounted, if any
public double getDiscountAmount()    returns the total discount for this list of items, if any
public double getDiscountPercent()    returns the percent of the total discount */

#include<iostream>
using namespace std;

//class Employee
class Employee
{
public:
    string name;
    Employee(string name)
    {
        this->name=name;
        cout<<name<<"\n";
    }
};

//class Item
class Item
{
public:
    string itemList[6]={"1.apple","2.onion","3.potato","4.tomato","5.ladyfinger","6.bringal"};
    int price[6]={50,35,20,30,28,30};
    int itemDiscountPrice[6]={5,5,0,3,0,0};

    Item()          //default constructor
    {
        for(int i=0;i<6;i++)
        {   cout<<itemList[i]<<" - "<<price[i]<<"    discount - "<<itemDiscountPrice[i]<<"\n";
        }
        cout<<"\n";
    }
    double getPrice(int n)      //return price of an item
    {
       //cout<<itemList[n-1]<<" - "<<price[n-1];
       cout<<price[n-1];
    }
    double getDiscount(int n)    //return discount for an item
    {
        cout<<"Actual Price - "<<price[n-1]<<"\n";
        cout<<"Discount Price - "<<itemDiscountPrice[n-1]<<"\n";
    }
};

//class VegetableBill
class VegetableBill
{
 public:
        string vegetableList[6];
        int vegetablePrice[6];
        int vegetableDiscountPrice[6];
        int in=0;
        int total=0;
        VegetableBill()     //default constructor
        {       }
        VegetableBill(Employee clerk)       //constructs a VegetableBill object for the given clerk
        {       }
        void add(int a)        //adds i to this bill's total
        {

            cout<<"Item List :\n";
            Item item;
            vegetableList[in]=item.itemList[a-1];
            vegetablePrice[in]=item.price[a-1];
            vegetableDiscountPrice[in]=item.itemDiscountPrice[a-1];
            ++in;
        }
        double getTotal()       //returns the cost of these items
        {
            for(int i=0;i<in;i++)
                total+=vegetablePrice[i];
        }
        void printReceipt()     //prints a list of items and cost
        {
            cout<<"Vegetable\tPrice\n";
            for(int i=0;i<in;i++)
                cout<<vegetableList[i]<<"\t\t"<<vegetablePrice[i]<<"\n";
            cout<<"Total Vegetable Bill - "<<total<<"\n";
        }
};

//class DiscountBill has VegetableBill (aggregation)
class DiscountBill
{
//constructor for DiscountBill accepts a parameter for whether the customer should get the discount.
public:
    VegetableBill* vegetableBill;
    int index=vegetableBill->in;

    int totalDiscount=0;
    DiscountBill()
    {       }
    DiscountBill(Employee clerk ,bool prefered)     //construct bill for clerk
    {
    }
    int getDiscount(VegetableBill* vegetableBill)          //return number of item that were discount
    {   this->vegetableBill=vegetableBill;
        int j=0;
        cout<<"Item that have discount - ";
        for(int i=0;i<index;i++)
        {
            if(vegetableBill->vegetableDiscountPrice[i]==0)
                cout<<vegetableBill->vegetableList[i]<<"\n";
            else
                j++;
        }
        if(j==index)
            cout<<"NONE\n";
    }
    double getDiscountAmount(VegetableBill* vegetableBill)      //return total discount
    {
        this->vegetableBill=vegetableBill;
        for(int i=0;i<index;i++)
        {
            totalDiscount+=vegetableBill->vegetableDiscountPrice[i];
        }
        cout<<"Total Discount - "<<totalDiscount <<"\n";
    }
    double getDiscountPercent(VegetableBill* vegetableBill)         //return percent of total discount
    {
        this->vegetableBill=vegetableBill;
        float percentage=0.0;
        percentage=(totalDiscount/vegetableBill->total)*100;
        cout<<"Discount Percentage - "<<percentage<<"\n";
    }
};

int main()
{
    cout<<"Employee - ";
    Employee emp("clerk");
    VegetableBill vege(emp);
    cout<<"Item List :\n";
    Item item;
    VegetableBill v1;
    int l;
    char ch;
    do{
        cout<<"Add item you want to buy : ";
        cin>>l;
        cout<<"\n";
        v1.add(l);
        cout<<"Want to add more(y/n) :";
        cin>>ch;
        cout<<"\n";
    }while(ch=='y' || ch=='Y');
    v1.getTotal();
    v1.printReceipt();
    DiscountBill dis;
    dis.getDiscount(&v1);
    dis.getDiscountAmount(&v1);
    dis.getDiscountPercent(&v1);

    return 0;
}
