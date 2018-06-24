#pragma once
/*
*	@author: ZhouHang
*	data structure project
*	binary tree
*/
#include<iostream>

typedef char DataType;
typedef struct BitNode
{
	DataType data;
	struct BitNode * lChild, *rChild;
}*BitTree;

class BinaryTree
{
	BitTree root;
public:
	BinaryTree() { root = NULL; }

	/*
	*	init the binary tree
	*/
	void initBitTree();

	/*
	*	construct the binary tree in pre-order
	*/
	void createBitTree();

	/*
	*	judge if the tree is empty
	*/
	bool isEmpty();

	void preOrderTrav();
	void postOrderTrav();
	void inOrderTrav();
	int countLeaf();
	int countDepth();
};


void BinaryTree::initBitTree()
{
	root = NULL;
	std::cout << "init binary tree successfully" << std::endl;
}

void createTree(BitTree * p)
{
	char q;
	std::cin >> q;
	if (q == '#')
	{
		*p = NULL;
	}
	else
	{
		*p = (BitTree)malloc(sizeof(BitNode));
		(*p)->data = q;
		createTree(&(*p)->lChild);
		createTree(&(*p)->rChild);
	}
}

void BinaryTree::createBitTree()
{
	std::cout << "please input your binary tree" << std::endl;
	createTree(&root);
}

bool BinaryTree::isEmpty()
{
	return root->lChild == NULL && root->rChild == NULL;
}

void preOrder(BitTree p)
{
	if (p != NULL)
	{
		std::cout << p->data;
		preOrder(p->lChild);
		preOrder(p->rChild);
	}
}

void BinaryTree::preOrderTrav()
{
	if (isEmpty())
	{
		std::cout << "tree is empty" << std::endl;
		return;
	}
	preOrder(root);
	std::cout << std::endl;
}

void inOrder(BitTree p)
{
	if (p != NULL)
	{
		inOrder(p->lChild);
		std::cout << p->data;
		inOrder(p->rChild);
	}
}

void BinaryTree::inOrderTrav()
{
	if (isEmpty())
	{
		std::cout << "tree is empty" << std::endl;
		return;
	}
	inOrder(root);
	std::cout << std::endl;
}

void postOrder(BitTree p)
{
	if (p != NULL)
	{
		postOrder(p->lChild);
		postOrder(p->rChild);
		std::cout << p->data;
	}
}

void BinaryTree::postOrderTrav()
{
	if (isEmpty())
	{
		std::cout << "tree is empty" << std::endl;
		return;
	}
	postOrder(root);
	std::cout << std::endl;
}

void countL(BitTree p, int& count)
{
	if (p)
	{
		if (p->lChild == NULL && p->rChild == NULL)
		{
			count++;
		}
		countL(p->lChild, count);
		countL(p->rChild, count);
	}
}

int BinaryTree::countLeaf()
{
	int count = 0;
	countL(root, count);
	std::cout << "the leaf number of the tree is " << count << std::endl;
	return count;
}

void countD(BitTree p, int level, int & depth)
{
	if (p)
	{
		if (level > depth) depth = level;
		countD(p->lChild, level + 1, depth);
		countD(p->rChild, level + 1, depth);
	}
}

int BinaryTree::countDepth()
{
	int level = 1, depth = 0;
	countD(root, level, depth);
	std::cout << "the depth of this tree is " << std::endl;
	return depth;
}