#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const ll mod = 998244353;
 
vector<int> stringToVec(const string& s) {
	vector<int> ret;
	for (char c : s) {
		ret.push_back(c - '0');
	}
	return ret;
}
 
string vecToString(const vector<int>& v) {
	string ret = "";
	for (int num : v) {
		ret += '0' + num;
	}
	return ret;
}
 
int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	
	map<string, ll> state;
	state[""] = 1;
	for (int i = 0; i < n; i++) {
		map<string, ll> nxt;
		
		for (auto it : state) {
			
			//cout << it.first << " " << it.second << endl;
			
			for (int num = 1; num <= m; num++) {
				vector<int> lis = stringToVec(it.first);
				ll qnt = it.second;
				
				int l = 0, r = lis.size();
				while (l < r) {
					int mid = (l + r) / 2;
					if (lis[mid] >= num) {
						r = mid;
					} else {
						l = mid + 1;
					}
				}
				if (l == (int)lis.size()) {
					lis.push_back(num);
				} else {
					lis[l] = num;
				}
				if (lis.size() < 4) {
					nxt[vecToString(lis)] += qnt;
					nxt[vecToString(lis)] %= mod;
				}
			}
		}
		state = nxt;
		//cout << endl;
	}
	
	ll ans = 0;
	for (auto it : state) {
		if (it.first.size() == 3) {
			ans += it.second;
			ans %= mod;
		}
	}
	cout << ans << endl;
	return 0;
}
