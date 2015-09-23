#include "game.h"

int game::getNumGuess(){return numGuess;};
int game::getRange(){return maxRange;};
int game::setRange(user usr, computer comp)
{
	string userChoice;
	//bool check = false;
	while(true)
	{
		cout<<"set range manually? (yes or no)"<<endl;
		cin>>userChoice;
		
		if (userChoice == "yes") { maxRange =usr.getRange(set); break;}
		else if (userChoice == "no"){maxRange=comp.getRange(set); break;}
		else cout<<"Sorry but it's either yes or no. Lets try again \n"<<endl;
	}
		return 0;
};
game::game(int v)
{
	//static const int sets[12]= {1,2,4,8,16,32,64,128,256,512,1024,2048};
	//vector<int> vec (sets, sets + sizeof(sets) / sizeof(sets[0]) );
	trigger=v;
};

//play game
void game::playGame(user usr, computer comp)
{	
	if (trigger == 1)	//user is picking a number and computer is guessing.
	{
		int check =3;
		setRange(usr, comp);
		trueAns = usr.getGuess(maxRange, check, Guess, toSort, highGuess, lowGuess);
		for (int i =0; i< maxRange; ++i)	// fill vector
		{toSort.push_back(i);}	
		
		lowGuess=1;
		highGuess=maxRange;	
			
		Guess.push_back(comp.getGuess(maxRange,check, Guess, toSort, highGuess, lowGuess));
		cout<<"Computer guessed "<<Guess.back()<<endl;
		check = checkGuess(Guess.back());
		++numGuess;

		//for(int i=0; i<maxRange; ++i) 
		while(check != 0)
		{
			Guess.push_back(comp.getGuess(maxRange, check, Guess, toSort, highGuess, lowGuess));
			cout<<"Computer guessed "<<Guess.back()<<endl;
			check = checkGuess(Guess.back());
			++numGuess;
		}

	}
	else if (trigger == 2)	// User is guessing the number, computer is picking range and set
	{	
		int check = 3;		
		setRange(usr, comp);
		trueAns = comp.getGuess(maxRange, check, Guess, toSort, highGuess, lowGuess);
		vector<int>::iterator it = Guess.begin();
		
		Guess.push_back(usr.getGuess(maxRange, check, Guess, toSort, highGuess, lowGuess));
		check = checkGuess(Guess[0]);
		++numGuess;

		while (check != 0)
		{

			Guess.push_back(usr.getGuess(maxRange, check, Guess, toSort, highGuess, lowGuess));
			check = checkGuess(Guess.back());
			++numGuess;
			
		}
	}
	
};


void game::setupGame(user usr, computer comp)
{
	int choosePlayer;
	int range;
	
	cout<<"Welcome to the random number guessing game! \n"<<endl;
	cout<<"In this game you can either be player1  who will be choosing a number between 1 & the selected range or player2 who two will be attempting to guess what that number is. \n"<<endl;
	cout<<"Would you prefer to pick the number as player1 or guess the number as player2? \n"<<"I would like to be player......(enter 1 or 2) ";
	cin>>choosePlayer;

	if (choosePlayer == 1)
	{
		usr.askName();
		comp.askName();
		trigger = 1;
	}
	else if(choosePlayer == 2)
	{
		comp.askName();
		usr.askName();
		trigger = 2;
	}
	else cout<<"coming soon"<<endl;//load file
	
};

int game::checkGuess(int guessed)
{
	while(true)
	{	
		if (guessed<trueAns)
		{
			cout<<"Guess Higher!- the number to be guessed is higher than the number in question."<<endl;
			cout<<"True answer = "<<trueAns<<endl;
			lowGuess = guessed;
			return 1;
			break;
		}
		else if (guessed>trueAns)
		{
			cout<<"Guess Lower!- the number to be guessed is Lower than the number in question."<<endl;
			cout<<"True answer = "<<trueAns<<endl;
			highGuess = guessed;
			return 2;
			break;
		}
		else if (guessed == trueAns) {cout<<"Yes!!!! the number is found!"<<endl; return 0; break;}
		else cout<<"sorry, Let's try that again"<<endl;
	}
};


