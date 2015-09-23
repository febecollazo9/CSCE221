#include <regex>
#include <thread>
#include <mutex>
#include <forward_list>
#include <ratio>
#include <tuple>
#include <chrono>
#include <random>
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
#include<time.h>
#include<stdlib.h>
#include <stdio.h>
using namespace std;


int main()
{
	string input;

	cout << "Please enter a string: ";
	cin >> input;
	
	if (input == string(input.rbegin(), input.rend())) 
	{
		cout << input << " is a palindrome";
	}
return 0;
}
