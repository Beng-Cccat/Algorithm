#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
class point {
public:
    double x, y;//坐标
};
bool compx(point a, point b) {
    return a.x < b.x;
}//比较横坐标的大小关系作为排序的依据
bool compy(point a, point b) {
    return a.y < b.y;
}
double distance(point a, point b) {
    return(pow((a.x - b.x),2) + pow((a.y - b.y),2));
}
double closedistance(point nodex[], point nodey[], int n) {
    //递归结束的条件
    if (n <= 3) {
        double mindist = FLT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                mindist = min(mindist, distance(nodex[i], nodex[j]));//更新最短距离
            }
        }
        return mindist;
    }
    int mid = n / 2;
    point midpoint = nodex[mid];
    point nodeleft[100];//左半部分的点
    point noderight[100];//右半部分的点
    int leftnum = 0;
    int rightnum = 0;
    for (int i = 0; i < n; i++) {
        if (nodey[i].x <= midpoint.x) {
            nodeleft[leftnum++] = nodey[i];
        }
        else {
            noderight[rightnum++] = nodey[i];
        }
    }
    double dl = closedistance(nodex, nodeleft, mid); //递归分治:左边的最近点对
    double dr = closedistance(nodex + mid, nodey + mid, n - mid);//递归分治：右边的最近点对
    double d = min(dl, dr);//找到左右最小的距离中最小的

    //中间部分的最小距离
    point m[100];
    int num = 0;
    for (int i = 0; i < n; i++) {//和中心点距离在d以内的所有点
        if (abs(nodey[i].x - midpoint.x) < d) {
            m[num++] = nodey[i];
        }
    }
    sort(m, m + num, compy);//按照y的大小进行排序
    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num && (m[j].y - m[i].y) < d; j++) {//两点纵向距离小于d，寻找最小距离点
            d = min(d, distance(m[i], m[j]));
        }
    }
    return d;
}
int main() {
    int n;
    cout << "请输入节点数目：" << endl;
    cin >> n;
    point node[100];
    cout << "请依次输入节点的横纵坐标：" << endl;
    for (int i = 0; i < n; i++) {
        cin >> node[i].x >> node[i].y;
    }
    sort(node, node + n, compx);
    cout << "最小点对间的距离为：" << endl;
    cout << closedistance(node, node, n);
    return 0;
}