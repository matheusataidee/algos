#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string transf(string s, string order) {
	string ret = "";
	set<char> forbidden;
	for (int i = 0; i < (int)order.size(); i++) {
		for (char c : s) {
			if (!forbidden.count(c)) ret += c;
		}
		forbidden.insert(order[i]);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	int tt;
	cin >> tt;
	while (tt--) {
		string t;
		cin >> t;
		vector<int> freq(26), partial(26);
		for (char c : t) freq[c - 'a']++;
		string s = "", ans;
		for (char c : t) {
			freq[c - 'a']--;
			if (!freq[c - 'a']) s += c;
		}
		for (char c : t) freq[c - 'a']++;
		
		int n = s.size();
		bool cond = false;
		for (int i = 0; !cond && i < (int)t.size(); i++) {
			partial[t[i] - 'a']++;
			cond = true;
			for (int j = 0; cond && j < n; j++) {
				if (freq[s[j] - 'a'] % (j + 1) != 0) cond = false;
				if (freq[s[j] - 'a'] / (j + 1) != partial[s[j] - 'a']) cond = false;
			}
			if (cond) {
				ans = t.substr(0, i+1);
				if (t == transf(ans, s)) {
					cout << ans << " " << s << endl;
				} else {
					cond = false;
				}
			}
		}
		if (!cond) cout << "-1" << endl;
	}
	
	return 0;
}
