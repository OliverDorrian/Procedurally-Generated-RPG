#include <fstream>
#include <iostream>
#include <string.h>
#include <vector> 
#include <cctype>
#include <sstream>
#include <string>  
using namespace std;

class file{ // files class gets a path then collections all the lines of a file
// it stores these lines within a vector of strings.
private:
  string fileName; // passed file path
  fstream fileObject; // created fStream object
  int numOfLines; // number of lines within the file
  vector<string> vec; // vector of strings
public:
  file(string passedFileName){ // gets pathed file path
    fileName = passedFileName;
    numOfLines = 0; 
    fileObject.open(fileName);
    this->readContents(); // runs the method that collects all the lines in a file   
  }

  void readContents(){ // collects lines from a file then adds it to a vector
    string tempString; // holds the string of the current lines as the fStream iterate
    if(fileObject.is_open()){ // tries to open the file
      while(getline(fileObject, tempString)){ // gets a line
          numOfLines++; 
          vec.push_back(tempString); // pushes string to vector
      }
    }
    numOfLines--; // reduces number of lines as it is zero based
    fileObject.close();
  }
  // getters
  vector<string> getVector(){
    return vec;
  }

  string getLine(int lineNumber){  
    return vec[lineNumber%numOfLines]; 
  }

  string getLineCap(int lineNumber) {
      string tempString = vec[lineNumber%numOfLines];
    tempString[0] = toupper(tempString[0]);
    return  tempString;
  }
};
