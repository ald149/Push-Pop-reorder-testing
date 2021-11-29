#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<fstream>
#include<set>
#include<queue>

using namespace std;

// function prototype
void testPerm(queue<int>, queue<int>);


int main() {

	ifstream inFile;		            //create input stream object
	ofstream outFile;		            //create output stream object
	string readFile = "Lab1Input.txt";	// name of input txt file
	set<int> numbers;	                // set to order numbers
	vector<int> testCase;               //
	queue<int> trainA;					// queue that holds in order set of numbers for track A
	queue<int> tC;
	string words;		                // string to hold all the characters inputted from the text file	
	int num;							// individual ints to be pushed into testCase vector and numbers set
	static int TESTCC;					// number of ints in testCase 
	static int NUMTESTCASES;			// number of test cases in the input

	inFile.open(readFile);	            // open lab1input file to read test cases
	if (inFile)				            // test success of file open
		cout << "file opened." << endl << endl;

	while (inFile >> words) {			// while there is input from txt file

		num = stoi(words);              // convert string input into ints
		testCase.push_back(num);		// fill testCase with ints
		numbers.insert(num);			// populate numbers ordered set with integer input
	}

	testCase.erase(testCase.begin());   // removes tag number
	numbers.erase(numbers.begin());	    // remove the zero 
	TESTCC = numbers.size();		    // number of ints per test case 


	vector<int> trackA(numbers.begin(), numbers.end());		// populate vector from set
	for (int i = 0; i < trackA.size(); i++) {
		trainA.push(trackA[i]);								// populate trackA queue with elements from vector 
	}

	while (testCase.front() != 0)
	{

		for (int j = 0; j < TESTCC; j++)
		{
			tC.push(testCase[j]);				// populate tC queue from vector testCase
		}


		testPerm(trainA, tC);		// call to permutation test function

		for (int i = 0; i < TESTCC; i++)
		{
			testCase.erase(testCase.begin());
			tC.pop();
		}

	}

	inFile.close();
	return 0;

}// end main

void testPerm(queue<int> trainA, queue<int> tC)
{
	queue<int> trackB;
	stack<int> station;

	while (!tC.empty())
	{
		trackB.push(tC.front());
		tC.pop();

	}



	while (!trainA.empty())
	{

		int element = trainA.front();
		trainA.pop();
		if (element == trackB.front())
		{
			trackB.pop();
			while (!station.empty())
			{
				if (station.top() == trackB.front())
				{
					station.pop();
					trackB.pop();
				}
				else
					break;
			}
		}
		else
			station.push(element);
	}
	if (trainA.empty() && station.empty())
		cout << "yes" << endl;
	else
		cout << "no" << endl;


	while (!trackB.empty())
	{
		trackB.pop();
	}
	cout << endl;
}
