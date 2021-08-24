#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAXN 200200
#define MOD 1000000007

class Binomial {
private:
	vector<ll> fact;
	
	ll gcd(ll a, ll b, ll& x, ll& y) {
		if (!b) {
			x = 1;
			y = 0;
			return a;
		}
		ll x1, y1;
		ll d = gcd(b, a % b, x1, y1);
		x = y1;
		y = x1 - (a / b) * y1;
		return d;
	}
	
	ll inverse(ll val) {
		ll x, y;
		gcd(MOD, val, x, y);
		y = (y + MOD) % MOD;
		return y;
	}
	
public:
	Binomial() {
		fact = vector<ll>(MAXN);
		fact[0] = 1;
		for (int i = 1; i < MAXN; i++) {
			fact[i] = (fact[i-1] * i) % MOD;
		}
	}
	
	ll nChoosesQ(int n, int q) {
		return (fact[n] * inverse((fact[n-q] * fact[q]) % MOD)) % MOD;
	}
};

struct Point {
	ll y, x;
	bool operator<(Point& other) {
		return x + y < other.x + other.y;
	}
	Point(int y, int x) : y(y), x(x) { }
};

Binomial binomial;

ll f(ll a, ll b) {
	return binomial.nChoosesQ(a + b, b);
}

int main() {
	ios::sync_with_stdio(false);
	int h, w, n;
	cin >> h >> w >> n;
	
	vector<Point> v(n, Point(0, 0));
	for (Point& p : v) cin >> p.y >> p.x;
	sort(begin(v), end(v));
	v.push_back(Point(h, w));
	
	// dp[i] - number of paths from (1, 1) to v[i] without
	// 		   going through any forbidden vertex
	vector<ll> dp(n+1);
	for (int i = 0; i <= n; i++) {
		dp[i] = f(v[i].y-1, v[i].x - 1);
		for (int j = 0; j < i; j++) {
			if (v[j].y <= v[i].y && v[j].x <= v[i].x) {
				dp[i] -= dp[j] * f(v[i].y - v[j].y, v[i].x - v[j].x);
				dp[i] = ((dp[i] % MOD) + MOD) % MOD;
			}
		}
	}
	cout << dp[n] << endl;
	
	return 0;
}
