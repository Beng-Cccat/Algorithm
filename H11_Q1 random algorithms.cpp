#include<iostream>
#include<cstdlib>
using namespace std;
string X;
string Y;
int su[200] = { 0 };
int m;
int n;
int p;

int random_(int M) {
	int k = 0;
	su[++k] = 2;
	for (int i = 3; i < M; i++) {
		bool flag = true;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				flag = false;
				break;
			}
		}
		if (flag == true) {
			su[++k] = i;
		}
	}
	int temp = rand();
	return su[temp%k];
}
int P(string str,int j,int Wp) {
	int f = 0;
	for (int i = 0; i < m; i++) {
		f += (Wp / 2) * (str[j + i] - 'a') % p;
		Wp = Wp/2;
	}
	return f;
}
int main() {
	cout << "请输入字符串：" << endl;
	cin >> X;
	cout << "请输入模式：" << endl;
	cin >> Y;

	int j = 0;
	n = X.length();
	m = Y.length();
	int M = 2 * m * n * n;
	p = random_(M);
	int Wp = (int)pow(2, m) % p;

	int Py = P(Y, 0, Wp);
	int Px = P(X, j, Wp);
	cout << "参数如下：" << endl;
	cout << "p=" << p << ' ' << "m=" << m << ' ' << "n=" << n << ' ' << "M=" << M << ' ' << "Wp=" << Wp << endl;
	bool tag = false;
	while (j <= n - m) {
		cout << "第" << j+1 << "次迭代结果为：" << endl;
		cout << "px=" << Px << ' ' << "py=" << Py << ' ' << "j=" << j << ' ' << "j+m=" << j + m << endl;
		if (Py == Px) {
			cout << "从下标为“ " << j << " ”的模式开始匹配";
			tag = true;
			break;
		}
		else {
			Px = (2 * Px - Wp * (X[j] - 'a') + (X[j + m] - 'a')) % p;
			j++;
		}
	}
	if (!tag) {
		cout << "无匹配模式！" << endl;
		cout << "0";
	}
}