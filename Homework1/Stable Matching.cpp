#include<iostream>
#include<stack>
using namespace std;
void select(string s, char array[100][100], int row,int n) {
	for (int j = 0; j < n+1; j++) {
		array[row][j] = s[2 * j];
	}
}
int search(char x, char array[100][100]) {
	for (int i = 0;; i++) {
		if (array[i][0] == x)
			return i;
	}
}
int main() {
	char mes[100][100] = {};
	int n;
	stack<char> man;
	cin >> n;
	char point[100][2] = {};
	char free[100][2];
	for (int i = 0; i < 2*n; i++) {
		string s;
		cin >> s;
		select(s, mes, i, n);
		if (i < n) {
			point[i][0] = s[0];
			point[i][1] = 1;
			man.push(s[0]);
		}
		if (i > n - 1) {
			free[i-n][0] = s[0];
			free[i-n][1] = 1;//1表示女生可撩
		}
	}
	while (!man.empty()) {
		int num = search(man.top(), mes);//这个男生在数组里面排第几,数组索引值
		bool tag = 1;//tag表示这个男生还没找到合适的
		while (tag) {
			char prewoman = mes[num][point[num][1]];//这个男生目前可以的最优选择
			bool vic = 1;//vic->是否找到该女生
			for (int i = 0;vic; i++) {//寻找此时的最佳伴侣
				if (free[i][0] == prewoman) {//找到这个女生的数组
					if (free[i][1] == 1) {
						free[i][1] = man.top();
						tag = 0;
						man.pop();
					}
					else {
						char man_now = man.top();
						char man_before = free[i][1];
						for (int j = 1; j < n; j++) {
							if (mes[search(prewoman, mes)][j] == man_before) {
								break;
							}
							else if (mes[search(prewoman, mes)][j] == man_now) {
								tag = 0;//这个男生找到合适的了
								free[i][1] = man_now;
								man.pop();
								man.push(man_before);
							}
						}
					}
					point[num][1]++;
					vic = 0;//跳出当前女生的循环
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << "(" << free[i][1] << ',' << free[i][0] << ')' << endl;
	}
}