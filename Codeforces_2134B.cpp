//codeforces 2134B

#include<iostream>
#include<vector>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;

		vector < long long > a(n);
		for (auto &i : a) {
			cin >> i;
			i += (i % (k + 1)) * k;
		}

		for (auto i : a)cout << i << " ";
		cout << "\n";
	}

}