#include "C:\Users\user\source\repos\123\sqlite3.h"
#include <cctype>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

using namespace std;

int main()
{
	ifstream inputfile("C:\\Users\\user\\source\\repos\\123\\output\\encrypted.txt");
	ofstream outputfile("C:\\Users\\user\\source\\repos\\123\\output\\decrypted.txt");

	int key = 11;

	int n = 0;

	string line;

	vector<string> stringArray;

	if (!inputfile.is_open())
	{
		cerr << "Error opening input file." << endl;
		return 1;
	}

	if (!outputfile.is_open())
	{
		cerr << "Error opening output file." << endl;
		return 1;
	}


	while (getline(inputfile, line))
	{
		string decryptedresult = "";

		for (char c : line)
		{
			if (isalpha(c))
			{
				char decryptedChar = static_cast<char>((toupper(c) - 'A' - key + 26) % 26 + 'A');
				decryptedresult += islower(c) ? tolower(decryptedChar) : decryptedChar;
			}
			else
			{
				decryptedresult += c;
			}
		}
		outputfile << decryptedresult << endl;
	}

	cout << "\nCompleted!\n";

	inputfile.close();
	outputfile.close();

	return 0;
}