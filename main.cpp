#include <iostream>
#include <string>
#include "Player.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <fstream>

using namespace std;

//This is a battle function that takes two players and pits them together.If i had more time I would make it more turn based
//But so far it works well and pits a players health and strength against each other
int battle(Player A,Player B)
{
    srand(time(NULL));
    while(A.getHealth()>0 && B.getHealth()>0)
        {

        int aAttack=rand()% 5 + (A.getStrength());
        int bAttack=rand()% 3 + (B.getStrength());
        B.setHealth(B.getHealth()-aAttack);
        A.setHealth(A.getHealth()-bAttack);
        cout<<"Your health is "<<A.getHealth()<<endl;
        cout<<"Your enemy's health is "<< B.getHealth()<<endl;

        }
//if the first charachter dies than the while loop is exited and results in
//in the following if statement
    if(A.getHealth()<=0)
        {
            cout<<"Your epic quest is over"<<endl;
            exit(0);
        }
    else
        {
        cout<<" You proved victorious in this bout! Excellent job! "<<endl;
        }
//I made it return the health function because it would not be carried out of the function otherwise.
    return A.getHealth();
}

int main()
{
    srand(time(NULL));
    Player account("Filler","Place",100,15);
    char gameIn, drinkIn;
    cout << "Would you like to play? (Y) or (N)" << endl; //typical while loop of where the user wants to play.
    cin >> gameIn;

    while (toupper(gameIn) != 'Y' && toupper(gameIn) != 'N')
    {
        cout << "Invalid response, please try again." << endl;
        cin >> gameIn;
    }

    /* User has requested to exit the game */
    if (toupper(gameIn) == 'N')
    {
        cout << "All that for nothing" << endl;
        return 0;
    }

    /* User has decided to stay in the game */
    cout << " ------------------------------Fade In--------------------------------------" << endl;
    cout << "You find yourself walking into a poorly lit tavern," << endl;
    cout << "Your clothing is soaked from the heavy rain just outside." << endl;
    cout << "A smirking barmaid strolls past you." << endl;
    cout << "\"Don’t you be dragging your dirty self over these floors." << endl;
    cout << "I only just cleaned them and honey," << endl;
    cout << "leave your weapon next to the door.\"" << endl;
    cout << "You look at her with shock but she merely pushes you to the entrance until you raise your hands and nod." << endl;
    cout << "You begin to strip down." << endl;
    cout << "\"Any drinks for you hun?\"" << endl;
    cout << "Do you want a drink? ('Y') or ('N')" << endl;
    cin >> drinkIn;

    while (toupper(drinkIn) != 'Y' && drinkIn != 'N')
    {
        cout << "Invalid response, please try again." << endl;
        cin >> drinkIn;
    }

    if (toupper(drinkIn) == 'Y')
    {
        cout << "You nod. \"That will be five gold.\" You toss five gold pieces onto the table." << endl;
        cout << "You now have " << account.getCoinsafterTrans((-5)) << " coins." << endl;//implentation of currency.
    }
    else
    {
        cout << "\"Suit yourself. Quiet, Sober, and drenched I guess you don\’t want to make any friends." << endl;
        cout << "Take it anyway. On the house...\"" << endl;
    }

    item beer;
    beer.setWeapon(3);
    account.setSlot(beer,3);//i created this item hoping to be able to use for the useItem function but oh well.
    //it gets placed in the array regardless.

    string nameIn;
    string placeIn;

    cout << "\"What’s your name stranger?\"" << endl;
    cin >> nameIn;
    cout << "\"Alright " << nameIn << ", from where do you hail?\"" << endl;
    cin >>  placeIn;
    cout << "\"Ahh yes, I’ve heard of those folk." << endl;
    cout << "Although I thought they would smile more than yourself " << nameIn << "!\"" << endl;

    account.setName(nameIn);
    account.setPlace(placeIn);


    cout << "\"Begin the fight!\" someone screeches from the corner. You look around and see as a man charges you."<<endl;

Player enemy("Figure","Unknown",50,10);

    cout << "What do you do?"<<endl;
    cout <<  "Press 1 to sidestep the man"<<endl;
    cout <<  "Press 2 to charge back"<<endl;
    cout <<  "Press 3 to do nothing"<<endl;
//creation of the enemy figure that attacks you
int choice=0;
cin>>choice;

while (choice != 1 && choice!=2 && choice!= 3)
     {
        cout << "Invalid response, please try again." << endl;
        cin >> choice;
     }
        if (choice==1)
        {
          if (rand() % 10 +1 >= 6)
            {cout<< "You successfully dodge the attack."<<endl;
            }
          else
            {
                cout << "You stumble out of the chair and attempt to jump to the side."<<endl;
                cout << "The mysterious figure charges you and knocks you on the ground"<<endl;
                account.setHealth(90);
            }


        }
        if(choice==2)
        {
            if (rand() % 10 +1 >= 6)
            {
                cout << "You roar your name and the many kings and lineages from whence you originate."<< endl;
                cout << "You bring your right leg into his face and knocks the figure to the ground." << endl;
                enemy.setHealth(35);
            }
            else
            {
                cout << "You squeal \"Mother\" and attempt to push the figure away but fail miserably..."<<endl;

            }
        }
        if(choice==3)
        {
            cout << "The figure hurdles into you and brandishes a large knife ululating a wild cry"<<endl;
            cout << "and stabs you in your right shoulder."<<endl;
            account.setHealth(40);
        }

    cout<< "Enter the battle!"<<endl;


    account.setHealth(battle(account,enemy));

    cout<<"You look through enemy's corpse and look through his pocket"<<endl;

    item weapon1;
    weapon1.setWeapon(rand()%3);
    account.setSlot(weapon1,0);
    string itemName;

    cout<< "You find a "<< account.Itembag[0].name<<endl;

    cout<<"You pick up the weapon and place it in your bag"<<endl;
    cout<< " You also find 20 gold pieces and quickly swipe that up."<<endl;
    cout<<"You now have "<<account.getCoinsafterTrans(20)<<" coins "<<endl;

    cout<<"The barmaid looks at you and lauds you're victory!"<<endl;
    cout<<"\"That was incredible! Can I have your autograph sir!\""<<endl;
    cout<<"\" Oh and feel free to drink your beer!\""<<endl;



//these functions below take the variables of the item in the bag and add it to the players.
//I tried to use a useItem functino but it did not work yet.
account.setHealth((account.getHealth()+account.Itembag[4].healthBoost));
account.setStrength((account.getStrength()+account.Itembag[0].strengthBoost));



string outPutFile;
cout<<"Please enter a file name for your statistics:"<<endl;
cin>>outPutFile;
ofstream outFile;
outFile.open(outPutFile);


outFile<<account.name<< " from " <<account.place<< endl;
outFile<<" You have "<<account.coins << " coins " << endl;
outFile<< " and you have in your inventory a "<<account.Itembag[0].name<< " and a "<<endl;
outFile<< account.Itembag[3].name<<endl;
outFile<<" Your total health and strength is now "<<account.health<<endl;
outFile<<" and "<< account.strength<<endl;

cout << " --------------------------Thanks for playing!------------------------" << endl;
return 0;
}
