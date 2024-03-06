#include<iostream>
using namespace std;
int n;
int num = 0;
int arr[40] = { 0 };
void backtrace(int depth) {
	if (depth == n) {
		num++;
		for (int i = 0; i < n; i++) {
			cout << arr[i];
		}
		cout << endl;
		return;
	}
	for (int i = depth; i < n; i++) {//总共有n个数字，需要进行n次循环（有n个数字可以在第一位）
		swap(arr[depth], arr[i]);
		backtrace(depth + 1);
		swap(arr[depth], arr[i]);
	}
}
int main() {
	cout << "请输入n的值：" << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}
	cout << "用回溯法得出1~"<<n<<"的全排列有：" << endl;
	backtrace(0);
	cout << "总共个数为：" << endl;
	cout << num;
}