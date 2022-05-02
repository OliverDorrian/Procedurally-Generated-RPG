#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <cstring>  
#include <string>
#include <random>
#include <algorithm>
#include <iterator>
#include <variant>
#include <Windows.h>
#include <mmsystem.h>
#include <utility.h>
using namespace std;


vector<healItems> allHealItems = getAllHealItems();
vector<richItems> allRichItems = getAllRichItems();
vector<relics> allRelics = getAllRelics();

class genericItem {
protected:
  string itemName;
  string itemDesc;
  int itemValue;
  int quantity;
public:

  genericItem(){
    quantity = 1; 
  }

  void incQuantity(){
    quantity += 1;
  }

  bool decQuantity(){
    if(quantity == 1){
      return false;
    } else{
      quantity--;
      return true;
    }
  }

  // GETTERS
  int getQuantity(){
    return quantity;
  }

  string getName(){
    return itemName;
  }

  string getDesc(){
    return itemDesc;
  }

  int getValue(){
    return itemValue;
  }
};

class healItem: public genericItem{
protected:
  healItems item;
  int healingValue;
public:
  healItem(){
    item = allHealItems[randNumber(0, allHealItems.size())];
    itemName = item.name;
    itemDesc = item.desc;
    itemValue = item.value;
    healingValue = item.healAmount;
  }

  healItem(string passedName){
    itemName = passedName;
  }

  int useItem(){
    return healingValue;
  }

  bool useItemDec(){
    return this->decQuantity();
  }

  int getHealValue(){
    return healingValue;
  }
};

class richItem: public genericItem{
protected:
  richItems item;
  int quantity;
public:
  richItem(){
    item = allRichItems[randNumber(0, allRichItems.size())];
    itemName = item.name;
    itemDesc = item.desc;
    itemValue = item.value;
  }

  richItem(string passedName){
    itemName = passedName;
  }
};

class relic{
  private:
  relics item;
  string itemName;
  string itemDesc;
  string itemAtt;
  int itemMod;
  int itemValue;
  public:
  relic(){
    item = allRelics[randNumber(0, allRelics.size())];
    itemName = item.name;
    itemDesc = item.desc;
    itemValue = item.value;
    itemMod = item.mod;
    itemAtt = item.att;
  }

  string getName(){
    return itemName;
  }

  string getDesc(){
    return itemDesc;
  }

  int getValue(){
    return itemValue;
  }

  int getMod(){
    return itemMod;
  }

  string getAtt(){
    return itemAtt;
  }

};

class quantItems{
protected:
  string itemName;
  vector<healItem> allHeals;
  vector<richItem> allRich;
public:
  template <class t1, class t2>
  bool checkIfPresent(t1 passedString, t2 &passedVector){
    for (size_t i = 0; i < passedVector.size(); i++){
      if (passedString == passedVector[i].getName()){
        passedVector[i].incQuantity();
        return true;
      }        
    }
    return false;
  }

  void addQuantityItem(string passedString, int passedInt){
    switch (passedInt){
      case 0:{
        healItem tempHealItem =  healItem(passedString);
        if(!(this->checkIfPresent(tempHealItem.getName(), allHeals))){
          allHeals.push_back(tempHealItem);
        }
        break;       
      }
      case 1:{
        richItem tempRichItem = richItem(passedString);
        if(!(this->checkIfPresent(tempRichItem.getName(), allRich))){
          allRich.push_back(tempRichItem);
        }
        break;         
      }
    }
  }

  void addHealItem(healItem& passedItem){
    if(!(this->checkIfPresent(passedItem.getName(), allHeals))){
      allHeals.push_back(passedItem);
    }
  }

  void addRichItem(richItem& passedItem){
    if(!(this->checkIfPresent(passedItem.getName(), allHeals))){
      allRich.push_back(passedItem);
    }
  } 

  void geneateQuantItem(){
    int rndNumber = randNumber(0, 1);
    switch (rndNumber){
      case 0:{
        healItem tempHealItem =  healItem();
        if(!(this->checkIfPresent(tempHealItem.getName(), allHeals))){
          allHeals.push_back(tempHealItem);
          textBox(1, "You find 1 " + tempHealItem.getName());
        }
        break;
      }
      case 1:{
        richItem tempRichItem = richItem();
        if(!(this->checkIfPresent(tempRichItem.getName(), allRich))){
          allRich.push_back(tempRichItem);
          textBox(1, "You find 1 " + tempRichItem.getName());
        }
        break;       
      }
    }
  }

  void addCertainQuantItem(int passedNumber){ // 0 for heals and 1 for rich
    switch (passedNumber){
      case 0:{
        healItem tempHealItem =  healItem();
        if(!(this->checkIfPresent(tempHealItem.getName(), allHeals))){
          allHeals.push_back(tempHealItem);
        }
        break;        
      }
      case 1:{
        richItem tempRichItem = richItem();
        if(!(this->checkIfPresent(tempRichItem.getName(), allRich))){
          allRich.push_back(tempRichItem);
        }
        break; 
      } 
    }
  }

  void displayItems(){
    longBox healBox = longBox(2, 60);
    healBox.title("Heal Items");
    for (vector<healItem>::size_type i = 0; i != allHeals.size(); i++){
      healBox.content("Item (" + to_string(i + 1) + "): " + allHeals[i].getName());
      healBox.content("Info: " + allHeals[i].getDesc());
      healBox.content("Quantity: " + to_string(allHeals[i].getQuantity()));
      if(i < allHeals.size()-1){
        healBox.separator();
      }
    }
    if (allHeals.size() == 0){
      healBox.content("None");
    }
    healBox.bottom();
    gap();

    longBox richBox = longBox(2, 60);
    richBox.title("Rich Items");
    for (vector<richItem>::size_type i = 0; i != allRich.size(); i++){
      richBox.content("Item (" + to_string(i + 1) + "): " + allRich[i].getName());
      richBox.content("Info: " + allRich[i].getDesc());
      richBox.content("Quantity: " + to_string(allRich[i].getQuantity()));
      if(i < allRich.size()-1){
        richBox.separator();
      }
    }
    if (allRich.size() == 0){
      richBox.content("None");
    }
    richBox.bottom();
  }

  int selectHealItem(){
    int selection;
    longBox healBox = longBox(2, 60);
    healBox.title("Heal Items");
    for (vector<healItem>::size_type i = 0; i != allHeals.size(); i++){
      healBox.content("Item (" + to_string(i + 1) + "): " + allHeals[i].getName());
      healBox.content("Info: " + allHeals[i].getDesc());
      healBox.content("Quantity: " + to_string(allHeals[i].getQuantity()));
      if(i < allHeals.size()-1){
        healBox.separator();
      }
    }
    if (allHeals.size() == 0){
      healBox.content("");
    }
    healBox.bottom();
    gap();
    selection = numInput(1, allHeals.size());
    return selection-1;

  }

  int getHeal(int selection){
    int value = allHeals[selection].useItem();
    if(allHeals[selection].useItemDec() == false){
      allHeals.erase(allHeals.begin() + selection);
    }
    textBox(1, "You healed " + to_string(allHeals[selection].getHealValue()) + " HP");
    return value;
  }

  void removeRichItem(int id){
    allRich.erase(allRich.begin() + id);
  }
  // Getters 
  vector<healItem> getHealingItemVector(){
    return allHeals;
  }

  vector<richItem> getRichItemVector(){
    return allRich;
  };
};

class inventory{
protected:
  vector<weapon> playerWeapons;
  quantItems playerQuantityItems;
  vector<relic> playerRelics;
  int currentWeaponIndex;
public:

  inventory(){
    weapon tempWeapon = weapon();
    playerWeapons.push_back(tempWeapon);
    weapon tempWeapon2 = weapon();
    playerWeapons.push_back(tempWeapon2);
    currentWeaponIndex = 0; 
  }

  void rndQuantityItem(){
    playerQuantityItems.geneateQuantItem();
  }

  void rndQuantityGroupItem(int passedInt){
    playerQuantityItems.addCertainQuantItem(passedInt);
  }

  void addQuantItem(string passedString, int passedGroup){
    playerQuantityItems.addQuantityItem(passedString, passedGroup);
  }

  void addRelic(relic& passedRelic){
    playerRelics.push_back(passedRelic);
  }

  void displayQuantityItems(){
    playerQuantityItems.displayItems();
  }

  void displayAllWeapons(){
    longBox weaponBox = longBox(2, 60);
    weaponBox.title("Weapons");
    for (int i = 0; i < playerWeapons.size(); i++){
      weaponBox.content("(" + to_string(i+1) + ") " + playerWeapons[i].getRarity() + " " + playerWeapons[i].getName());
      weaponBox.content("Damage: " + to_string(playerWeapons[i].getMinDmg()) + "-" + to_string(playerWeapons[i].getMaxDmg()));
      if(i < (playerWeapons.size()-1)){
        weaponBox.separator();
      }
    }
    weaponBox.bottom();
  }

  void displayAllRelics(){
    longBox relicBox = longBox(2, 60);
    relicBox.title("Relics");
    for (int i = 0; i < playerRelics.size(); i++){
      relicBox.content("(" + to_string(i + 1) + ") " + playerRelics[i].getName());
      relicBox.content("Info: " + playerRelics[i].getDesc());
      if(i < (playerRelics.size()-1)){
        relicBox.separator();
      }
    }
    if (playerRelics.size() == 0){
      relicBox.content("None");
    }
    relicBox.bottom();
  }

  void generateNewWeapon(){
    weapon tempWeapon = weapon();
    playerWeapons.push_back(tempWeapon);
  }

  void changeCurrentWeapon(){
    this->displayAllWeapons();
    int tempInput;
    textBox(1, "Please select a new weapon");
    tempInput = numInput(1, playerWeapons.size());
    currentWeaponIndex = tempInput-1;

  }

  int healPlayer(int selection){
    return this->playerQuantityItems.getHeal(selection);
  }

  // GETTERS
  weapon& getCurrentWeapon(){
    return playerWeapons[currentWeaponIndex];
  }

  quantItems& getQuantItems(){
    return playerQuantityItems;
  }
};
