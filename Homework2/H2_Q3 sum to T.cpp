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
	//O(n2):暴力求解
	cout << "O(n2)查找后的结果：" << endl;
	for (int i = 0; i <= num; i++) {
		for (int j = i + 1; j <= num; j++) {
			int temp = a[i] + a[j];
			if (temp == T) {
				cout << a[i] << '+' << a[j] << '=' << T << endl;
				tag = 1;
			}
		}
	}
	//O(nlogn):for循环+二分查找
	cout << "O(nlogn)查找后的结果：" << endl;
	for (int i = 0; i < num; i++) {
		int begin = i;
		int last = num;
		int medium = last;
		while (true) {
			if (begin >= last)
				break;
			if (a[i] + a[medium] < T) {
				last = medium - 1;
			}
			else if (a[i] + a[medium] > T)
				last -= 1;
			else if (a[i]+a[medium]==T) {
				cout << a[i] << '+' << a[medium] << '=' << T << endl;
				tag = 1;
				break;
			}
			medium = (medium + last) / 2;
		}
	}
	//O(n):
	cout << "O(n)查找后的结果：" << endl;
	cout <<"方法1：" << endl;
	int a_mir[100] = { 0 };
	for (int i = 0; i <= num; i++) 
		a_mir[i] = T - a[i];
	int a_ptr = 0;
	int a_mir_ptr = num;
	while (a_ptr<a_mir_ptr) {
		if (a[a_ptr] < a_mir[a_mir_ptr])
			a_ptr++;
		else if (a[a_ptr] > a_mir[a_mir_ptr])
			a_mir_ptr--;
		else if (a[a_ptr] == a_mir[a_mir_ptr]) {
			cout << a[a_ptr] << '+' << a[a_mir_ptr] << '=' << T << endl;
			a_ptr++;
			a_mir_ptr--;
			tag = 1;
		}
	}
	cout<<"方法2：" << endl;//双指针法
	int left = 0;
	int right = num;
	while (left < right) {
		int temp = a[left] + a[right];
		if (temp < T)
			left++;
		else if (temp > T)
			right--;
		else if (temp == T) {
			cout << a[left] << '+' << a[right] << '=' << T << endl;
			left++;
			tag = 1;
		}
	}

	if (tag == 0)
		cout << "查找不到两数相加和为T！" << endl;
}