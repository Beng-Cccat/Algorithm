#include<iostream>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
int n;
int object[100][2] = { 0 };
int dp(int n,int V) {
	if (n == -1)
		return 0;
	if (V - object[n][0] >= 0)
		return max(object[n][1] + dp(n - 1, V - object[n][0]), dp(n - 1, V));
	else
		return dp(n - 1, V);
}
void badd(int used[]) {
	for (int i = 0; i < n; i++) {
		if (used[i] != 1) {
			used[i] = 1;
			return;
		}
		else
			used[i] = 0;
	}
		return;
}
int main() {
	clock_t start1, finish1, start2, finish2;
	int V;
	int used[100] = { 0 };
	cout << "请输入背包容量V：" << endl;
	cin >> V;
	cout << "请输入物品个数n：" << endl;
	cin >> n;

	//cout << "请依次输入物品所占背包容量和物品价值：" << endl;
	//for (int i = 0; i < n; i++) {
	//	cin >> object[i][0] >> object[i][1];
	//}
	cout << "由随机数产生的物品所占背包容量和物品价值如下所示：" << endl;
	for (int i = 0; i < n; i++) {
		object[i][0] = rand() % (2 * n);
		object[i][1] = rand() % (V / n) + 2 * n;
		cout << object[i][0] << ' ' << object [i][1] << endl; 
	}
	cout << "由dp算法求出该背包所能容纳物品的最大价值为：" << endl;
	start1 = clock();
	cout << dp(n, V) << endl;
	finish1 = clock();
	cout << "dp算法程序运行时长为： " << (double)(finish1 - start1) / CLOCKS_PER_SEC << endl;

	int sum = 0;
	start2 = clock();
	for (int i = 0; i < pow(2, n); i++) {
		badd(used);
		int tempw = 0;
		int tempV = 0;
		for (int j = 0; j < n; j++) {
			tempw += used[j] * object[j][1];
			tempV += used[j] * object[j][0];
		}
		if (tempV <= V && tempw > sum)
			sum = tempw;
	}
	cout << "由枚举法求出该背包所能容纳物品的最大价值为：" << endl;
	cout << sum << endl;
	finish2 = clock();
	cout << "枚举法程序运行时长为： " << (double)(finish2 - start2) / CLOCKS_PER_SEC << endl;
}