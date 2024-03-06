#include<iostream>
#include<queue>
using namespace std;

int Time[5][5] = { 0 };
int mincost[5] = { 0 };//记录第i个老师备课时间最少的那门课的时间
int llb = INT_MAX;

class node {
public:
	int lb;//目标函数（最优边界）
	int task[5];//记录第i个老师分配到了第几个课
	int teachernum;//该节点分配的老师的下标
	int num;//该节点分配给该老师第几个课程
	bool visit[5] = { 0 };//第i个任务是否被分配

	int getlb() {
		//求在分配第teachernum（下标）个老师时的目标函数值
		//比如分配第4个老师的时候，下标为4，需要加上前三个老师的分配的课程的备课时间以及第4个老师的当前分配到的任务时间
		int temp = 0;
		for (int i = 1; i < teachernum; i++) {
			temp += Time[i][task[i]];
		}
		temp += Time[teachernum][num];
		for (int i = teachernum + 1; i <= 4; i++)
			temp += Time[i][task[i]];
		return temp;
	}
	void init(int teachernum, int num, int task[5]) {
		this->teachernum = teachernum;
		this->num = num;
		for (int i = 1; i <= 4; i++) {
			this->task[i] = task[i];
			visit[i] = 0;
		}
		this->lb = getlb();
		for (int i = 1; i <= teachernum; i++) {
			visit[task[i]] = 1;
		}
	}
	void print() {
		int sum = 0;
		for (int i = 1; i <= 4; i++)
		{
			cout << "第" << i << "个老师分配第" << task[i] << "节课" << endl;
			sum += Time[i][task[i]];
		}
		cout << "总共备课时间为：" << sum << endl;
	}
	bool operator< (const node a)const {
		return lb > a.lb ;//升序排列
	}
};

node target;
void bab() {
	priority_queue<node> queue;
	node head;
	head.init(0, -1, mincost);
	
	queue.push(head);
	while (!queue.empty()) {
		node topnode = queue.top();

		int task[5] = { 0 };
		for (int i = 1; i <= 4; i++)
			task[i] = topnode.task[i];

		queue.pop();
		int new_teachernum = topnode.teachernum + 1;
		node newnode;
		for (int j = 1; j <= 4; j++)//查看第i节课是否被分配
		{
			if (!topnode.visit[j]) {
				newnode.num = j;
				newnode.init(new_teachernum, j, task);
				newnode.visit[j] = 1;
				newnode.task[new_teachernum] = j;
				if (newnode.lb < llb&&newnode.teachernum!=4)
					queue.push(newnode);
			}
		}
		if (newnode.teachernum == 4) {//分配结束，此处最后一个老师已经分配完成
			if (newnode.getlb() <= llb) {
				llb = newnode.getlb();
				target = newnode;
				continue;
			}
		}
		if (queue.empty())
			target.print();
	}
}
int main() {
	cout << "请依次输入4名教师对4门课的备课时间：" << endl;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			cin >> Time[i][j];
		}
		cout << endl;
	}//输入
	for (int i = 1; i <= 4; i++) {//初始化mincost[]
		int mincost_ = INT_MAX;
		for (int j = 1; j <= 4; j++)
			if (mincost_ > Time[i][j]) {
				mincost_ = min(mincost_, Time[i][j]);
				mincost[i] = j;
			}
	}
	bab();
}
