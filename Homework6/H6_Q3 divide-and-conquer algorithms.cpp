#include<iostream>
using namespace std;
int num;
int key[20] = { 0 };
void merge(int begin, int middle, int last) {
	int n1 = middle - begin;
	int n2 = last - middle;
	int* left = new int[n1];
	int* right = new int[n2];
	for (int i = 0; i < n1; i++)
		left[i] = key[begin + i];
	for (int i = 0; i < n2; i++)
		right[i] = key[middle + i];
	int i = 0, j = 0;
	for (int ptr = begin; ptr < last; ptr++) {
		if (i < n1 && left[i] <= right[j])
			key[ptr] = left[i++];
		else if (j < n2 && left[i] >= right[j])
			key[ptr] = right[j++];
		else if (i == n1 && j < n2)
			key[ptr] = right[j++];
		else if (j == n2 && i < n1)
			key[ptr] = left[i++];
	}
}
void devide(int begin, int last) {
	if (begin + 1 < last) {
		int middle = (last + begin) / 2;
		devide(begin, middle);
		devide(middle, last);
		merge(begin, middle, last);
	}
}
int main() {
	cout << "请输入节点数目：" << endl;
	cin >> num;
	cout << "请依次输入节点值：" << endl;
	for (int i = 0; i < num; i++)
		cin >> key[i];
	devide(0, num);
	cout << "采用归并排序后的结果为：" << endl;
	for (int i = 0; i < num; i++)
		cout << key[i] << ' ';
}