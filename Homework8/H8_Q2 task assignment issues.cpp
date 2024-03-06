#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;

int nA, nB, p;
int ta[10] = { 0 }, tb[10] = { 0 }, ka[10] = { 0 }, kb[10] = { 0 };
int onenode[50][50][50] = { 0 };
int nodes[50][50][50] = { 0 };

void anode() {//onenode[z][i][j]为第z个节点完成i个A任务和j个B任务所要使用的最短时间
	for (int z = 1; z <= p; z++) {
		//节点序号为1-p

		int P[30][30][2] = { 0 };
		//节点i完成任务(a,b)所花的最短时间(最后完成的一项子任务是A类子任务)
		//节点i完成任务(a,b)所花的最短时间(最后完成的一项子任务是B类子任务)
		memset(P, 0x3F, sizeof(P));//初始化为最大值
		P[0][0][0] = 0;
		P[0][0][1] = 0;

		for (int i = 0; i <= nA; i++) {
			//总共可能有0-nA个A类任务
			for (int j = 0; j <= nB; j++) {
				//总共可能有0-nB个B类任务
				for (int w = 1; w <= i; w++)
					P[i][j][0] = min((P[i - w][j][1] + ta[z] + ka[z] * w * w), P[i][j][0]);
					//Pi(a,b,0)=min(1<=w<=a){Pi(a-w,b,1)+ta+ka*w*w}
				for (int w = 1; w <= j; w++)
					P[i][j][1] = min((P[i][j - w][0] + tb[z] + kb[z] * w * w), P[i][j][1]);
					//Pi(a,b,1)=min(1<=w<=a){Pi(a,b-w,0)+tb+kb*w*w}
				onenode[z][i][j] = min(P[i][j][0], P[i][j][1]);
				//节点i完成所分配的任务时,最后所完成的子任务不是A类子任务就是B类子任务.
			}
		}
	}
}

void manynodes() {
	memset(nodes, 0x3f, sizeof(nodes));
	for (int i = 0; i <= nA; i++) {
		for (int j = 0; j <= nB; j++) {
			nodes[1][i][j] = onenode[1][i][j];
		}
	}
	//nodes[a][i][j]：将任务分配给前a个节点，完成i个A任务和j个B任务所要的最短时间
	for (int a = 2; a <= p; a++) {
		//节点个数从2开始，一直到p（总共p个节点）
		for (int i = 0; i <= nA; i++)
			//总共可能有0-nA个A类任务
			for (int j = 0; j <= nB; j++)
				//总共可能有0-nB个B类任务
				for (int k = 0; k <= i; k++)
					for (int l = 0; l <= j; l++)
						nodes[a][i][j] = min(nodes[a][i][j], max(nodes[a - 1][i - k][j - l], onenode[a][k][l]));
						//分配给第a个节点的任务是(k,l)
						//前a-1个节点的任务是(a-k,j-l)，所要的最短时间为nodes[a-1][i-k][j-l]
						//节点是并行完成任务的，所以最短时间即为所有节点完成任务的最短时间max{nodes[a-1][i-k][j-l],onenode[a][k][l]}
						//而我们要求的是这些最短时间中的最短时间，即min{nodes[a][i][j],max{...}}

	}
}
int main() {
	ifstream infile(".//hpc.in.txt", ios::in);
	if (!infile)
		cout << "打开失败！" << endl;
	int x = 3;
	int xx[3];//存nA，nB,p三个变量
	while (x) {
		infile >> xx[3 - x];
		x--;
	}
	nA = xx[0];
	nB = xx[1];
	p = xx[2];//依次赋值
	for (int i = 1; i <= p; i++)
		infile >> ta[i] >> tb[i] >> ka[i] >> kb[i];
	infile.close();

	anode();
	manynodes();
	ofstream outfile("hpc.out.txt");
	outfile << nodes[p][nA][nB];
	outfile.close();
	cout << "已成功将答案写入文件hpc.out";
	return 0;
}
