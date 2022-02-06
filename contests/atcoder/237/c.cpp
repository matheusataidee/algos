#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isPalindrome(string& s, int l, int r) {
	while (l < r) {
		if (s[l] != s[r]) return false;
		l++;
		r--;
	}
	return true;
}

bool solve(string& s) {
	int a = 0, b = (int)s.size() - 1;
	while (a < b && s[a] == 'a' && s[b] == 'a') {
		a++;
		b--;
	}
	if (a >= b) return true;
	if (s[a] == 'a') return false;
	while (s[b] == 'a') b--;
	return isPalindrome(s, a, b);
}

int main() {
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	if (solve(s)) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}
