#include<iostream>
using namespace std;

int k;
int initial[20] = { 0 };
int way[20] = { 0 };
int miss[20] = { 0 };
int initialnum;
int waynum;
int ptr = 0;

bool misshave(int key) {//miss数组中是否含有当前数字
	for (int i = 0; i < ptr; i++) {
		if (key == miss[i])
			return 1;
	}
	return 0;
}
bool exist(int key) {//initial数组中是否存在当前数字
	for (int i = 0; i < initialnum; i++) {
		if (key == initial[i])
			return 1;
	}
	return 0;
}
int far(int start) {
	int far = INT_MIN;//当前initial中对应的way中的最远的索引
	int far_num = 0;//该最远索引对应的initial中的索引
	bool tag = 1;//tag为1表示当前模式为后面数列中均有对应的，tag为0则表示至少有一个数字后面不再出现
	for (int i = 0; i < k; i++) {//k轮，找到initial中的数中对应的way中的最远的那一个
		for (int j = start; j < waynum; j++) {
			if (way[j] == initial[i]&&tag) {//两者相等
				if (far < j) {//如果曾经最远的那一个还要更小一点，则交换
					far = j;//利用far作为比较的依据
					far_num = i;
				}
				break;
			}
			else if (way[j] == initial[i] && !tag)
				break;
			if (j == waynum-1) {
				far_num = i;
				if (!misshave(initial[i]))//第一次出现则直接输出，第二次出现（miss数组中已含有则继续向后查找）
					i = k;
				tag = 0;
				break;
			}
		}
	}
	return far_num;
}

int main() {
	cout << "请输入缓存k的大小，初始缓冲序列的元素个数和请求序列的元素个数：" << endl;
	cin >> k >> initialnum >> waynum;
	cout << "请输入初始缓冲序列：" << endl;
	for (int i = 0; i < initialnum; i++)
		cin >> initial[i];

	cout << "请输入请求序列：" << endl;
	for (int i = 0; i < waynum; i++)
		cin >> way[i];

	for (int i = 0; i < waynum; i++) {
		if (!exist(way[i])) {
			if (initialnum < k) {
				initial[initialnum] = way[i];
				initialnum++;
			}
			else {
				int temp = far(i);
				miss[ptr] = initial[temp];
				ptr++;
				initial[temp] = way[i];
			}
		}
	}
	cout << "eviction schedule:" << endl;
	for (int i = 0; i < ptr; i++)
		cout << miss[i] << ' ';
}