#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define len(x) (int)x.size()

typedef long long ll;

int mergeSort(int l, int r, vector<int>& v, vector<int>& buffer) {
	if (l == r) return 0;
	int mid = (l + r) / 2;
	int ret = mergeSort(l, mid, v, buffer) + mergeSort(mid+1, r, v, buffer);
	for (int i = l, pl = l, pr = mid+1; i <= r; i++) {
		if (pl == mid + 1) {
			buffer[i] = v[pr++];
		} else if (pr == r + 1) {
			buffer[i] = v[pl++];
		} else if (v[pl] < v[pr]) {
			buffer[i] = v[pl++];
		} else {
			buffer[i] = v[pr++];
			ret += mid + 1 - pl;
		}
	}
	for (int i = l; i <= r; i++) {
		v[i] = buffer[i];
	}
	return ret;
}

int getInversionNumber(vector<int> v) {
	int n = len(v);
	vector<int> buffer(n);
	return mergeSort(0, n - 1, v, buffer);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	map<int, int> freq;
	bool has_multiple = false;
	for (int& val : a) {
		cin >> val;
		freq[val]++;
		if (freq[val] > 1) has_multiple = true;
	}
	bool ok = true;
	for (int& val : b) {
		cin >> val;
		if (!freq.count(val) || freq[val] == 0) {
			ok = false;
		} else {
			freq[val]--;
		}
	}
	if (ok && (has_multiple || getInversionNumber(a) % 2 == getInversionNumber(b) % 2)) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}
