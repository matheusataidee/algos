#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void remove(int k, vector<int>& avail) {
	int n = avail.size();
	for (int i = 1; i * k < n; i++) {
		avail[i * k] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> avail(n, 1);
	int num = n;
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			while (num % i == 0) num /= i;
			remove(i, avail);
		}
	}
	if (num > 1) remove(num, avail);
	ll total = 1;
	for (int i = 1; i < n; i++) {
		if (avail[i]) {
			total *= i;
			total %= n;
		}
	}
	if (total % n != 1) avail[total] = 0;
	
	vector<int> ans;
	for (int i = 1; i < n; i++) {
		if (avail[i]) ans.push_back(i);
	}
	cout << ans.size() << endl;
	for (int& val : ans) cout << val << " ";
	cout << endl;
	
	return 0;
}
