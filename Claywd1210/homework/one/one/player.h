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
using namespace std;

class player{	//define base player class
	protected:
		int input;
		string name;
		
	public:
//	inline player(string n){name = n;};
	string askName();
	int getRange(vector<int> set);
	int getGuess(int range, int check, vector<int> guess, vector<int>& toSort, int& high, int& low);
};

class user: protected player{	//declare and derive user class from player class
	public:
		string askName()
		{
			cout<<"Please enter your name"<<endl;
			cin>>name;
			return name;	
		};
		int getRange(vector<int> set)	//define function for user class
		{
			while(true)
			{
				cout<<" Great please choose an option from the set as your highest value: {1,2,4,8,16,32,64,128,256,512,1024,2048}"<<endl;
				cin>>input; 
				vector<int>::iterator it=find(set.begin(), set.end(), input);
				
				if (it !=set.end()) {return input; break;}
				else {cout<<"Sorry, that is not an option, Let's try again. \n"; }
			}
		};
		int getGuess(int maxRange, int check, vector<int> guess, vector<int>& toSort, int& high, int& low)
		{
			bool checkInput = false;
			while(!checkInput)
			{
				cout<< "Please enter a number between 1 & "<< maxRange<<"\n";
				cin>>input;
				if(input<=maxRange && input>0){checkInput = true; return input; break;}
				else {cout<<"Sorry, that is not within the range of 1 - "<<maxRange<<". Please try again. \n";}
			}
		};
};

class computer: protected player{	//declare and dervice computer class from player class. 
	public:
		computer(){name="computer";};
		int getRange(vector<int> set)
		{

			srand ( time(NULL) ); //initialize the random seed
			int randIndex= rand() % set.size(); //generates a random number between 0 and 11
			input= set[randIndex];
			cout<<input;
			return  input;
		};
		int getGuess(int range, int check, vector<int>& guess, vector<int>& toSort, int& high, int& low)
		{
			if (check != 3)
			{
				if (check == 2)//value too great need to decrease max
				{
					int pos = find(toSort.begin(), toSort.end(), high) - toSort.begin();	//get position of last guess
					toSort.erase(toSort.begin()+pos,toSort.end());
				}
				
				if (check == 1)//value too low need to update min
				{
					int pos = find(toSort.begin(), toSort.end(), low) - toSort.begin();	//get position of last guess
					toSort.erase(toSort.begin(),toSort.begin()+pos);
				}
				
				double middle = toSort.size()/2;
				cout<<"middle = "<<middle<<endl;
				int mid= middle;
				cout<<"mid = "<<mid<<endl;
				if(middle < 2){return toSort[1]+1;	}
				else return toSort[mid];
			}
			else if (check ==3)
			{
			srand ( time(NULL) ); //initialize the random seed
			input= rand() % range + 1; //generates a random number between 0 and 11
			return  input;
			}	
			else if (check == 4)
			{
				cout<<"coming soon!"<<endl;
			}
			
			
		};
		string askName(){name="Computer"; return name;};

};
