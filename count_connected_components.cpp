// Đếm số miền liên thông của đồ thị vô hướng
// Đầu vào số đỉnh, các số 0 và 1 thể hiện sự liên thông các đỉnh

#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<iomanip>

using namespace std;
void read(int** &a, int &n) {
	cout << "Nhap so dinh cua do thi: "; cin >> n; cout << endl;
	a = new int*[n];
	cout << "Nhap cac dinh lien ke\n ";
	for (int i = 1; i <= n; i++)cout << " "<<i ;
	cout << endl;
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
		cout << i + 1<<" ";
		for (int j = 0; j < n; j++)cin >> a[i][j]; cout << endl;
	}
}

void dele (int** a, int n) {
	for (int i = 0; i < n; i++) {
		delete[] a[i];
	}
	delete[] a;
}

void print(int** a, int n) {
	cout << "Bang bieu dien canh ke cua do thi \n";
	for (int i = 1; i <= n; i++)cout << "  " << i;
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << i + 1<<" ";
		for (int j = 0; j < n; j++)cout<< a[i][j]<<" "; cout << endl;
	}
}


int so_mien(int**& a, int n) {           // It's better
	int* marked = new int[n];  // dùng int thay vì char
	for (int i = 0; i < n; i++) marked[i] = 0;  // 0 = chưa thăm

	int somlth = 0; // số miền liên thông
	bool cucces;
	int dem = 0;

	do {
		// tìm 1 đỉnh chưa thăm
		int j = 0;
		while (marked[j] != 0) j++;

		somlth++;            // bắt đầu miền mới
		marked[j] = somlth;  // gán nhãn miền
		dem++;

		do {
			cucces = false;
			for (int i = 0; i < n; i++) {
				if (marked[i] == somlth) { // chỉ duyệt đỉnh trong miền hiện tại
					for (int k = 0; k < n; k++) {
						if (marked[k] == 0 && a[i][k] > 0) {
							marked[k] = somlth;
							cucces = true;
							dem++;
							if (dem == n) return somlth;
						}
					}
				}
			}
		} while (cucces);
	} while (dem < n);

	delete[] marked;
	return somlth;
}

int main() {
	system("CLS");
	int** a=nullptr, n=0;
	read(a, n);
	cout << "\n\n";
	cout << "So mien lien thong tronf do thi da cho = " << so_mien(a, n);
	dele(a, n);
	_getch();
	return 0;
}
