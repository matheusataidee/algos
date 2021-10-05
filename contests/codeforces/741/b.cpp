#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxx = 1e3 + 5;
bitset<maxx> is_prime;
vector<int> not_primes;

void init() {
	is_prime.flip();
	is_prime[1] = 0;
	for (int i = 2; i * i < maxx; i++) {
		if (is_prime[i]) {
			int x = i * i;
			while (x < maxx) {
				is_prime[x] = 0;
				x += i;
			}
		}
	}
	for (int i = 1; i < maxx; i++) {
		if (!is_prime[i]) {
			//cout << i << " ";
			not_primes.push_back(i);
		}
	}
	//cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	init();
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string num;
		cin >> num;
		for (int not_prime : not_primes) {
			string cand = to_string(not_prime);
			int j = 0;
			for (int i = 0; j < (int)cand.size() && i < (int)num.size(); i++) {
				if (cand[j] == num[i]) j++;
			}
			if (j == (int)cand.size()) {
				cout << cand.size() << endl;
				cout << cand << endl;
				break;
			}
		}
	}
	return 0;
}
