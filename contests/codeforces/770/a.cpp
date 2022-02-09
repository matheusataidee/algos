#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isPalindrome(const string& s) {
	int l = 0, r = (int)s.size() - 1;
	while (l < r) {
		if (s[l] != s[r]) {
			return false;
		}
		l++; r--;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		if (isPalindrome(s) || !k) {
			cout << "1" << endl;
		} else {
			cout << "2" << endl;
		}
	}
	return 0;
}
