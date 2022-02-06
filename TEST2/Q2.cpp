/*Question 2 : We need to find manufacturing cost of a box.There are  5 type of Box
1. Universal
2. AllFlapMeeting
3. HoneyComb
4. ReverseTuckIn
5. TopOpening SnapLock
Each Box has some basic properties :  length,height,width,area, flute;
A box can either use pins or pasting() to join.
A box can either single part or double part.
there are 7 types of flute : A,B,C,E,F,G and B(B is mostly used).a flute has gsm and extra gsm;
you need to calcuate cost of a box  : area * totalGSM * ExtraGSM * stitching cost (if double part cost is multiplied by 3)
where as Area : length * width * hightand total GSM : extraGSM + GSM * 100;and Extra GSM For Flute :
A = 10,B = 30,C = 20,E = 40,F =50,G = 20
and stitching cost :1.if box has a pin then  :  10rs per pin
2.if box has a pasting then cost is :
1. Universal : 20
2. AllFlapMeeting : 30
3. HoneyComb : 40
4. ReverseTuckIn : 40
5. TopOpening SnapLock = 50*/
#include<iostream>
using namespace std;
//class flute
class Flute
{
public:
		int GSM;
		int extraGSM;
		Flute()         //default constructor
		{
		    GSM=10;
		}
};
//class flute is inherited by fluteA, fluteB, fluteC, fluteE, fluteF, fluteG
class FluteA : public Flute
{
public:
		FluteA()
		{   extraGSM = 10;	}
};
class FluteB : public Flute
{
public:
		FluteB()
		{	extraGSM = 30;	}
};
class FluteC : public Flute
{
public:
		FluteC()
		{	extraGSM = 20;	}
};
class FluteE : public Flute
{
public:
		FluteE()
		{	extraGSM = 40;	}
};
class FluteF : public Flute
{
public:
		FluteF()
		{	extraGSM = 50;	}
};
class FluteG : public Flute
{
public:
		FluteG()
		{	extraGSM = 20;	}
};
//class pin
class Pin
{
protected:
	int cost;
public:
		int getCost(int amount)
		{
			cost = amount*10;
			return cost;
		}
};
//class paste
class Paste
{
protected:
        int cost;
public:
		int getCost(string type)
		{
			if(type == "Universal")
			cost = 20;
			else if(type == "AllFlapMeeting")
			cost = 30;
			else if(type == "HoneyComb")
			cost = 40;
			else if(type == "ReverseTuckIn")
			cost = 40;
			else if(type == "TopOpeningSnapLock")
			cost = 50;
			return cost;
		}
};
//class box
class Box
{
protected:
    int length;
	int height;
	int width;
	int area;
	Flute flutE;
	int totalGSM;
	int stitchingCost;
	int part;
public:
	string type;
		Box()
		{		}
		void setBox(int length, int width, int height, int part){
			this->length = length;
			this->width = width;
			this->height = height;
			this->part = part;
		}
		long long int calculateCost(Flute flute){
			area = length*height*width;
			totalGSM = (flute.extraGSM+flute.GSM)*100;

			int totalCost;
			totalCost = area*totalGSM*flute.extraGSM*stitchingCost;
			return totalCost;
		}
		join(Pin pin){
			int amount;
			cout<<endl<<"Enter Required pin : ";
			cin>>amount;
			stitchingCost = pin.getCost(amount);
			if(part==2) stitchingCost*=3;
		}
		join(Paste paste){
			stitchingCost = paste.getCost(type);
			if(part==2) stitchingCost*=3;
		}
};
//class Universal
class Universal : public Box
{
public:
		Universal()
		{
			type = "Universal";
		}
};
//class  AllFlapMeeting
class AllFlapMeeting : public Box
{
public:
		AllFlapMeeting()
		{
			type = "AllFlapMeeting";
		}
};
//class HoneyComb
class HoneyComb : public Box
{
	public:
		HoneyComb()
		{
			type = "HoneyComb";
		}
};
//class ReverseTuckIn
class ReverseTuckIn : public Box
{
public:
		ReverseTuckIn()
		{
			type = "ReverseTuckIn";
		}
};
//class TopOpeningSnapLock
class TopOpeningSnapLock : public Box
{
public:
		TopOpeningSnapLock()
		{
			type = "TopOpeningSnapLock";
		}
};

int main()
{
	FluteA fluteA;
	Pin pin;
	Universal universal;
	int part = 1;
	universal.setBox(10,10,10,part);
	universal.join(pin);
    cout<<universal.calculateCost(fluteA);
	return 0;
}
