#include <bits/stdc++.h>
using namespace std;
#define int long long
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
void f()
{
	int c=rng()%100;
	cout<<c<<" "<<100<<"\n";
}
int baoli(int c,int m)
{
	int p=(c+1)%m;
	int cnt=1;
	int sum=p;
	while(p!=1)
	{
		p=(p+c)%m;
		cnt++;
		sum+=p;
	}
	return sum/cnt;
}
void solve()
{
	int c,m;
	cin>>c>>m;
    c%=m;
//	int ans1=baoli(c,m);
	int ans2;
	if(c==0) ans2=1;
	else 
	{
		int k=__gcd(c,m);
		if(k==1) ans2=(m-1)/2;
		else ans2=(1+m+1-k)/2;
	}
	cout<<ans2<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
