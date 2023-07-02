#include<string.h>
#include "util.h"
#include<fstream>
#include <cstdlib>
#include<iostream>
using namespace std;

class Interface{
protected:
	bool Quit;
	bool Start;
	string Pname;

public:
	string getName() {
		return Pname;
	}
	void SetName(string name) {
		Pname = name;
	}
	bool getQuit() {
		return Quit;
	}
	bool setQuit(bool Exit) {
		Quit = exit;
	}
	bool getStart() {
		return Start;
	}
	bool setStart(bool initialize) {
		Start = initialize;
	}
	void EnterYourName() {
		cout << "Enter your nickname!" << endl;
		ofstream myfile("name.txt");
		myfile << Pname;
		myfile.close();
	}
	
};