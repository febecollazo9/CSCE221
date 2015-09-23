#include <iostream>
#include <vector>
using namespace std;

void fillVector(vector<int>& vec) {
	vector<int>::iterator it = vec.begin();
	for(int i=0;i<=9;++i) vec.push_back(i); ++it;
}

void printVector(const vector<int> &v) {
	for(vector<int>::const_iterator it=v.begin();it!=v.end();++it)
		cout << (*it) << ' ';
	cout << endl;
}

int main(int argc, char **argv) {
	vector<int> vec;
	fillVector(vec);
	printVector(vec);
	vec.push_back(10);
	printVector(vec);
	return 0;
}
