#include<iostream>
#include"Sort.h"
using namespace std;
int main()
{
	sorting sortInst;
	cout << "**************************************" << endl;
	cout << "Here is the description for this test program" << endl;
	cout << "                                        " << endl;
	cout << "-----------------------------" << endl;
	cout << "* MENU FOR TESTING SORT ALGORITHM" << endl;
	cout << "* OPTIONS:" << endl;
	cout << "* 1. insert sort" << endl;
	cout << "* 2. select sort" << endl;
	cout << "* 3. heap sort" << endl;
	cout << "* 4. fast sort" << endl;
	cout << "* 5. bubble sort" << endl;
	cout << "* 6. merge sort" << endl;
	cout << "-----------------------------" << endl;
	cout << "press  [Q]  to exit the programme" << endl;
	cout << "press  [R]  to generate/refresh the test data" << endl;
	cout << "press  [T]  to test the algorithm" << endl;
	cout << "**************************************" << endl;
	
	while (1)
	{
		char key;
		cin >> key;
		if (key == 'q') break;
		if (key == 'r')
		{
			cout << "-----" << endl;
			cout << "waiting for refreshing, please input the number of test set( input [0] to stop refreshing )" << endl;
			int n;
			while (1)
			{
				cin >> n;
				if (n == 0)
				{
					cout << "-----" << endl;
					break;
				}
				if (n < 2 || n > maxSize)
				{
					cout << "your input is out of range, please input again" << endl;
					continue;
				}
				sortInst.genTestData(n);
				cout << "test data refreshed" << endl << "-----" << endl;
				break;
			}
		}
		if (key == 't')
		{	
			cout << "waiting for test, press [0] to exit" << endl;
			while (1)
			{
				if (sortInst.testData.empty())
				{
					cout << "please generate the test data first" << endl << "*****" << endl;
					break;
				}
				cout << "*****" << endl;
				cout << "please choose the algorithm" << endl;
				int t;
				cin >> t;
				if (t == 0) break;
				switch (t)
				{
				case 1:
					sortInst.insertSort();
					break;
				case 2:
					sortInst.selectSort();
					break;
				case 3:
					sortInst.heapSort();
					break;
				case 4:
					sortInst.fastSort();
					break;
				case 5:
					sortInst.bubbleSort();
					break;
				case 6:
					sortInst.mergeSort();
					break;
				default:
					cout << "Not a option, please input again" << endl;
					break;
				}
			}
			cout << "*****" << endl;
		}
	}
	return 0;
}