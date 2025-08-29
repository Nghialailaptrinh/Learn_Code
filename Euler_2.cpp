
//Chu trình Euler

#include <iostream>
#include <vector>
using namespace std;

int n;                          // Số đỉnh
vector<vector<int>> A;          // Ma trận kề
bool have = true;               // Kiểm tra bậc chẵn
vector<int> L;                  // Chu trình Euler hiện tại
int so_canh = 0;                // Tổng số cạnh đã đếm

// Đọc đồ thị
void readGraph() {
    cout << "Nhap so dinh cua do thi: ";
    cin >> n;
    A.assign(n, vector<int>(n, 0));
    cout << "Nhap ma tran bieu dien do thi (0 hoac 1):\n";

    for (int i = 0; i < n; i++) {
        int bac_dinh = 0;
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
            if (A[i][j] == 1) bac_dinh++;
        }
        if (bac_dinh % 2 == 1) have = false;
        so_canh += bac_dinh;
    }
    so_canh /= 2; // mỗi cạnh đếm 2 lần
}

// In chu trình Euler
void printEuler() {
    cout << "\nChu trinh Euler: ";
    for (size_t i = 0; i < L.size(); i++) {
        if (i > 0) cout << "->";
        cout << L[i] + 1;
    }
    cout << endl;
}

// Tìm chu trình con bắt đầu từ đỉnh 'u'
vector<int> findCycle(int u) {
    vector<int> cycle;
    cycle.push_back(u);

    int curr = u;
    while (true) {
        bool found = false;
        for (int v = 0; v < n; v++) {
            if (A[curr][v] == 1) {
                // Đi qua cạnh
                A[curr][v] = A[v][curr] = 0;
                cycle.push_back(v);
                curr = v;
                found = true;
                break;
            }
        }
        if (!found || curr == u) break; // quay lại đỉnh bắt đầu hoặc không còn cạnh
    }

    return cycle;
}

// Thuật toán Euler
void euler() {
    if (!have) {
        cout << "Khong co chu trinh Euler\n";
        return;
    }

    // Bắt đầu từ đỉnh 0
    L = findCycle(0);

    // Ghép các chu trình con vào chu trình chính
    for (size_t i = 0; i < L.size(); i++) {
        int u = L[i];
        // Nếu còn cạnh chưa đi từ u
        bool hasEdge = false;
        for (int v = 0; v < n; v++) {
            if (A[u][v] == 1) {
                hasEdge = true;
                break;
            }
        }
        if (hasEdge) {
            vector<int> cycle = findCycle(u);
            // Chèn vào đúng vị trí i (bỏ phần đầu chu trình con vì đã có u)
            L.insert(L.begin() + i + 1, cycle.begin() + 1, cycle.end());
        }
    }

    printEuler();
}

int main() {
    readGraph();
    euler();
    return 0;
}
