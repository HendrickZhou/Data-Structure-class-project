#pragma once

/*
*	@author: ZhouHang
*	implement six different sorting alg
*/

#include<vector>
#include<iostream>
#include<chrono>

const int maxSize = 1000;

class sorting
{
public:
	std::vector<int> testData;
public:
	sorting() {};
public:
	void insertSort();

	void selectSort();

	void heapSort();

	void fastSort();

	void bubbleSort();

	void mergeSort();
public:
	//generate random int in[0, 100]
	void genTestData(int);
};

void sorting::genTestData(int n)
{
	testData.clear();
	if (n < 2 || n > maxSize) return;
	testData.emplace_back(rand() % 100);
}

void sorting::insertSort()
{
	std::cout << "Insert Sort" << std::endl;
	std::cout << "the origin data is:" << std::endl;
	for (const auto & data : testData)
	{
		std::cout << data << ",";
	}
	std::cout << std::endl;

	auto t1 = std::chrono::high_resolution_clock::now();

	std::vector<int> result(testData);
	int i, j;
	int key;
	for (j = 1; j < result.size(); j++)
	{
		key = result[j];
	    i = j - 1;
		// find and make room for newly added data key
		while (i >= 0 && result[i] < key)
		{
		    result[i + 1] = result[i];
			i--;
		}
		// insert the key
		result[i + 1] = key;
	}

	auto t2 = std::chrono::high_resolution_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);

	std::cout << "data after insert sort:" << std::endl;
	for (const auto & data : result)
	{
		std::cout << data << ",";
	}
	std::cout << endl;
	std::cout << "the time cost is : " << time.count() << " ms" << std::endl;
}

void sorting::selectSort()
{
	std::vector<int> result;
	std::vector<int> data(testData);
}

void sorting::heapSort()
{
	std::vector<int> result;
	std::vector<int> data(testData);
}

void sorting::fastSort()
{
	std::vector<int> result;
	std::vector<int> data(testData);
}

void sorting::bubbleSort()
{
	std::vector<int> result;
	std::vector<int> data(testData);
}

void sorting::mergeSort()
{
	std::vector<int> result;
	std::vector<int> data(testData);

}