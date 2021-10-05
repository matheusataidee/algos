#include <bits/stdc++.h>

using namespace std;

// === Debug macro starts here ===

int recur_depth = 0;
#ifdef DEBUG
#define dbg(x) {++recur_depth; auto x_=x; --recur_depth; cerr<<string(recur_depth, '\t')<<"\e[91m"<<__func__<<":"<<__LINE__<<"\t"<<#x<<" = "<<x_<<"\e[39m"<<endl;}
#else
#define dbg(x)
#endif
template<typename Ostream, typename Cont>
typename enable_if<is_same<Ostream,ostream>::value, Ostream&>::type operator<<(Ostream& os,  const Cont& v){
	os<<"[";
	for(auto& x:v){os<<x<<", ";}
	return os<<"]";
}

// === Debug macro ends here ===

typedef long long ll;

const int maxx = 15;

int main() {
	ios::sync_with_stdio(false);
	
	vector<int> acc(maxx, 0);
	for (int i = 1; i < maxx; i++) acc[i] = acc[i-1] ^ i;
	
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		if (acc[a-1] == b) {
			cout << a << endl;
		} else if ((acc[a-1] ^ b) == a) {
			cout << a + 2 << endl;
		} else {
			cout << a + 1 << endl;
		}
	}
	dbg(acc);
	return 0;
}
