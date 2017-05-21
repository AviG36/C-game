#include "item.h"


//this function takes an Id type and allows a database of items to be created from it.
//this is especially useful with the random number generator used in the function
string item::setWeapon(int Id)
{
    string nameI;
    if (Id==0)
    {
     nameI = "Knife";
     name=nameI;
     strengthBoost=2;
    }

    else if(Id==1)
    {
    nameI = "Sword";
    name=nameI;
    strengthBoost=5;
    }

    else if (Id==2)
    {
        nameI="Battle Axe";
        name=nameI;
        strengthBoost=8;
    }
    else if (Id==3)
    {
        nameI="Beer";
        name=nameI;
        strengthBoost=4;
    }
    else if (Id==4)
    {
        nameI="Potion";
        name=nameI;
        healthBoost=10;
    }

    return name;

}
//here is the destroyer i was trying to use but oh well
//item::~item()
//{
    //dtor
//}

