//https://codeforces.com/problemset/problem/2134/C
//codeforces 2134C
#include <iostream>
using namespace std;
#define N 1000005

long long a[N];

long long fix(long long a[N], int n) {
    long long count = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2) {
            long long k = a[i - 1] + a[i + 1] - a[i];
            if (k > 0) {
                if (a[i + 1] >= k) a[i + 1] -= k;
                else {
                    long long tmp = a[i + 1];
                    a[i + 1] = 0;
                    a[i - 1] -= (k - tmp);
                }
                count += k;
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        a[n] = 0; // tránh out of bound
        cout << fix(a, n) << "\n";
    }
}
