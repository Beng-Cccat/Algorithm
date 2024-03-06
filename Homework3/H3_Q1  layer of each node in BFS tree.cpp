#include<iostream>
#include<queue	>
using namespace std;
int main() {
	int nodenum;
	cin >> nodenum;//节点数目
	int edgesnum;
	cin >> edgesnum;//边的数目
	int edges[20][20] = { 0 };//记录节点链接情况
	int start;
	cin >> start;//开始节点
	for (int i = 0; i < edgesnum; i++) {
		int edge1;
		int edge2;
		cin >> edge1 >> edge2;
		edges[edge1][edge2] = 1;
		edges[edge2][edge1] = 1;
	}
	queue<int> q;
	bool used[20] = { 0 };//是否已经被查找到路径
	int layer[20] = { 0 };//记录路径长度（层数）
	q.push(start);
	used[start] = 1;
	int way = 0;//记录第几层（从0开始）
	int num = 1;
	while (!q.empty()) {
		bool change = 1;
		for (int i = num; i > 0; i--) {
			if(change==1)
				num = 0;//第一次循环的时候初始化变量
			way++;
			int temp = q.front();
			q.pop();
			change = 0;
			for (int i = 0; i < nodenum; i++) {
				if (edges[temp][i] == 1 && used[i] == 0) {
					num++;//下一层有多少个节点
					layer[i] = way;
					q.push(i);
					used[i] = 1;//被使用过
				}
			}
		}
	}
	cout << "该图从"<<start<<"开始的BFS排序为：" << endl;
	for (int i = 0; i < nodenum; i++) {
		cout << layer[i] << ' ';
	}
}