#include <bits/stdc++.h>

using namespace std;

void perform_test() {
	int l, r, a;
	cin >> l >> r >> a;
	// initial value of x to take is r itself because it is the
	// largest value in the sequence (larger numerator -> larger quotient)
	int x = r % a;
	int ans = r / a + x;
	// the next value to check other than r, is r - (r mod a) + 1 because:
	// - it has the maximum possible remainder
	// - it has the maximum possible quotient among numbers < r - (r mod a) + 1, but
	// it is only applicable to compared iff it's within the range of [l, r] inclusive
	r -= (x + 1); // this is where the next cycle begins
	if(r >= l) {
		ans = max(ans, r / a + r % a);
	}
	//sample testcase:
	//let l = 3, r = 8m a = 5
	//3 4 5 6 7 8
	//8 % 5 = 3
	//7 % 5 = 2
	//6 % 5 = 1
	//5 % 5 = 0
	//4 % 5 = 4 <- maximal
	//3 % 5 = 3
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc = 1;
	cin >> tc;
	for(int t = 0; t < tc; t++) {
		perform_test();
	}
	return 0;
}
