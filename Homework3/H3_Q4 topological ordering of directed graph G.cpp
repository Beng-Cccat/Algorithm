#include<iostream>
using namespace std;

int nodesnum;
int edgesnum;
int edges[20][20];
bool used[20] = { 0 };
int way[20] = { 0 };
int ptr = 0;

bool isDegreezero(int node) {
	for (int i = 0; i < nodesnum; i++) {
		if (edges[i][node] == 1)
			return false;
	}
	return true;
}

void clear(int node) {
	for (int i = 0; i < nodesnum; i++)
		edges[node][i] = 0;
}

int main() {
	cin >> nodesnum;
	cin >> edgesnum;
	for (int i = 0; i < edgesnum; i++) {
		int edges1;
		int edges2;
		cin >> edges1 >> edges2;
		edges[edges1][edges2] = 1;
	}
	for (int i = 0; i < nodesnum; i++) {
		if (isDegreezero(i)&&used[i]==0) {
			way[ptr] = i;
			used[i] = 1;
			ptr++;
			clear(i);
			i = -1;
		}
		if (ptr == nodesnum)
			break;
	}
	cout << "该图的拓扑排序为（有多个入度为0的顶点时按索引值大小排序）：" << endl;
	for (int i = 0; i < nodesnum; i++)
		cout << way[i] << ' ';
}