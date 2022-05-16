
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
#include "fileHand.cpp"
#include "eventStructs.cpp"
#include "intro.cpp"
#include "preamble.cpp"
#include "items.cpp"
#include "headers/utility.h"
#include "title.cpp"
using namespace std;

// FILE CONSTANTS

// Race files
file orcFileWord = file("files/Races/Names/Orc/word.txt");
file orcFileAdjective = file("files/Races/Names/Orc/adjective.txt");
file dwarfFileWord = file("files/Races/Names/Dwarf/word.txt");
file dwarfFileSuffix = file("files/Races/Names/Dwarf/suffix.txt");
file elfFileWord = file("files/Races/Names/Elf/words.txt");
file humanMaleForeName = file("files/Races/Names/Human/male.txt");
file humanFemaleForeName = file("files/Races/Names/Human/female.txt");
file humanSurname = file("files/Races/Names/Human/surname.txt");
file lizardWord = file("files/Races/Names/Lizard/word.txt");
file lizardSuffix = file("files/Races/Names/Lizard/suffix.txt");
file cephWord = file("files/Races/Names/Cephalopoid/word.txt");
file cephSuffix = file("files/Races/Names/Cephalopoid/suffix.txt");
file catWord = file("files/Races/Names/Cat/word.txt");
file catPrefix = file("files/Races/Names/Cat/prefix.txt");
file dogWord = file("files/Races/Names/Dog/word.txt");
file dogSuffix = file("files/Races/Names/Dog/suffix.txt");
file vulWord = file("files/Races/Names/Vulture/word.txt");
file vulForeSuffix = file("files/Races/Names/Vulture/foresuffix.txt");
file vulSuffix = file("files/Races/Names/Vulture/suffix.txt");
file goblinWord = file("files/Races/Names/Goblin/prefix.txt");
file goblinSuffix = file("files/Races/Names/Goblin/suffix.txt");

// Weapon Files
file sharpFile = file("files/Weapons/Names/sharp.txt"); // gets file object of names of weapons
file sharpWords = file("files/Weapons/Actions/sharpWord.txt"); // gets file object with the words associated with weapon type
file genFile = file("files/Weapons/Names/random.txt");
file randomWords = file("files/Weapons/Actions/randomWord.txt");
file bluntFile = file("files/Weapons/Names/blunt.txt");
file bluntWords = file("files/Weapons/Actions/bluntWord.txt");

// Motto Files
file orcMotto = file("files/Races/Mottos/orc.txt");
file dogMotto = file("files/Races/Mottos/dog.txt");
file genericMotto = file("files/Races/Mottos/generic.txt");

vector<events> allEvents = getAllEvents();
vector<string> allMeadowsIntro = getAllMeadowsIntro();
vector<string> allUnderIntro = getAllUnderWorldIntro();

vector<string> allBarPreamble = getAllBarPreamble();
vector<string> allHousePreamble = getAllHousePreamble();
vector<string> allStreetPreamble = getAllStreetPreamble();
vector<string> allVillagePreamble = getAllVillagePreamble();
vector<string> allRoadPreamble = getAllRoadPreamble();
vector<string> allCryptPreamble = getAllCryptPreamble();

vector<healItems> allHealItems = getAllHealItems();
vector<richItems> allRichItems = getAllRichItems();
vector<relics> allRelics = getAllRelics();





// Weapon is given to each person within a One to One relationship
class weapon {
protected: 
  string name; // name of the weapon
  string biomeType; // location the weapon is found in
  string weaponType; // type of weapon damage
  int weight; // how heavy the weapon will be on the player inventory
  int minWeight = 1;
  int maxWeight = 4;
  int minDamage; // minimum damage a weapon will deal
  int maxDamage; // maximum damage a weapon will deal
  string rarity; // the rarity of the weapon
  vector<string> vectorOfWords;
public:
  // randomly select number, through a mod remainder, each determins the weapon type
  weapon() {
    int switchCaseInt = randNumber(0, 3);
    setDamage(); // sets the rarity and damage ranges for a weapon
    switch (switchCaseInt){
    case 0:
      weaponType = "Sharp"; 
      biomeType = "Underworld";
      name = sharpFile.getLineCap(randNumber()); // get a random line from the file object, then up-case the fist letter in the
      weight = randNumber(minWeight, maxWeight); // gets a weight between the max and min
      vectorOfWords = sharpWords.getVector();
      break;
    case 1:
      weaponType = "Stuff you would find in a car boot sale";
      biomeType = "Random";
      name = genFile.getLineCap(randNumber());
      weight = randNumber(minWeight, maxWeight);
      vectorOfWords = randomWords.getVector();
      break;
    case 2:
      weaponType = "Blunt"; 
      biomeType = "Industrial";
      name = bluntFile.getLineCap(randNumber());
      weight = randNumber(minWeight, maxWeight);
      vectorOfWords = bluntWords.getVector();
      break;
    }
  }

  weapon(int passedWeapon){ // 0 human start
    setDamage(); // sets the rarity and damage ranges for a weapon
    switch (passedWeapon){
    case 0:
      weaponType = "Sharp";
      biomeType = "Insert biome of humans here";
      name = sharpFile.getLineCap(randNumber());
      weight = randNumber(minWeight, maxWeight);
      vectorOfWords = bluntWords.getVector();
    }
  }

  string getItemFromVectorCap(){
    string tempString = getItemFromVector();
    tempString[0] = toupper(tempString[0]);
    return tempString;
  }

  string getItemFromVector(){
    return vectorOfWords[randNumber(0, vectorOfWords.size())];
  }
  
  // GETTERS
  string getName(){
    return name;
  }

  string getBiomeType(){
    return biomeType;
  }

  string getWeaponType(){
    return weaponType;
  }

  int getDamage(){ // gets a damage number between min and max damage ranges
    return randNumber(minDamage, maxDamage);
  }

  int getMinDmg(){ // returns minimum damage
    return minDamage;
  }

  int getMaxDmg(){ // returns max damage
    return maxDamage;
  }

  string getRarity(){ // returns the rarity of a weapon
    return rarity;
  }

  void setDamage(){ // sets the rarity and damage ranges for a weapon
    int rarityInt = randNumber(0, 20) + 1;
    if(rarityInt >= 1 && rarityInt <= 8){ // 40% chance to be common
      rarity = "Common";
      minDamage = 1;
      maxDamage = 3;
    }
    if(rarityInt >= 9 && rarityInt <= 14){ // 30% chance to be uncommon
      rarity = "Uncommon";
      minDamage = 2;
      maxDamage = 4;
    }
    if(rarityInt >= 15 && rarityInt <= 17){ // 15% chance to be unique
      rarity = "Unique";
      minDamage = 3;
      maxDamage = 5;
    }
    if(rarityInt >= 18 && rarityInt <= 19){ // 10% chance to be rare
      rarity = "Rare";
      minDamage = 4;
      maxDamage = 6;
    }
    if(rarityInt >= 20){ // 5% chance to be epic
      rarity = "Epic";
      minDamage = 5;
      maxDamage = 8;
    }
  }
};

class person { // Person is a super class of race
protected:
  string gender; // gender string   
  string faction; // which faction the person belongs to
  string name; // name of the person
  string race; // which race they belong to
  string desc;
  string desc2;
  string motto;
  int height; // how tall they are
  int age; // age of the person
  int health = 15; // health stat
  int ageMax = 50; // default max possible age
  int ageMin = 20; // default min possible
  int heightMin = 155; // default min height
  int heightMax = 190; // default max height
public:  
  weapon personWeapon = weapon(); // creates the weapon object. this is a one to one relationship

  void personDetail(){ // This class show the information of the person, including weapon object and race information
    longBox box = longBox(2, 80);
    system("CLS");
    box.top();
    box.content(race);
    box.content(desc);
    box.content(desc2);
    box.separator();
    box.content("Name: " + name);
    box.content("Age: " + to_string(age));
    box.content("Height: " + to_string(height) + "cm");
    box.content("Gender: " + gender);
    box.content("Faction: " + faction);
    box.content("Motto: '" + motto + "'");
    box.bottom();
    gap();
  }

  void setMotto(){
    motto = genericMotto.getLineCap(randNumber());
  }

  string getMotto(){
    return motto;
  }

  void header(){
    textBox(4, 2, this->name + " | Health: " + to_string(this->health) + " | Damage: " + to_string(personWeapon.getMinDmg()) + "-" + to_string(personWeapon.getMaxDmg()));
  }

  void decreaseHealth(int passedInt){
    health -= passedInt;

  }

  // GETTERS
  string getName(){
    return name;
  }

  int getHealth(){
    return health;
  }
};

class orc: public person { // child of person class, this allows for races to implement constructor for person in a different way
public:
  void setMotto(){
    motto = orcMotto.getLineCap(randNumber()); 
  }

  orc(){
    race = "Orc";
    name = orcFileWord.getLineCap(randNumber()) + orcFileWord.getLine(randNumber()) + " the " + orcFileAdjective.getLineCap(randNumber());
    age = randNumber(ageMin, ageMax);
    height = randNumber(heightMin, heightMax);
    gender = randNumber(0, 1) == 0 ? "Male" : "Female";
    faction = "Bandit";      
    desc = "Beefy, brutal, and brainless.";
    desc2= "Orcs like to crush first and ask questions never.";   
    setMotto(); 
  }

  
};

class dwarf: public person{ // child of person class, this allows for races to implement constructor for person in a different way
private: // file objects that crate the names of the race
  int heightMax = 150;
  int heightMin = 120;
public:
  dwarf(){
    race = "Dwarf";
    name = dwarfFileWord.getLineCap(randNumber()) + dwarfFileWord.getLine(randNumber()) 
    + " " + dwarfFileWord.getLineCap(randNumber()) + dwarfFileSuffix.getLine(randNumber());
    age = randNumber(ageMin, ageMax);
    height = randNumber(heightMin, heightMax);
    gender = randNumber(0, 1) == 0 ? "Male" : "Female";
    faction = "Commoner"; 
    desc = "Tubby, tough, and tiny.";
    desc2= "99 tankards of mead on the bar, 99 tankards of mead.";   
    setMotto(); 
  }
};

class elf:  public person{ // child of person class, this allows for races to implement constructor for person in a different way
private: // file objects that crate the names of the race
  int minElfAge = 70;
  int maxElfAge = 300;
  int minElfHeight = 180;
  int maxElfHeight = 215;
public:
  elf(){
    race = "Elf";
    name = elfFileWord.getLineCap(randNumber()) + elfFileWord.getLine(randNumber()) + elfFileWord.getLine(randNumber()); 
    age = randNumber(minElfAge, maxElfAge);
    height = randNumber(minElfHeight, maxElfHeight);
    gender = randNumber(0, 1) == 0 ? "Male" : "Female";
    faction = "Commoner"; 
    desc = "Moral, meticulous, and meek.";
    desc2= "Medieval pencil pushers.";   
    setMotto(); 
  }
};

class human: public person{ // child of person class, this allows for races to implement constructor for person in a different way
public:
  human(){
    race = "Human";
    gender = randNumber(0, 2) == 0 ? "Male" : "Female";
    if (gender == "Male"){
      name = humanMaleForeName.getLineCap(randNumber()) + " " + humanSurname.getLineCap(randNumber());
    } else{
      name = humanFemaleForeName.getLineCap(randNumber()) + " " + humanSurname.getLineCap(randNumber());
    }
    height = randNumber(heightMin, heightMax);
    age = randNumber(ageMin, ageMax);
    faction = "Commoner";
    desc = "Just human.";
    desc2 = "Nothing special.";   
    setMotto(); 
  }
};

class lizard: public person{ // child of person class, this allows for races to implement constructor for person in a different way
public:
  lizard(){
    race = "Lizard";
    if (randNumber(0, 6)){
      name = lizardWord.getLineCap(randNumber()) + lizardWord.getLine(randNumber()) + " " + lizardWord.getLineCap(randNumber()) + lizardSuffix.getLine(randNumber());
    } else {
      name = lizardWord.getLineCap(randNumber()) + lizardWord.getLine(randNumber()) + " Von " + lizardWord.getLineCap(randNumber()) + lizardSuffix.getLine(randNumber());
    }
    age = randNumber(ageMin, ageMax);
    height = randNumber(heightMin, heightMax);
    gender = randNumber(0, 1) == 0 ? "Male" : "Female";
    faction = "Imperial"; 
    desc = "Scaley, scary, and sophisticated.";
    desc2= "A cruel crowd of cold blooded crocs.";   
    setMotto(); 
  }
};

class cephalopod: public person{ // child of person class, this allows for races to implement constructor for person in a different way
public:
  cephalopod(){
    race = "Cephalopoid";
    name = cephWord.getLineCap(randNumber()) + cephWord.getLine(randNumber()) + " " + cephWord.getLineCap(randNumber()) + cephSuffix.getLine(randNumber()); 
    age = randNumber(ageMin, ageMax);
    height = randNumber(heightMin, heightMax);
    gender = randNumber(0, 1) == 0 ? "Male" : "Female";
    faction = "Imperial"; 
    desc = "Smart, solitary, and squidgy.";
    desc2= "Flibugulub buglub fibblug gugblibble.";
    setMotto(); 
  }
};

class cat: public person{ // child of person class, this allows for races to implement constructor for person in a different way
public:
  cat(){
    race = "Cat";
    name = catPrefix.getLineCap(randNumber()) + catWord.getLine(randNumber()) + " " + catWord.getLineCap(randNumber()) + catWord.getLine(randNumber()); 
    age = randNumber(ageMin, ageMax);
    height = randNumber(heightMin, heightMax);
    gender = randNumber(0, 1) == 0 ? "Male" : "Female";
    faction = "Merchants Guild"; 
    desc = "Crafty, cunning, and cuddly.";
    desc2= "Masters in the art of the deal, these cats always land on their feet.";   
    setMotto(); 
  }
};

class dog: public person{ // child of person class, this allows for races to implement constructor for person in a different way
public:
  void setMotto(){
    motto = dogMotto.getLineCap(randNumber());
  }
  dog(){
    race = "Dog";
    name = dogWord.getLineCap(randNumber()) + dogSuffix.getLine(randNumber()) + " " + dogWord.getLineCap(randNumber()) + dogSuffix.getLine(randNumber()); 
    age = randNumber(ageMin, ageMax);
    height = randNumber(heightMin, heightMax);
    gender = randNumber(0, 1) == 0 ? "Male" : "Female";
    faction = "Mercenaries Guild"; 
    desc = "Rough, raring, and righteous.";
    desc2= "They can sniff out anyone...if the price is right.";   
    setMotto(); 
  }

  
};

class vulture: public person{ // child of person class, this allows for races to implement constructor for person in a different way
public:
  vulture(){
    race = "Vulture";
    name = vulWord.getLineCap(randNumber()) + vulForeSuffix.getLine(randNumber()) + " " + vulWord.getLineCap(randNumber()) + vulSuffix.getLine(randNumber()); 
    age = randNumber(ageMin, ageMax);
    height = randNumber(heightMin, heightMax);
    gender = randNumber(0, 1) == 0 ? "Male" : "Female";
    faction = "Imperial"; 
    desc = "Funny, feared, and feathered.";
    desc2= "Smooth-talkers of the Imperial realm who love to chew you ear off.";   
    setMotto(); 
  }
};

class goblin: public person { // child of person class, this allows for races to implement constructor for person in a different way
private: // file objects that crate the names of the race
  int goblinAgeMax = 16; // default max possible age
  int goblinAgeMin = 5; // default min possible
  int heightMax = 150;
  int heightMin = 120;
public:
  goblin(){
    race = "Goblin";
    name = goblinWord.getLineCap(randNumber()) + goblinSuffix.getLine(randNumber());
    age = randNumber(goblinAgeMin, goblinAgeMax);
    height = randNumber(heightMin, heightMax);
    gender = randNumber(0, 1) == 0 ? "Male" : "Female";
    faction = "Bandit"; 
    desc = "Charismatic, compact, and crooked.";
    desc2= "Never trust a goblin.";   
    setMotto(); 
  }
}; 

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
    healBox.title("Healing Items");
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

class player {
protected:
  int strengthAttribute = 10;
  int speechAttribute = 10;
  int intelligenceAttribute = 10;
  int dreadAttribute = 10;
  int health = 15;
  int playerGold;
  //Reputation counters
  int comRep = 5; //Commoner reputation
  int impRep = 5; //Imperial reputation
  int banRep = 5; //Bandit reputation
  int merchantRep = 5; //Merchant reputation
  int mercRep = 5; //Mercenary reputation
  string race;
  string name;
  string secondName;
  string gender; 
  string motto;
  string killedBy; 
  bool hasDied = false;
  bool hasRetired = false;
  inventory invObj = inventory();
public:
  player(string passedName, string passedFamilyName, string passedRace, string passedGender, string passedMotto, int passedGold){
    name = passedName;
    race = passedRace;
    gender = passedGender;
    secondName = passedFamilyName;
    motto = passedMotto;
    playerGold = passedGold;
    
    if(passedRace == "Human"){
      speechAttribute += 1;
      comRep += 5;
      banRep -= 5;
      impRep -= 2;
    } else if(passedRace == "Elf"){
      intelligenceAttribute += 2;
      strengthAttribute -= 1;
      speechAttribute -= 1;
      comRep += 5;
      banRep -= 5;
      impRep -= 2;
    } else if(passedRace == "Dwarf"){
      strengthAttribute += 2;
      dreadAttribute -= 1;
      comRep += 5;
      banRep -= 5;
      impRep -= 2;
    } else if(passedRace == "Orc"){
      strengthAttribute += 3;
      dreadAttribute += 1;
      intelligenceAttribute -= 3;
      speechAttribute -= 1;
      banRep += 7;
      comRep -= 5;
      impRep -= 5;
    } else if(passedRace == "Lizard"){
      dreadAttribute += 3;
      strengthAttribute += 1;
      speechAttribute -= 2;
      comRep -= 4;
      banRep -= 5;
      impRep += 6;
    } else if(passedRace == "Cephalopoid"){
      intelligenceAttribute += 3;
      speechAttribute -= 3;
      comRep -= 3;
      banRep -= 5;
      impRep += 5;
    } else if(passedRace == "Goblin"){
      speechAttribute += 2;
      strengthAttribute -=2;
      comRep -= 5;
      banRep += 5;
      impRep -= 5;
    } else if(passedRace == "Cat"){
      speechAttribute += 2;
      intelligenceAttribute += 1;
      strengthAttribute -= 1;
      dreadAttribute -= 2;
      merchantRep += 5;
    } else if(passedRace == "Dog"){
      strengthAttribute += 2;
      dreadAttribute += 2;
      speechAttribute -= 2;
      mercRep += 5;
      impRep -= 5;
    } else if(passedRace == "Vulture"){
      speechAttribute += 2;
      dreadAttribute += 1;
      strengthAttribute -= 3;
      comRep -= 3;
      banRep -= 4;
      impRep += 5;
    } 
  }
  
  bool getDiceChance(string passedAtt, string passedFaction, int passedCheck){
    int roll;
    int mod;
    string op = (mod > 0) ? "+": "";
    if (passedAtt == "strength"){
      mod = (this->strengthAttribute -10) + this->getRep(passedFaction);
      roll = ((randNumber(0, (20 + 1))) + (this->strengthAttribute -10) + this->getRep(passedFaction));
    } else if (passedAtt == "speech"){
      mod = (this->speechAttribute -10) + this->getRep(passedFaction);
      roll = ((randNumber(0, (20 + 1))) + (this->speechAttribute -10) + this->getRep(passedFaction));
    } else if (passedAtt == "dread"){
      mod = (this->dreadAttribute -10) + this->getRep(passedFaction);
      roll = ((randNumber(0, (20 + 1))) + (this->dreadAttribute -10) + this->getRep(passedFaction));
    } else if (passedAtt == "intelligence"){
      mod = (this->intelligenceAttribute -10) + this->getRep(passedFaction);
      roll = ((randNumber(0, (20 + 1))) + (this->intelligenceAttribute -10) + this->getRep(passedFaction));
    }

    cout<<name + " rolled " << roll; 
    if (mod != 0){
      cout << " (" <<(roll - mod)<<op<<mod<<")"; // displays who rolled, and the score they got
    }
    cout<<"\n"; 
    if(roll >= passedCheck){
      return true;
    } else {
      return false;
    }
  }

  void displayPlayerInfo(){
    system("CLS");
    longBox info = longBox(2, 60);
    info.title(this->secondName + " clan");
    info.content("          Name: " + this->name + " " + this->secondName);
    info.content("        Gender: " + this->gender);
    info.content("          Race: " + this->race);
    info.separator();
    info.content("      Strength: " + to_string(this->strengthAttribute));
    info.content("        Speech: " + to_string(this->speechAttribute));
    info.content("  Intelligence: " + to_string(this->intelligenceAttribute));
    info.content("         Dread: " + to_string(this->dreadAttribute));
    info.separator();
    info.content("  Commoner Rep: " + to_string(comRep));
    info.content("  Imperial Rep: " + to_string(impRep));
    info.content("    Bandit Rep: " + to_string(banRep));
    info.content("  Merchant Rep: " + to_string(merchantRep));
    info.content(" Mercenary Rep: " + to_string(mercRep));
    info.bottom();

    cout<< "" << endl;
    textBox(2, "Gold: " + to_string(playerGold), 60);
    cout<< "" << endl;

    longBox weaponBox = longBox(2, 60);
    weaponBox.title("Weapon");
    weaponBox.content(invObj.getCurrentWeapon().getRarity() + " " + invObj.getCurrentWeapon().getName());
    weaponBox.content("Damage: " + to_string(invObj.getCurrentWeapon().getMinDmg()) + "-" + to_string(invObj.getCurrentWeapon().getMaxDmg()));
    weaponBox.bottom();
    cout<< "" << endl;

    invObj.displayAllRelics();
    cout<< "" << endl;
    invObj.displayQuantityItems();
    cout<< "" << endl;
  }

  int getRep(string passsedRepType){
    if(passsedRepType == "Commoner"){
      return comRep;
    } else if (passsedRepType == "Imperial"){
      return impRep;
    } else if (passsedRepType == "Bandit"){
      return banRep;
    } else if (passsedRepType == "Merchant"){
      return merchantRep;
    } else if (passsedRepType == "Mercenary"){
      return mercRep;
    }
    return 7809; // Nice
  }

  void addRep(string passedRepType){
    if(passedRepType == "Commoner"){
      comRep += 1;
      textBox(1, "Commoner rep increased");
    } else if (passedRepType == "Imperial"){
      impRep += 1;
      textBox(1, "Imperial rep increased");
    } else if (passedRepType == "Bandit"){
      banRep += 1;
      textBox(1, "Bandit rep increased");
    } else if (passedRepType == "Merchant"){
      merchantRep += 1;
      textBox(1, "Merchant rep increased");
    } else if (passedRepType == "Mercenary"){
      mercRep += 1;
      textBox(1, "Mercenary rep increased");
    }
  }

  void removeRep(string passedRepType){
    if(passedRepType == "Commoner"){
      comRep -= 1;
      textBox(1, "Commoner rep decreased");
    } else if (passedRepType == "Imperial"){
      impRep -= 1;
      textBox(1, "Imperial rep decreased");
    } else if (passedRepType == "Bandit"){
      banRep -= 1;
      textBox(1, "Bandit rep decreased");
    } else if (passedRepType == "Merchant"){
      merchantRep -= 1;
      textBox(1, "Merchant rep decreased");
    } else if (passedRepType == "Mercenary"){
      mercRep -= 1;
      textBox(1, "Mercenary rep decreased");
    }
  }

  void consumeHealItem(){
      if (this->getInventory().getQuantItems().getHealingItemVector().size() == 0 )
      {
        textBox(1, "There are no items that you can use to heal you!");
        pressKey();
      } else{
        int selection = getInventory().getQuantItems().selectHealItem();
        this->increaseHealth(this->invObj.healPlayer(selection));
        pressKey();
      }
  }

 void addRelicMod(relic& passedRelic){
    if(passedRelic.getAtt() == "Dread"){
      setDread(getDread() + passedRelic.getMod());
    }
    if(passedRelic.getAtt() == "Strength"){
      setStrength(getStrength() + passedRelic.getMod());
    }
    if(passedRelic.getAtt() == "Intelligence"){
      setIntelligence(getIntelligence() + passedRelic.getMod());
    }
    if(passedRelic.getAtt() == "Speech"){
      setSpeech(getSpeech() + passedRelic.getMod());
    }
 }

  // SETTERS
  void setRetired(bool passedBool){
    hasRetired = passedBool;
  }

  void setStrength(int passedStrength){
    strengthAttribute = passedStrength;
  }

  void setSpeech(int passedSpeech){
    speechAttribute = passedSpeech;
  }

  void setIntelligence(int passedIntelligence){
    intelligenceAttribute = passedIntelligence;
  }

  void setDread(int passedDread){
    dreadAttribute = passedDread;
  }

  void removeGold(int passedInt){
    playerGold -= passedInt;
  }
  void addGold(int passedInt){
    playerGold += passedInt;
  }

  void decreaseHealth(int passedInt, string passedNPC){
    //cout << "Your Health: " << this->getHealth() << " has been decreased by: " << passedInt << "!"  <<  endl;
    health -= passedInt;
    //cout << "Your health is: " << this->getHealth() << endl;
    if (health <= 0){
      hasDied = true;
      killedBy = passedNPC;
    }

  }

  void increaseHealth(int passedInt){
    health += passedInt;
  }

  void header(){
    textBox(1, 2, this->name + " " + this->secondName + " | Health: " + to_string(this->health) + " | Damage: " + to_string(invObj.getCurrentWeapon().getMinDmg()) + "-" + to_string(invObj.getCurrentWeapon().getMaxDmg()));
  }

  // Getters
  inventory& getInventory(){
    return invObj;
  }

  string getRace(){
    return race;
  }

  string getName(){
    string fullName = name + " " + secondName;
    return fullName;
  }

  string getMotto(){
    return motto;
  }

  string getGender(){
    return gender;
  }

  string getWeaponName(){
    return this->getInventory().getCurrentWeapon().getName();
  }

  string getNpcKiller(){
    return killedBy; 
  }

  int getHealth(){
    return health;
  }

  int getGold(){
    return playerGold;
  }

  int getStrength(){
    return strengthAttribute;
  }

  int getSpeech(){
    return speechAttribute;
  }

  int getIntelligence(){
    return intelligenceAttribute;
  }

  int getDread(){
    return dreadAttribute;
  }
  int getMerchantRep(){
    return merchantRep;
  }

  bool getPlayerStatus(){
    return hasDied;
  }
  
  bool getRetired(){
    return hasRetired;
  }
};

class family {
protected:
  string familyName;
  string motto;
  string race; 
  int familyGold = 25;
  int familyPrestige = 0;
  int currentPlayerIndex = -1;
  vector<player> allDecedents;

public:
  family(string passedName, string passedMotto, string passedRace){
    familyName = passedName;
    motto = passedMotto;
    race = passedRace; 
  }

  void generateNewPlayer(string passedFamilyName, string passedMotto, string passedRace, int passedGold){
    currentPlayerIndex += 1;
    textBox(2, "Please enter your first Name");
    string playerNameInput;
    cin.clear();
    playerNameInput = lenCheck();
    gap();


    textBox(2, "Please select a gender");
    textBox(1, "(1)  Male", 15);
    textBox(1, "(2)  Female", 15);
    int selection;
    string playerGenderInput;
    selection = numInput(1, 2);
    switch(selection){
      case 1:
        playerGenderInput = "Male";
        break;
      case 2:
        playerGenderInput = "Female";
        break;
    }
    system("CLS");

    player tempPlayer = player(playerNameInput, passedFamilyName, passedRace, playerGenderInput, passedMotto, passedGold);
    allDecedents.push_back(tempPlayer);
  }

  void familyStories(){
  longBox box = longBox(1, 60);
   for(int i = 0 ; i < allDecedents.size(); i++){
     box.title(allDecedents[i].getName());
     if (allDecedents[i].getPlayerStatus()){
        box.content("You were killed by: " + allDecedents[i].getNpcKiller());
     } else{
       box.content("You lived till old age!");
     }
     box.content("You contributed " +  to_string(allDecedents[i].getGold()) + " gold to the family cause!");
     box.bottom();
     gap();
   }
  }

  // SETTERS
  void increaseFamilyGold(int passedGold){
    familyGold += passedGold;
  }

  void setFamilyPrestige(int passedPrestige){
    familyPrestige += passedPrestige;
  } 

  void setFamilyName(string passedFamilyName){
    familyName = passedFamilyName;
  }

  void setFamilyMotto(string passedFamilyMotto){
    motto = passedFamilyMotto;
  }

  // GETTERS
  player& getCurrentPlayer(){
    return allDecedents[currentPlayerIndex];
  }

  string getFamilyName(){
    return familyName;
  }

  string getFamilyMotto(){
    return motto;
  }

  string getFamilyRace(){
    return race; 
  }

  int getGold(){
    return familyGold;
  }
};

class event {
protected:
  events currentEvent;
  string introText;
  string preAmbleText;
  string problemText;
  string eventName;
  string eventFaction;
  string biome;
  string location;
  int speechCheck; 
  int intCheck;
  int dreadCheck;
  int repCheck;
  string npcName;
  string npcWeaponName;
  string eventRace;
  int eventID;
public:
 person eventNpc;
 event(int passedCode){
    // gets the event structure 
    eventID = passedCode;
    try{
      currentEvent = allEvents[eventID];
    } catch (out_of_range& e){
      cout << e.what() << endl;
    }

    eventName = currentEvent.name;
    biome = currentEvent.biomeType;
    location = currentEvent.location;
    eventFaction = currentEvent.faction;
    
    // Functions that create the event NPC based on the events faction
    int tempInt = randNumber(0, 10);
    if (eventFaction == "Default"){
      switch(tempInt){
      case 0: {
        eventNpc = human();
        npcWeaponName = eventNpc.personWeapon.getName();
        npcName = eventNpc.getName();
        eventRace = "Human";
        eventFaction = "Commoner";
        break;
      }
      case 1: {
        eventNpc = dwarf();
        npcWeaponName = eventNpc.personWeapon.getName();
        npcName = eventNpc.getName();
        eventRace = "Dwarf";
        eventFaction = "Commoner";
        break;
      }
      case 2: {
        eventNpc = elf();
        npcWeaponName = eventNpc.personWeapon.getName();
        npcName = eventNpc.getName();
        eventRace = "Elf";
        eventFaction = "Commoner";
        break;
      }
      case 3: {
        eventNpc = lizard();
        npcWeaponName = eventNpc.personWeapon.getName();
        npcName = eventNpc.getName();
        eventRace = "Lizard";
        eventFaction = "Imperial";
        break;
      }
      case 4: {
        eventNpc = cephalopod();
        npcWeaponName = eventNpc.personWeapon.getName();
        npcName = eventNpc.getName();
        eventRace = "Cephalopoid";
        eventFaction = "Imperial";
        break;
      }
      case 5: {
        eventNpc = vulture();
        npcWeaponName = eventNpc.personWeapon.getName();
        npcName = eventNpc.getName();
        eventRace = "Vulture";
        eventFaction = "Imperial";
        break;
      }
      case 6: {
        eventNpc = orc();
        npcWeaponName = eventNpc.personWeapon.getName();
        npcName = eventNpc.getName();
        eventRace = "Orc";
        eventFaction = "Bandit";
        break;
      }
      case 7: {
        eventNpc = goblin();
        npcWeaponName = eventNpc.personWeapon.getName();
        npcName = eventNpc.getName();
        eventRace = "Goblin";
        eventFaction = "Bandit";
        break;
      }
      case 8: {
        eventNpc = cat();
        npcWeaponName = eventNpc.personWeapon.getName();
        npcName = eventNpc.getName();
        eventRace = "Cat";
        eventFaction = "Merchant";
        break;
      }
      case 9: {
        eventNpc = dog();
        npcWeaponName = eventNpc.personWeapon.getName();
        npcName = eventNpc.getName();
        eventRace = "Dog";
        eventFaction = "Mercenary";
        break;
      }
    }
  } else if(eventFaction == "Bandit"){
      int tempInt = randNumber(0, 2);
      switch(tempInt){
        case 0: {
          eventNpc = orc();
          npcWeaponName = eventNpc.personWeapon.getName();
          npcName = eventNpc.getName();
          eventRace = "Orc";
        break;
      }
      case 1: {
          eventNpc = goblin();
          npcWeaponName = eventNpc.personWeapon.getName();
          npcName = eventNpc.getName();
          eventRace = "Goblin";
        break;
      }
    }
  } else if(eventFaction == "Merchant"){
      eventNpc = cat();
      npcWeaponName = eventNpc.personWeapon.getName();
      npcName = eventNpc.getName();
      eventRace = "Cat";
    } else if(eventFaction == "Mercenary"){
      eventNpc = dog();
      npcWeaponName = eventNpc.personWeapon.getName();
      npcName = eventNpc.getName();
      eventRace = "Dog";
    } else if(eventFaction == "Commoner"){
      int tempInt = randNumber(0, 3);
      switch(tempInt){
      case 0: {
        eventNpc = human();
        npcWeaponName = eventNpc.personWeapon.getName();
        npcName = eventNpc.getName();
        eventRace = "Human";
        break;
      }
      case 1: {
        eventNpc = dwarf();
        npcWeaponName = eventNpc.personWeapon.getName();
        npcName = eventNpc.getName();
        eventRace = "Dwarf";
        break;
      }
      case 2: {
        eventNpc = elf();
        npcWeaponName = eventNpc.personWeapon.getName();
        npcName = eventNpc.getName();
        eventRace = "Elf";
        break;
      }
      }
    } else if(eventFaction == "Imperial"){
      int tempInt = randNumber(0, 3);
      switch(tempInt){
      case 0: {
        eventNpc = lizard();
        npcWeaponName = eventNpc.personWeapon.getName();
        npcName = eventNpc.getName();
        eventRace = "Lizard";
        break;
      }
      case 1: {
        eventNpc = cephalopod();
        npcWeaponName = eventNpc.personWeapon.getName();
        npcName = eventNpc.getName();
        eventRace = "Cephalopoid";
        break;
      }
      case 2: {
        eventNpc = vulture();
        npcWeaponName = eventNpc.personWeapon.getName();
        npcName = eventNpc.getName();
        eventRace = "Vulture";
        break;
      }
      }
    }

    if (this->biome == "Underworld"){
      introText = processText(allUnderIntro[randNumber(0, allUnderIntro.size())]);
    } else if(this->biome == "Meadows"){
      introText = processText(allMeadowsIntro[randNumber(0, allMeadowsIntro.size())]);
    }

    // sets the strings for event 

    if (this->location == "bar"){
      preAmbleText = processText(allBarPreamble[randNumber(0, allBarPreamble.size())]);
    }
    if (this->location == "house"){
      preAmbleText = processText(allHousePreamble[randNumber(0, allHousePreamble.size())]);
    }
    if (this->location == "street"){
      preAmbleText = processText(allStreetPreamble[randNumber(0, allStreetPreamble.size())]);
    }
    //preAmbleText = processText(currentEvent.preAmble[randNumber(0, 2)]);
    problemText = processText(currentEvent.problem[randNumber(0, 3)]);

    speechCheck = currentEvent.speech;
    intCheck = currentEvent.intelligence;
    dreadCheck = currentEvent.dread;
    repCheck = currentEvent.rep;
  }
  
  int diceRoll(string name, int mod){ // Dice roll function that rolls a D20
    int roll = ((randNumber(0, 20)) + 1); // Grabs a number between 0 and 19
    int number = roll + mod; 
    string op = (mod > 0) ? "+": "";
    if (mod != 0){
      textBox(1, name + " rolled " + to_string(number) + " (" + to_string(roll) + op + to_string(mod) + ")"); // displays who rolled, and the score they got
    } else {
      textBox(1, name + " rolled " + to_string(number));
    }
    return number; // returns the dice roll
  }

  int diceRoll(string name){ // Dice roll function that rolls a D20
    int number = ((randNumber(0, 20)) + 1); // Grabs a number between 0 and 19
    textBox(1, name + " rolled " + to_string(number));
    return number; // returns the dice roll
  }

  int damageCalc(int diceRoll, int weaponDamage){ // used to calculate the damage a player or NPC will do
    int dmg;
    if(diceRoll <= 1){ // if dice roll is one, the roller will hurt themselves
      dmg = -1;
    }
    if(diceRoll >= 2 && diceRoll <= 4){ // the roller misses their attack
      dmg = 0;
    }
    if(diceRoll >= 5 && diceRoll <= 10){ // the roller deals just the damage of their weapon
      dmg = weaponDamage;
    }
    if(diceRoll >= 11 && diceRoll <= 16){ // the roller deals their weapon damage +1
      dmg = weaponDamage + 1;
    }
    if(diceRoll >= 17 && diceRoll <= 19){ // the roller deals their weapon damage +2
      dmg = weaponDamage + 2;
    }
    if(diceRoll >= 20){ // CRITICAL HIT! The roller deals their weapon damage +4
      dmg = weaponDamage + 4;
    }
    return dmg;
  }

  string processText(string passedString){
    findAndReplaceAll(passedString, "<npcName>", npcName);
    return passedString;
  }


  int fightLoop(player& passedPlayer, person& eventNpc){
    longBox box = longBox(1, 30);
    int firstLoop = 0;
    do { 
      system("CLS");
      textBox(2, this->eventName, 60);
      passedPlayer.header();
      eventNpc.header();
      if(firstLoop == 0){
        textFunc("'" + passedPlayer.getMotto() + "' you say.");
        textFunc("'" + eventNpc.getMotto() + "' " + eventNpc.getName() + " replies.");
        firstLoop++;
      }
      box.title("Options");
      box.content("(1) Attack");
      box.content("(2) Heal");
      box.content("(3) Change weapon");
      box.bottom();
      int selection;
      selection = numInput(1, 3);
      switch(selection){
        case 2:
          passedPlayer.consumeHealItem();
          break;
        case 3:
          passedPlayer.getInventory().changeCurrentWeapon();
          break;
      }
      system("CLS");
      textBox(2, this->eventName, 60);
      passedPlayer.header();
      eventNpc.header();
      gap();
      int playerDamage = damageCalc(diceRoll("Player", (passedPlayer.getStrength() - 10)), passedPlayer.getInventory().getCurrentWeapon().getDamage()); // Generates the damage the player will do
      if (playerDamage <= -1){
        textFunc(passedPlayer.getName() + " hurt themselves trying to attack!");
        passedPlayer.decreaseHealth(1, passedPlayer.getName());
      }else if (playerDamage == 0){
        textFunc(passedPlayer.getName() + " misses!");
      }else{
        textFunc(passedPlayer.getName() + " " + passedPlayer.getInventory().getCurrentWeapon().getItemFromVector() + " " + eventNpc.getName() + " with their " + passedPlayer.getInventory().getCurrentWeapon().getRarity() + " " +passedPlayer.getInventory().getCurrentWeapon().getName() + " dealing " + to_string(playerDamage) + " damage");
        eventNpc.decreaseHealth(playerDamage);    
      }

      pressKey();
      if(eventNpc.getHealth() > 0){
        system("CLS");
        textBox(2, this->eventName, 60);
        passedPlayer.header();
        eventNpc.header();
        gap();
        int npcDamage = damageCalc(diceRoll("NPC"), eventNpc.personWeapon.getDamage());
        if (npcDamage <= -1){
          textFunc(eventNpc.getName() + " hurt themselves trying to attack!");
          eventNpc.decreaseHealth(1);
        } else if (npcDamage == 0){
          textFunc(eventNpc.getName() + " misses!");
        } else{
          textFunc(eventNpc.getName() + " " + eventNpc.personWeapon.getItemFromVector() + " " + passedPlayer.getName() + " with their " + eventNpc.personWeapon.getRarity() + " " + eventNpc.personWeapon.getName() + " dealing " + to_string(npcDamage) + " damage");
          passedPlayer.decreaseHealth(npcDamage, eventNpc.getName());
        }
        pressKey();

      } 
    }while(eventNpc.getHealth() > 0 && passedPlayer.getHealth() > 0);
    if(passedPlayer.getHealth() <= 0){
      textBox(2, passedPlayer.getName() + " loses!");
      return 0;
    }
    if(eventNpc.getHealth() <= 0){
      textBox(2, npcName + " has died!");
      return 1;
    }
    return 0;
  }


  void changeRep(player& passedPlayer, string repPassed){
    if(eventFaction == "Commoner"){
      passedPlayer.removeRep(eventFaction);
      passedPlayer.addRep("Bandit");
    } else if(eventFaction == "Bandit"){
      passedPlayer.removeRep(eventFaction);
      passedPlayer.addRep("Commoner");
    } else if (eventFaction == "Imperial"){
      passedPlayer.addRep("Bandit");
      passedPlayer.addRep("Commoner");
      passedPlayer.removeRep("Imperial");
    } else if(eventFaction == "Mercenary"){
      passedPlayer.addRep("Mercenary");
      passedPlayer.addRep("Imperial");
    } else if(eventFaction == "Merchant"){
      passedPlayer.removeRep(eventFaction);
    }    
  }

  void startEvent(player& passedPlayer, person& eventNpc){
    system("CLS");
    longBox box = longBox (2, 60);
    textBox(2, this->eventName, 60);
    textFunc(introText);
    gap();
    textFunc(preAmbleText);
    gap();
    textFunc(problemText);
    //cout << introText << endl; 
    //cout << preAmbleText << endl;
    //cout << problemText << endl;
    box.title("Actions");
    box.content("(1) Attack");
    box.content("(2) Persuasion");
    box.content("(3) Dread");
    box.content("(4) Intelligence");
    box.content("(5) Play Guitar");
    box.bottom();

    // If the player has a better reputation with the events faction, their dread and speech rolls will be increased
    // however, if the player has a negative reputation, their rolls are decreased
    int repMod;
    if(passedPlayer.getRep(eventFaction) >= 8 && passedPlayer.getRep(eventFaction) <= 12){ // rep between these ranges will increase roll score by 1
      repMod = 1;
    } else if (passedPlayer.getRep(eventFaction) >= 13 && passedPlayer.getRep(eventFaction) >= 17){ // rep between these ranges will increase roll score by 2
      repMod = 2;
    } else if (passedPlayer.getRep(eventFaction) >= 18){ // rep above 20 will increase roll score by 3
      repMod = 3;
    } else if (passedPlayer.getRep(eventFaction) <= 0 && passedPlayer.getRep(eventFaction) >= -4 ){
      repMod = -1;
    } else if (passedPlayer.getRep(eventFaction) <= -5 && passedPlayer.getRep(eventFaction) >= -10 ){
      repMod = -2;
    } else if (passedPlayer.getRep(eventFaction) <= -11){
      repMod = -3;
    } else{ // standard reputation means no increase
      repMod = 0; 
    }

    int tempConsoleInput;
    tempConsoleInput = numInput(1, 5);
    system("CLS");
    textBox(2, this->eventName, 60);
    switch(tempConsoleInput){
      case 1: // Returns Boolea 
        if (fightLoop(passedPlayer, eventNpc)) {
          system("CLS");
          textBox(2, this->eventName, 60);
          passedPlayer.header();
          eventNpc.header();
          textBox(1, "Attack success");
          textFunc(processText(currentEvent.attackSuccess));
          passedPlayer.removeRep(eventFaction);
          this->eventSuccess(passedPlayer);
        } else {
          system("CLS");
          textBox(2, this->eventName, 60);
          passedPlayer.header();
          eventNpc.header();
          textBox(1, "Attack fail");
          textFunc(processText(currentEvent.attackFailure));
        }
      break;
      case 2:
        if (diceRoll("Player", ((passedPlayer.getSpeech() - 10)+repMod)) >= speechCheck) { // speech check
          system("CLS");
          textBox(2, this->eventName, 60);
          textBox(1, "Persuasion Success");
          textFunc(processText(currentEvent.persuasionSuccess));
          passedPlayer.addRep(eventFaction);
          this->eventSuccess(passedPlayer);
        } else{
          system("CLS");
          textBox(2, this->eventName, 60);
          textBox(1, "Persuasion Fail");
          textFunc(processText(currentEvent.persuasionFail));
          passedPlayer.removeRep(eventFaction);
          this->eventFail(passedPlayer);
        }
      break;
      case 3:
        if(diceRoll("Player", ((passedPlayer.getDread() - 10)+repMod)) >= dreadCheck){ // dread check
          system("CLS");
          textBox(2, this->eventName, 60);
          textBox(1, "Dread Success");
          textFunc(processText(currentEvent.dreadSuccess));
          passedPlayer.addRep(eventFaction);
          this->eventSuccess(passedPlayer);
        } else{
          system("CLS");
          textBox(2, this->eventName, 60);
          textBox(1,"Dread Fail");
          textFunc(processText(currentEvent.dreadFail));
          passedPlayer.removeRep(eventFaction);
          this->eventFail(passedPlayer);
        }
      break;
      case 4:
        if(diceRoll("Player", (passedPlayer.getIntelligence() - 10) + repMod) >= intCheck){ // intelligence check
          system("CLS");
          textBox(2, this->eventName, 60);
          textBox(1, "Intelligence Success");
          textFunc(processText(currentEvent.intelligenceSuccess));
          passedPlayer.addRep(eventFaction);
          this->eventSuccess(passedPlayer);
        } else{
          system("CLS");
          textBox(2, this->eventName, 60);
          textBox(1, "Intelligence Fail");
          textFunc(processText(currentEvent.intelligenceFail));
          passedPlayer.removeRep(eventFaction);
          this->eventFail(passedPlayer);
        }
      break;
      case 5:
        if(diceRoll("Player", 0) >= 11){ // guitar is a skill-less roll, success is a 50/50, but no reputation will be lost if you fail. This option gives less risk and less reward.
          system("CLS");
          textBox(2, this->eventName, 60);
          textBox(1, "Guitar Success");
          textFunc(processText(currentEvent.guitarSuccess));
          this->eventSuccess(passedPlayer);
        } else{
          system("CLS");
          textBox(2, this->eventName, 60);
          textBox(1, "Guitar Fail");
          textFunc(processText(currentEvent.guitarFail));
          this->eventFail(passedPlayer);
        }
      break;
    }
  }

  void eventSuccess(player& passedPlayer){
    int randNum = randNumber(0, 4);
    switch (randNum){
    case 0:{
      int tempGold = randNumber(20, 80);
      textBox(1, "You Gain: " + to_string(tempGold) + " gold");
      passedPlayer.addGold(tempGold);
      break;
    }
    case 1: // Gives Player Item
      passedPlayer.getInventory().rndQuantityItem();
      break;
    case 2:{
      textBox(1, "Your good fortune applies to your health as well");
      int rand = randNumber(5, 10);
      passedPlayer.increaseHealth(rand);
      textBox(1, "You heal " + to_string(rand) + " HP");
      break;      
    }
    case 3: 
      textBox(1,"You found a cool new weapon");
      passedPlayer.getInventory().generateNewWeapon();
      break;
    }
  }

  void eventFail(player& passedPlayer){
    int randNum = randNumber(0, 2);

    switch (randNum){
    case 0:{
      int tempGold = randNumber(10, 40);
      textBox(1, "You lose " + to_string(tempGold) + " gold");
      passedPlayer.removeGold(tempGold);
      break;
    }
    case 1: // Gives Player Item
      int rand = randNumber(2, 5);
      passedPlayer.decreaseHealth(randNumber(2, 5), this->npcName);
      textBox(1, "Your poor fortune applies to your health as well");
      textBox(1, "You lose " + to_string(rand) + " HP");
      break;
    }
  }
};

class store{ // Event that lets player buy items
  private:
    cat catshier = cat();
    int gold;
    int selection;

    // instantiation of placeholder items, these will eventually be randomly generated

    healItem item1 = healItem();
    healItem item2 = healItem();
    healItem item3 = healItem();
    relic item4 = relic();
    vector<healItem> stock; // adds the items to the stores stock vector


  public:

  int discountCheck(int cost, int rep){
    if(rep >= 10 && rep <= 19){ // If the player has this range of merchant rep, they receive an approximate 10% discount
        cost = cost - (cost / 10);
      }else if(rep >= 20){ // If the player has above this level of merchant rep, they receive an approximate 20% discount
        cost = cost - (cost / 20);
      } else if(rep <= 0){ // If the player has below this level of merchant rep, they pay an approximate extra 10% discount
        cost = cost + (cost / 10);
      }
    return cost;
  }

  void catAscii(int number){
    if(number == 0){
              cout<<R"( 
  ____________________________
 |                   |____|   |
 |      |\___/|     |      |  |
 |     / _   ^ \    | OPEN |  |
 |    (  O>o<O  )   |______|  |
 |     \_  V  _/              |
 |     __)   (__              |
 |    /  \___/  \             |
 |___/__|_____|__\____________|
 |____________________________|

     )"<<endl;

    }
    if(number == 1){
              cout<<R"( 
  ____________________________
 |                   |____|   |
 |      |\___/|     |      |  |
 |     / _   _ \    | OPEN |  |
 |    (  O>o<O  )   |______|  |
 |     \_  ^  _/              |
 |     __)   (__              |
 |    /  \___/  \             |
 |___/__|_____|__\____________|
 |____________________________|

     )"<<endl;
    }

    if(number == 2){
              cout<<R"( 
  ____________________________
 |                   |____|   |
 |      |\___/|     |      |  |
 |     / _   ~ \    | OPEN |  |
 |    (  O>o<O  )   |______|  |
 |     \_  ^  _/              |
 |     __)   (__              |
 |    /  \___/  \             |
 |___/__|_____|__\____________|
 |____________________________|

     )"<<endl;
    }

    if(number == 3){
              cout<<R"( 
  ____________________________
 |                   |____|   |
 |      |\___/|     |      |  |
 |     / ^   ^ \    | OPEN |  |
 |    (  O>o<O  )   |______|  |
 |     \_  V  _/              |
 |     __)   (__              |
 |    /  \___/  \             |
 |___/__|_____|__\____________|
 |____________________________|

     )"<<endl;

    }
  }

  store(player& passedPlayer){
    system("CLS");
    int owner = randNumber(0,4);
    gold = passedPlayer.getGold(); //gets the players gold amount

    // adds the items to the stores stock vector
    stock.push_back(item1);
    stock.push_back(item2);
    stock.push_back(item3);
    textBox(2, catshier.getName() + "'s Store");
    catAscii(owner);
    textFunc("You enter the store. " + catshier.getName() +" greets you.");
    textFunc("'Can I interest you in anything?' they say.");
    gap();
    textBox(1, "(1) Buy Items ");
    textBox(1, "(2) Sell items");
    int choice;
    choice = numInput(1, 2);
    switch(choice){
      case 1:
      {
      system("CLS");
      textBox(2, catshier.getName() + "'s Store");
      catAscii(owner);
      textBox(1, "Your gold: " + to_string(gold));
      longBox box = longBox(2, 50);
      box.title("FOR SALE");
      for(vector<healItem>::size_type i=0; i != stock.size(); i++){
        box.content("(" + to_string(i+1) + ")");
        box.content("Name: " + stock[i].getName());
        box.content("Info: " + stock[i].getDesc());
        box.content("Cost: " + to_string(discountCheck(stock[i].getValue(),passedPlayer.getRep("Merchant"))) + " gold");
        box.separator();
      }
      box.content("(4)");
      box.content("Name: " + item4.getName());
      box.content("Info: " + item4.getDesc());
      box.content("Cost: " + to_string(discountCheck(item4.getValue(),passedPlayer.getRep("Merchant"))) + " gold");
      box.bottom();
      gap();
      textBox(1, "Select item number or type 0 to leave");
      selection = numInput(0, 4);
      selection --;
      if(selection >= 0 && selection < 3){
        if(passedPlayer.getGold() >= discountCheck(stock[selection].getValue(),passedPlayer.getRep("Merchant"))){ //checks the player can actually purchase the item
          passedPlayer.getInventory().getQuantItems().addHealItem(stock[selection]); // adds the item to the players inventory
          passedPlayer.removeGold((discountCheck(stock[selection].getValue(),passedPlayer.getRep("Merchant")))); // Takes the cost of the item away from the players gold
          passedPlayer.addRep("Merchant");
          textBox(1, stock[selection].getName() + " added to inventory"); 
          pressKey();
        } else{
          textBox(1,"Not enough gold");
          pressKey();
        }
        }else if (selection == 3){
          if(passedPlayer.getGold() >= discountCheck(item4.getValue(),passedPlayer.getRep("Merchant"))){ //checks the player can actually purchase the item
          passedPlayer.getInventory().addRelic(item4); // adds the item to the players inventory
          passedPlayer.addRelicMod(item4);
          passedPlayer.removeGold((discountCheck(item4.getValue(),passedPlayer.getRep("Merchant")))); // Takes the cost of the item away from the players gold
          passedPlayer.addRep("Merchant");
          textBox(1, item4.getName() + " added to inventory"); 
          pressKey();
        }else{
          textBox(1,"Not enough gold");
          pressKey();
        }
      }
      break;
      }

      case 2:
      {
      system("CLS");
      longBox box = longBox(2, 50);
      textBox(2, catshier.getName() + "'s Store");
      catAscii(owner);
      textBox(1, "Your gold: " + to_string(gold));
      box.title("Your Inventory");
      if(passedPlayer.getInventory().getQuantItems().getRichItemVector().size() == 0){
        box.content("Empty");
      }
      for(vector<richItem>::size_type i=0; i != passedPlayer.getInventory().getQuantItems().getRichItemVector().size(); i++){
        box.content("(" + to_string(i+1) + ")");
        box.content("Name: " + passedPlayer.getInventory().getQuantItems().getRichItemVector()[i].getName());
        box.content("Info: " + passedPlayer.getInventory().getQuantItems().getRichItemVector()[i].getDesc());
        box.content("Cost: " + to_string(passedPlayer.getInventory().getQuantItems().getRichItemVector()[i].getValue()) + " gold");
        if(i < passedPlayer.getInventory().getQuantItems().getRichItemVector().size() -1){
          box.separator();
        }
      }
      box.bottom();
      gap();
      textBox(1, "Select item number or type 0 to leave");
      selection = numInput(0, passedPlayer.getInventory().getQuantItems().getRichItemVector().size());
      selection --;
      if(selection < passedPlayer.getInventory().getQuantItems().getRichItemVector().size()){
        passedPlayer.addGold(passedPlayer.getInventory().getQuantItems().getRichItemVector()[selection].getValue());
        textBox(1, passedPlayer.getInventory().getQuantItems().getRichItemVector()[selection].getName() + " sold"); 
        passedPlayer.getInventory().getQuantItems().removeRichItem(selection); // adds the item to the players inventory
        pressKey();
      }
      break;
      }

      default:
      break;
    }
  }
  

};

class node{
public:
  // Data == Location distribution
  int data = 0;
  event* nodeEvent;
  node* leftNode;
  node* rightNode;

  node(int passData, int eventCode) {
    data = passData;
    rightNode = NULL;
    leftNode = NULL;
    nodeEvent = new event(eventCode);
  }

  event* getNodeEvent(){
    return nodeEvent;
  }

  void updateNodeLeft(node* passNode){
    leftNode = passNode;
  }

  void updateNodeRight(node* passNode){
    rightNode = passNode;
  }
  
  void delNodeLeft(){
    leftNode = NULL;
    rightNode = NULL;
  }
};

class binTree{
private:
  node* curretNode = NULL;
  node* rootNode = NULL;
  int sizeOfTree;

  bool findNode(node* passedNode, int passedData){
    if(passedNode == NULL){
      return false;
    } else if (passedNode->data == passedData){
      return true; 
    } else if (passedNode->data > passedData){
      return findNode(passedNode->leftNode, passedData);
    } else{
      return findNode(passedNode->rightNode, passedData);
    } 
  }

  void printBT(string prefix, node* passedNode, bool isLeft){
    if (passedNode != nullptr){
      cout << prefix;
      cout << (isLeft ? "L--" : "R--");
      if(passedNode == curretNode){
        cout << "C" << endl;
      } else{
        cout << passedNode->data << endl;
      }
      // enter the next tree level - left and right branch
      printBT(prefix + (isLeft ? "|   " : "    "), passedNode->leftNode, true);
      printBT(prefix + (isLeft ? "|   " : "    "), passedNode->rightNode, false);
    }
  }
public:
  binTree(const int passedSize){
    sizeOfTree = passedSize;

    int tempArrayOfIndex[100];
    for (int i = 0; i < (passedSize); i++){
      tempArrayOfIndex[i] = i;
    } 

    for (int i = 0; i < (passedSize); i++){
      int genNumber = (randNumber(0, passedSize));
      int tempHolder = tempArrayOfIndex[i];
      tempArrayOfIndex[i] = tempArrayOfIndex[genNumber];
      tempArrayOfIndex[genNumber] = tempHolder;
    } 

    rootNode = new node((randNumber(0, passedSize)) + 1, randNumber(0, allEvents.size())); // change this to rnd number
    
    try{
      for (size_t i = 0; i < passedSize -1; i++){
        this->generate_node(randNumber(0, allEvents.size()) + 1, rootNode, tempArrayOfIndex[i]); // change this to rnd number
      }
    } catch (out_of_range& e){
      cout << e.what() << endl;
    }
    curretNode = rootNode; 
  }

  void generate_node(int passedKey, node* nodePassed, int eventCode){
    if (passedKey < nodePassed->data){
      if (nodePassed->leftNode !=NULL){
        generate_node(passedKey, nodePassed->leftNode, eventCode);
      }else{
        nodePassed->leftNode = new node(passedKey, eventCode);
      }
    } else if (passedKey >= nodePassed->data){
      if(nodePassed->rightNode != NULL){
        generate_node(passedKey, nodePassed->rightNode, eventCode);
      } else{
        nodePassed->rightNode = new node(passedKey, eventCode);
      }
    }
  }

  bool moveCurrentNode(bool left){
    if((left == true) && (curretNode->leftNode != NULL)){
      cout << "You Moved left" << endl;
      curretNode = curretNode->leftNode;
      return true;
    } else if((left == false) && (curretNode->rightNode != NULL)){
      cout << "You Moved Right" << endl;
      curretNode = curretNode->rightNode; 
      return true;
    } else{
      cout << "Invalid position, please reinput" << endl;
      pressKey();
      return false;
    }
  }

  bool lastLevel(node* passedNode){
    if (passedNode->rightNode == NULL && passedNode->leftNode ==  NULL){
      return true;
    } else{
      return false;
    }
  }
    
  bool search(int passedData){
    return findNode(this->rootNode, passedData);
  }

  void printBT(){
    printBT("",rootNode, false);
  }

  node* getCurrentNode(){
    return this->curretNode; 
  }
};

class map {
private:
  binTree currentMap = binTree(allEvents.size());
  int sizeOfMap;
public:
  map(int passedSize) {
    sizeOfMap = passedSize;
    binTree currentMap = binTree(sizeOfMap);
  }

  void regenerateMap(){
    currentMap = binTree(sizeOfMap);
  } 

  bool changeLocation(bool leftMove){
    return currentMap.moveCurrentNode(leftMove);
  }

  bool checkIfEndLevel(){
    return this->currentMap.lastLevel(currentMap.getCurrentNode());
  }

  node* getCurrentLocation(){
    return currentMap.getCurrentNode(); 
  }

  binTree getBinTree(){
    return currentMap;
  }
};

void raceInfo(){
  bool breakFree = false;
  while(!breakFree){
    system("CLS");
    textBox(2, "Please select a race");
    textBox(1, "(1)  Orc", 20);
    textBox(1, "(2)  Elf", 20);
    textBox(1, "(3)  Dwarf", 20);
    textBox(1, "(4)  Human", 20);
    textBox(1, "(5)  Goblin", 20);
    textBox(1, "(6)  Cat", 20);
    textBox(1, "(7)  Dog", 20);
    textBox(1, "(8)  Lizard", 20);
    textBox(1, "(9)  Vulture", 20);
    textBox(1, "(10) Cephalopoid", 20);
    textBox(1, "(11) Back", 20);
    int selection;
    selection = numInput(1, 11);
    switch(selection){
      case 1:
      {
        orc temp = orc();
        temp.personDetail();
        pressKey();
        break;
      }
      case 2:
      {
        elf temp = elf();
        temp.personDetail();
        pressKey();
        break;
      }
      case 3:
      {
        dwarf temp = dwarf();
        temp.personDetail();
        pressKey();
        break;
      }
      case 4:
      {
        human temp = human();
        temp.personDetail();
        pressKey();
        break;
      }
      case 5:
      {
        goblin temp = goblin();
        temp.personDetail();
        pressKey();
        break;
      }
      case 6:
      {
        cat temp = cat();
        temp.personDetail();
        pressKey();
        break;
      }
      case 7:
      {
        dog temp = dog();
        temp.personDetail();
        pressKey();
        break;
      }
      case 8:
      {
        lizard temp = lizard();
        temp.personDetail();
        pressKey();
        break;
      }
      case 9:
      {
        vulture temp = vulture();
        temp.personDetail();
        pressKey();
        break;
      }
      case 10:
      {
        cephalopod temp = cephalopod();
        temp.personDetail();
        pressKey();
        break;
      }
      case 11:
        breakFree = true;
        break;
    }
  }
}

void about(){
    bool breakFree = false;
    while (breakFree != true){
      system("CLS");
      longBox menu = longBox(2, 32);
      menu.title("About Section");
      menu.content("");
      menu.content("(1) Race Info");
      menu.content("(2) How to Play");
      menu.content("(3) Main Menu");
      menu.content("");
      menu.bottom();
      int eventLoopInput;
      eventLoopInput = numInput(1, 3);
      switch (eventLoopInput){
      case 1:
        raceInfo();
        break;
      case 2:
      {
        system("CLS");
        textBox(2, "Inheritance Quest");
        textFunc("Inheritance quest is a rogue-like text based RPG. In it, you play as a member of your family blood line. The objective is simple, stay alive and earn as much gold as you can for your family.");
        gap();

        textBox(2, "Map");
        textFunc("When playing, you will navigate a map of events. A choice will be given to you each time you move forwards, 'Do you wish to move left or right?'. Whichever option you choose will take you to the next event.");
        gap();

        textBox(2, "Events");
        textFunc("Events are generated randomly, and it is your choice as the player on how you will deal with each one. When starting an event, you will be shown 5 options:");
        longBox box = longBox (2, 60);
        box.title("Actions");
        box.content("(1) Attack");
        box.content("(2) Persuasion");
        box.content("(3) Dread");
        box.content("(4) Intelligence");
        box.content("(5) Play Guitar");
        box.bottom();
        textFunc("These options, whichever you select, will lead to different outcomes. The result of your success is calculated using a dice roll and your player stats as a modifier.");
        textFunc("Once you have chosen an option, the event will continue, and you will be rewarded or punished accordingly.");
        gap();

        textBox(2, "Weapons");
        textFunc("Weapons are used during the attack sequence of an event. Each new player will start with 2 random weapons. There is a chance that when you complete an event, you will find another weapon.");
        textFunc("Each weapon varies in rarity. The rarer the weapon, the more damage it will do, so be sure to look out for those.");
        gap();

        textBox(2, "Items");
        textFunc("Items can come in 3 varities: Healing items, rich items, and relics.");
        textFunc("Healing items are used to heal the player for any lost health. Each healing item can vary in the amount it will heal you. These can either be found during an event, or bought from the store.");
        textFunc("Rich items can be sold at the store in exchange for gold. These items can only be found during events.");
        textFunc("Relics increase the players base stats, making modifiers on dice rolls higher. These can only be bought from the store.");
        gap();

        textBox(2, "Store");
        textFunc("The store can be accessed from the main menu. Here you can spend the gold that your family has earnt on items and upgrades. Each store you visit will have 3 healing items and a relic to choose from.");
        textFunc("If you aren't in the market for any of these items however, you can sell any rich items that you have found on your travels.");
        textFunc("If your merchant reputation is high enough, you may even qualify for a discount on purchasable items.");
        gap();

        textBox(2, "Reputation");
        textFunc("If you upset an NPC of a certain faction, you will lose reputation within that faction. However, if you leave them with a favourable opinion of you, then your faction reputation will increase.");
        textFunc("If your faction repuation is too low, then your dice rolls during an event with that faction will be decreased. The worse your reputation is, the lower your roll scores will be. The opposite applies for a high reputation.");
        gap();

        textBox(2, "Death and Retirement");
        textFunc("Each time your player dies or retires, you will start again with a new player within the same family. You will inherit the family gold, however, all items, weapons, and upgrades will be lost with the last player.");
        textFunc("You will find that if you reach the end of the map, your player will automatically retire, and you will begin again.");
        pressKey();
        break;
      }

      case 3:
        breakFree = true;
        break;
      }
    }
}



int main(){

  intro();
  system("CLS");
  textBox(2, "Please enter your family name");
  string familyNameInput;
  familyNameInput = lenCheck();
  gap();

  textBox(2, "Please enter your family's motto");
  string familyMottoInput;
  familyMottoInput = lenCheck();
  gap();

  textBox(2, "Please select a race");
  textBox(1, "(1)  Orc", 20);
  textBox(1, "(2)  Elf", 20);
  textBox(1, "(3)  Dwarf", 20);
  textBox(1, "(4)  Human", 20);
  textBox(1, "(5)  Goblin", 20);
  textBox(1, "(6)  Cat", 20);
  textBox(1, "(7)  Dog", 20);
  textBox(1, "(8)  Lizard", 20);
  textBox(1, "(9)  Vulture", 20);
  textBox(1, "(10) Cephalopoid", 20);
  int selection;
  string familyRaceInput;
  selection = numInput(1, 10);
  switch(selection){
    case 1:
      familyRaceInput = "Orc";
      break;
    case 2:
      familyRaceInput = "Elf";
      break;
    case 3:
      familyRaceInput = "Dwarf";
      break;
    case 4:
      familyRaceInput = "Human";
      break;
    case 5:
      familyRaceInput = "Goblin";
      break;
    case 6:
      familyRaceInput = "Cat";
      break;
    case 7:
      familyRaceInput = "Dog";
      break;
    case 8:
      familyRaceInput = "Lizard";
      break;
    case 9:
      familyRaceInput = "Vulture";
      break;
    case 10:
      familyRaceInput = "Cephalopoid";
      break;
  }
  gap();

  family playerFamily = family(familyNameInput, familyMottoInput, familyRaceInput);
  playerFamily.generateNewPlayer(playerFamily.getFamilyName(), playerFamily.getFamilyMotto(), playerFamily.getFamilyRace(), playerFamily.getGold());
  
  playerFamily.getCurrentPlayer().getInventory().rndQuantityGroupItem(1);
  bool pressedExit = false;

  do{  
    map gameMap = map(allEvents.size());   
    bool isEmpty = false;
    while (isEmpty != true){
      bool breakFree = false;
      while (breakFree != true){
        system("CLS");
        playerFamily.getCurrentPlayer().header();
        longBox menu = longBox(2, 32);
        menu.title("Main Menu");
        menu.content("");
        menu.content("(1) Continue to Next Event");
        menu.content("(2) Visit Shop");
        menu.content("(3) Inventory");
        menu.content("(4) Select Weapon");
        menu.content("(5) Heal Player");
        menu.content("(6) Retire");
        menu.content("(7) Exit Game");
        menu.content("(8) About");
        menu.content("");
        menu.bottom();
        int eventLoopInput;
        eventLoopInput = numInput(1, 8);
        switch (eventLoopInput){
        case 1:
          breakFree = true;
          break;
        case 2:
          store(playerFamily.getCurrentPlayer());
          break;
        case 3:
          playerFamily.getCurrentPlayer().displayPlayerInfo();
          pressKey();
          break;
        case 4:
          system("CLS");
          playerFamily.getCurrentPlayer().header();
          playerFamily.getCurrentPlayer().getInventory().changeCurrentWeapon();
          break;
        case 5:
          system("CLS");
          playerFamily.getCurrentPlayer().header();
          playerFamily.getCurrentPlayer().consumeHealItem();
          break;
        case 6: 
          system("CLS");
          textFunc("You feel like the road ahead is too far..");
          textFunc("It's consquences too great..");
          textFunc("Throwing your weapon down, you give in, and go home.");
          pressKey();
          system("CLS");
          playerFamily.increaseFamilyGold(playerFamily.getCurrentPlayer().getGold());
          playerFamily.getCurrentPlayer().setRetired(true);
          breakFree = true;
          break;
        case 7:
          playerFamily.familyStories();
          pressKey();
          return 1;
          break;
        case 8:
          about();
          break;  
        }    
         
      }
      
      if (playerFamily.getCurrentPlayer().getRetired() == true){
        textFunc("The family grows and a new adventruer take up the helm");
        pressKey();
        system("CLS");
        playerFamily.increaseFamilyGold(playerFamily.getCurrentPlayer().getGold());
        playerFamily.generateNewPlayer(playerFamily.getFamilyName(), playerFamily.getFamilyMotto(), playerFamily.getFamilyRace(), playerFamily.getGold());
        map gameMap = map(allEvents.size());   
      }  
  
      if(gameMap.checkIfEndLevel()){
        textFunc("You have reached the end of your path");
        break;
      }

      system("CLS"); 
      gameMap.getBinTree().printBT();
      longBox box = longBox(1, 40);
      box.title("Do you wish to move left or right?");
      box.content("(1) Left");
      box.content("(2) Right");
      box.bottom();
      int playerChoiceLeftOrRight;
      playerChoiceLeftOrRight = numInput(1,2);

      if (playerChoiceLeftOrRight == 1){
        if(gameMap.changeLocation(true)){ // if you want to go left put true
          gameMap.getCurrentLocation()->getNodeEvent()->startEvent(playerFamily.getCurrentPlayer(), gameMap.getCurrentLocation()->getNodeEvent()->eventNpc );
          pressKey();
          isEmpty = gameMap.checkIfEndLevel();
        }; 
      } else{
        if(gameMap.changeLocation(false)){ // if you want to go right put false
          gameMap.getCurrentLocation()->getNodeEvent()->startEvent(playerFamily.getCurrentPlayer(), gameMap.getCurrentLocation()->getNodeEvent()->eventNpc);
          pressKey();
          isEmpty = gameMap.checkIfEndLevel();
        } 
      }

      if (isEmpty == true){
        system("CLS");
        textFunc("You reach the end of known world");
        textFunc("Turning back you face the path of your travels");
        textFunc("It is time to go home.");
        pressKey();
        system("CLS");
        playerFamily.increaseFamilyGold(playerFamily.getCurrentPlayer().getGold());
        playerFamily.generateNewPlayer(playerFamily.getFamilyName(), playerFamily.getFamilyMotto(), playerFamily.getFamilyRace(), playerFamily.getGold());
      }

      if (playerFamily.getCurrentPlayer().getPlayerStatus()){
        system("CLS");
        textFunc("The world fade around you...");
        textFunc("...You feel your last breath");
        textFunc("But new life begins to stir...");
        textFunc("your child starts anew");
        pressKey();
        system("CLS");
        playerFamily.increaseFamilyGold(playerFamily.getCurrentPlayer().getGold());
        playerFamily.generateNewPlayer(playerFamily.getFamilyName(), playerFamily.getFamilyMotto(), playerFamily.getFamilyRace(), playerFamily.getGold());
      }
    }
  } while (pressedExit != true);
  return 1;
}
