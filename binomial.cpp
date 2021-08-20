// Application of modular inverse
// Calculates any n chooses q in O(logN) given a O(N) preprocessing

#define MAXN 200200
#define MOD 1000000007
 
typedef long long ll;
 
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
