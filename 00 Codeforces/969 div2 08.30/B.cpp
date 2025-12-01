#include <bits/stdc++.h>
using namespace std;
int n,m,a[100010],l,r;
char op;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int mx=a[n];
	while(m--)
	{
		cin>>op>>l>>r;
		if(op=='+')
		{
			if(mx>=l&&mx<=r) mx++;
		}
		else if(mx>=l&&mx<=r) mx--;
		cout<<mx<<" ";
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
