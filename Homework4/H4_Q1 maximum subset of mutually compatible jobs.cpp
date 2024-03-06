#include<iostream>
using namespace std;

int jobs[20][2] = { 0 };
int n = 1;

void change(int i, int j) {
	int temp[2] = { jobs[i][0],jobs[i][1] };
	jobs[i][0] = jobs[j][0];
	jobs[i][1] = jobs[j][1];
	jobs[j][0] = temp[0];
	jobs[j][1] = temp[1];
}

int main() {
	int num_jobs;
	cin >> num_jobs;
	for (int i = 0; i < num_jobs; i++)
		cin >> jobs[i][0] >> jobs[i][1];
	int before[2] = { jobs[0][0],jobs[0][1] };

	//按照结束时间升序排列：
	for (int i = 0; i < num_jobs; i++) {
		for (int j = i; j < num_jobs; j++) {
			if (jobs[i][1] > jobs[j][1])
				change(i, j);
		}
	}

	for (int i = 0; i < num_jobs; i++) {
		if (before[1] <= jobs[i][0]) {
			n++;
			before[0] = jobs[i][0];
			before[1] = jobs[i][1];
		}
	}
	cout << "利用贪心算法求得的最大兼容子集中的活动数：" << endl;
	cout << n ;
}