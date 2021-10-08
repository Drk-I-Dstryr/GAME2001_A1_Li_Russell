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

	int exit = 1;
	int choice = 5;

	//bool dupData = false;

	for (int i = 0; exit != 2; i++)
	{
		cout << "What number do you want to enter into the array? Enter 0 to exit: ";
		cin >> choice;

		if ((array2.search(choice)) != -1)
		{
			cout << "You cannot enter duplicate data." << endl << endl;
		}
		else
		{
			array2.push(choice);
		}
		array1.push2(choice);

		for (int i = 0; i < array2.GetSize(); i++)
		{
			cout << array2[i] << " ";
		}

		cout << "\n\nDo you want to exit? 1 = no, 2 = yes: ";
		cin >> exit;
	}

	return 0;
}