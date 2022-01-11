#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template <typename T>
T sumArray(const vector<T>& arr, T sum) {
	for (T element : arr) {
		sum += element;
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	vector<int> v_int{1, 2, -1, 7, 4};
	vector<double> v_double{1.2, 5.4, 3.5, 9.9, 4.4};
	cout << sumArray(v_int, 0) << endl;
	cout << sumArray(v_double, 0.0) << endl;
	return 0;
}
