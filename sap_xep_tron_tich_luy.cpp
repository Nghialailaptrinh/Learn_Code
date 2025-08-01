#include<iostream>
#include<iomanip>
#include<conio.h>
#include<stdio.h>
//Sắp xếp trộn không đệ quy
#define max 100
using namespace std;
int b[max], c[max], nb, nc;

void phan_phoi(int a[], int N, int& nb, int& nc, int k) {
	int i, ja, jb, jc;
	ja = jb = jc = 0;
	while (ja < N) {
		for (i = 0; (ja < N) && (i < k); i++, ja++, jb++) {
			b[jb] = a[ja];
		}
		for (i = 0; (ja < N) && (i < k); i++, ja++, jc++) {
			c[jc] = a[ja];
		}
	}
	nb = jb;
	nc = jc;
}

int min(int a, int b) {
	if (a > b)return b;
	else return a;
}

void tron(int a[], int nb, int nc, int k) {
	int j, jb, jc, ib, ic, kb, kc;
	j = jb = jc = 0;
	kb = kc = 0;
	ib = ic = 0;
	while ((nb > 0) && (nc > 0)) {
		kb = min(k, nb);
		kc = min(k, nc);
		if (b[jb + ib] < c[jc + ic]) {
			a[j++] = b[jb + ib]; ib++;
			if (ib == kb) {
				for (; ic < kc; ic++) {
					a[j++] = c[jc + ic];
				}
				jb += kb;
				jc += kc;
				ib = ic = 0;
				nb -= kb;
				nc -= kc;

			}
		}
		else {
			a[j++] = c[jc + ic]; ic++;
			if (ic == kc) {
				for (; ib < kb; ib++) {
					a[j++] = b[jb + ib];
				}
				jb += kb;
				jc += kc;
				ib = ic = 0;
				nb -= kb;
				nc -= kc;
			}
		}
	}
}

void xep_tron(int a[], int N) {
	int k, nc = 0, nb = 0;
	for (k = 1; k < N; k *= 2) {
		phan_phoi(a, N, nb, nc, k);
		tron(a, nb, nc, k);
	}
}

void nhap(int a[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		cout << "\nNhap [" << i << "]: ";
		cin >> a[i];
	}
}

void xuat(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << setw(4) << a[i];
	}
}

int main() {
	int a[max], n;
	system("CLS");
	cout << "Nhap so phan tu n cua day: ";
	cin >> n;
	nhap(a, n);
	cout << "\nDay vua nhap la: "; xuat(a, n);
	xep_tron(a, n);
	cout << "\nKet qua xep tron la: "; xuat(a, n);
	//getch();
}
