//Sinh số nhị phân
#include<iostream>

using namespace std;

bool check_end(int a[], int n) {
	for (int i = 0; i < n ; i++) {
		if (a[i] !=1)return false;
	}
	return true;
}

void sinh_binary(int a[], int n) {
	if (check_end(a, n))return;

	int i = n - 1;
	while (a[i] == 1)
	{
		a[i] = 0; i--;
	}
	a[i] = 1;

	for (i = 0; i < n; i++)cout << a[i];
	cout << endl;
	sinh_binary(a, n);
}

void sinh_binary_permutation(int a[], int n) {
	int i = n - 1;
	while (a[i] == 1)i--;
	while (a[i] == 0) i--;
	if (i == -1) return ; // Hiệu quả hơn hàm check_end
	swap(a[i], a[i + 1]);
	reverse(a + i + 2, a + n);

	for (i = 0; i < n; i++)cout << a[i];
	cout << endl;

	sinh_binary_permutation(a, n);
}


int main() {
	int n; cin >> n;
	int a[100] = { 0 };
	//for (int i = 0; i < n; i++) { cin >> a[i]; }
	for (int i = 0; i < n; i++)cout << a[i];
	cout << endl;
	sinh_binary(a, n);


	cout << "Nhap so so 1";
	int number_one; cin >> number_one;

	fill(a, a + n, 0); cout << endl;
	fill(a, a + number_one, 1);
	for (int i = 0; i < n; i++)cout << a[i]; cout << endl;

	sinh_binary_permutation(a, n);
}