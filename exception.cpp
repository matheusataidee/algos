#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int division(int a, int b) {
	if (b == 0) {
		throw string("Division by zero.");
	}
	return a / b;
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	try {
		for (int i = 0; i < n; i++) {
			int numerator, denominator;
			cin >> numerator >> denominator;
			int result = division(numerator, denominator);
			cout << "Result = " << result << endl;
		}
	} catch (const string msg) {
		cerr << msg << endl;
	}
	return 0;
}
