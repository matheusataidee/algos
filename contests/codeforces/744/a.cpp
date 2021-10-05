#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		vector<int> freq(26);
		for (char c : s) {
			freq[c - 'A']++;
		}
		if (freq['A' - 'A'] + freq['C' - 'A'] == freq['B' - 'A']) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
