//Đây là code sắp xếp bằng phann phối tự nhiên
#include<iostream>
#include<vector>

using namespace std;
vector<int> a, b, c;
int n;// Kích cỡ của a

void phan_phoi(int n) {
	int i = 0;
	b.push_back(a[i]);
	for (i++; i < n; i++) {    // lấy một run ra b
		if (a[i] >= a[i - 1]) { b.push_back(a[i]); }
		else break;
	}
	if (i < n) { c.push_back(a[i]); }
	for (i++; i < n; i++) {  //Lấy một run ra c
		if (a[i] >= a[i - 1]) { c.push_back(a[i]); }
		else break;
	}
}

void tron() {
	int nb = b.size(), nc = c.size();
	int i = 0, j = 0,k=0;
	while (i < nb && j < nc) {
		if (b[i] < c[j]) { a[k] = b[i]; i++;  }
		else { a[k] = c[j]; j++;  }

		k++;
	}
	if(i<nb){
		for (; i < nb; i++) { 
			a[k] = b[i]; k++;
		}
	}
	if (j < nc) {
		for (; j < nc; j++) {
			a[k] = c[j]; k++;
		}
	}
	b.clear();
	c.clear();
}

bool da_sap_xep() {
	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) { return false; }
	}
	return true;
}

int main() {
	cout << "Nhap so phan tu cua mang a: "; cin >> n;
	cout << "\nNhap phan tu cua a: ";
	for (int i = 0; i < n; i++) { int x; cin >> x; a.push_back(x); }
	while (!da_sap_xep() ) {
		phan_phoi(n);
		tron();
	}

	for (int i = 0; i < n; i++)cout << a[i] << " ";
	cout << endl;
}