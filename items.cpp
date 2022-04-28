#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct healItems{
  string name;
  string desc;
  int healAmount;
  int value;
};

struct richItems{
    string name;
    string desc;
    int value;
};

struct relics{
    string name;
    string desc;
    string att;
    int mod;
    int value;
};

vector<healItems> getAllHealItems(){
  vector<healItems> allHealItems;

  healItems apple;
  apple.name = "Apple";
  apple.desc = "Crunchy! [+2 Health]";
  apple.healAmount = 2;
  apple.value = 15;
  allHealItems.push_back(apple);

  healItems bread;
  bread.name = "Bread";
  bread.desc = "Doughy! [+2 Health]";
  bread.healAmount = 2;
  bread.value = 5;
  allHealItems.push_back(bread);

  healItems soup;
  soup.name = "Soup";
  soup.desc = "Gooey! [+2 Health]";
  soup.healAmount = 2;
  soup.value = 5;
  allHealItems.push_back(soup);

  healItems fish;
  fish.name = "Fish";
  fish.desc = "Fishy! [+3 Health]";
  fish.healAmount = 3;
  fish.value = 8;
  allHealItems.push_back(fish);

  return allHealItems;
}

vector<richItems> getAllRichItems(){
  vector<richItems> allRichItems;

  richItems rock;
  rock.name = "Rock";
  rock.desc = "Shiney! [3 Gold]";
  rock.value = 3;
  allRichItems.push_back(rock);

  richItems spoon;
  spoon.name = "Golden Spoon";
  spoon.desc = "Too nice to eat with. [15 Gold]";
  spoon.value = 15;
  allRichItems.push_back(spoon);


  return allRichItems;
}

vector<relics> getAllRelics(){
  vector<relics> allRelics;

  relics eyeliner;
  eyeliner.name = "Black Eyeliner";
  eyeliner.desc = "Scary! [+1 Dread]";
  eyeliner.att = "Dread";
  eyeliner.mod = 1;
  eyeliner.value = 50;
  allRelics.push_back(eyeliner);

  relics glasses;
  glasses.name = "Glasses";
  glasses.desc = "You'll sure look smarter. [+1 Intelligence]";
  glasses.att = "Intelligence";
  glasses.mod = 1;
  glasses.value = 50;
  allRelics.push_back(glasses);

  relics protein;
  protein.name = "Protein Powder";
  protein.desc = "Gains! [+1 Strength]";
  protein.att = "Strength";
  protein.mod = 1;
  protein.value = 50;
  allRelics.push_back(protein);

  relics sunglasses;
  sunglasses.name = "Sunglasses";
  sunglasses.desc = "It sure is bright in here. [+1 Speech]";
  sunglasses.att = "Speech";
  sunglasses.mod = 1;
  sunglasses.value = 50;
  allRelics.push_back(sunglasses);

  return allRelics;
}