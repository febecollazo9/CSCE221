#include<array>
#include<regex>
#include<thread>
#include<mutex>
#include<forward_list>
#include<ratio>
#include<tuple>
#include<chrono>
#include<random>
#include<iostream>
#include<fstream>
#include<sstream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<list>
#include<vector>
#include<algorithm>
#include<stdexcept>
#include"player.h"
using namespace std;

class game{
	friend class player;
	int trigger;
	int maxRange=0;
	int trueAns;
	int highGuess;
	int lowGuess;
	int numGuess=0;
	vector<int> Guess;
	vector<int> toSort;
	vector<int> set={1,2,4,8,16,32,64,128,256,512,1024,2048};
	
	public:
		game(int v);
		int setRange(user usr, computer comp);
		int getRange();
		//int getPlayers(player)
		//string getPlayers();
		int getNumGuess();
		int checkGuess(int guessed);
		void playGame(user usr, computer comp);
		void setupGame(user usr, computer comp);
};




			