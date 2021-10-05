#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define color first
#define hp second

struct Model {
	int color;
	int hp;
	
	Model(int color_, int hp_) : color(color_), hp(hp_) { }
	
	bool operator<(const Model& other) {
		if (color == other.color) {
			return !hp;
		}
		return color < other.color;
	}
};

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>> v(m);
		
		for (pair<int, int>& model : v) {
			cin >> model.color;
			model.hp = 1;
		}
		sort(begin(v), end(v));
		
		int ans = 0;
		for (int i = 0; i < n; i++) {
			vector<pair<int, int>> new_v, has_to_change;
			vector<int> round(m), ids;
			for (int& color : round) cin >> color;
			sort(begin(round), end(round));
			
			int p = 0, q = 0;
			while (q < m && p < m) {
				if (round[q] == v[p].color) {
					new_v.push_back(v[p]);
					q++; p++; 
				} else if (round[q] > v[p].color) {
					has_to_change.push_back(v[p++]);
				} else {
					ids.push_back(q++);
				}
			}
			while (p < m) {
				has_to_change.push_back(v[p++]);
			}
			while (q < m) {
				ids.push_back(q++);
			}
				
			
			for (pair<int, int>& model : has_to_change) {
				if (!model.hp) ans++;
			}
			
			for (int id : ids) {
				new_v.push_back({round[id], 0});
			}
			sort(begin(new_v), end(new_v));
			v = new_v;
		}
		
		
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
