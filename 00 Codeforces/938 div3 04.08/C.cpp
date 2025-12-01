#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[200010],b[200010],c[200010],l,f,fi,li,ans;
void solve()
{
	ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	c[n+1]=0;
	for(int i=n;i>=1;i--) c[i]=c[i+1]+a[i];
	/*
	for(int i=1;i<=n;i++) cout<<c[i]<<" ";
	cout<<"\n";
	*/
	for(int i=1;i<=n/2;i++) swap(c[i],c[n-i+1]);
	/*
	for(int i=1;i<=n;i++) cout<<c[i]<<" ";
	cout<<"\n";
	*/
	if(b[n]<=k)
	{
		cout<<n<<"\n";
		return ;
	}
	f=(k+1)/2;
	l=k-f;
	fi=lower_bound(b+1,b+1+n,f)-b;
	if(b[fi]==f) ans=fi;
	else ans=fi-1;
	li=lower_bound(c+1,c+1+n,l)-c;
//	cout<<f<<" "<<l<<" "<<li<<" "<<c[li]<<" "<<"\n";
	if(c[li]==l) ans+=li;
	else ans+=li-1;
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
