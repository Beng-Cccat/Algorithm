#include<iostream>
using namespace std;
int main() {
	cout << "请依次输入各点的坐标(xi,yi)，以空格连接：" << endl;
	int a[100][2] = { 0 };
	cin >> a[0][0] >> a[0][1];
	int num = 0;
	char b;
	while ((b = getchar()) != '\n') {
		num++;
		cin >> a[num][0] >> a[num][1];
	}
	double min =DBL_MAX;
	int mm[20][4] = { 0 };
	int ptr = 0;
	for (int i = 0; i < num; i++) {
		for (int j = i + 1; j <= num; j++) {
			double temp = sqrt(pow((a[i][0] - a[j][0]), 2) + pow((a[i][1] - a[j][1]), 2));
			if (temp < min) {
				min = temp;
				mm[ptr][0] = a[i][0]; mm[ptr][2] = a[j][0];
				mm[ptr][1] = a[i][1]; mm[ptr][3] = a[j][1];
				ptr++;
			}
			else if (temp == min) {
				mm[ptr][0] = a[i][0]; mm[ptr][2] = a[j][0];
				mm[ptr][1] = a[i][1]; mm[ptr][3] = a[j][1];
				ptr++;
			}
		}
	}
	for (int i = 0; i < ptr; i++) 
		cout << "第" << i+1 << "组最近的两点为：(" << mm[i][0] << ',' << mm[i][1] << ")-(" << mm[i][2] << ',' << mm[i][3] << ")" << endl;
	cout << "shortest distance=" << min;
}