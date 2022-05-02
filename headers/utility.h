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
using namespace std;

void gap(){
  cout<<""<<endl;
}

void textColour(int colour){
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
}

void textFunc(string text){
  int count = 0;
  cout<<"  ";
  for(int i = 0; i < text.length(); i++){
    cout<<text[i];
    count++;
    if((count >= 50) && (isspace(text[i]))){
      cout<<"\n  ";
      count = 0;
    }
  }
  gap();
}

void inputBox(){
  //cout << " " << char(218); for(int i=0; i<8; i++){cout << char(196);} cout << char(196) << endl;
//cout << " " << char(179) << " ";
cout<<"  -> ";
}

class longBox{
  private:
  int h;
  int v;
  int bLCorner;
  int tLCorner;
  int bRCorner;
  int tRCorner;
  int lCross;
  int rCross;
  int length;

  public:
  longBox(int mode, int boxLength){
    length = boxLength;
    if(mode == 1){
      h = 196;
      v = 179;
      bLCorner = 192;
      tLCorner = 218;
      bRCorner = 217;
      tRCorner = 191;
      lCross = 195;
      rCross = 180;
    } else if(mode == 2){
      h = 205;
      v = 186;
      bLCorner = 200;
      tLCorner = 201;
      bRCorner = 188;
      tRCorner = 187;
      lCross = 204;
      rCross = 185;
    }
  }

  void title(string text){
    cout << " " << char(tLCorner); for(int i=0; i<length; i++){cout << char(h);} cout << char(tRCorner) << endl;
    cout << " " << char(v) << " " + text; for(int i = 0; i < (length - (text.length() + 1)); i++){cout<<" ";} cout << char(v) << endl;
    cout << " " << char(lCross); for(int i=0; i<length; i++){cout << char(h);} cout << char(rCross) << endl;
  }

  void content(string text){
    cout << " " << char(v) << " " + text; for(int i = 0; i < (length - (text.length() + 1)); i++){cout<<" ";} cout << char(v) << endl;
  }

  void bottom(){
    cout << " " << char(bLCorner); for(int i=0; i<length; i++){cout << char(h);} cout << char(bRCorner) << endl;
  }

  void separator(){
    cout << " " << char(lCross); for(int i=0; i<length; i++){cout << char(h);} cout << char(rCross) << endl;
  }

  void top(){
    cout << " " << char(tLCorner); for(int i=0; i<length; i++){cout << char(h);} cout << char(tRCorner) << endl;
  }

};

class textBox{
  public:

  textBox(int mode, string text){
    if(mode == 1){
      cout << " " << char(218); for(int i=0; i<(text.length() + 2); i++){cout << char(196);} cout << char(191) << endl;
      cout << " " << char(179) << " " + text + " " << char(179) << endl;
      cout << " " << char(192); for(int i=0; i<(text.length() + 2); i++){cout << char(196);} cout << char(217) << endl;
    } else if(mode == 2){
      cout << " " << char(201); for(int i=0; i<(text.length() + 2); i++){cout << char(205);} cout << char(187) << endl;
      cout << " " << char(186) << " " + text + " " << char(186) << endl;
      cout << " " << char(200); for(int i=0; i<(text.length() + 2); i++){cout << char(205);} cout << char(188) << endl;
    }
  }

  textBox(int mode, string text, int length){
    if(mode == 1){
      cout << " " << char(218); for(int i=0; i<length; i++){cout << char(196);} cout << char(191) << endl;
      cout << " " << char(179) << " " + text; for(int i = 0; i < (length - (text.length() + 1)); i++){cout<<" ";} cout << char(179) << endl;
      cout << " " << char(192); for(int i=0; i<length; i++){cout << char(196);} cout << char(217) << endl;
    } else if(mode == 2){
      cout << " " << char(201); for(int i=0; i<length; i++){cout << char(205);} cout << char(187) << endl;
      cout << " " << char(186) << " " + text; for(int i = 0; i < (length - (text.length() + 1)); i++){cout<<" ";} cout << char(186) << endl;
      cout << " " << char(200); for(int i=0; i<length; i++){cout << char(205);} cout << char(188) << endl;
    }
  }

  textBox(int colour, int mode, string text){
    if(mode == 1){
      textColour(colour);
      cout << " " << char(218); for(int i=0; i<(text.length() + 2); i++){cout << char(196);} cout << char(191) << endl;
      cout << " " << char(179) << " ";
      textColour(7);
      for(int i = 0; i<text.size(); i++){
        if(text[i] == '|'){
          textColour(colour);
          cout<<text[i];
          textColour(7);
        } else {
          cout<<text[i];
        }
      }
      textColour(colour); 
      cout<< " " << char(179) << endl;
      cout << " " << char(192); for(int i=0; i<(text.length() + 2); i++){cout << char(196);} cout << char(217) << endl;
      textColour(7);
    } else if(mode == 2){
      textColour(colour);
      cout << " " << char(201); for(int i=0; i<(text.length() + 2); i++){cout << char(205);} cout << char(187) << endl;
      cout << " " << char(186) << " ";
      textColour(7);
      for(int i = 0; i<text.size(); i++){
        if(text[i] == '|'){
          textColour(colour);
          cout<<text[i];
          textColour(7);
        } else {
          cout<<text[i];
        }
      }
      textColour(colour);
      cout<< " " << char(186) << endl;
      cout << " " << char(200); for(int i=0; i<(text.length() + 2); i++){cout << char(205);} cout << char(188) << endl;
      textColour(7);
    }
  }
};

bool isStringDigit(string input){
  for(int i=0; i<input.length(); i++){
    if(!isdigit(input[i])){
      return false;
    }
  }
  return true;
}

int numInput(int low, int high){
  string input;
  int inputInt;
  bool passed = false;
  while(!passed){
    inputBox();
    cin >> input;
    if(!isStringDigit(input)){
      textBox(4,1,"Invalid input");
      cin.clear();
    } else{
      inputInt = stoi(input);
      if(inputInt > low-1 && inputInt < high+1){
        passed = true;
        return inputInt;
      } else{
        textBox(4,1,"Invalid input");
        cin.clear();
      }
    } 
  }
  return 0;
}

string lenCheck(){
  string input = "";
  bool passed = false;
  while(!passed){
    inputBox();
    //getline(cin, input, '\n');
    cin >> input;
    if(input.length() > 15){
      textBox(4,1,"Input must be 15 characters or less");
      cin.clear();
    } else{
      passed = true;
      return input;
    }
  }
  return input;
}

void pressKey(){
  textBox(1, "Press any key to continue");
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


