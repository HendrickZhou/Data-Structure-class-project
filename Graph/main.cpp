#include"Graph.h"
using namespace std;

int main()
{
	cout << "I'm so sorry that I cannot handle the file I/O in C++" << endl;
	cout << "This program is just a demo that use the given infomation of the graph" << endl;
	cout << "The graph info:" << endl;
	cout << "***********************************" << endl;
	cout << "Vertex: " << "V1, V2, V3, V4, V5, V6" << endl;
	cout << "Edges:" << "V1,V2,6;V1,V3,1;V1,V4,5;V2,V3,5;V2,V5,6;V3,V4,5;V3,V5,6;V3,V6,4;V4,V5,2;V5,V6,6;" << endl;
	cout << "***********************************" << endl;
	cout << "And here is the result of my MST using Prim" << endl;

	ALGraph * g = creatGraph(6);
	addEdge(g, 0, 6, 1);
	addEdge(g, 0, 1, 2);
	addEdge(g, 0, 5, 3);
	addEdge(g, 1, 5, 2);
	addEdge(g, 1, 6, 4);
	addEdge(g, 2, 5, 3);
	addEdge(g, 2, 6, 4);
	addEdge(g, 2, 4, 5);
	addEdge(g, 3, 2, 4);
	addEdge(g, 4, 6, 5);
	
	PrimMST(g);

	system("pause");
	return 0;
}