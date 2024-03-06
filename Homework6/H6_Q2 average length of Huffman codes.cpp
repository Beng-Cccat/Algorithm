#include<iostream>
using namespace std;
int num;
int nodes[20] = { 0 };
int nodes1[20] = { 0 };
int way[20][2] = { 0 };
int sum1 = 0;
void sort() {
	for (int i = 0; i < num; i++)
		for (int j = i + 1; j < num; j++)
			if (nodes[i] > nodes[j]) {
				int temp = nodes[j];
				nodes[j] = nodes[i];
				nodes[i] = temp;
			}
}
void changefather(int son1, int son2, int father) {
	for (int i = 0; i < num; i++) {
		if (way[i][0] == son1 || way[i][0] == son2) {
			way[i][0] = father;
			way[i][1]++;
		}
	}
}
int main() {
	cout << "请输入节点数目：" << endl;
	cin >> num;
	cout << "请依次输入节点值：" << endl;
	for (int i = 0; i < num; i++) {
		cin >> nodes[i];
		nodes1[i] = nodes[i];
		way[i][0] = nodes[i];
		sum1 += nodes[i];
	}
	int anum = num;
	while (anum != 1) {
		sort();
		int sum = nodes[0] + nodes[1];
		changefather(nodes[0], nodes[1], sum);
		nodes[0] = sum;
		nodes[1] = INT_MAX;
		anum--;
	}
	double sum = 0;
	for (int i = 0; i < num; i++)
		sum += way[i][1] * nodes1[i];
	sum /= sum1;
	cout << "The average length of this Huffman codes is:" << endl;
	cout << sum << endl;
}