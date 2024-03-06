#include<iostream>
using namespace std;

int nodenum = 0;
int edgenum = 0;
int node[20][3] = { 0 };
int set[20] = { 0 };
int sum = 0;

void reset(int x, int y) {
	int temp = set[y];
	for (int i = 1; i <= nodenum; i++) {
		if (set[i] == temp)
			set[i] = set[x];
	}
}

int main() {
	cout << "请输入节点数目和边的数目：" << endl;
	cin >> nodenum >> edgenum;
	cout << "请依次输入各边的起点终点和两边的长度：" << endl;
	for (int i = 0; i < edgenum; i++)
		cin >> node[i][0] >> node[i][1] >> node[i][2];
	for (int i = 0; i < edgenum; i++) {
		for (int j = i + 1; j < edgenum; j++) {
			if (node[i][2] > node[j][2]) {
				int temp[3] = { node[i][0],node[i][1],node[i][2] };
				node[i][0] = node[j][0];
				node[i][1] = node[j][1];
				node[i][2] = node[j][2];
				node[j][0] = temp[0];
				node[j][1] = temp[1];
				node[j][2] = temp[2];
			}
		}
	}
	for (int i = 1; i <= nodenum; i++)
		set[i] = i;
	for (int i = 0; i < edgenum; i++) {
		if (set[node[i][0]] != set[node[i][1]]) {//不属于同一个集合
			sum += node[i][2];
			reset(node[i][0], node[i][1]);
		}
	}
	cout << "最小生成树的总路径长度为：" << endl;
	cout << sum;
}