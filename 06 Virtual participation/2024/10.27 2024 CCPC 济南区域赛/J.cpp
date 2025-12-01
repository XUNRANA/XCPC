#include <bits/stdc++.h>
using namespace std;

int n;
int x[100010],y[100010],z[100010],ans[100010];
void solve()
{
	cin>>n;
	map<int,int>mpx,mpy,mpz;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i]>>z[i];
		mpx[x[i]]++;
		mpy[y[i]]++;
		mpz[z[i]]++;
	}
	for(int i=1;i<=n;i++) ans[i]=max({mpx[x[i]],mpy[y[i]],mpz[z[i]]})-1;
	sort(ans+1,ans+1+n);
	int j=1;
	for(int i=0;i<n;i++)
	{
		while(j<=n&&ans[j]<i) j++;
		cout<<j-1<<" ";
	}
	cout<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
