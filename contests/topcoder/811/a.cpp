#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class ReconstructPermutation {
public:
	vector<int> reconstruct(int N, vector<int> partial) {		
		vector<int> ans;
		vector<int> used(N);
		priority_queue<int, vector<int>, greater<int> > heap;
		for (int& num : partial) used[num] = 1;
		for (int i = 0; i < N; i++) if(!used[i]) heap.push(i);
		for (int i = 0; i < (int)partial.size(); i++) {
			while (!heap.empty() && heap.top() < partial[i]) {
				ans.push_back(heap.top());
				heap.pop();
			}
			ans.push_back(partial[i]);
		}
		while (!heap.empty()) {
			ans.push_back(heap.top());
			heap.pop();
		}
		return ans;
	}
};

int main() {
	ios::sync_with_stdio(false);
	return 0;
}
