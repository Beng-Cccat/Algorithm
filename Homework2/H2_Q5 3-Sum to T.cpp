#include<iostream>
using namespace std;
int main() {
	int a[100] = { 0 };
	int num = 0;
	char b;
	cout << "请输入一个数组（严格递增）：" << endl;
	cin >> a[0];
	while ((b = getchar()) != '\n') {
		num++;
		cin >> a[num];
	}
	cout << "请输入加和T：" << endl;
	int T;
	cin >> T;
	bool tag = 0;
	//O(n3):
	cout << "O(n3)查找后的结果：" << endl;//暴力三层循环
	for (int i = 0; i < num - 1; i++) {
		for (int j = i + 1; j < num; j++) {
			for (int z = j + 1; z <= num; z++) {
				int temp = a[i] + a[j] + a[z];
				if (temp == T) {
					cout << a[i] << '+' << a[j] << '+' << a[z] << '=' << T << endl;
					tag = 1;
				}
			}
		}
	}
	//O(nlogn):
	cout << "O(n2logn)查找后的结果：" << endl;//两个嵌套for循环+二分查找
	for (int i = 0; i < num - 1; i++) {
		for (int j = i+1; j < num; j++) {
			int begin = j;
			int last = num;
			int medium = last;
			while (true) {
				if (begin >= last)
					break;
				if (a[i] + a[j] + a[medium] > T)
					last -= 1;
				else if (a[i] + a[j] + a[medium] < T)
					last = medium - 1;
				else if (a[i] + a[j] + a[medium] == T) {
					cout << a[i] << '+' << a[j] << '+' << a[medium] << '=' << T << endl;
					tag = 1;
					break;
				}
				medium = (medium + last) / 2;
			}
		}
	}
	
	//O(n2):
	cout << "O(n2)查找后的结果：" << endl;
	cout << "方法1：" << endl;//一个算法分两步，强行降低复杂度
	int a_search[100][3] = { 0 };
	int point = 0;
	for (int i = 0; i < num; i++) {
		for (int j = i + 1; j <= num; j++) {
			a_search[point][0] = i;
			a_search[point][1] = j;
			a_search[point][2] = a[i] + a[j];
			point++;
		}
	}
	for (int i = 0; i < num-1; i++) {
		for (int j = 0; j < point; j++) {
			if ((a_search[j][2] + a[i]) == T&&a_search[j][0]>i) {
				cout << a[i] << '+' << a[a_search[j][0]] << '+' << a[a_search[j][1]] << '=' << T << endl;
				tag = 1;
			}
		}
	}
	cout << "方法2：" << endl;//for循环+双指针
	for (int i = 0; i <= num; i++) {
		int left = i + 1;
		int right = num;
		while (left < right) {
			int temp = a[i] + a[left] + a[right];
			if (temp < T)
				left++;
			else if (temp > T)
				right--;
			else if (temp == T) {
				cout << a[i] << '+' << a[left] << '+' << a[right] << '=' << T << endl;
				tag = 1;
				left++;
				right--;
			}
		}
	}

	if (tag == 0)
		cout << "查找不到三数相加和为T！" << endl;
}