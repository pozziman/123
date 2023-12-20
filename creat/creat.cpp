#include <cctype>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const int key = 11;
const int lenght = 20;


int main()
{
	int digit1 = 0;

	srand(time(0));

	string chars = "qwertyuiopasdfghjklzxcvbnm1234567890";

	string org = "";
	string encrypted = "";

	ofstream outputFile("C:\\Users\\user\\source\\repos\\123\\output\\encrypted.txt");
	ofstream outputFile1("C:\\Users\\user\\source\\repos\\123\\output\\org.txt");


	if (!outputFile.is_open() || !outputFile1.is_open())
	{
		cerr << "Error opening output files." << endl;
		return 1;
	}

	for (int q = 0; q < lenght; q++)
	{
		for (int i = 0; i < lenght; i++)
		{
			int index = rand() % chars.length();
			org += chars[index];
		}
		if (outputFile.is_open())
		{
			for (char c : org)
			{
				if (isalpha(c))
				{
					char encryptedChar = static_cast<char>((toupper(c) - 'A' + key) % 26 + 'A');

					encrypted += islower(c) ? tolower(encryptedChar) : encryptedChar;
				}
				else
				{
					encrypted += c;
				}
			}
			outputFile1 << org << endl;
			outputFile << encrypted << endl;
		}
		org = "";
		encrypted = "";
	}
	outputFile.close();
	outputFile1.close();

	return 0;
}