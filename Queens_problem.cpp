//Queens problem
//Bài toán Xếp hậu
//Liệt ke n con hậu trong bàn cờ nxn sao cho chúng không thể ăn lần nhau
/*Quy ước i là dòng, i là cột, đường chéo góc 45 độ là i + j = const value, góc -45 độ là i - j = const value
với mội con hậu gắn với một giá trị i, ta tìm giá trị j duy nhất ứng với mỗi quân hậu sao cho nó không đứng vào vị trí hai đường chéo của các con hậu đã được đặt

2<=i+j<= n*2;
1<=i-j +n <=2*n-1
*/
#include<iostream>
using namespace std;
int row[100],col[100], Dia45[200], Dia_45[200]; //Các cột, dòng, các đường chéo chưa được điền có giá trị là 0; row đặc biệt vì row[1]=2 tức là dòng 1 cột 2
int n=0; 

void print() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (row[i] == j) { cout << 'X'; }
			else cout << "--";
		}

		cout << endl;
	}
	cout << endl;
}

bool can_put(int i, int j) {
	return ((Dia45[i + j] == 0) && (Dia_45[i - j + n] == 0) &&(col[j]==0));
}

void put(int i) {
	for (int j = 1; j <= n; j++) {
		if (can_put(i, j)) {
			row[i] = j; Dia45[i + j] = 1; Dia_45[i - j + n] = 1; col[j] = 1;
			if (i == n) { print();}
			else put(i + 1);
			row[i] = 0; Dia45[i + j] = 0; Dia_45[i - j + n] = 0; col[j] = 0;
		}
	}

}

int main() {
	cout << "Nhap kich thuoc ban co:\n";
	cin >> n; 
	put(1);
	  
}
