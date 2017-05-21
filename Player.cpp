#include "Player.h"

//sets the name of the player
void Player::setName(string nameIn)
{
    name=nameIn;
}
//sets the health of the player
void Player::setHealth(int healthIn)
{
health=healthIn;
}
//sets the place of origin of the player charachter
void Player::setPlace(string placeIn)
{
    place=placeIn;
}
//sets the strength of the player
void Player::setStrength(int strengthIn)
{
    strength=strengthIn;
}
//gets the coin amount after a transaction
int Player::getCoinsafterTrans(int cost)
{
    coins=coins+cost;
    return coins;
}
//retrieves the coins amount, in essence the same as getCoinsafterTrans if you were to just type in 0.
int Player::getCoins()
{
     return coins;
}
//gets the place from where the charachter originated
string Player::getPlace()
{
    return place;
}
//gets the health of the player.
int Player::getHealth()
{
    return health;
}
//gets the strength of the charachter.
int Player::getStrength()
{
    return strength;
}
//this sets the slot inside an array
void Player::setSlot(item weaponIn,int slotIn)
{
    Itembag[slotIn]=weaponIn;
}

//I was trying to make a useitem an array that would use an item and then destroy it
//but I was not able to figure it out in time :(.
//int Player::useItem(item potion,int slot)
//{
  //  return Itembag[slot].healthBoost;

   // Itembag[slot].~item();
//}
