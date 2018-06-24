#include"BinaryTree.h"
using namespace std;
int main()
{
	BinaryTree bt;

	cout << "MENU" << endl;
	cout << "Here are the options:" << endl;
	cout << "1.初始化二叉树" << endl << "2.按先序序列建立二叉树" << endl << "3.判断二叉树是否为空" << endl;
	cout << "4.先序遍历二叉树" << endl << "5.中序遍历二叉树" << endl << "6.后序遍历二叉树" << endl;
	cout << "7.求二叉树深度" << endl << "8.求二叉树节点个数" << endl;
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