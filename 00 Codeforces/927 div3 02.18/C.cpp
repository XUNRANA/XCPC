#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[200010],b[200010];
ll sum,l,r,j;
string s;
void solve()
{
	j=l=1;
	sum=1;
	cin>>n>>m;
	r=n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) 
	if(s[i]=='L') b[j++]=a[l++];
	else b[j++]=a[r--];
	for(int i=n;i>=1;i--)
	{
		sum=sum*b[i]%m;
		a[i]=sum;
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<"\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
