//Sinh số hoán vị tăng, không tăng
#include<iostream>
#include<vector>

using namespace std;


bool can_rise(int a, int m) {
	return a < m;
}
bool included(int a[], int n,int value) {
	for (int i = 0; i < n; i++) { if (a[i] == value)return true; }
	return false;
}


void sinh_hoan_vi_tang(int a[], int n, int m) {
	int i = n - 1;
	while (can_rise(a[i],m) == false || a[i] >= a[i + 1] - 1) {
		i--;
	}
	if (i < 0) return;
	a[i]++;
	for (; i < n-1; i++) { a[i + 1] = a[i] + 1; }

	for (i = 0;  i < n; i++)cout << a[i]; cout << endl;
	sinh_hoan_vi_tang(a, n, m);
}

void print(int a[100], int n) {
	for (int i = 0; i < n; i++)cout << a[i];
	cout << endl;
}

void sinh_hoan_vi(int a[], int n, int m, int pos) {
	if (pos == n) {
		for (int i = 0; i < n; i++) cout << a[i];
		cout << endl;
		return;
	}
	for (int j = 1; j <= m; j++) {
		if (included(a, pos, j)) continue;
		else a[pos] = j;
		if (pos == n - 1)print(a, n);
		sinh_hoan_vi(a, n, m, pos + 1);
	}
}

int main() {
	cout << "Nhap pham vi: ";
	int m; cin >> m;
	cout << "\nNhap kich thuoc: ";
	int n; cin >> n; cout << endl;
	int a[100];

	for (int i = 0; i < n; i++)a[i] = i + 1; a[n] = 100;  //Ta thêm một phần tử ở cuối để chạy hàm sinh
	cout << "Hoan vi tang la : \n";
	for (int i = 0; i < n; i++)cout << a[i]; cout << endl;
	sinh_hoan_vi_tang(a, n,m);
	cout << "\t\t\t\t\t\t\t\t\\t\n";
	for (int i = 0; i < n; i++)a[i] = i + 1; a[n] = 100;  //Ta thêm một phần tử ở cuối để chạy hàm sinh
	cout << "Hoan vi : \n";
	for (int i = 0; i < n; i++)cout << a[i]; cout << endl;
	sinh_hoan_vi(a, n ,m,0 );
}