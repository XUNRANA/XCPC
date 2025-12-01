#include <bits/stdc++.h>
using namespace std;
bool cmp(int a1,int a2)
{
	return a1>a2;
}
int n,f,k,a[110];
void solve()
{
	cin>>n>>f>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==n)
	{
		cout<<"YES\n";
		return ;
	}
	int b=a[f];
	sort(a+1,a+1+n,cmp);
	if(a[k]<=b)
	{
		if(a[k+1]==b) cout<<"MAYBE\n";
		else cout<<"YES\n";
	}
	else cout<<"NO\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
