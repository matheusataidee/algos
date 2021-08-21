#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 4.1e7;

bitset<MAXN> is_prime;
vector<ll> primes;

void init(){
	is_prime.flip();
	for (int i = 2; i * i < MAXN; i++) {
		if (is_prime[i]) {
			int x = i * i;
			while (x < MAXN) {
				is_prime[x] = 0;
				x += i;
			}
		}
	}
	for (int i = 2; i < MAXN; i++) {
		if (is_prime[i]) primes.push_back(i);
	}
}

class SmoothDivisors {
	
public:
	int count(int A, int B) {
		init();
		int n = primes.size();
		ll a = A, b = B;
		ll ans = B - A + 1;
		for (int i = 0; i < n; i++) {
			ll p = primes[i];
			for (int j = i + 1; j < n; j++) {
				ll q = primes[j];
				if (p * q > b) break;
				if (p * q >= a) ans--;
				if (p * p * q <= b && p * p * q >= a) ans--;
				if (p * q * q <= b && p * q * q >= a) ans--;
			}
		}
		return ans;
	}
};

int main() {
	ios::sync_with_stdio(false);
	SmoothDivisors solver;
	cout << solver.count(1, 40000000) << endl;
	return 0;
}
