#include<iostream>
using namespace std;
int main() {
	string number;
	cin >> number;
	int length = number.length();
	if (number[0] != '-')
		cout << number;
	else {
		if (number[length - 2] < number[length-1]) {
			number.erase(length - 1);
		}
		else {
			number[length - 2] = number[length - 1];
			number.erase(length - 1);
		}
		if (number.length() == 2 && number[1] == '0')
			cout << 0;
		else
			cout << number;
	}
}