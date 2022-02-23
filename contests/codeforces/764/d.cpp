#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int alp_size = 26;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		string s;
		cin >> n >> k;
		cin >> s;
		
		vector<int> freq(alp_size, 0);
		for (char c : s) {
			freq[c - 'a']++;
		}
		int sum = 0, odd = 0;
		for (int i = 0; i < alp_size; i++) {
			sum += freq[i] / 2;
			odd += freq[i] % 2;
		}
		odd += (sum % k) * 2;
		
		int ans = (sum / k) * 2;
		if (odd >= k) ans++;
		cout << ans << endl;
	}
	return 0;
}
