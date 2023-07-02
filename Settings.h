#include<iostream>
#include"UserId.h"

using namespace std;
class Settings: public Interface {
	int highscore = 0;
	int mode = 0;
public:
	void modeset(int x) {
		mode = x;
	}
	int getmode() {
		return mode;
	}
	void setHS(int x) {
		highscore = x;
	}
	int getHS() {
		return highscore;
	}

};