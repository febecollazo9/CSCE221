#include "game.h"

using namespace std;

int main()
{
	user usr;
	computer comp;
	game first(0);

	first.setupGame(usr, comp);
	first.playGame(usr, comp);
	cout<<"Number of Guesses it took to get the right answer"<<first.getNumGuess()<<endl;
	
return 0;
}