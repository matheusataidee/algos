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
		
		deque<int> deq;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (deq.empty() || deq[0] > x) {
				deq.push_front(x);
			} else {
				deq.push_back(x);
			}
		}
		
		for (int i = 0; i < n; i++) {
			cout << deq[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
