#include"BinaryTree.h"
using namespace std;
int main()
{
	BinaryTree bt;

	cout << "MENU" << endl;
	cout << "Here are the options:" << endl;
	cout << "1.��ʼ��������" << endl << "2.���������н���������" << endl << "3.�ж϶������Ƿ�Ϊ��" << endl;
	cout << "4.�������������" << endl << "5.�������������" << endl << "6.�������������" << endl;
	cout << "7.����������" << endl << "8.��������ڵ����" << endl;
	cout << "9.quit" << endl;
	while (1)
	{
		cout << "please input your option" << endl;
		int key;
		cin >> key;
		if (key == 9) break;
		switch (key)
		{
		case 1:
			bt.initBitTree();
			break;
		case 2:
			bt.createBitTree();
			break;
		case 3:
			if (bt.isEmpty())
			{
				cout << "this tree is empty" << endl;
			}
			else
			{
				cout << "this tree is not empty" << endl;
			}
			break;
		case 4:
			bt.preOrderTrav();
			break;
		case 5:
			bt.inOrderTrav();
			break;
		case 6:
			bt.postOrderTrav();
			break;
		case 7:
			bt.countDepth();
			break;
		case 8:
			bt.countLeaf();
			break;
		default:
			break;
		}
	}
	
	
	
	
	
	
	system("pause");
}