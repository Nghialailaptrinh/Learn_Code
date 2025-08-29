//Đồ thị Euler
//Code liệt ke đường đi Euler
//Đường đi EUler là đường đi qua tất cả các cạnh của đò thị đúng một lần

#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

int dem = 0, so_canh = 0;
int* L, ** A, n;
int  nguon = 0;

void read(int** &A, int& n) {
	cout << "Nhap so dinh cua do thi: "; cin >> n;
	A = new int* [n]; int bac_dinh;
	cout << "Nhap ma tran bieu dien do thi\n";
	for (int i = 0; i < n; i++) {
		A[i] = new int[n];
		bac_dinh = 0;
		for (int j = 0; j < n; j++) { cin >> A[i][j]; if (A[i][j] == 1)bac_dinh++; }
		if (bac_dinh % 2 == 1)nguon = i;
		so_canh += bac_dinh;
	}
	so_canh /= 2;
	L = new int[so_canh + 1];
	L[0] = nguon;
}

//In
void print() {
	dem++;
	cout << "\n" << nguon + 1;
	for (int i = 1; i <= so_canh; i++) {
		cout << "->" << L[i] + 1;
	}
}

void Try(int canh) {
	if (canh > so_canh) print();
	else {
		for (int i = 0; i < n; i++) {
			if (A[L[canh - 1]][i] > 0) {
				L[canh] = i;   // đi tiếp sang i
				A[L[canh - 1]][i] = A[i][L[canh - 1]] = 0; // xóa cạnh (đã đi qua)
				Try(canh + 1);
				A[L[canh - 1]][i] = A[i][L[canh - 1]] = 1; // backtrack, khôi phục cạnh
				L[canh] = 0;
			}
		}
	}
}

//Delete
void dele(int** A, int* L, int n) {
	delete[]L;
	for (int i = 0; i < n; i++) {
		delete[] A[i];
	}
	delete[]A;
}

int main() {
	system("CLS");
	read(A, n);
	cout << "Duong di Euler: \n";
	Try(1);
	if (dem == 0) {
		cout << "Khong co duong di Euler!\n";
		dele(A, L, n);
		_getch();
	}
	return 0;
}

