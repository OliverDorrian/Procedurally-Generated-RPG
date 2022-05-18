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
        villagePreamble.push_back("An offensive smell pierces your nostril, you follow the source of the smell and come across a village.");
        villagePreamble.push_back("As you continue on your path, the road leads to a nice looking, but foul smelling, village.");
        return villagePreamble;
    }

vector<string> getAllCryptPreamble(){
        vector<string>cryptPreamble;
        cryptPreamble.push_back("Headed on your way you see the entrance to what appears to be an old crypt, thinking you may be able to pinch a penny or two, you head inside.");
        return cryptPreamble;
    }


vector<string> getAllRoadsPreamble(){
        vector<string> roadsPreamble;
        roadsPreamble.push_back("You head on your way and follow a road.");
        roadsPreamble.push_back("You decide to travel alongside a road you came across.");
        return roadsPreamble;
    }

vector<string> getAllCampPreamble(){
        vector<string> campPreamble;
        campPreamble.push_back("In the distance you spot a circle of structures, isolated from civilization. Huts, small and large, seemingly constructed from any materials that could be plundered. 'This must be a bandit encampment' you think to yourself. You approach with apprehension.");
        return campPreamble;
    }