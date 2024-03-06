#include<iostream>
using namespace std;

int nodenum;
int edgenum;
int node[20][20] = { 0 };
int nodeshort[20] = { 0 };
int ptr = 1;
int way = 0;

void remake(int y) {
	for (int i = 1; i <= nodenum; i++) {
		node[i][y] = INT_MAX;
	}
}
bool shorthave(int target) {
	for (int i = 0; i < ptr; i++) {
		if (nodeshort[i] == target)
			return true;
	}
	return false;
}
int shortedge(int start) {
	int temp = INT_MAX;
	int x = 0;
	int i;
	for (int i = 0; i < ptr; i++) {
		for (int j = 1; j <= nodenum; j++) {
			if (shorthave(j))//不与最小生成树的节点相连
				continue;
			if (temp > node[nodeshort[i]][j]&&j!=nodeshort[i]) {//找最短边
				temp = node[nodeshort[i]][j];
				x = j;
			}
		}
	}
	way += temp;
	return x;
}
int main() {
	cout << "请输入节点数目：" << endl;
	cin >> nodenum;
	cout << "请输入边的数目：" << endl;
	cin >> edgenum;
	cout << "请依次输入每一条边的两点以及边的长度：" << endl;
	for (int i = 1; i <= nodenum; i++)
		for (int j = 1; j <= nodenum; j++)
			if(j!=i)
				node[i][j] = INT_MAX;

	for (int i = 0; i < edgenum; i++) {
		int x, y, l;
		cin >> x >> y >> l;
		node[x][y] = l;
		node[y][x] = l;
	}
	nodeshort[0] = 1;
	for (int i = 1; i < nodenum; i++) {//再加nodenum-1个点
		nodeshort[ptr] = shortedge(nodeshort[ptr - 1]);
		ptr++;
	}
	cout << "The sum of all edges in minimum spanning tree is(最小生成树中所有边的总和):" << endl;
	cout << way;
}