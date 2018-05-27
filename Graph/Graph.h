#pragma once

/*
*	@author: ZhouHang
*	data structure project
*	adjacency list graph and prim alg
*/

#include<iostream>
#include<vector>

/*
*	edge info
*
*/
template<typename T, typename E>
struct EdgeNode
{
	int id;
	E weight;
	EdgeNode<T, E> * next;
	EdgeNode() {};
};

/*
*	vertex info
*
*/
template<typename T, typename E>
struct Vertex
{
	T data;
	//int id;
	EdgeNode<T, E> * adjList;
	Vertex(T Data) : data(Data), adjList(NULL) {};
};

template<typename T, typename E>
class ALGraph
{
	//Vertex<T, E> * nodeTable;
	std::vector<Vertex<T, E>> nodeTable;
	int vertexNum;
public:
	ALGraph() {};
	bool insertEdge(int, int, E);

	//to do
	//insertVertex()
	//removeVertex()
	//removeEdge()
public:
	/*
	*	@Brief:			file data interface
	*	@Param:			file path & 2 empty vector used to contain vertex and edge info
	*	@Description:	interface for client test.
	*/
	bool readFile(std::string, std::vector<T> &, std::vector<std::array<std::string, 3>> &);
	
	/*
	*	@Brief:			build the graph
	*	@Param:			2 vectors contain vertex and edge info
	*	@Description:
	*/
	bool buildGraph(std::vector<T>, std::vector<std::array<std::string, 3>>);

	bool displayBFS();

	/*
	*	@Brief: build the minist spanning tree using Prim alg
	*	@Description: start the tree by 
	*	@Tip: This function only changes the edges and show them
	*	by BFS. It doesn't build a real tree by definition.
	*/
	bool primMst(int id);
};


template<typename T, typename E>
bool ALGraph<T, E>::insertEdge(int id1, int id2, E Weight)
{
	if (id1 >= 0 && id1 <= vertexNum && id2 >= 0 && id2 <= vertexNum)
	{
		//nodeTable[id1]无法访问成员
		EdgeNode<T, E> *q, *p = nodeTable[id1].adjList;
		while (p != NULL && p->id != id2) p = p->next;

		//if edge already exits, return false
		if (p != NULL) return false;

		//else insert the edge
		//insert nodes to the first node of both vertexs
		p = new EdgeNode<T, E>; 
		p->id = id2;
		p->weight = Weight;
		p->next = nodeTable[id1].adjList;
		nodeTable[id1].adjList = p;

		q = new EdgeNode<T, E>;
		q->id = id1;
		q->weight = Weight;
		q->next = nodeTable[id2].adjList;
		nodeTable[id2].adjList = q;
		
		vertexNum++;
		return true;
	}
	return 0;
}

template<typename T, typename E>
bool ALGraph<T, E>::readFile(std::string filename, std::vector<T> & nodes, std::vector<std::array<std::string, 3>> & edges)
{
	//to do
	return true;
}

template<typename T, typename E>
bool ALGraph<T, E>::buildGraph(std::vector<T> nodesDatas, std::vector<std::array<std::string, 3>> edgesInfoArrays)
{
	//step 1 : build the vertex list
	vertexNum = 0;
	for (const auto & nodeData : nodesDatas)
	{
		Vertex<T, E> ver(node);
		ver.id = vertexNum;
		nodeTable.emplace_back(ver);
		vertexNum ++;
	}

	//step 2 : build edge list
	for (const auto & edgeInfoArray : edgesInfoArrays)
	{
		//store the datas
		E weight;
		T vertexData, nodeData;
		std::stringstream w(edgeInfoArray[2]), v(edgeInfoArray[0]), n(edgeInfoArray[1]);
		w >> weight;
		v >> vertexData;
		n >> nodeData;
		
		// find id of these datas
		int id1, id2;
		int i = 0;
		for (const auto & node : nodeTable)
		{
			// 为什么无法访问成员
			if (vertexData == node.data) id1 = i;
			if (nodeData == node.data) id2 = i;
			i++;
		}

		//add the edge
		insertEdge(id1, id2);
	}
	
}

template<typename T, typename E>
bool ALGraph<T, E>::displayBFS()
{

}

template<typename T, typename E>
bool ALGraph<T, E>::primMst(int id)
{

}