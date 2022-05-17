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

// TEXT AND UI

// Creates a new line
void gap(){ 
  cout<<""<<endl;
}

// Sets the console text colour
void textColour(int colour){
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
}

// Formats outputted text to print to a certain line length
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

// Ui for input prompt
void inputBox(){
  cout<<"  -> ";
}

// Class that defines UI box proerties
class longBox{
  private:
  int h; // Horizontal line
  int v; // Vertical line
  int bLCorner; // Bottom left corner
  int tLCorner; // Top left corner
  int bRCorner; // Bottom right corner
  int tRCorner; // Top Right corner
  int lCross; // Left vertical horizontal cross
  int rCross; // Right vertical horizontal cross
  int length; // The box length from left to right

  public:
  longBox(int mode, int boxLength){
    length = boxLength;
    if(mode == 1){ // Sets the box to single line outline
      h = 196;
      v = 179;
      bLCorner = 192;
      tLCorner = 218;
      bRCorner = 217;
      tRCorner = 191;
      lCross = 195;
      rCross = 180;
    } else if(mode == 2){ // Sets the box to double line outline
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

  void title(string text){ // Creates a title for the box, containing text
    cout << " " << char(tLCorner); for(int i=0; i<length; i++){cout << char(h);} cout << char(tRCorner) << endl;
    cout << " " << char(v) << " " + text; for(int i = 0; i < (length - (text.length() + 1)); i++){cout<<" ";} cout << char(v) << endl;
    cout << " " << char(lCross); for(int i=0; i<length; i++){cout << char(h);} cout << char(rCross) << endl;
  }

  void content(string text){ // Creates a row within the box
    cout << " " << char(v) << " " + text; for(int i = 0; i < (length - (text.length() + 1)); i++){cout<<" ";} cout << char(v) << endl;
  }

  void bottom(){ // Creates a bottom line for the box
    cout << " " << char(bLCorner); for(int i=0; i<length; i++){cout << char(h);} cout << char(bRCorner) << endl;
  }

  void separator(){ // Creates a separator between rows
    cout << " " << char(lCross); for(int i=0; i<length; i++){cout << char(h);} cout << char(rCross) << endl;
  }

  void top(){ // Creates a top line for the box
    cout << " " << char(tLCorner); for(int i=0; i<length; i++){cout << char(h);} cout << char(tRCorner) << endl;
  }

};

// Class for a standard single line text box
class textBox{
  public:

  // BOX CREATORS
  // Box with outline setting only
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

  // Box with outline setting, and custom length
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

  // Box with outline setting, and custom colour
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

// Stops the code from continuing until a key is pressed
void pressKey(){
  textBox(1, "Press any key to continue");
  _getwch();
}

// VALIDATION FUNCTIONS

// Checks if inputted string is a digit
bool isStringDigit(string input){
  for(int i=0; i<input.length(); i++){ // Iterates through each character
    if(!isdigit(input[i])){ // Checks each character individually
      return false;
    }
  }
  return true;
}

// Number validation with numeric and range checks
int numInput(int low, int high){ // Takes high and low values
  string input;
  int inputInt;
  bool passed = false;
  while(!passed){
    inputBox();
    cin >> input; // Input as a string
    if(!isStringDigit(input)){ 
      textBox(4,1,"Invalid input");
      cin.clear();
    } else{
      inputInt = stoi(input); // Converts input to an integer
      if(inputInt > low-1 && inputInt < high+1){ // Checks number is between specified ranges
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

// Checks the length of an input
string lenCheck(){
  string input = "";
  bool passed = false;
  while(!passed){
    inputBox();
    cin.clear();
    getline(cin >> ws, input);
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

// RANDOM NUMBER FUNCTIONS

// Random number generator, used for generating a new random seed
int random_number(){ 
  random_device generator;
  uniform_int_distribution<int> distribution(0,100000);
  int number = distribution(generator);
  return number;
}

// Generates a random number
int randNumber(){
  srand(random_number());
  return rand();
}

// Generates and returns random number between specified ranges
int randNumber(int base, int top){
  return randNumber() % (top - base) + base;
}


// TEXT REPLACEMENT

// Finds each instance of a specified string within text and replaces with another specified string
string findAndReplaceAll(string & data, string toSearch, string replaceStr){ // string you want to chance, what you want to change, what you replace it with
  size_t pos = data.find(toSearch);
  while( pos != string::npos){
    data.replace(pos, toSearch.size(), replaceStr);
    pos = data.find(toSearch, pos + replaceStr.size());
  }
  return data;
}




