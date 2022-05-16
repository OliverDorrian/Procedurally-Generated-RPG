#include <vector>
#include <string>
using namespace std;

vector<string> getAllBarPreamble(){
  vector<string> barPreamble;
	// Under-Underworld       
  barPreamble.push_back("You stray in from the cold, entering a bar.");
  barPreamble.push_back("The door of a bar greets you with a smiling face, obligating you to enter.");
  barPreamble.push_back("Revelers stumble unconsciously out of a bar. Accosting your collar as they tell a tall tale. Feeling interested, you enter the bar they reference.");
  barPreamble.push_back("Entering a seedy venue, your thirst gets the better of you. You dread to know this places hygiene rating.");
  barPreamble.push_back("A faceless drone tells you of their favorite venue, and not wanting to be socially awkward, you enter.");
  barPreamble.push_back("A neon sign lights up, shouting BAR in large lettering. You like neon signs.");
  return barPreamble;
}

vector<string> getAllHousePreamble(){
    vector<string> housePreamble;
    housePreamble.push_back("You come across a house in the hills, dilapidated and old. Something about it seems to beckon you. You approach it, and step inside.");
    return housePreamble;
}

vector<string> getAllStreetPreamble(){
    vector<string> streetPreamble;
    streetPreamble.push_back("You wander through the streets aimlessly.");
    return streetPreamble;
}

vector<string> getAllVillagePreamble(){
    vector<string> villagePreamble;
    villagePreamble.push_back("You wander through a village aimlessly.");
    return villagePreamble;
}

vector<string> getAllCryptPreamble(){
    vector<string> cryptPreamble;
    cryptPreamble.push_back("You wander through some crypts aimlessly.");
    return cryptPreamble;
}

vector<string> getAllRoadPreamble(){
    vector<string> roadPreamble;
    roadPreamble.push_back("You wander along a road aimlessly.");
    return roadPreamble;
}