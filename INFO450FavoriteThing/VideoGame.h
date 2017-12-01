#pragma once
#include <string>
using namespace std;

class VideoGame
{
private:
	string name;
	string genre;
	string rating;
	int cost;
public:
	int addVideoGame();
	void displayVideoGame();
	VideoGame();
	VideoGame(string n, string g, string r, int c);

	friend ofstream& operator<<(ofstream &fs, VideoGame *item);
	friend bool operator ==( VideoGame a,  VideoGame b);
};