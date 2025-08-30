//Luồng cực đại

#include <iostream>
#include<vector>
#include<queue>
using namespace std;

const int MAXN = 1001;

int n, m, s, t;                  // số đỉnh, số cạnh, đỉnh nguồn, đỉnh đích
vector<int> adj[MAXN];           // danh sách kề (lưu cả cạnh thuận và cạnh ngược)
int c[MAXN][MAXN];               // ma trận dung lượng c[u][v]
int f[MAXN][MAXN];               // ma trận luồng hiện tại f[u][v]
int trace[MAXN];                 // mảng lưu "cha" của mỗi đỉnh trong BFS
int maxFlow;                     // kết quả luồng cực đại

// ====== Hàm BFS để tìm đường tăng luồng ======
bool bfs() {
    fill(trace, trace + n + 1, 0);  // reset trace
    trace[s] = -1;                  // đánh dấu nguồn (không có cha)

    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int v : adj[u]) {
            // Nếu v đã thăm rồi → bỏ qua
            if (trace[v]) continue;

            // Nếu cạnh u->v không còn dung lượng dư → bỏ qua
            if (c[u][v] - f[u][v] == 0) continue;

            // Ghi nhận cha của v là u
            trace[v] = u;
            q.push(v);

            // Nếu đã đến đích thì dừng BFS luôn
            if (v == t) return true;
        }
    }
    return false;  // không tìm được đường tăng luồng
}

// ====== Hàm tăng luồng theo đường tìm được ======
void incFlow() {
    // Bước 1: tìm giá trị delta nhỏ nhất (nghẽn cổ chai)
    int delta = INT_MAX;
    int v = t;
    while (v != s) {
        int u = trace[v];
        delta = min(delta, c[u][v] - f[u][v]);  // dung lượng dư
        v = u;
    }

    // Bước 2: tăng luồng dọc theo đường vừa tìm
    v = t;
    while (v != s) {
        int u = trace[v];
        f[u][v] += delta;   // tăng luồng thuận
        f[v][u] -= delta;   // giảm luồng ngược (cho phép “lùi” luồng sau này)
        v = u;
    }

    // Cộng delta vào tổng luồng cực đại
    maxFlow += delta;
}

// ====== Chương trình chính ======
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> s >> t;   // nhập số đỉnh, cạnh, nguồn, đích
    for (int i = 1; i <= m; i++) {
        int u, v, cap;
        cin >> u >> v >> cap;
        c[u][v] += cap;             // có thể có nhiều cạnh song song → cộng dồn dung lượng
        adj[u].push_back(v);        // cạnh thuận
        adj[v].push_back(u);        // cạnh ngược (dùng khi cần giảm luồng)
    }

    maxFlow = 0;

    // Lặp BFS + tăng luồng đến khi không còn đường từ s tới t
    while (bfs()) {
        incFlow();
    }

    cout << maxFlow << "\n";   // in kết quả
    return 0;
}
