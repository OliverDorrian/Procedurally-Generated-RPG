#include <vector>
#include <string>
using namespace std;

vector<string> getAllUnderWorldIntro(){
  vector<string> undWorldIntro;
	// Under-Underworld       
	undWorldIntro.push_back("Things are dirty in the underworld. Crime is rife, and the stench rifer. It's everyone for themselves down here.");
  undWorldIntro.push_back("You find your way down into the underworld. Danger lurks on every corner, but there is money to be made here.");
  return undWorldIntro;
}

vector<string> getAllMeadowsIntro(){
  vector<string> meadowsIntro;

  // Meadow
  meadowsIntro.push_back("The grass is green and the sky is blue. Its peaceful here in the meadows.");
  meadowsIntro.push_back("Birds chirp around you, and you are calmed by the rushing of wind between the trees. Its peaceful here in the meadows.");
  return meadowsIntro;
}

vector<string> getAllDesertIntro(){
  vector<string> desertIntro;

  // Meadow
  desertIntro.push_back("The sun beats down from the sky above. 50 miles ahead of you, there is sand. 50 miles behind, you guessed it, sand. You wander through the desert aimlessley.");
  return desertIntro;
}
