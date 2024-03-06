#include<iostream>
#include<queue>
using namespace std;
int nodenum;
int edgesnum;
int edges[20][20] = { 0 };//记录节点链接情况
int start;

int way_DFS[20] = { 0 };
int used_DFS[20] = { 0 };
static int num = 1;

int DFS(int now) {//DFS：递归
	for (int i = 0; i < nodenum; i++) {
		if (edges[now][i] == 1 && used_DFS[i] == 0) {
			used_DFS[i] = 1;
			way_DFS[num] = i;
			num++;
			DFS(i);
		}
	}
	return num;
}
int main() {

	cin >> nodenum;//节点数目

	cin >> edgesnum;//边的数目

	cin >> start;//开始节点
	for (int i = 0; i < edgesnum; i++) {
		int edge1;
		int edge2;
		cin >> edge1 >> edge2;
		edges[edge1][edge2] = 1;
		edges[edge2][edge1] = 1;
	}
	//BFS:
	int way_BFS[20] = { 0 };
	bool used_BFS[20] = { 0 };
	way_BFS[0] = start;
	used_BFS[start] = 1;
	queue<int> q;
	int ptr = 0;
	q.push(start);
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		for (int i = 0; i < nodenum; i++) {
			if (edges[temp][i] == 1 && used_BFS[i] == 0) {
				ptr++;
				used_BFS[i] = 1;
				q.push(i);
				way_BFS[ptr] = i;
			}
		}
	}
	cout << "该图从" << start << "开始的BFS排序为：" << endl;
	for (int i = 0; i <= ptr; i++)
		cout << way_BFS[i] << ' ';
	cout << endl;
	
	//DFS:
	way_DFS[0] = start;
	used_DFS[start] = 1;
	DFS(start);
	cout << "该图从" << start << "开始的DFS排序为：" << endl;
	for (int i = 0; i < num; i++)
		cout << way_DFS[i] << ' ';
	cout << endl;
}