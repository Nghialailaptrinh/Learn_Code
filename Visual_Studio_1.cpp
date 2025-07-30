// Visual_Studio_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//day la code de chuyen thap phann sang nhi phan
#include<iostream>
using namespace std;
void thap_phan_sang_nhi_phan(const int& n) {
	bool print = false; // Bỏ qua số 0 để bắt đầu in hay chưa
	int BIT = sizeof(int) * 8;
	while (BIT--) {
		int i = (n >> BIT) & 0x01;
		if (print) { cout << i; }
		else if (i == 1) { cout << i; print = true; }

	}
}

int main() {
	int n;
	cin >> n;
	thap_phan_sang_nhi_phan(n);
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

