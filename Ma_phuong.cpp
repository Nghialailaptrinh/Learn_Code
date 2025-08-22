//Code tạo ra ma phương kich thuoc nxn
//n phải nhập số lẻ
#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std;


int main() {
	int row, col, value=1,n;
	int a[100][100];

	do {
		cout << "Nhap kich thuoc cua ma phuong: "; cin >> n;
	} while (n % 2 == 0 || n>100);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = 0;

		}
	}
	row = 0; col = n / 2;
	a[row][col] = value++;

	while (value <= n * n) {
		row = (row - 1 + n) % n;
		col = (col + 1) % n;
		if (a[row][col] == 0)a[row][col] = value ++;
		else {
			row = (row - 1 + n) % n;
			col = (col - 1 + n) % n;
			a[row][col] = value++;
		}
	}

	cout << "Ma phuong:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) { 
			 cout<<setw(3) << a[i][j];

		}
		cout << endl;
	}
	cout << "Press any key to end.";
	//getch();  //không dùng với VS Studio
	system("pause");  // Có thể dùng với Window
	//_getch();  //Chỉ dùng với VS Studio
	return 0;
}