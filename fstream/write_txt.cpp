// writing on a text file
#include <iostream>
#include <fstream>
using namespace std;

int main () {
	ofstream myfile ("example.txt");
	if (myfile.is_open())
	{
		for(int i = 0; i < 50; i++)
		{
			myfile << i << "\n";
		}
		myfile.close();
	}
	else cout << "Unable to open file";
	return 0;
}
