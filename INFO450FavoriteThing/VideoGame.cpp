#include "stdafx.h"
#include "VideoGame.h"
#include <iostream>
#include <fstream>

using namespace std;


	int VideoGame::addVideoGame()
	{
		cout << "Please enter the name of the game" << endl;
		cin.clear();
		getline(cin, name);
		cout << "Please enter the genre" << endl;
		cin.clear();
		getline(cin, genre);
		cout << "Please enter the ESRB rating (E,T,M,A)" << endl;
		cin.clear();
		cin >> rating;
		cout << "Please enter the cost" << endl;
		cin.clear();
		cin >> cost;
		return 0;
	}

	void VideoGame::displayVideoGame()
	{
		cout << "Name: " << name << endl;
		cout << "Genre: " << genre << endl;
		cout << "Rating:" << rating << endl;
		cout << "Cost: " << cost << endl;
	}

	
	VideoGame::VideoGame()
	{
		name = "";
		genre = "";
		rating = "";
		cost = 0;
	}
	
	VideoGame::VideoGame(string n, string g, string r, int c)
	{
		name = n;
		genre = g;
		rating = r;
		cost = c;
	}

	ofstream& operator<<(ofstream &fs, VideoGame *item)
	{
		fs << item->name << "|" << item->genre << "|" << item->rating << "|" << item->cost << endl;
		return fs;
	}
	 bool operator == ( VideoGame a,VideoGame b) 
	{
		if (a.name == b.name)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}