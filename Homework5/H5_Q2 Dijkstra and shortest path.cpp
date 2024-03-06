#include<iostream>
using namespace std;

int nodenum = 0;
int edgenum = 0;
int sourcenode = 0;
int node[20][20] = { 0 };
bool used[20] = { 0 };
int source[20] = { 0 };

int shortpath() {
	int temp = INT_MAX;
	int temp_i = 0;
	for (int i = 1; i <= nodenum; i++) {
		if (source[i] < temp&&source[i]!=0&&!used[i]) {
			temp = source[i];
			temp_i = i;
		}
	}
	return temp_i;
}

int main() {
	cout << "请输入节点数目，边的数目和源节点：" << endl;
	cin >> nodenum >> edgenum >> sourcenode;
	cout << "请依次输入两边的节点以及两节点中间的距离：" << endl;
	for (int i = 1; i <= nodenum; i++) {
		for (int j = 1; j <= nodenum; j++)
			node[i][j] = INT_MAX;
		node[i][i] = 0;
	}

	for (int i = 0; i < edgenum; i++) {
		int x, y, l;
		cin >> x >> y >> l;
		node[x][y] = l;
		node[y][x] = l;
	}

	for (int i = 1; i <= nodenum; i++)
		source[i] = INT_MAX;

	for (int i = 1; i <= nodenum; i++)
		source[i] = node[sourcenode][i];

	used[sourcenode] = 1;
	for (int i = 0; i < nodenum; i++) {
		int nowshort = shortpath();
		used[nowshort] = 1;
		for (int j = 1; j <= nodenum; j++) {
			if (node[nowshort][j] == INT_MAX||used[j])
				continue;
			int temp = source[nowshort] + node[nowshort][j];
			if (temp < source[j])
				source[j] = temp;
		}
	}
	cout << sourcenode << "到各节点的最短路径为：" << endl;
	for (int i = 1; i <= nodenum; i++)
		cout << source[i] << ' ';
}