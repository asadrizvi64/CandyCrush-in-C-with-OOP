#include<string.h>
#include<iostream>
using namespace std;

class Jewel{
private:
	int x,y ;
	string Gem;
public:
	int choosen = 0;
	 int select;
	 int ch_x;
	 int ch_y;
	int getx() {
		return x;
	}
	void setx(int a) {
		x = a;
	}
	int gety() {
		return y;
	}
	void sety(int b) {
		y = b;
	}
	string getGem() {
		return Gem;
	}
	void setGem(string cb) {
		Gem = cb;
	}
};
