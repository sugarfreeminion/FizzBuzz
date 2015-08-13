#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc,char *argv[])
{
	int input[3];
	int fizz,buzz;
	int maxCount;
	int testCaseIndex = 0;
	
	string dataFile;
	
	ifstream inputFile(argv[1]);
	
	bool isInputOk = true;
	
	//cin >> dataFile;
	
	//inputFile.open(dataFile.c_str());
	
	if(inputFile.is_open() == false)
	{
		cout << "Error opening file" << endl;
	}
	else
	{
		while(testCaseIndex <= 20 &&
			  inputFile.eof() == false)
		{
			string userInput = "";
			
			getline(inputFile,userInput);
			
			int index = 0;
			int inputIndex = 0;
			int start = 0;
			
			isInputOk = true;
			
			if(userInput != "")
			{
				while(index <= userInput.length())
				{
					if(userInput[index] == ' ' || index == userInput.length())
					{
						string foo = userInput.substr(start,index-start);
						
						istringstream str(foo);
						
						str >> input[inputIndex];
						
						++inputIndex;
						
						start = index+1;
					}
					
					++index;
				}
				
				index = 1;
				fizz = input[0];
				buzz = input[1];
				maxCount = input[2];
				
				if(fizz < 1 || fizz > 20)
				{
					printf("Error with fizz in test case %d!",testCaseIndex);
					isInputOk = false;
				}
				
				if((buzz < 1) || (buzz > 20))
				{
					printf("Error with buzz in test case %d!",testCaseIndex);
					isInputOk = false;
				}
				
				if(maxCount < 21 || maxCount > 100)
				{
					printf("Counting to far in test case %d!",testCaseIndex);
					isInputOk = false;
				}
				
				if(isInputOk == true)
				{
					while(index <= maxCount)
					{
						if((index % fizz == 0) && (index % buzz == 0))
						{
							printf("FB ");
						}
						else if(index % fizz == 0)
						{
							printf("F ");
						}
						else if(index % buzz == 0)
						{
							printf("B ");
						}
						else
						{
							printf("%d ", index);
						}
						++index;
					}

					printf("\n");
				}
			}
			
			++testCaseIndex;
		}
	}	
	
	return 0;
}