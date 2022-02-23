#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

typedef long long ll;

struct Spice {
	ll hotness;
	ll cost;
	
	bool operator<(Spice& other) {
		return cost < other.cost;
	}
};

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<Spice> spices((1 << n) - 1);
	int cur_hotness = 1;
	for (Spice& spice : spices) {
		spice.hotness = cur_hotness++;
		cin >> spice.cost;
	}
	sort(all(spices));
	ll ans = 0;
	set<ll> ok;
	ok.insert(0);
	for (int i = 0; i < (1 << n) - 1; i++) {
		if (!ok.count(spices[i].hotness)) {
			ans += spices[i].cost;
			
			vector<ll> hotness_to_add;
			for (auto it : ok) {
				hotness_to_add.push_back(it ^ spices[i].hotness);
			}
			for (ll& hotness : hotness_to_add) {
				ok.insert(hotness);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
