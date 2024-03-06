#include<iostream>
using namespace std;

int jobs[20][2] = { 0 };
int num_jobs;
int room_num = 0;
int n = 1;
class room {
public:
	int jobs[20][2];
	int ptr = 0;
	int before[2] = { 0 };
	room() {};
	void add(int jobs_[2]) {
		jobs[ptr][0] = jobs_[0];
		jobs[ptr][1] = jobs_[1];
		ptr++;
		before[0] = jobs_[0];
		before[1] = jobs_[1];
	}
};
void change(int i, int j) {
	int temp[2] = { jobs[i][0],jobs[i][1] };
	jobs[i][0] = jobs[j][0];
	jobs[i][1] = jobs[j][1];
	jobs[j][0] = temp[0];
	jobs[j][1] = temp[1];
}

int main() {
	cout << "请输入课程数：" << endl;
	cin >> num_jobs;
	cout << "请依次输入这些课程的开始时间和结束时间：" << endl;
	for (int i = 0; i < num_jobs; i++)
		cin >> jobs[i][0] >> jobs[i][1];

	//按照开始时间进行升序排序：
	for (int i = 0; i < num_jobs; i++) {
		for (int j = i; j < num_jobs; j++) {
			if (jobs[i][0] > jobs[j][0])
				change(i, j);
		}
	}
	room classroom[20];
	classroom[0].add(jobs[0]);
	for (int i = 0; i < num_jobs; i++) {
		bool tag = 0;
		for (int j = 0; j < room_num; j++) {
			if (classroom[j].before[1] <= jobs[i][0]) {
				classroom[j].add(jobs[i]);
				tag = 1;
				break;
			}
		}
		if (tag == 0) {
			classroom[room_num].add(jobs[i]);
			room_num++;
		}
	}
	cout << "容纳这些课程至少需要的教室数为：" << endl;
	cout << room_num;
}