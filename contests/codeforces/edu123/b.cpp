#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v;
		if (n == 3) {
			cout << "3 2 1" << endl;
			cout << "1 3 2" << endl;
			cout << "3 1 2" << endl;
		} else {
			for (int i = n; i >= 1; i--) {
				v.push_back(i);
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cout << v[(i+j) % n] << " ";
				}
				cout << endl;
			}
		}
	}
	return 0;
}
