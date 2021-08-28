#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, q;
vector<int> v;
vector<int> frq;

struct Query {
	int l, r, id;
	
	bool operator<(Query& other) {
		int sq = sqrt(n);
		return make_pair(l / sq, r) < make_pair(other.l / sq, other.r);
	}
};

int findBestSplit(int k, int total) {
	int b = total - k;
	return max(0, total - (2 * b + 1)) + 1;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios::sync_with_stdio(false);
	cin >> n >> q;
	v = vector<int>(n);
	frq = vector<int>(n+1);
	for (int& val : v) cin >> val;
	
	vector<int> ans(q);
	vector<Query> queries(q);
	for (int i = 0; i < q; i++) {
		cin >> queries[i].l >> queries[i].r;
		queries[i].l--;
		queries[i].r--;
		queries[i].id = i;
	}
	sort(begin(queries), end(queries));
	
	int l = 0, r = -1;
	for (Query& query : queries) {
		while (r < query.r) {
			frq[v[++r]]++;
		}
		while (l > query.l) {
			frq[v[--l]]++;
		}
		while (r > query.r) {
			frq[v[r]]--;
			r--;
		}
		while (l < query.l) {
			frq[v[l]]--;
			l++;
		}
		int maxi = 0;
		for (int i = 0; i < 40; i++) {
			int cand = l + (rng() % (r - l + 1));
			maxi = max(maxi, frq[v[cand]]);
		}
		
		ans[query.id] = findBestSplit(maxi, query.r - query.l + 1);
	}
	for (int i = 0; i < q; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}
