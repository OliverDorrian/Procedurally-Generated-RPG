#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <cstring>  
#include <string>
#include <random>
#include <stdlib.h>
#include <algorithm>
#include <iterator>
#include <variant>
#include "fileHand.cpp"
#include "eventStructs.cpp"
#include "intro.cpp"
#include "preamble.cpp"
using namespace std;

// sets file constants
file orcFileWord = file("files/Orc/word.txt");
file orcFileAdjective = file("files/Orc/adjective.txt");
file dwarfFileWord = file("files/Dwarf/word.txt");
file dwarfFileSuffix = file("files/Dwarf/suffix.txt");
file elfFileWord = file("files/Elf/words.txt");
file humanMaleForeName = file("files/Human/male.txt");
file humanFemaleForeName = file("files/Human/female.txt");
file humanSurname = file("files/Human/surname.txt");
file lizardWord = file("files/Lizard/word.txt");
file lizardSuffix = file("files/Lizard/suffix.txt");
file cephWord = file("files/Cephalopoid/word.txt");
file cephSuffix = file("files/Cephalopoid/suffix.txt");
file catWord = file("files/Cat/word.txt");
file catPrefix = file("files/Cat/prefix.txt");
file dogWord = file("files/Dog/word.txt");
file dogSuffix = file("files/Dog/suffix.txt");
file vulWord = file("files/Vulture/word.txt");
file vulForeSuffix = file("files/Vulture/foresuffix.txt");
file vulSuffix = file("files/Vulture/suffix.txt");
file goblinWord = file("files/Goblin/prefix.txt");
file goblinSuffix = file("files/Goblin/suffix.txt");
file sharpFile = file("files/item/weapon_sharp.txt"); // gets file object of names of weapons
file sharpWords = file("files/item/words/sharpWord.txt"); // gets file object with the words associated with weapon type
file genFile = file("files/item/random.txt");
file randomWords = file("files/item/words/randomWord.txt");
file bluntFile = file("files/item/blunt.txt");
file bluntWords = file("files/item/words/bluntWords.txt");
file healingWords = file("files/items/healing.txt");
file richWords = file("files/items/rich.txt");
vector<events> allEvents = getAllEvents();
vector<string> allMeadowsIntro = getAllMeadowsIntro();
vector<string> allUnderIntro = getAllUnderWorldIntro();
vector<string> allBarPreamble = getAllBarPreamble();
vector<string> allHousePreamble = getAllHousePreamble();
vector<string> allStreetPreamble = getAllStreetPreamble();


void pressKey(){
  cout << "Press any key to continue" << endl;
  _getwch();
}

int random_number(){ // random number generator, used for generating a new random seed
  random_device generator;
  uniform_int_distribution<int> distribution(0,100000);
  int number = distribution(generator);
  return number;
}

int randNumber(){
  srand(random_number());
  return rand();
}

int randNumber(int base, int top){
  return randNumber() % (top - base) + base;
}

string findAndReplaceAll(string & data, string toSearch, string replaceStr){ // string you want to chance, what you want to change, what you replace it with
  size_t pos = data.find(toSearch);
  while( pos != string::npos){
    data.replace(pos, toSearch.size(), replaceStr);
    pos = data.find(toSearch, pos + replaceStr.size());
  }
  return data;
}

class item{ //Temporary item class used within store event
protected:
  string name; 
  string description;
  string type;
  int cost;
public:

  item(string passedName, string passedDesc, string passedType, int passedCost){
    name = passedName;
    description = passedDesc;
    type = passedType;
    cost = passedCost;
  }
    
  // getters 
  string getName(){
    return name;
  }

  string getDesc(){
    return description;
  }

  string getType(){
    return type;
  }
    
  int getCost(){
    return cost;
  }    
  item(){};
};

class relic: public item{
private:
  string blah;
public:
  relic(string passedName, string passedDesc, string passedType, int passedCost){
    name = passedName;
    description = passedDesc;
    type = passedType;
    cost = passedCost;
  }
};

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
    cout<< "===================================="<<endl;
    cout<< " " + race << endl;
    cout<< " " + desc << endl;
    cout<< "------------------------------------"<<endl;
    cout<< " Name: " << name << endl;
    cout<< " Age: " << age << endl;
    cout<< " Height: " << height << " cm"<< endl;
    cout<< " Gender: " << gender << endl;
    cout<< " Weapon: " << this->personWeapon.getRarity() + " " + this->personWeapon.getName() << endl;    
    cout<< " Type: " << this->personWeapon.getWeaponType() << endl;
    cout<< " Biome: " << this->personWeapon.getBiomeType() << endl;
    cout<< " Weapon Action: " << this->personWeapon.getItemFromVectorCap() << endl; 
    cout<< " Faction: "<< this-> faction << endl;
    cout<<"===================================="<<endl;
    cout<< "" << endl;
  }

  string getName(){
    return name;
  }
};

class orc: public person { // child of person class, this allows for races to implement constructor for person in a different way
public:
  orc(){
    race = "Orc";
    name = orcFileWord.getLineCap(randNumber()) + orcFileWord.getLine(randNumber()) + " the " + orcFileAdjective.getLineCap(randNumber());
    age = randNumber(ageMin, ageMax);
    height = randNumber(heightMin, heightMax);
    gender = randNumber(0, 1) == 0 ? "Male" : "Female";
    faction = "Bandit";      
    desc = "Beefy, brutal, and brainless. \n Orcs like to crush first and ask questions never.";    
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
    desc = "Tubby, tough, and tiny. \n 99 tankards of mead on the bar, 99 tankards of mead. \n Take one down and pass it around, 98 tankards of mead on the bar.";   
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
    desc = "Moral, meticulous, and meek. \n Cringe race tbf.";   
  }
};

class human: public person{ // child of person class, this allows for races to implement constructor for person in a different way
public:
  human(){
    race = "Human";
    gender = randNumber(0, 1) == 0 ? "Male" : "Female";
    if (gender == "Male"){
      name = humanMaleForeName.getLineCap(randNumber()) + " " + humanSurname.getLineCap(randNumber());
    } else{
      name = humanFemaleForeName.getLineCap(randNumber()) + " " + humanSurname.getLineCap(randNumber());
    }
    height = randNumber(heightMin, heightMax);
    age = randNumber(ageMin, ageMax);
    faction = "Commoner";
    desc = "Nothing special.";   
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
    desc = "Scaled, scary, and sophisticated. \n A cruel crowd of cold blooded crocs.";   
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
    desc = "Smart, solitary, and squidgy. \n Flibugulub buglub fibblug gugblibble.";
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
    desc = "Crafty, cunning, and cuddly. \n Masters in the art of the deal, these cats always land on their feet.";   
  }
};

class dog: public person{ // child of person class, this allows for races to implement constructor for person in a different way
public:
  dog(){
    race = "Dog";
    name = dogWord.getLineCap(randNumber()) + dogSuffix.getLine(randNumber()) + " " + dogWord.getLineCap(randNumber()) + dogSuffix.getLine(randNumber()); 
    age = randNumber(ageMin, ageMax);
    height = randNumber(heightMin, heightMax);
    gender = randNumber(0, 1) == 0 ? "Male" : "Female";
    faction = "Mercenaries Guild"; 
    desc = "Rough, raring, and righteous. \n They can sniff out anyone...if the price is right.";   
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
    desc = "Funny, feared, and feathered. \n Smooth-talkers of the Imperial realm who love to chew you ear off.";   
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
    desc = "Charismatic, compact, and crooked. \n Goblin on deez nuts lol.";   
  }
}; 

class genericItem {
protected:
  string itemName;
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
};

class healItem: public genericItem{
protected:
  int healingValue;
public:
  healItem(){
    itemName = healingWords.getLineCap(randNumber());
  }

  healItem(string passedName){
    itemName = passedName;
  }

  int useItem(){
    this->decQuantity();
    return healingValue;
  }
};

class richItem: public genericItem{
protected:
  int healingValue;
  int quantity;
public:
  richItem(){
    itemName = richWords.getLineCap(randNumber());
  }

  richItem(string passedName){
    itemName = passedName;
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

  void geneateQuantItem(){
    int rndNumber = randNumber(0, 2);
    switch (rndNumber){
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
    cout << "Inventory" << endl;
    for (size_t i = 0; i < allHeals.size(); i++){
      cout << "===========================" << endl;
      cout<< "Item (" << (i + 1) << "): " << allHeals[i].getName() << endl; 
      cout << "Quantity: " << allHeals[i].getQuantity() <<endl; 
    }
    cout << "===========================" << endl;
    for (size_t i = 0; i < allRich.size(); i++){
      cout << "===========================" << endl;
      cout<< "Item (" << (i + 1) << "):  " << allRich[i].getName() << endl;
      cout << "Quantity: " << allRich[i].getQuantity() <<endl; 
    }
    cout << "===========================" << endl;
  }

  int getRndHeal(){
    return allHeals[randNumber(0, allHeals.size())].useItem();
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

  void displayQuantityItems(){
    playerQuantityItems.displayItems();
  }

  void displayAllWeapons(){
    for (int i = 0; i < playerWeapons.size(); i++){
      cout << "===========================" << endl;
      cout << "(" << (i) << ") " << playerWeapons[i].getRarity() + " " + playerWeapons[i].getName() << endl;
    }
    cout << "===========================" << endl;
  }

  void generateNewWeapon(){
    weapon tempWeapon = weapon();
    playerWeapons.push_back(tempWeapon);
  }

  void changeCurrentWeapon(){
    this->displayAllWeapons();
    int tempInput;
    cout << "Please select a new weapon" << endl;
    cin >> tempInput;
    currentWeaponIndex = tempInput;

  }

  int healPlayer(){
    return this->playerQuantityItems.getRndHeal();
  }

  // GETTERS
  weapon& getCurrentWeapon(){
    return playerWeapons[currentWeaponIndex];
  }

  quantItems getQuantItems(){
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
  int playerGold = 100;
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
  player(string passedName, string passedFamilyName, string passedRace, string passedGender, string passedMotto){
    name = passedName;
    race = passedRace;
    gender = passedGender;
    secondName = passedFamilyName;
    motto = passedMotto;
    
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
    cout<< "===================================="<<endl;
    cout<< " " + this->secondName + " clan" << endl;
    cout<< "------------------------------------"<<endl;
    cout<< " Name: " << this->name + " " + this->secondName<< endl;
    cout<< " Gender: " << this->gender << endl;
    cout<< " Race: " << this->race<< endl; 
    cout<< " Strength: " << this->strengthAttribute << endl;
    cout<< " Speech: " << this->speechAttribute << endl;
    cout<< " Intelligence: " << this->intelligenceAttribute << endl;   
    cout<< " Dread: " << this->dreadAttribute << endl;
    cout<< " Commoner Rep: "<< comRep <<endl;
    cout<< " Imperial Rep: "<< impRep <<endl;
    cout<< " Bandit Rep: "<< banRep <<endl;
    cout<< " Merchant Rep: "<< merchantRep <<endl;
    cout<< " Mercenary Rep: "<< mercRep <<endl;
    cout<< "------------------------------------"<<endl;
    cout<< "===================================="<<endl;
    cout<< "" << endl;
    cout<< "====================================" << endl;
    cout<< " Weapon" << endl;
    cout<< "------------------------------------"<<endl;
    cout<<" " + invObj.getCurrentWeapon().getRarity() + " " + invObj.getCurrentWeapon().getName()<<endl;
    cout<<" Damage: " << invObj.getCurrentWeapon().getMinDmg() << "-" << invObj.getCurrentWeapon().getMaxDmg()<<endl;
    cout<< "====================================" << endl;
    cout<< "" << endl;
    cout<< "====================================" << endl;
    cout<< " Inventory" << endl;
    cout<< "------------------------------------"<<endl;
    cout<<"====================================" << endl;
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
    } else if (passedRepType == "Imperial"){
      impRep += 1;
    } else if (passedRepType == "Bandit"){
      banRep += 1;
    } else if (passedRepType == "Merchant"){
      merchantRep = 1;
    } else if (passedRepType == "Mercenary"){
      mercRep += 1;
    }
  }

  void removeRep(string passedRepType){
    if(passedRepType == "Commoner"){
      comRep -= 1;
    } else if (passedRepType == "Imperial"){
      impRep -= 1;
    } else if (passedRepType == "Bandit"){
      banRep -= 1;
    } else if (passedRepType == "Merchant"){
      merchantRep -= 1;
    } else if (passedRepType == "Mercenary"){
      mercRep -= 1;
    }
  }

  void consumeHealItem(){
      if (this->getInventory().getQuantItems().getHealingItemVector().size() == 0 )
      {
        cout << "There are no items that you can use to heal you!" << endl;
        pressKey();
      } else{
        this->increaseHealth(this->invObj.healPlayer());
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
    cout << "Your Health: " << this->getHealth() << " has been decreased by: " << passedInt << "!"  <<  endl;
    health -= passedInt;
    cout << "Your health is: " << this->getHealth() << endl;
    if (health < 0){
      hasDied == true;
      killedBy = passedNPC;
    }

  }

  void increaseHealth(int passedInt){
    cout << "Your Health: " << this->getHealth() << " has been incerased by: " << passedInt << "!"  <<  endl;
    health += passedInt;
    cout << "Your health now is: " << this->getHealth() << endl;
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
  int familyGold = 100;
  int familyPrestige = 0;
  int currentPlayerIndex = -1;
  vector<player> allDecedents;

public:
  family(string passedName, string passedMotto, string passedRace){
    familyName = passedName;
    motto = passedMotto;
    race = passedRace; 
  }

  void generateNewPlayer(string passedFamilyName, string passedMotto, string passedRace){
    currentPlayerIndex += 1;
    cout<<"Please Enter your First Name"<<endl;
    cout<<"First Name: ";
    string playerNameInput;
    cin >> playerNameInput;
    system("CLS");

    cout<<"Please enter your gender(Kindly please capitalize)"<<endl;
    cout<<"Gender: ";
    string playerGenderInput;
    cin>> playerGenderInput;
    system("CLS");

    player tempPlayer = player(playerNameInput, passedFamilyName, passedRace, playerGenderInput, passedMotto);
    allDecedents.push_back(tempPlayer);
  }

  void familyStories(){
   for(int i = 0 ; i < allDecedents.size(); i++){
     cout << "=========================" << endl; 
     cout << allDecedents[i].getName() << endl;
     if (allDecedents[i].getPlayerStatus()){
        cout << "You where killed by: "<<allDecedents[i].getNpcKiller() << endl;
     } else{
       cout << "You lived till old age!" << endl;
     }
     cout << "You contributed " <<  allDecedents[i].getGold() << " gold to the family cause!" << endl << endl;
   }
  }

  // SETTERS
  void setFamilyGold(int passedGold){
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
    currentEvent = allEvents[eventID];
    eventName = currentEvent.name;
    biome = currentEvent.biomeType;
    location = currentEvent.location;
    eventFaction = currentEvent.faction;
    
    // Functions that create the event NPC based on the events faction
    int tempInt = randNumber(0, 7);
    if (eventFaction == "Default"){
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
      case 3: {
        eventNpc = lizard();
        npcWeaponName = eventNpc.personWeapon.getName();
        npcName = eventNpc.getName();
        eventRace = "Lizard";
        break;
      }
      case 4: {
        eventNpc = cephalopod();
        npcWeaponName = eventNpc.personWeapon.getName();
        npcName = eventNpc.getName();
        eventRace = "Cephalopoid";
        break;
      }
      case 5: {
        eventNpc = vulture();
        npcWeaponName = eventNpc.personWeapon.getName();
        npcName = eventNpc.getName();
        eventRace = "Vulture";
        break;
      }
      case 6: {
        eventNpc = orc();
        npcWeaponName = eventNpc.personWeapon.getName();
        npcName = eventNpc.getName();
        eventRace = "Orc";
        break;
      }
      case 7: {
        eventNpc = goblin();
        npcWeaponName = eventNpc.personWeapon.getName();
        npcName = eventNpc.getName();
        eventRace = "Goblin";
        break;
      }
    }
  } else if(eventFaction == "Bandit"){
      int tempInt = randNumber(0, 1);
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
      int tempInt = randNumber(0, 2);
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
      int tempInt = randNumber(0, 2);
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
    problemText = processText(currentEvent.problem[randNumber(0, 2)]);

    speechCheck = currentEvent.speech;
    intCheck = currentEvent.intelligence;
    dreadCheck = currentEvent.dread;
    repCheck = currentEvent.rep;
  }
  
  int diceRoll(string name, int mod){ // Dice roll function that rolls a D20
    int roll = ((randNumber(0, 20)) + 1); // Grabs a number between 0 and 19
    int number = roll + mod; 
    cout<<name + " rolled " << number << endl;   
    string op = (mod > 0) ? "+": "";
    if (mod != 0){
      cout << " (" <<roll<<op<<mod<<")" << endl; // displays who rolled, and the score they got
    }
    return number; // returns the dice roll
  }

  int diceRoll(string name){ // Dice roll function that rolls a D20
    int number = ((randNumber(0, 20)) + 1); // Grabs a number between 0 and 19
    cout<<name + " rolled " << number << endl;
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
    int playerHealth = 15;
    int npcHealth = 15;
    randNumber();
    cout<<"-=== " + passedPlayer.getName() + " VS " + eventNpc.getName() + " ===-" << endl;
    cout<<"Player health: " << playerHealth << endl;
    cout<<"Enemy health: " << npcHealth <<endl;
    cout<<""<<endl;

    do { 
      pressKey();
      int playerDamage = damageCalc(diceRoll("Player", (passedPlayer.getStrength() - 10)), passedPlayer.getInventory().getCurrentWeapon().getDamage()); // Generates the damage the player will do
      if (playerDamage <= -1){
        cout<<passedPlayer.getName() + " hurt themselves trying to attack!"<<endl;
        playerHealth --;
      }else if (playerDamage == 0){
        cout<<passedPlayer.getName() + " misses!"<<endl;
      }else{
        cout << passedPlayer.getName() + " " + passedPlayer.getInventory().getCurrentWeapon().getItemFromVector() + " " + eventNpc.getName() + " with their " + passedPlayer.getInventory().getCurrentWeapon().getRarity() + " " +passedPlayer.getInventory().getCurrentWeapon().getName() + " dealing " << playerDamage << " damage" << endl;
        npcHealth = npcHealth - playerDamage;      
      }
      cout<<""<<endl;

      cout<<"Player health: " << playerHealth << endl;
      cout<<" Enemy health: " << npcHealth <<endl;
      cout<<""<<endl;
      pressKey();
      if(npcHealth > 0){
        int npcDamage = damageCalc(diceRoll("NPC"), eventNpc.personWeapon.getDamage());
        if (npcDamage <= -1){
          cout<<eventNpc.getName() + " hurt themselves trying to attack!"<<endl;
          npcHealth --;
        } else if (npcDamage == 0){
          cout<<eventNpc.getName() + " misses!"<<endl;
        } else{
          cout << eventNpc.getName() + " " + eventNpc.personWeapon.getItemFromVector() + " " + passedPlayer.getName() + " with their " + eventNpc.personWeapon.getRarity() + " " + eventNpc.personWeapon.getName() + " dealing " << npcDamage << " damage" << endl;
          playerHealth = playerHealth - npcDamage;
        }
        cout<<""<<endl;
        cout<<"Player health: " << playerHealth << endl;
        cout<<" Enemy health: " << npcHealth <<endl;
        cout<<""<<endl;
      } else{
        cout << npcName + " has died!" << endl;
        return 1;
      }
    }while(npcHealth > 0 && playerHealth > 0);
    if(playerHealth <= 0){
      cout << passedPlayer.getName() + " loses!" << endl;
      return 0;
    }
    if(npcHealth <= 0){
      cout << npcName + " has died!" << endl;
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
    cout << "===================================="<<endl;
    cout << passedPlayer.getName() << " and the " << this->eventName << endl; 
    cout << "====================================" << endl;
    cout << introText << endl; 
    cout << preAmbleText << endl;
    cout << problemText << endl;
    cout << "====================================" << endl;
    cout << "(1) Attack" << endl;
    cout << "(2) Persuasion" << endl; 
    cout << "(3) Dread" << endl;
    cout << "(4) Intelligence" << endl;
    cout << "(5) Play Guitar " <<endl;
    cout << "====================================" << endl;

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
    cin >> tempConsoleInput;
    switch(tempConsoleInput){
      case 1: // Returns Boolea 
        if (fightLoop(passedPlayer, eventNpc)) {
          cout << "Attack success." << endl;
          cout << processText(currentEvent.attackSuccess) << endl;
        } else {
          cout << endl << "Attack fail." << endl;
          cout << processText(currentEvent.attackFailure) << endl;
          this->eventFail(passedPlayer);
        }
      break;
      case 2:
        if (diceRoll("Player", ((passedPlayer.getSpeech() - 10)+repMod)) >= speechCheck) { // speech check
          cout <<"Persuasion Success." << endl;
          cout << processText(currentEvent.persuasionSuccess) << endl;
          this->eventSuccess(passedPlayer);
        } else{
          cout << "Persuasion Fail." << endl;
          cout << processText(currentEvent.persuasionFail) << endl;
          this->eventFail(passedPlayer);
        }
      break;
      case 3:
        if(diceRoll("Player", ((passedPlayer.getDread() - 10)+repMod)) >= dreadCheck){ // dread check
          cout << "Dread Success." << endl;
          cout << processText(currentEvent.dreadSuccess) << endl;
          this->eventSuccess(passedPlayer);
        } else{
          cout << "Dread Fail." << endl;
          cout << processText(currentEvent.dreadFail) << endl;
          this->eventFail(passedPlayer);
        }
      break;
      case 4:
        if(diceRoll("Player", (passedPlayer.getIntelligence() - 10) + repMod) >= intCheck){ // intelligence check
          cout << "Intelligence Success." << endl;
          cout << processText(currentEvent.intelligenceSuccess) << endl;
          this->eventSuccess(passedPlayer);
        } else{
          cout << "Intelligence Fail." << endl;
          cout << processText(currentEvent.intelligenceFail) << endl;
          this->eventFail(passedPlayer);
        }
      break;
      case 5:
        if(diceRoll("Player", 0) >= 11){ // guitar is a skill-less roll, success is a 50/50, but no reputation will be lost if you fail. This option gives less risk and less reward.
          cout << "Guitar Success." << endl;
          cout << processText(currentEvent.guitarSuccess) << endl;
          this->eventSuccess(passedPlayer);
        } else{
          cout << "Guitar Fail." << endl;
          cout << processText(currentEvent.guitarFail) << endl;
          this->eventFail(passedPlayer);
        }
      break;
    }
  }

  void eventSuccess(player& passedPlayer){
    int randNum = randNumber(0, 4);
    passedPlayer.addRep(eventFaction);
    switch (randNum){
    case 0:{
      int tempGold = randNumber(20, 100);
      cout<< "You Gain: " << tempGold << " gold." << endl;
      passedPlayer.addGold(tempGold);
      break;
    }
    case 1: // Gives Player Item
      passedPlayer.getInventory().rndQuantityItem();
      break;
    case 2:{
      cout << "Your good fortune applies to your health as well" << endl;
      passedPlayer.increaseHealth(randNumber(5, 10));
      break;      
    }
    case 3:
      cout << "You found a cool new weapon" << endl; 
      passedPlayer.getInventory().generateNewWeapon();
      break;
    }
  }

  void eventFail(player& passedPlayer){
    int randNum = randNumber(0, 2);
    passedPlayer.removeRep(eventFaction);

    switch (randNum){
    case 0:{
      int tempGold = randNumber(20, 100);
      cout<< "You Loose: -" << tempGold << " gold." << endl;
      passedPlayer.removeGold(tempGold);
      break;
    }
    case 1: // Gives Player Item
      passedPlayer.decreaseHealth(randNumber(5, 10), this->npcName);
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
  binTree(int passedSize){
    sizeOfTree = passedSize;

    int tempArrayOfIndex[passedSize];
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

    for (size_t i = 0; i < passedSize -1; i++){
      this->generate_node(randNumber(0, allEvents.size()) + 1, rootNode, tempArrayOfIndex[i]); // change this to rnd number
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

int main(){
  cout<<"Please Enter your family's name"<<endl;
  cout<<"Family Name: ";
  string familyNameInput;
  cin >> familyNameInput;
  system("CLS");

  cout<<"Please Enter your family's motto"<<endl;
  cout<<"Family Motto: ";
  string familyMottoInput;
  cin >> familyMottoInput;
  system("CLS");

  cout<<"Please Enter your family's race"<<endl;
  cout<<"Family Race: ";
  string familyRaceInput;
  cin >> familyRaceInput;
  system("CLS");

  family playerFamily = family(familyNameInput, familyMottoInput, familyRaceInput);
  playerFamily.generateNewPlayer(playerFamily.getFamilyName(), playerFamily.getFamilyMotto(), playerFamily.getFamilyRace());
  playerFamily.getCurrentPlayer().getInventory().generateNewWeapon();
  playerFamily.getCurrentPlayer().getInventory().generateNewWeapon();
  bool pressedExit = false;

  do{  
    map gameMap = map(allEvents.size());   
    bool isEmpty = false;
    while (isEmpty != true){
      bool breakFree = false;
      while (breakFree != true){
        system("CLS");      
        cout<< "Please Select an action" <<endl;
        cout<< "(1) Continue to next event" << endl;
        cout<< "(2) Visit shop" << endl;
        cout<< "(3) Retire" << endl;
        cout<< "(4) View inventory" << endl;
        cout<< "(5) Select Weapon" << endl;
        cout<< "(6) Heal Player" << endl;
        cout<< "(10) EXIT" << endl;
        int eventLoopInput;
        cin >> eventLoopInput;
        switch (eventLoopInput){
        case 1:
          breakFree = true;
          break;
        case 2:
          // Shop code
          break;
        case 3: 
          cout<< "You feel like the road ahead is too far.."<< endl;
          cout<< "It's consquences too great.."<< endl;
          cout<< "Throwing your weapon down, you give in, and go home." << endl;
          pressKey();
          system("CLS");
          playerFamily.getCurrentPlayer().setRetired(true);
          breakFree = true;
          break;
        case 4:
          playerFamily.getCurrentPlayer().getInventory().displayQuantityItems();
          playerFamily.getCurrentPlayer().getInventory().displayAllWeapons();
          pressKey();
          break;
        case 5:
          playerFamily.getCurrentPlayer().getInventory().changeCurrentWeapon();
          pressKey();
          break;
        case 6:
          playerFamily.getCurrentPlayer().consumeHealItem();
          break;
        case 10:
          playerFamily.familyStories();
          pressKey();
          return 1;
          break;
        }       
      }
      
      if (playerFamily.getCurrentPlayer().getRetired() == true){
        cout<< "The family grows and a new adventruer take up the helm" << endl;
        playerFamily.generateNewPlayer(playerFamily.getFamilyName(), playerFamily.getFamilyMotto(), playerFamily.getFamilyRace());
        map gameMap = map(allEvents.size());   
      }  
  
      if(gameMap.checkIfEndLevel()){
        cout<<"You have reached the end of your path" << endl;
        break;
      }

      system("CLS"); 
      gameMap.getBinTree().printBT();
      cout << "Do you wish to move left or right? " << endl;
      string playerChoiceLeftOrRight;
      cin >> playerChoiceLeftOrRight;

      if (playerChoiceLeftOrRight == "left" ||	playerChoiceLeftOrRight == "Left"){
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
        cout << "You reach the end of known world" << endl;
        cout << "Turning back you face the path of your travels" << endl; 
        cout << "It is time to go home."<< endl;
        pressKey();
        system("CLS");
        playerFamily.generateNewPlayer(playerFamily.getFamilyName(), playerFamily.getFamilyMotto(), playerFamily.getFamilyRace());
      }

      if (playerFamily.getCurrentPlayer().getPlayerStatus()){
        cout<< "The world fade around you..."<< endl;
        cout<< "...You feel your last breath"<< endl;
        cout<< "But new life begins to stir..." <<endl;
        cout<< "your child starts anew"<<endl;
        pressKey();
        playerFamily.generateNewPlayer(playerFamily.getFamilyName(), playerFamily.getFamilyMotto(), playerFamily.getFamilyRace());
      }
    }
  } while (pressedExit != true);
  return 1;
}
