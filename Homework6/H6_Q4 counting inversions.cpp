#include<iostream>
using namespace std;
int merge(int key[],int temp[],int begin, int middle, int last) {
	int i = begin, j = middle + 1; 
	int number = 0;
	int ptr = begin;
	for (int x = begin; x <= last; x++) {
		temp[x] = key[x];
	}
	while (i <= middle && j <= last) {
		if (temp[i] > temp[j]) {
			number += middle - i + 1;
			key[ptr++] = temp[j++];
		}
		else
			key[ptr++] = temp[i++];
	}
	if (i > middle)
		while (j <= last) {
			key[ptr++] = temp[j++];
		}
	else
		while (i <= middle)
			key[ptr++] = temp[i++];
	return number;
}

int devide(int key[],int temp[],int begin, int last) {
	if (begin + 1 <= last) {
		int middle = (last + begin) / 2;
		int leftnum=devide(key,temp,begin, middle);
		int rightnum=devide(key,temp,middle+1, last);
		int allnum=merge(key,temp,begin, middle, last);
		return leftnum + rightnum + allnum;
	}
	return 0;
}
int main() {
	int num;
	int key[20] = { 0 };
	int temp[20] = { 0 };
	cout << "请输入节点个数：" << endl;
	cin >> num;
	cout << "请依次输入节点值：" << endl;
	for (int i = 0; i < num; i++)
		cin >> key[i];
	cout << "The number of inversions is:" << endl;
	cout<<devide(key,temp,0, num-1);

}