#include <bits/stdc++.h>
using namespace std;

constexpr double pi = 3.1415926;
constexpr double pi2 = pi / 2;

void solve()
{
	map<double, int> dela;
	dela[0] += 1;
	dela[pi2] -= 1;
	int n; cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		double x, y, r; cin >> x >> y >> r;
		double s = sqrt(x * x + y * y);
		double mid = atan(y / x);
		double o = asin(r / s);
		dela[mid - o] -= 1;
		dela[mid + o] += 1;
	}
	int cur = 0;
	double res = 0;
	auto start = dela.lower_bound(0), end = (dela.upper_bound(pi2));
	for (auto it = start; it != end; it++) 
	{
		cur += it -> second;
		auto l = it -> first;
		auto nxt = next(it);
		if (nxt == end) continue;
		auto r = nxt -> first;
		if (cur > 0) res += r - l;
	}
	printf("%.3f\n",res/pi2);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
