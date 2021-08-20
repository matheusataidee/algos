/* Computes mobius function of every integer < X 
   while also computing every prime < X.			*/

const int X = 2.1e5;
 
bitset<X> is_prime;
vector<int> pr;
vector<int> mu(X, 0);
 
void init(){
	is_prime.flip();
	is_prime[0] = is_prime[1] = false;
	mu[1] = 1;
	for (int i = 2; i < X; i++){
		if (is_prime[i]) {
			pr.push_back(i);
			mu[i] = -1;
		}
		for (int p : pr){
			if (i * p >= X) break;
			is_prime[i * p] = false;
			if (i % p == 0){
				mu[i * p] = 0;
				break;
			} else {
				mu[i * p] = -mu[i];
			}
		}
	}
}
