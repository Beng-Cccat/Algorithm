#include<iostream>
using namespace std;
int main() {
	int array1[100];
	int array2[100];
	for (int i = 0; i < 100; i++) {
		array1[i] = INT_MAX;
		array2[i] = INT_MAX;
	}
	int arraynum1 = 0;
	int arraynum2 = 0;
	cout << "请依次输入第一个排序数组（严格递增）：" << endl;
	char a;
	cin >> array1[0];
	while ((a=getchar())!='\n') {
		arraynum1++;
		cin>>array1[arraynum1];
	}

	cout << "请依次输入第二个排序数组（严格递增）：" << endl;
	cin >> array2[0];
	while ((a = getchar()) != '\n') {
		arraynum2++;
		cin>>array2[arraynum2];
	}
	int array3[100] = {};
	int port1 = 0;
	int port2 = 0;
	int port3 = 0;
	for (int i = 0; i < arraynum1 + arraynum2+2; i++) {
		if (array1[port1] < array2[port2]) {
			array3[port3] = array1[port1];
			port1++;
		}
		else if (array1[port1] > array2[port2]) {
			array3[port3] = array2[port2];
			port2++;
		}
		else if (array1[port1] == array2[port2]) {
			array3[port3] = array2[port2];
			port1++;
			port2++;
			i++;
		}
		port3++;
	}
	for (int i = 0; i < port3; i++) {
		cout << array3[i] << ' ';
	}
}