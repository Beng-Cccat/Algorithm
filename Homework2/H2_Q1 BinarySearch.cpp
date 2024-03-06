#include<iostream>
using namespace std;
int main() {
	int array[100] = {};
	cout << "请依次输入数组元素：" << endl;

	int number = 0;
	while (cin .peek()!='\n') {
		cin >> array[number];
		number++;
	};
	number--;

	int goal;
	cout << "请输入需要进行查找的元素：" << endl;
	cin >> goal;
	int begin = 0;
	int last = number - 1;
	int medium = (begin + last) / 2;
	while (true) {
		if (begin>last) {
			cout << "未查找到该元素" << endl;
			break;
		}
		if (goal < array[medium]) {
			last = medium-1;
		}
		else if (goal > array[medium])
			begin = medium+1;
		else if (goal == array[medium]) {
			cout << medium << endl;
			break;
		}
		medium = (begin + last) / 2;
	}
}