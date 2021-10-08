#include "OrderedArray.h"
#include "UnorderedArray.h"
#include <iostream>
using namespace std;

int main()
{
	int numSpaces = 5;
	UnorderedArray<int> array1(numSpaces);
	OrderedArray<int> array2(numSpaces);

	array1.push2(0);
	array1.push2(0);
	array1.push2(0);
	array1.push2(0);
	array1.push2(0);

	array2.push(0);
	array2.push(0);
	array2.push(0);
	array2.push(0);
	array2.push(0);

	int choice2 = 1;
	int choice = 5;

	for (int i = 0; choice2 != 0; i++)
	{
		cout << "What number do you want to enter into the array? Enter 0 to exit: ";
	}

	return 0;
}