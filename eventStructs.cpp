#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct events{
  string name;
  string biomeType;
  string location;
  string faction;
  string problem[3];
  string attackSuccess;
  string attackFailure;
  string persuasionSuccess;
  string persuasionFail;
  string dreadSuccess;
  string dreadFail;
  string intelligenceSuccess;
  string intelligenceFail;
  string guitarSuccess;
  string guitarFail;
  int rep;
  int speech; //required speech roll to succeed
  int dread; //required dread roll to succeed
  int intelligence; //required intelligence roll to succeed
};

vector<events> getAllEvents(){
  vector<events> allEvents;

  events event1;
  event1.name = "Wild Jazz Band";
  event1.biomeType = "Underworld";
  event1.location = "bar";
  event1.faction = "Default";
  event1.rep = 2;

  event1.problem[0] = "You sit in anticpitation as the tables fill up. You have no idea what is about to happen, but you are excited to find out. <npcName>'s band enters the stage, proclaiming to be the heirs to 'Freestyle Expressionist' Jazz. You wish to hit them.";
  event1.problem[1] = "The bar fills, the tables stop being empty, and there is a line out the door. You feel a scene is about to unfold. A jazz band walks on, sits down, and <npcName>'s trumpet produces a noise so bastardly evil that it demands silence.";
  event1.problem[2] = "A small dwarf trots over. Handing you a advertisment, he leaves. The page tells of a jazz performance, you hate jazz. <npcName>'s band plays wildly like a hound that been hit by a nail gun. You feel the urge to stop its creation.";

  event1.attackSuccess = "You swing your weapon at the saxophone, splitting it in two. Moving on to strings of cello, you free the tension by snapping each one.";
  event1.attackFailure = "As you stand and begin to move toward the stage, the music reaches such a height that you collapse, hitting your head on the bass players foot as you fall.";

  event1.speech = 6;
  event1.persuasionSuccess = "You talk to <npcName>. They seem nice and stop playing to begin happy chit-chat, Blessing you the good fortune of jazz";
  event1.persuasionFail = "<npcName> calls you a fool and carries on wild jazz regardless. Hurting you ceaselessly.";

  event1.dread = 6;
  event1.dreadSuccess = "<npcName> cowers in literal fear as you stand over him in a powering Patrick Bateman stance";
  event1.dreadFail = "Jazz music continues.";

  event1.intelligence = 6;
  event1.intelligenceSuccess = "You take each instrument of <npcName>'s band. After tuning each one to perfection you hand them back. Funky!";
  event1.intelligenceFail = "You take each instrument of <npcName>'s band. You attempt to tune each one, but fail at every opportunity. You hand them back, <npcName> thanks you, but the sound is twice as bad as before.";

  event1.guitarSuccess ="You take your guitar off your back and step on to the stage, 'Uh this is an oldie...well, its an oldie where I come from' you say to the crowd. You play Johnny B Goode and the crowd goes wild.";
  event1.guitarFail ="You take your guitar off your back and step on to the stage, 'Uh this is an oldie...well, its an oldie where I come from' you say to the crowd. You play Johnny B Goode as they stand motionless staring at you. 'Guess you guys aren't ready for that yet' you say 'but your kids are gonna love it'.";
  allEvents.push_back(event1);

  events event2;
  event2.name = "Bar Fight";
  event2.biomeType = "Underworld";
  event2.location = "bar";
  event2.faction = "Default";
  event2.rep = 2;

  event2.problem[0] = "You walk over to the bar to get a drink. <npcName> sits to your side. They spit in your mug. 'Drink that hahahaha!' <npcName> says. You turn to face them.";
  event2.problem[1] = "A rogue bottle flies swiftly over your head, narrowly avoiding the moppish mess you call a haircut. Soon after another goes by...and another...and another. You turn to face the source, but as you do, a bottle lands square on your nose. Looking past your now crooked snout, you see <npcName> readying their arm to throw yet another bottle from their seemingly infinite supply.";
  event2.problem[2] = "<npcName>'s band plays wildly like a hound that been hit by a nail gun. You feel the urge to stop its creation.";

  event2.attackSuccess = "You turn <npcName>'s body inside out.";
  event2.attackFailure = "Taking one swing at <npcName>, you spin round in a circle on your left foot, missing their face and flying into an arrangement of bar stools. You don't remember much of what happened next, but you spent the rest of the afternoon picking glass out of your cheek and scavenging the floor for the teeth you lost hidden among the many that now littered the bars otherwise pristine floorboards.";

  event2.speech = 8;
  event2.persuasionSuccess = "You stare into <npcName>'s eyes. 'I would appreciate it if you would stop this nonsense' you say. <npcName> leaves the bar.";
  event2.persuasionFail = "'Well, if I could just...' you stutter, but before you can finish, a flurry of fists fly into your face knocking you swiftly to the ground. ";

  event2.dread = 10;
  event2.dreadSuccess = "<npcName> cowers in literal fear as you stand over him in a powering Patrick Bateman stance.";
  event2.dreadFail = "In the poorest attempt to be intimidating the land had ever seen, you actually survive the situation without a single scratch or blemish to your name. The pure comedic concept of your shallow and squeaky attempt to be frightening had sent the entire bar into an outburst of hysterics. On the upside, the situation had been diffused successfully, which you continue to tell yourself was the plan all along.";

  event2.intelligence = 6;
  event2.intelligenceSuccess = "You explain the costly health implications that might arise if <npcName> decided to fight you. They nod their head, and turn away.";
  event2.intelligenceFail = "You point behind <npcName>. 'What's that!' you screech. They turn their head to see nothing, and then turn back to face you. You hadn't thought this far ahead. You receive double the beating you might have done if you'd kept your mouth shut.";

  event2.guitarSuccess ="You take your guitar off your back and step on to the stage, 'Uh this is an oldie...well, its an oldie where I come from' you say to the crowd. You play Johnny B Goode and the crowd goes wild.";
  event2.guitarFail ="You take your guitar off your back and step on to the stage, 'Uh this is an oldie...well, its an oldie where I come from' you say to the crowd. You play Johnny B Goode as they stand motionless staring at you. 'Guess you guys aren't ready for that yet' you say 'but your kids are gonna love it'.";
  allEvents.push_back(event2);

  events event3;
  event3.name = "A Stray Dog";
  event3.biomeType = "Underworld";
  event3.location = "street";
  event3.faction = "Default";
  event3.rep = 2;

  event3.problem[0] = "A weeping whimper sounds from a small dog as he timidly approaches you. Clearly injured, his face gives you the saddness of glances. The small dog yelps as he demands food, feeling guilty, you give in. But before you get on your way you notice a man snatch the meal.";
  event3.problem[1] = "You hear footsteps behind you, the trot of small paws, drawing your weapon. You turn to face a small shy dog, clearly hungry. The tiny framed dog needs food, and being the softie you are, you give in. Yet, before the dog can even take a bite, the food is nabbed by a random man.";
  event3.problem[2] = "A little face illuminates an dim alleyway. Upon closer inspection you see a defenseless dog. You set out a trail of food to get the dog close enough to pet it, but before this a person impersionating a hoover takes all the crumbs right before your eyes.";

  event3.attackSuccess = "You slice <npcName> into two, smiling in grim statsfaction as the dog finnishes the rest of his meal.";
  event3.attackFailure = "You fall quickly to the floor as <npcName> lands hit after hit. The dog, not quite understanding the situation beings to lick your face. You will forever be known as dog breath.";

  event3.speech = 8;
  event3.persuasionSuccess = "You inform <npcName> that you have a perticular set of skills, watching his eyes widen, he quickly runs off.";
  event3.persuasionFail = "You remonstrate with the man, but he informs you that he is a do...and...you kinda believe him...not much gets past this hero."; 

  event3.intelligence = 6;
  event3.intelligenceSuccess = "Outlining a logical framework you convince <npcName> that he is not a dog. A really heros adventure.";
  event3.intelligenceFail = "Stating that dogs need less food than humans, and you are willing to feed you both, <npcName> says that he 'fed thy mother last night'.";
  
  event3.guitarSuccess = "You bring out your guitar, playing a memorinsing tune, <npcName> wanders off, constantly repeating the word 'despacitio'.";
  event3.guitarFail = "You use your guitar, for some reason you believed this would help you with a dog and a person who eats dog food.";
  allEvents.push_back(event3);

  events event4;
  event4.name = "Squats the problem?";
  event4.biomeType = "Meadows";
  event4.location = "house";
  event4.faction = "Default";
  event4.rep = 2;

  event4.problem[0] = "You see <npcName> lying on the ground, submerged in a sea of empty ale bottles and tobacco pipes. 'What are you doing here?' you ask. <npcName> leaps to their feet in shock. 'WHAT?!?' they yell. 'Sorry, I must've dozed off there for a minute.' they continue, regaining their senses. 'Do you live here?' you ask. <npcName> takes a moment to prepare their response. 'Well...do I live here? Yes! In so much as this is where I sleep I mean'. 'What legal claim have you on this land and building?' you reply. <npcName> takes another moment. 'Well...what legal claim do I have? Some! In so much as I have none at all' they blabber on. 'I beg you don't inform the authorities, good traveller! I see the kindness in your eyes!' they plead.";
  event4.problem[1] = "A man barges past you and out of the front door. 'A squatter! On my land! Oh this just really isn't my day at all!' he mutters to himself. Upon noticing your presence, he turns to you. 'You there! You seem to be the problem solving type! How do you fancy making a little extra coin as an agent of the underprivileged, overworked, and exceedingly kind landlord population?' he grins. You open your mouth to respond but before you can, the landlord continues. 'Wonderful! Just splendid! I knew you were a first class fellow when first I laid eyes on you. You shall be rewarded my friend! But if you'll excuse me for now, I must go cheer myself up. I'm thinking...raise a few rents? Yes, that should do it!' he says, now slinking away from you. You turn to see a ragged <npcName>, cowering in the corner of the room.";
  event4.problem[2] = "<npcName> slow dances in the centre of the room, taking no notice of your arrival. 'La da di daaa, and a rum dum brum chuuuum, an ounce of blee blee blah yaaaah, and owee wah woh' they sing to themselves. 'Excuse me' you call. <npcName> turns to you. 'Yes yes, oh quite right, another guest for our evening of entertainment don't you know?' he blabbers. 'Please, do sit, make yourself quite comfortable, this is a classy affair after all, don't you know?'. You glance around, noticing the thick layers of grime coating the walls and the floor, the ripped sheets strewn here and there, and a few rats nibbling on some broken glass. 'Are you squatting here?' you ask. 'Squatting? Why of course not, no no no, I inherited this estate and this mansion from my father, as he did with his father before him. Though the decorations were all my doing, don't you know?' he replies. 'Tea?' he inquires, offering you a rusty mug full of mystery liquid.";

  event4.attackSuccess = "You slice <npcName> into two, smiling in grim statsfaction as the dog finnishes the rest of his meal.";
  event4.attackFailure = "You fall quickly to the floor as <npcName> lands hit after hit. The dog, not quite understanding the situation beings to lick your face. You will forever be known as dog breath.";

  event4.speech = 8;
  event4.persuasionSuccess = "'It is abundantly clear, to anyone with even a shred of intelligence, that you are in fact a master squatter!' you begin. <npcName> glances at you with a puzzled expression. 'By far the best I've ever seen!' you continue. 'Which of course means that, you need not live here, no my friend, a master squatter such as yourself could live...well...anywhere!'. <npcName> ponders on this thought. 'Anywhere...' they say to themselves. 'You're right! That's it, I'm off!' they shout. And without another second passing, <npcName> races out the front door.";
  event4.persuasionFail = "'You don't own this place' you say. 'Okay' <npcName> replies. 'So you must leave.' you implore. 'I'm alright actually' they state before turning away from you."; 

  event4.dread = 7;
  event4.dreadSuccess = "'LEAVE THIS LODGING AT ONCE!' you bellow. A startled <npcName> scuttles around the floor in bewilderment, much in the way a dog might chase its own tail. They clutch any of their possessions they can grab a hold of, and scurry past you out of the front door.";
  event4.dreadFail = "'Listen to me, you wretched pig! I implore...nay...I demand that you vacate this area immediately or...or...' you stutter. Breaking from your monologue you notice <npcName> on the ground, sound asleep. 'Excuse me!' you shout, to no avail. You find it difficult to speak at a volume louder than the squatters snore. 'This is below me' you whisper to yourself as you turn on your heel, and walk away.";

  event4.intelligence = 6;
  event4.intelligenceSuccess = "'I have a plan my friend' you say 'for your continued lodging at this residence'. <npcName> looks at you with interest. You kneel down and peel back one of the floorboards. 'See! Down here!' you motion for the squatter to enter. 'A cosy basement for you!'. <npcName> takes a second to ponder the arrangement. 'Alright, I accept' they say as they jump below. You seal the hole, and take your leave.";
  event4.intelligenceFail = "'I have a plan my friend' you say 'for your continued lodging at this residence'. <npcName> looks at you with interest. 'So we just need to...um...we can...well...if we...' you stutter preceding a deathly long silence. 'Alright, I've got nothing' you admit in shame, before turning around and walking away.";
  
  event4.guitarSuccess = "You unstrap your trusty guitar from your back. 'Listen <npcName>, I'm not going to try and evict you, this really isn't any of my business. But if you will, sit with me for a moment, and enjoy a song perhaps. I can tell that you're tired, me too, so let's relax and spend some time away from this hectic world.' you say and then begin to play a sweet melody.";
  event4.guitarFail = "You unstrap your trusty guitar from your back and begin to play a few notes. 'WHAT IS THAT?' <npcName> screeches. 'Music! Damned be the traveller who dares serenade me with such drivel! Begone with you!' they continue, shuffling you towards, and out of, the door.";
  allEvents.push_back(event4);

  return allEvents;
}