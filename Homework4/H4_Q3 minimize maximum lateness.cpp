#include<iostream>
using namespace std;

int timeend = 0;
int delaynum = 0;
int jobs[20][2] = { 0 };

void change(int i, int j) {
	int temp[2] = { jobs[i][0],jobs[i][1] };
	jobs[i][0] = jobs[j][0];
	jobs[i][1] = jobs[j][1];
	jobs[j][0] = temp[0];
	jobs[j][1] = temp[1];
}
int main() {
	int jobs_num;
	cout << "请输入事件数：" << endl;
	cin >> jobs_num;
	cout << "请依次输入事件持续时间和截止时间：" << endl;
	for (int i = 0; i < jobs_num; i++) 
		cin >> jobs[i][0] >> jobs[i][1];
	//按照截止时间升序排序：
	for (int i = 0; i < jobs_num; i++) {
		for (int j = i+1; j < jobs_num; j++) {
			if (jobs[i][1] > jobs[j][1])
				change(i, j);
		}
	}

	for (int i = 0; i < jobs_num; i++) {
		timeend += jobs[i][0];
		if (timeend > jobs[i][1]&&(delaynum<timeend-jobs[i][1])) {
			delaynum = timeend - jobs[i][1];
		}
			
	}
	cout << "最小延迟调度为：" << endl;
	cout << delaynum;
}