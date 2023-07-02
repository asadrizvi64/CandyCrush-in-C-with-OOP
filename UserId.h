#include<string.h>
#include"menu.h"
#include<iostream>
using namespace std;

class UserId:public Interface {
private:
	int Score;
	Interface I1;
	int level;
public:
	int getScore() {
		return Score;
	}
	void setScore(int score) {
		Score = score;
	}
	int getLevel() {
		return level;
	}
	void setGem(int lvl) {
		level = lvl;
	}


};

