#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		string s;
		int sum;
		cin >> s >> sum;
		
		vector<int> num;
		int acc = 0, n = s.size();
		for (int i = 0; i < n; i++) {
			num.push_back(s[i] - '0');
			acc += num[i];
		}
		while (acc < sum) {
			for (int i = n - 2; i >= 0; i--) {
				if (num[i]) {
					num[i]--;
					num[i+1] += 10;
					acc += 9;
					break;
				}
			}
		}
		priority_queue<int, vector<int>, greater<int>> heap;
		int pot = 1;
		for (int i = n - 1; i >= 0; i--, pot *= 10) {
			while (num[i]--) {
				heap.push(pot);
			}
		}
		while ((int)heap.size() > sum) {
			int a = heap.top();	heap.pop();
			int b = heap.top(); heap.pop();
			
			heap.push(a+b);
		}
		while (!heap.empty()) {
			cout << heap.top() << " ";
			heap.pop();
		}
		cout << endl;
	}
	return 0;
}
