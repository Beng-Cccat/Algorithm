#include<iostream>
#include<time.h>
using namespace std;
int m;
int C[50][50] = { 0 };
string rand_str(const int len)
{
    string str;
    //循环向字符串中添加随机生成的字符
    for (int i = 0; i < len; i++)
    {
        char c = 'a' + rand() % 26;
        str.push_back(c);       
        //push_back()是string类尾插函数,这里插入随机字符c
    }
    return str;
}
void badd(int used[],int n) {
    for (int i = 1; i <= n; i++) {
        if (used[i] != 1) {
            used[i] = 1;
            return;
        }
        else
            used[i] = 0;
    }
    return;
}
void LCS(int n1, int n2,string str1,string str2) {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i] == str2[j])
                C[i][j] = C[i - 1][j - 1] + 1;
            else
                C[i][j]=max(C[i][j-1],C[i-1][j]);
        }
    }
}
int main() {
    clock_t start1, finish1, start2, finish2;
	cout << "请输入序列长度：" << endl;
    cin >> m;
    string str1;
    string str2;

    //cout << "随机产生的字符串为：" << endl;
    //str1 = rand_str(m);
    //str2 = rand_str(m);
    //cout << str1 << endl << str2 << endl;
    //str1 = '0' + rand_str(m);
    //str2 = '0' + rand_str(m);

    cout << "请输入两字符串：" << endl;
    cin >> str1 >> str2;
    str1 = '0' + str1;
    str2 = '0' + str2;

    cout << "动态规划法算出的最大子序列中元素为：" << endl;
    start2 = clock();
    LCS(m, m, str1, str2);
    cout << C[m][m] << endl;
    finish2 = clock();

    cout << "动态规划法耗时：" << finish2 - start2 << "s" << endl;

    int maxstring = 0;
    int used[30] = { 0 };
    start1 = clock();
    string ss;
    for (int i = 0; i < pow(2, str1.length() - 1);i++) {
        badd(used, str1.length() - 1);
        int temp = 0;
        string s;
        for (int j = 0; j < str1.length(); j++)
            if (used[j] == 1)
                s += str1[j];
        int ptr = 1;
        int total = 0;
        for (int j = 0; j < s.length(); j++) {
            while (ptr < str2.length())
            {
                if (s[j] == str2[ptr]) {
                    ptr++;
                    if (j == s.length() - 1)
                        total = 1;
                    break;
                }
                ptr++;
            }
        }
        if (total==1) {
            if (maxstring < (int)s.length())
                ss = s;
            maxstring = max(maxstring, (int)s.length());
        }
    }
    cout << "穷举法算出的最大子序列为：" << ss << endl;
    finish1 = clock();
    cout << "穷举法算出的最大子序列中元素为：" << endl;
    cout << maxstring << endl;
    cout << "穷举法耗时：" << finish1 - start1 << "s" << endl;
}