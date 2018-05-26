#pragma once
/*
*	@author ZhouHang
*	@this is the tiny project for the Data Structure class
*/

#include<vector>
#include<iostream>
#include<algorithm>

/*
*	@Brief: Triple for sparse matrix
*/
template <typename Type>
class Triple
{
public:
	int row, col;
	Type value;
public:
	Triple<Type> operator = (const Triple & t)
	{
		row = t.row;
		col = t.col;
		value = t.value;
	}
	Triple(int Row, int Col, int Value)
	{
		row = Row;
		col = Col;
		value = Value;
	}
};

/*
*	@Brief: Sparses matrix implementation
*
*/
template <class Type>
class SparseMatrix
{
public:
	SparseMatrix() {};
	SparseMatrix (int Rows, int Cols, int Terms)
	{
		rows = Rows;
		cols = Cols;
		terms = Terms;
	}
	SparseMatrix<Type> operator = (const SparseMatrix<Type> & sm)
	{
		rows = sm.rows;
		cols = sm.cols;
		terms = sm.terms;

		//to do
	}
public:
	//basic matrix operation
	//to do if you have time
	//SparseMatrix<Type> operator + (const SparseMatrix<Type> & r);
	//SparseMatrix<Type> Transp();
	/*
	*	insert the new triple
	*	if already exist, nothing change, return flase
	*/
	bool insert(const Triple<Type> & tri);
public:
	/*
	*	generate the aux vector
	*/
	void genVec();

	/*
	*	get the value of (row, col) in sparse matrix
	*	if not in triple list, return 0
	*/
	Type getValue(int row, int col);

	/*
	*	set the value of (row, col) 
	*	if the value is 0, add this value to triple
	*/
	bool setValue(int row, int col, Type value);

	/*
	*	fast transposition using aux vector
	*	return the trans sparse mat
	*/
	SparseMatrix<Type> fastTransPos();

	/*
	*	get the triple with max value
	*	if all value is negtive, return 0
	*/
	Triple<Type> max();

	/*
	*	get the triple with min value
	*	if all value is positive, return 0
	*/
	Triple<Type> min();

	/*
	*	display the sparse matrix
	*/
	void display();
private:
	/*
	*	rows & cols descripte the size of this sparse martix
	*	terms is the num of non-zero element
	*/
	int rows, cols, terms;
	std::vector<int> auxVecSize, auxVecStart;
	//Triple<Type> * triArray;
	std::vector<Triple<Type>> triArray;
};

template <class Type>
bool SparseMatrix<Type>::insert(const Triple<Type> & tri)
{
	std::vector<Triple<Type>>::iterator it = triArray.begin();
	for (auto i = 0; i != triArray.size(); i++)
	{
		if (triArray[i].row < tri.row || (triArray[i].row == tri.row && triArray[i].col < tri.col)) continue;
		if (triArray[i].row == tri.row && triArray[i].col == tri.col)
		{
			std::cout << "insert pos error" << std::endl;
			return false;
		}
		triArray.insert(it + i, tri);
	}
	return true;
}

template <class Type>
void SparseMatrix<Type>::genVec()
{
	if (triArray.empty())
	{
		std::cout << "you cannot operate on empty matrix" << std::endl;
		return;
	}
	int i;
	for (i = 0; i < terms; i++)	auxVecSize[i] = 0;
	for (i = 0; i < terms; i++)
	{
		auxVecSize[triArray[i].col] ++;
	}
	auxVecStart[0] = 0;
	for (i = 1; i < cols; i++)
	{
		auxVecStart[i] = auxVecStart[i - 1] + auxVecSize[i - 1];
	}
}

template<class Type>
Type SparseMatrix<Type>::getValue(int Row, int Col)
{
	if (triArray.empty())
	{
		std::cout << "you cannot operate on empty matrix" << std::endl;
		return NULL;
	}
	for (const auto & triple : triArray)
	{
		if (triple.row == Row && triple.col == Col) return triple.value;
	}
	return 0;
}

template<class Type>
bool SparseMatrix<Type>::setValue(int Row, int Col, Type Value)
{
	if (triArray.empty())
	{
		std::cout << "you cannot operate on empty matrix" << std::endl;
		return false;
	}
	for (auto i = 0; i != triArray.size(); i++)
	{
		if (triArray[i].col == Col && triArray[i].row == Row)
		{
			triArray[i] = Value;
			return true;
		}
	}
	Triple<Type> temp = Triple(Row, Col, Value);
	this->insert(temp);
	return true;
}

template<class Type>
SparseMatrix<Type> SparseMatrix<Type>::fastTransPos()
{
	if (triArray.empty())
	{
		std::cout << "you cannot operate on empty matrix" << std::endl;
		return NULL;
	}
	SparseMatrix <Type> tSparseMat;
	int i, ti;
	for (i = 0; i < terms; i++)
	{
		ti = auxVecStart[triArray[i].col];
		tSparseMat.triArray[ti] = triArray[i];
		auxVecStart[triArray[i].col] ++;
	}
	return tSparseMat;
}

template<class Type>
Triple<Type> SparseMatrix<Type>::max()
{
	if (triArray.empty())
	{
		cout << "you cannot operate on empty matrix" << std::endl;
		return NULL;
	}
	std::sort(triArray.begin(), triArray.end(), [](const Triple & a, const Triple & b)
	{
		return a.value > b.value;
	});
	return triArray[0] > 0 ? triArray[0] : 0;
}

template<class Type>
Triple<Type> SparseMatrix<Type>::min()
{
	if (triArray.empty())
	{
		cout << "you cannot operate on empty matrix" << std::endl;
		return NULL;
	}
	std::sort(triArray.begin(), triArray.end(), [](const Triple & a, const Triple & b)
	{
		return a.value < b.value;
	});
	return triArray[0] > 0 ? 0 : triArray[0];
}

template<class Type>
void SparseMatrix<Type>::display()
{
	if (triArray.empty())
	{
		cout << "you cannot operate on empty matrix" << std::endl;
		return NULL;
	}
	
}