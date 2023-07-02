#include<iostream>
#include<cstring>
#include<string.h>
#include<fstream>
#include"interface.h"

using namespace std;
class Menu : public Interface {
protected:
	int MenuArr[4];
	Interface I;
public:
	bool getStart() {
		return Start;
	}
	void setStart(bool initializer) {
		Start = initializer;
	}
	void howtoplay() {

		ifstream myfile;
		myfile.open("H2P.txt");
		if (myfile) {
			//	display;
		}
		else {
			cout << "File cannot be accessed";
			myfile.close();
		}
		myfile.close();
	}

};