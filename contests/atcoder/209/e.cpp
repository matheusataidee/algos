#include <bits/stdc++.h>

using namespace std;

#define MAXN 52 * 52 * 52

typedef long long ll;

vector<int> win(MAXN, -1);
vector<int> deg(MAXN);
vector<vector<int> > g(MAXN);

int charToInt(char c) {
	if (c >= 'a' && c <= 'z') return c - 'a';
	return c - 'A' + 26;
}

int convert(char c1, char c2, char c3) {
	return charToInt(c1) + 52 * charToInt(c2) + 52 * 52 * charToInt(c3);
}

int main() {
	ios::sync_with_stdio(false);
	int n;	cin >> n;
	vector<string> v(n);
	for (string& s : v) {
		cin >> s;
		int sz = s.size();
		int from = convert(s[sz-3], s[sz-2], s[sz-1]);
		int to = convert(s[0], s[1], s[2]);
		g[from].push_back(to);
		deg[to]++;
	}
	queue<int> myq;
	for (int i = 0; i < MAXN; i++) {
		if (!deg[i]) {
			win[i] = 0;
			myq.push(i);
		}
	}
	while (!myq.empty()) {
		int p = myq.front();	myq.pop();
		for (int to : g[p]) {
			if (win[to] != -1) continue;
			if (win[p] == 0) {
				win[to] = 1;
				myq.push(to);
			} else {
				deg[to]--;
				if (deg[to] == 0) {
					win[to] = 0;
					myq.push(to);
				}
			}
		}
	}
	
	for (string& s : v) {
		int sz = s.size();
		int converted = convert(s[sz-3], s[sz-2], s[sz-1]);
		if (win[converted] == 1)	cout << "Aoki" << endl;
		if (win[converted] == 0)	cout << "Takahashi" << endl;
		if (win[converted] == -1)	cout << "Draw" << endl;
	}
	
	return 0;
}
