#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int l[100010];
int get(int k)
{
	if(k==1) return 1;
	int a1=1,a2=1,a3;
	int i=3;
	while(1)
	{
		a3=(a1+a2)%k;
		if(a3==0) return i;
		i++;
		a1=a2;
		a2=a3;
	}
}
void solve()
{
	int n,k;
	cin>>n>>k;
	cout<<n%P*get(k)%P<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
