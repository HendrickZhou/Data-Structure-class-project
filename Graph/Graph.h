#pragma once
#include<iostream>
#include<vector>

struct ALNode
{
	int dest;
	int weight;
	struct ALNode * next;
};

struct AL
{
	ALNode * head;
};

struct ALGraph
{
	int vertexSize; // number of vertex, aka size of Adj List
	AL * array; 
};


/*
*	@decription: toolkit for construct new node
*/
ALNode * newALNode(int dest, int weight)
{
	ALNode * newNode = (ALNode*)malloc(sizeof(ALNode));
	newNode->dest = dest;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}

/*
*	@decription:创建一个只有节点没有边的图
*/
ALGraph * creatGraph(int v)
{
	ALGraph * graph = (ALGraph *)malloc(sizeof(ALGraph));
	AL * newArray = (AL *)malloc(sizeof(AL));

	graph->vertexSize = v;
	graph->array = newArray;
	for (int i = 0; i < v; i++)
	{
		graph->array[i].head = NULL;
	}
	return graph;
}

/*
*	@description:在图G中节点dest1, dest2之间加上一条边 
*	@param: index of node->dest1,dest2
*/
void addEdge(ALGraph * G, int dest1, int weight, int dest2)
{
	ALNode * newNode = (ALNode*)malloc(sizeof(ALNode));
	
	//step1. 在dest2节点的array头插入dest1节点
	newNode = newALNode(dest1, weight);
	newNode->next = G->array[dest2].head;
	G->array[dest2].head = newNode;

	//step2. 在dest1节点的array头里插入dest2节点
	newNode = newALNode(dest2, weight);
	newNode->next = G->array[dest1].head;
	G->array[dest1].head = newNode;
}

/**************************************/

// Structure to represent a min heap node
struct MinHeapNode
{
	int  v;
	int key;
};

// Structure to represent a min heap
struct MinHeap
{
	int size;      // Number of heap nodes present currently
	int capacity;  // Capacity of min heap
	int *pos;     // This is needed for decreaseKey()
	struct MinHeapNode **array;
};

// A utility function to create a new Min Heap Node
struct MinHeapNode* newMinHeapNode(int v, int key)
{
	struct MinHeapNode* minHeapNode =
		(struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
	minHeapNode->v = v;
	minHeapNode->key = key;
	return minHeapNode;
}

// A utilit function to create a Min Heap
struct MinHeap* createMinHeap(int capacity)
{
	struct MinHeap* minHeap =
		(struct MinHeap*) malloc(sizeof(struct MinHeap));
	minHeap->pos = (int *)malloc(capacity * sizeof(int));
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array =
		(struct MinHeapNode**) malloc(capacity * sizeof(struct MinHeapNode*));
	return minHeap;
}

// A utility function to swap two nodes of min heap. Needed for min heapify
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
	struct MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}

// A standard function to heapify at given idx
// This function also updates position of nodes when they are swapped.
// Position is needed for decreaseKey()
void minHeapify(struct MinHeap* minHeap, int idx)
{
	int smallest, left, right;
	smallest = idx;
	left = 2 * idx + 1;
	right = 2 * idx + 2;

	if (left < minHeap->size &&
		minHeap->array[left]->key < minHeap->array[smallest]->key)
		smallest = left;

	if (right < minHeap->size &&
		minHeap->array[right]->key < minHeap->array[smallest]->key)
		smallest = right;

	if (smallest != idx)
	{
		// The nodes to be swapped in min heap
		MinHeapNode *smallestNode = minHeap->array[smallest];
		MinHeapNode *idxNode = minHeap->array[idx];

		// Swap positions
		minHeap->pos[smallestNode->v] = idx;
		minHeap->pos[idxNode->v] = smallest;

		// Swap nodes
		swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

		minHeapify(minHeap, smallest);
	}
}

// A utility function to check if the given minHeap is ampty or not
int isEmpty(struct MinHeap* minHeap)
{
	return minHeap->size == 0;
}

// Standard function to extract minimum node from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
	if (isEmpty(minHeap))
		return NULL;

	// Store the root node
	struct MinHeapNode* root = minHeap->array[0];

	// Replace root node with last node
	struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
	minHeap->array[0] = lastNode;

	// Update position of last node
	minHeap->pos[root->v] = minHeap->size - 1;
	minHeap->pos[lastNode->v] = 0;

	// Reduce heap size and heapify root
	--minHeap->size;
	minHeapify(minHeap, 0);

	return root;
}

// Function to decreasy key value of a given vertex v. This function
// uses pos[] of min heap to get the current index of node in min heap
void decreaseKey(struct MinHeap* minHeap, int v, int key)
{
	// Get the index of v in  heap array
	int i = minHeap->pos[v];

	// Get the node and update its key value
	minHeap->array[i]->key = key;

	// Travel up while the complete tree is not hepified.
	// This is a O(Logn) loop
	while (i && minHeap->array[i]->key < minHeap->array[(i - 1) / 2]->key)
	{
		// Swap this node with its parent
		minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
		minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
		swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);

		// move to parent index
		i = (i - 1) / 2;
	}
}

// A utility function to check if a given vertex
// 'v' is in min heap or not
bool isInMinHeap(struct MinHeap *minHeap, int v)
{
	if (minHeap->pos[v] < minHeap->size)
		return true;
	return false;
}

/*********************************************/

std::string encoder(int i)
{
	switch (i)
	{
	case 0:
		return "V1";
	case 1:
		return "V2";
	case 2:
		return "V3";
	case 3:
		return "V4";
	case 4:
		return "V5";
	case 5:
		return "V6";
	default:
		break;
	}
}

void displayMSTInfo(std::vector<int> arr)
{
	int weight = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		std::string v1 = encoder(arr[i]);
		std::string v2 = encoder(i);
		printf("(%s, %s),", v1, v2);
	}
}

// The main function that constructs Minimum Spanning Tree (MST)
// using Prim's algorithm
void PrimMST(ALGraph* graph)
{
	int V = graph->vertexSize;// Get the number of vertices in graph
	std::vector<int> parent(V);   // store constructed MST
	std::vector<int> key(V);	// Key values used to pick minimum weight edge in cut

	// minHeap represents set E
	struct MinHeap* minHeap = createMinHeap(V);

	// Initialize min heap with all vertices. Key value of
	// all vertices (except 0th vertex) is initially infinite
	for (int v = 1; v < V; ++v)
	{
		parent[v] = -1;
		key[v] = INT_MAX;
		minHeap->array[v] = newMinHeapNode(v, key[v]);
		minHeap->pos[v] = v;
	}

	// Make key value of 0th vertex as 0 so that it
	// is extracted first
	key[0] = 0;
	minHeap->array[0] = newMinHeapNode(0, key[0]);
	minHeap->pos[0] = 0;

	// Initially size of min heap is equal to V
	minHeap->size = V;

	// In the followin loop, min heap contains all nodes
	// not yet added to MST.
	while (!isEmpty(minHeap))
	{
		// Extract the vertex with minimum key value
		struct MinHeapNode* minHeapNode = extractMin(minHeap);
		int u = minHeapNode->v; // Store the extracted vertex number

		// Traverse through all adjacent vertices of u (the extracted
								// vertex) and update their key values
		struct ALNode* pCrawl = graph->array[u].head;
		while (pCrawl != NULL)
		{
			int v = pCrawl->dest;

			// If v is not yet included in MST and weight of u-v is
			// less than key value of v, then update key value and
			// parent of v
			if (isInMinHeap(minHeap, v) && pCrawl->weight < key[v])
			{
				key[v] = pCrawl->weight;
				parent[v] = u;
				decreaseKey(minHeap, v, key[v]);
			}
			pCrawl = pCrawl->next;
		}
	}

	displayMSTInfo(parent);
}