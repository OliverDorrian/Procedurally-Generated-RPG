#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct events{
  string name; //name of the event
  string biomeType; //event biome
  string location; //event location
  string faction; //event faction
  string problem[3]; //Problem text
  string attackSuccess; //Attack success text
  string attackFailure; //Attack fail text
  string persuasionSuccess; //Persuasion success text
  string persuasionFail; //Persuasion fail text
  string dreadSuccess; //Dread success text
  string dreadFail; //Dread fail text
  string intelligenceSuccess; //Intelligence success text
  string intelligenceFail; //Intelligence fail text
  string guitarSuccess; //Guitar success text
  string guitarFail; //Guitar fail text
  int rep; //reputation check
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

  event2.attackSuccess = "You kill <npcName>. The jazz music stops.";
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

  event4.attackSuccess = "You kill <npcName>. It's all quiet now.";
  event4.attackFailure = "<npcName> destroys you with indescribable strength. If you lived beyond this moment, you'd vow never to fight a squatter again.";

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

  events event5;
  event5.name = "THIEF!";
  event5.biomeType = "Meadows";
  event5.location = "Roads";
  event5.faction = "Default";
  event5.rep = 2;



  event5.problem[0] = "Strolling through the lush meadows, you hear heavy footsteps approaching you from behind, you react in time to stop an attempt on your money pouch.";
  event5.problem[1] = "Taking a second to rest against a nearby tree, and closing your eyes, a bandit appears and makes an effort for your valuables. You manage to stop him from stealing anything, but now he stands in front of you.";
  event5.problem[2] = "'Stop right there, hand over your belongings and you can leave with your life'  you are not about to let this low life boss you about." ;


  event5.attackSuccess = "Victory! No one will be stealing from you in a rush.";
  event5.attackFailure = "The bandit defeats you.";

  event5.speech = 6;
  event5.persuasionSuccess = "You reason with the bandit, stating that since you stopped him the first time, surely you deserve to get away with your belongings. He seems to agree. ";
  event5.persuasionFail ="In a shocking turn of events, the bandit seems unable to be reasoned with.";

  event5.dread = 7;
  event5.dreadSuccess = " You put your hand on the hilt of your weapon, and the bandit trembles before you then runs away. Clearly, you own an air of fright.";
  event5.dreadFail = "You do your best attempt at looking threatening as you draw your weapon, but the bandit stands tall. It is you who feels as though you should run.";


  event5.intelligence = 4;
  event5.intelligenceSuccess = "Using your wit you manage to make the bandit believe that he already stole your valuables. He must be quite thick.";
  event5.intelligenceFail = "You try to smart talk your way out of this, but you're unable to do outsmart the bandit. Yikes.";


  event5.guitarSuccess ="You play a nice song about the rights and wrongs of the world in a kind, warm tune. This takes the bandit back to his schooldays and he seems to visibly change.";
  event5.guitarFail ="Before you can get into the flow of things, the bandit- seemingly perplexed at the concept of you trying to sing your way out of this- gets bored and decides no amount of money is worth listening to you sing.";
  allEvents.push_back(event5);

  events event6;
  event6.name = "Ambush heard";
  event6.biomeType = "Meadows";
  event6.location = "Roads";
  event6.faction = "Default";
  event6.rep = 2;



  event6.problem[0] = "You come across a man who seems to be very stressed, one of his fingers cut off, you ask him what happened 'I was ambushed, you heard? ' You step towards the man.";
  event6.problem[1] = "You see an overturned carriage, with an injured man looking defeated, but drinking some of his goods that were left unbroken, he is missing a finger.";
  event6.problem[2] = "You hear the tell-tale sounds of an ambush, but by the time you get there it is too late the damage has been dealt, he managed to escape mostly uninjured but lost much of his wares, and a fingertip to boot.";


  event6.attackSuccess = "Well, good job, you killed the poor injured man. Monster ";
  event6.attackFailure = "Deservedly, the injured man bests you. Karma.";

  event6.speech = 6;
  event6.persuasionSuccess = "You convince <npcName> to get up and leave his destroyed belongings, he thanks you for talking sense into him.";
  event6.persuasionFail ="You try to make <npcName> leave his belongings behind and get somewhere safe, but your words seem to have no effect, he really seems a nervous wreck after the ambush you heard.";

  event6.dread = 6;
  event6.dreadSuccess = "You head over to the side of the road where the ambush occurred, Poising your weapon ready to strike at the attacker you see a woman with blonde hair fleeing the scene. You tell <npcName> he is safe now.";
  event6.dreadFail = "As you head towards the ambush site, something rustles in the bushes and you lose your nerve. You head back to <npcName> unsuccessful ";


  event6.intelligence = 6;
  event6.intelligenceSuccess = "You tell <npcName> that if he gets out of this alive he could face his attacker in court. This knowledge seems to bring him some comfort. He thanks you";
  event6.intelligenceFail = " You tell <npcName> that if he gets out of this alive he could face his attacker in court. But he replies 'there's no use, it'll never go my way' You leave the man with a defeated look on his face.";


  event6.guitarSuccess ="Your melody seems to settle the nerves of <npcName> he thanks you for not leaving him during this trying time.";
  event6.guitarFail ="Unfortunately, your tune does nothing to help <npcName> you decide to leave him.";
  allEvents.push_back(event6);

  events event7;
  event7.name = "Poodunit?";
  event7.biomeType = "Meadows";
  event7.location = "Village";
  event7.faction = "Default";
  event7.rep = 2;


  event7.problem[0] = "You overhear some bickering and decide to see what's going on, upon approaching the commotion you hear various accusations of someone pooing in the local river, which is used to clean clothes. One of the villagers approaches you 'Hey, you! We are in need of an impartial 3rd party, could you help us out? ";
  event7.problem[1] = "'POO BANDIT! ' You hear a villager scream. 'Don't call me that you witch, for all I know it was you' It appears the village is currently having a crisis, they can't figure out who left a poo unflushed in the mayor's house. You, being the noble person you are, step in to help.";
  event7.problem[2] = " ' WANTED: DEAD OR ALIVE' It would seem the village has an unknown phantom pooper, currently linked with 4 unspeakable acts of toiletry. Seeing as you seek glory and riches, you decide to see if you can't put a stop to this";


  event7.attackSuccess = "You stand triumphant over the one responsible for these occurrences, this town will be troubled no more.";
  event7.attackFailure = "Oh. Oh dear. I don't think you want anyone seeing you like this. After being bested in combat, the poo bandit marks you.";


  event7.speech = 6;
  event7.persuasionSuccess = "After making a rousing speech the village rallies together and put aside their differences. This changes however when the bandit reveals themselves to everyone publicly. This might end violently but I personally don't think it's your fault.";
  event7.persuasionFail ="You fail to captivate just about anyone really. The village is now unified, but it would seem their new public enemy is you.";

  event7.dread = 6;
  event7.dreadSuccess = "You walk into the centre of all the attention and tower above the lowly villagers, making them cower, one of them is so scared they involuntarily let out a number 2. 'Well it would seem we found him! ' you exclaim. A job well done";
  event7.dreadFail = "You try your best to look as menacing and serious as you can, but no one seems to take you seriously. After a while you realise you had some loo roll stuck to the bottom of your shoe.";


  event7.intelligence = 6;
  event7.intelligenceSuccess = "Using your vast intellect, you simply remind the villagers that what they are all arguing about like toddlers could easily be resolved by adding public toilets to all.";
  event7.intelligenceFail = "You try to appear intelligent but it's clear to all that you don't know anything about what you're trying to preach. You should probably move on.";


  event7.guitarSuccess ="You masterfully play a beautiful tune, which seems to make everyone forget about the conflict.";
  event7.guitarFail ="Just as you are about to get to the main part of your melody, you let out a loud fart. Whoops.";
  allEvents.push_back(event7);

  events event8;
  event8.name = "Who you gonna call?";
  event8.biomeType = "Underworld";
  event8.location = "Crypt";
  event8.faction = "Default";
  event8.rep = 2;


  event8.problem[0] = "POOF! A flash of blue light briefly appears and then disappears as soon as it started. Leaving in its trace, a stern ghostly apparition. 'HOW DARE YOU ENTER MY CRYPT!? Leave now, mortal! ' the ghost screams. It would appear you have upset him slightly, but you don't want to let him stand in the way of you and accruing your riches.";
  event8.problem[1] = "The crypt shakes around you, violently, as though the building itself wants you to leave. 'YOU HAVE THE NERVE TO DISTURB MY REST?! ' says a voice, though it has no body yet. Then, out of the tomb raises a dark, menacing figure. You need to get out of here somehow.";
  event8.problem[2] = "A spooky, scary skeleton beckons you deeper into the crypt, the way it stares at you sends a shiver down your spine. 'ohhhh it's been so long since the last foolish adventurer came in here, I've been so bored. ' The skeleton lunges towards you.";


  event8.attackSuccess = "After a large degree of effort, you defeat your enemy, killing them. Again";
  event8.attackFailure = "The undead being bests you, it must have had a lot of experience during its life";


  event8.speech = 6;
  event8.persuasionSuccess = "'Hey, come on now I just wanted some coin, can't you help a guy out? ' Upon hearing this you see a tear form in the corner of where the ghost's eye would be, and it allows you to go on your way. It turns out ghosts have quite the false reputation.";
  event8.persuasionFail ="'Spare me your sniffling, whelp. ' You feel a sharp pain as the ghost gets a quick jab in to shut you up.";

  event8.dread = 9;
  event8.dreadSuccess = "Somehow you manage to scare a literal ghost back into its grave. Well done.";
  event8.dreadFail = "Not quite sure what you were trying to achieve there. Obviously, that didn't work.";


  event8.intelligence = 8;
  event8.intelligenceSuccess = "You, being a highly intellectual being, simply remind the ghost that it is dead, and it promptly disappears.";
  event8.intelligenceFail = "Your wits fail you, you can't think of anything to say that would have an impact here.";


  event8.guitarSuccess ="You hastily bring out the guitar and let loose the first song that comes to mind. The ghost seems appeased at this performance 'Well, I really enjoyed that. That song really was a thriller.";
  event8.guitarFail ="In your state of pure fear, you can't keep your hands from quivering, and you mess up what you were trying to play.";
  allEvents.push_back(event8);

  events event9;
  event9.name = "The people's champion.";
  event9.biomeType = "Meadows";
  event9.location = "Village";
  event9.faction = "Default";
  event9.rep = 2;



  event9.problem[0] = "As you walk through the town centre, dipping through the back alleys to get out the other side of the village, you overhear the distinct sounds of a fight, a rather one-sided one. A poor old man hunched over on the floor, getting kicked by a thug. You decide to help.";
  event9.problem[1] = "'please, stop', you hear someone whimper as you skulk through the backend of the village streets. *THUD* *THUD*, the clear sounds of a beating. You must help this poor victim.";
  event9.problem[2] = "Walking through the village you see someone beating a poor defenceless old man, and decide to help. 'Just who do you think you are' asks the thug. 'I'm vengeance' you reply. ";


  event9.attackSuccess = "Turns out picking on someone his own size wasn't something he could manage. Truly, you are the shadow for the scum and villainy of this village to fear.";
  event9.attackFailure = "The thug bests you in combat. Not a good day for vigilantism.";

  event9.speech = 6;
  event9.persuasionSuccess = " 'Hey that's some impressive skill, surely that could be put to use in a better way? Have you tried professionally fighting rather than preying on defenceless people? ' Upon hearing your kind words the thug leaves the man alone and you feel as though a new chapter has started in his life.";
  event9.persuasionFail ="Unable to think of a convincing reason to compel him to stop his attack, you decide there is nothing to be done.";

  event9.dread = 7;
  event9.dreadSuccess = "Donning your signature black eyeliner, you step from the shadows, wind flapping against your cloak. The sight is enough to make any man run, which is exactly what happens.";
  event9.dreadFail = "You are unable to provoke any sort of fear in the thug.";


  event9.intelligence = 7;
  event9.intelligenceSuccess = "You draw upon your vast experience of law and say 'Assault is illegal my friend'. Excellent work.";
  event9.intelligenceFail = "It would appear watching 3 episodes of suits doesn't qualify as a law degree. Your threats about jail time don't seem to work.";


  event9.guitarSuccess ="You use your guitar and masterfully play a rendition of something in the way. The thug recognises the meaning of this and runs away.";
  event9.guitarFail ="You couldn't quite play well enough to replicate the song you had in mind. Defeated, you lower your head and back away.";
  allEvents.push_back(event9);

  events event10;
  event10.name = "The half-wit in the bandit sand pit";
  event10.biomeType = "Desert";
  event10.location = "Camp";
  event10.faction = "Bandit";
  event10.rep = 2;



  event10.problem[0] = "A crowd of Goblins and Orcs surround a crudely designed web of wooden spikes encircling a bloodied and battered pit. <npcName> roars at the crowd. They stand amidst the gore, at the centre of the pit, clutching the head of an Orc they'd just butchered in battle. 'I AM THE UNDEFEATED' they bellow. The spectators become rowdy. This wasn't <npcName>'s first victory. 'WHO'S NEXT' they cry. Hands from everywhere shoot up into the air, each desperate to be selected by the champion. Lost in the elation, you raise your hand as well. What a wonderful display of bravado this all is, you think to yourself. Without hesitation, <npcName> casts their weapon in your direction. 'YOU!' they scream. 'FACE ME!'. Looking nervous, you clamber into the pit. The crowd goes mad with excitement. Perhaps this wasn't the brightest idea, you think to yourself.";
  event10.problem[1] = "You pass through an open area, littered with scraps of parchment containing scribblings of numbers and symbols. The trail leads to an arena, surrounded by an excited mob of Goblins and Orcs. You notice an ocean of mutilated bandit scholars caking the arena floor. '2 PLUS 2 IS 5' <npcName> yells, standing amid the corpses. 'LET ANYONE BRAVE ENOUGH, CHALLENGE THIS NOTION, AND I SHALL PROVE JUST HOW WRONG YOU ARE''. It seems as though these bandits have been trying to understand math. In your haughty hubris, you step forward. 'I shall hear no more of this nonsense.' you cry. '2 plus 2 is 4'. The crowd gasps and turns to face you. <npcName> grins. 'If that is so, little outsider, come down here and convince me'. You realise you are being challenged into combat. This is perhaps one of your more regrettable decisions, you think to yourself.";
  event10.problem[2] = "Wandering around the camp, you find a crowd of Goblins and Orcs scribbling notes on flat chunks of rocks. They surround a pit adorned with spikes and corpses. You overhear <npcName> in the centre of the pit, addressing the crowd. They're giving a lecture on advanced mutilation and disfigurement of common folk. 'You see, the works of professor Hamgor the Studious seem to imply that brutality should intrinsically come before technique.' they declare. 'It's with this in my mind that I...' <npcName> stops mid sentence upon observing your presence. 'You there!' they cry. 'I don't recognise you. Have you paid the fee to attend this lecture?'. You freeze on the spot. You hadn't paid the fee. 'Uh...' you tremble 'no I didn't'. 'I apologise students for this heinous disruption to your learning' <npcName> says 'May I demonstrate what we've covered with a practical example?'. The crowd drop their notes and clamour with overzealous fervour. You're hurled into the pit. Getting to your feet, you brush yourself off, and find yourself standing face to face with <npcName>.";


  event10.attackSuccess = "Landing hit after hit, you bring <npcName> to their knees. They gaze up at you in horror. You turn to face their leader, Grogbor the Glorious, sitting on his elevated makeshift throne. He takes some time to ponder the events. <npcName> quivers with fear as the crowd cheers at your performance. After a moment, Grogbor the Glorious sticks out his hand, and gestures a thumbs down. <npcName> howls in terror. You cut their misery short, and in one fell swoop, strike their head from their body. You emerge victorious.";
  event10.attackFailure = "Landing hit after hit, <npcName> brings you to your knees. You gaze up at them in horror. They turn to face their leader, Grogbor the Glorious, sitting on his elevated makeshift throne. He takes some time to ponder the events. You quiver with fear as the crowd cheers at <npcName>'s performance. After a moment, Grogbor the Glorious sticks out his hand, and gestures a thumbs down. You howl in terror. <npcName> cuts your misery short, and in one fell swoop, strikes your head from your body. You succumb to defeat.";

  event10.speech = 6;
  event10.persuasionSuccess = " ''Whoa whoa whoa, cool off there slick!' you say to <npcName>. 'There's no need for this to get violent. And besides, why waste your strength on a meek outsider like me? I mean that's no challenge, a great warrior like you deserves a better opponent!'. <npcName> takes a moment to think. 'Outsider, you make a fair point. Now take your weakness elsewhere, before I batter you'. You swiftly make your exit from the pit.";
  event10.persuasionFail ="'Hey now' you say 'how about we just settle this like gentlemen? Let's just sit down and talk it out!'. <npcName> doesn't seem to hear you over the crowd. They charge towards you and pummell you into the ground. Lifting you up by your leg, they bring their face to yours. You gulp in fear. <npcName> begins to spin around in a circular motion, holding you out in front of themself. Before long, they release their grip, and you go flying into the air, travelling far beyond the walls of the bandit camp.";

  event10.dread = 7;
  event10.dreadSuccess = "You spin around in a circle barking. <npcName> looks bewildered. 'Don't come any closer! BARK BARK BARK! I'll get you, hahaha, yeah I'll get you!' you mutter. At the sight of this, <npcName> decides they want no part in your madness.";
  event10.dreadFail = "You raise your arms to your side, and bend your left leg, resting your foot on the side of your other leg. 'I KNOW KUNG FU' you yell. But as you say this, the muscles in your leg begin to tighten. 'Ow..ouch..cramp..cramp..cramp' you say, hopping around in an attempt to ease your pain. <npcName> grabs your arms. You gulp in fear. They begin to spin around in a circular motion, holding you out in front of themself. Before long, they release their grip, and you go flying into the air, travelling far beyond the walls of the bandit camp.";


  event10.intelligence = 7;
  event10.intelligenceSuccess = "'I've got to find a way out' you mutter to yourself. <npcName> charges towards you in a rage. Just before they reach you, you sidestep left. Bewildered, <npcName> trips on a stone and flies into the air. They fall back down, only to land on their own weapon, killing them in the process. The crowd goes silent. 'Have a nice trip!' you say before long. The crowd roars in ecstasy.";
  event10.intelligenceFail = "'I've got to find a way out' you mutter to yourself. <npcName> charges towards you in a rage. 'I've got it' you say as you dive forwards, head first, into the sand. Squirming and wriggling you attempt to burrow your head beneath the grit. After a few seconds, a puzzled <npcName> lifts you out of the ground by your leg, suspending you upside down. You gulp in fear. They begin to spin around in a circular motion, holding you out in front of themself. Before long, they release their grip, and you go flying into the air, travelling far beyond the walls of the bandit camp.";


  event10.guitarSuccess ="Ignoring your impending doom for a few moments, you realise the opportunity that lays before you. You unstrap the guitar from your back, your audience awaits. Playing a melody, you begin to sing 'Soooo Sally can wait, she knows it's too late'. The crowd join in, and soon forget about the violence.";
  event10.guitarFail ="'An audience?' you think to yourself. This seems like the perfect time to play a little tune. You unstrap the guitar from your back and play a little tune. Nobody seems to hear it though, and <npcName> grabs your face and launches you beyond the camp walls. What were you thinking?'";
  allEvents.push_back(event10);

  return allEvents;
}