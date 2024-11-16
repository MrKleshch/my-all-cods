#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n, x, y; cin >> n >> x >> y;
	long long time = min(x, y); n--;
	if (n < 1) {
		cout << time;
		return 0;
	}

	long long l = min(x, y), r = max(x, y) * n;

	while (l + 1 < r) {
		long long mid = (l + r) / 2;
		if (mid/x + mid/y < n) l = mid;
		r = mid;
	}
	cout << r + time;

	return 0;
}