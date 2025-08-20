//Queens problem
//Bài toán Xếp hậu
//Liệt ke k <=n con hậu trong bàn cờ nxn sao cho chúng không thể ăn lần nhau vaf không chế tất cả cả ô cảu bàn cờ, tất nhiên không phải với cặp số k, n nào cũng có lời giải
/*Quy ước i là dòng, i là cột, đường chéo góc 45 độ là i + j = const value, góc -45 độ là i - j = const value
với mội con hậu gắn với một giá trị i, ta tìm giá trị j duy nhất ứng với mỗi quân hậu sao cho nó không đứng vào vị trí hai đường chéo của các con hậu đã được đặt

2<=i+j<= n*2;
1<=i-j +n <=2*n-1
*/
#include <iostream>
using namespace std;

int row[100], col[100], Dia45[200], Dia_45[200]; // đánh dấu các vị trí đã bị chiếu
int n, k;
int countSolution = 0;

// Kiểm tra ô (i, j) có bị khống chế không
bool under_attack(int i, int j) {
    return row[i] || col[j] || Dia45[i + j] || Dia_45[i - j + n];
}

// In lời giải
void print() {
    cout << "------------------------\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (row[i] && row[i] == j) cout << " Q ";
            else cout << " _ ";
        }
        cout << endl;
    }
    cout << endl;
}

// Kiểm tra toàn bộ bàn cờ có bị khống chế bởi ít nhất 1 quân hậu không
bool fullfill() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!under_attack(i, j)) return false;
    return true;
}

// Đặt hậu
void put(int placed, int startRow = 1) {
    if (placed == k) {
        if (fullfill()) {
            countSolution++;
            print();
        }
        return;
    }

    for (int i = startRow; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!under_attack(i, j)) {
                row[i] = j;
                col[j] = Dia45[i + j] = Dia_45[i - j + n] = 1;

                put(placed + 1, i + 1); // chỉ đặt 1 hậu mỗi dòng

                // backtrack
                row[i] = 0;
                col[j] = Dia45[i + j] = Dia_45[i - j + n] = 0;
            }
        }
    }
}

int main() {
    cout << "Nhap kich thuoc ban co (n): ";
    cin >> n;
    cout << "Nhap so quan hau (k): ";
    cin >> k;

    put(0); // bắt đầu đặt hậu từ dòng 1

    if (countSolution == 0)
        cout << "Khong co cach dat nao thoa man.\n";
    else
        cout << "So cach dat: " << countSolution << endl;
}
