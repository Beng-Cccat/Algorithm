#include<iostream>
#include<queue>
using namespace std;
int ptr_red = 1;
int ptr_blue = 0;
int red[20] = { 0 };
int blue[20] = { 0 };

int whereit(int node) {
	for (int i = 0; i < ptr_red; i++)
		if (red[i] == node)
			return 1;//1表示红节点
	return -1;//-1表示蓝节点
}

int main() {
	int nodesnum;
	cin >> nodesnum;
	int edgesnum;
	cin >> edgesnum;
	int edges[20][20];
	for (int i = 0; i < edgesnum; i++) {
		int edges1;
		int edges2;
		cin >> edges1 >> edges2;
		edges[edges1][edges2] = 1;
		edges[edges2][edges1] = 1;
	}

	bool used[20] = { 0 };
	queue<int> q;
	q.push(0);
	red[0] = 0;
	used[0] = 1;
	int num = 1;
	int tag = 1;//1表示放入红的
	while (!q.empty()) {
		bool change = 1;
		for (int i = num; i > 0; i--) {
			int temp = q.front();
			q.pop();
			if (change==1) {
				tag =- tag;
				num = 0;
			}
			change = 0;
			for (int i = 0; i < nodesnum; i++) {
				if (edges[temp][i] == 1 && used[i] == 0) {
					num++;
					q.push(i);
					if (tag == 1) {
						red[ptr_red] = i;
						ptr_red++;
					}
					else if (tag == -1) {
						blue[ptr_blue] = i;
						ptr_blue++;
					}
					used[i] = 1;
				}
			}

		}
	}
	cout << "各节点着色情况如下：" << endl;
	for (int i = 0; i < nodesnum; i++)
		if (whereit(i) == 1)
			cout << i << "(红色)" << ' ';
		else
			cout << i << "(蓝色)" << ' ';
	cout << endl << endl;
	cout << "是否为二分图？" << endl;
	for (int i = 0; i < nodesnum; i++) {
		for (int j = 0; j < nodesnum; j++) {
			if (edges[i][j] == 1) {
				if (whereit(i) == whereit(j)) {
					cout << "NO";
					return 1;
				}
			}
		}
	}
	cout <<"YES"<< endl;
}