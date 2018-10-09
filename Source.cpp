#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<assert.h>
using namespace std;

//void read(string filename, vector<string> & nodes, vector<array<string, 3>> & edges)
//{
//	ifstream inFile;
//	inFile.open(filename.data());
//	assert(inFile.is_open());
//
//	vector<string> lines;
//	string sLine;
//	string nodename;
//	for (size_t i = 0; i < 2; i++)
//	{
//		getline(inFile, sLine);
//		istringstream iss(sLine);
//		while (iss >> nodename)
//		{
//			lines.emplace_back(nodename);
//		}
//	}
//	inFile.close();
//	inFile.clear();
//}

void main()
{
	string filename = "treedata.txt";
	vector<string> lines;
	vector<string> result;
	//vector<array<string, 3>> edges;

	ifstream inFile;
	inFile.open(filename.data());
	assert(inFile.is_open());

	string sLine;
	string nodename;
	for (size_t i = 0; i < 2; i++)
	{
		getline(inFile, sLine);
		lines.emplace_back(sLine);
	}
	inFile.close();
	inFile.clear();


	for (auto line : lines)
	{
		cout << line << endl;
	}

	char *s_input = (char *)lines[0].c_str();
	const char * split = ",";
	char * p = strtok(s_input, split);

	string a;
	while (p != NULL)
	{
		sscanf(p, "%s", &a);
		result.push_back(a);
		p = strtok(NULL, split);
	}

	for (int i  = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}

	system("pause");
}