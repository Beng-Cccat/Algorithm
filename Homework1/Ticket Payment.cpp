#include<iostream>
using namespace std;
int main() {
	int number;
	int cheap_number;
	int normal_price;
	int cheap_price;
	int least_price = INT_MAX;
	cin >> number >> cheap_number >> normal_price >> cheap_price;
	for (int i = 0; i * cheap_number <= number; i++) {
		int temp = i * cheap_price + (number - i * cheap_number) * normal_price;
		if (temp < least_price)
			least_price = temp;
	}
	cout << least_price;
}