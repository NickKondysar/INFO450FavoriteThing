
#include "stdafx.h"
#include "VideoGame.h"
#include <iostream>
#include <fstream>
using namespace std;

const int LEN = 10;


int main()
{
	VideoGame **mylist;
	int count = 0;
	int i;
	string response = "Y";
	string outputFile;


	mylist = new VideoGame*[LEN];


	cout << "Specify a file to output to" << endl;
	cin >> outputFile;

	ifstream infile(outputFile);
	if (infile.good())
	{
		while (!infile.eof())
		{
			string name, genre, rating, cost;
			getline(infile, name, '|');
			if (name.length())
			{
				getline(infile, genre, '|');
				getline(infile, rating, '|');
				getline(infile, cost, '\n');
				mylist[count] = new VideoGame(name, genre, rating, stoi(cost));
				count++;
				
			}
		}
	}
	cout << "There were: " << count << " objects read in from the file." << endl;
	cin.ignore();
	while (response == "Y" || response == "y")
	{
		mylist[count] = new VideoGame();
		if (mylist[count]->addVideoGame() == 0) 
		{
			for (int i = 0; i < count; i++)
			{
				if (mylist[count] == mylist[i])
				{
					cout << "That video game is already in the list." << endl;
					delete mylist[count];
					count--;
				}
			}
			count++;
		}
		cout << "Another one?" << endl;
		cin >> response;
		cin.ignore();
	}


	for (i = 0; i < count; i++)
	{
		mylist[i]->displayVideoGame();
	}

	//Save to a File
	cout << "Specify a file to output to" << endl;
	cin >> outputFile;
	ofstream outfile(outputFile);
	if (!outfile.good())
	{
		cout << "ERROR - cant open file for output! " << endl;
		return -1;
	}

	for (i = 0; i < count; i++)
	{
		outfile << mylist[i];
	}

	
	for (i = 0; i < count; i++)
	{
		delete mylist[i];
	}
	delete mylist;


	return 0;
}
