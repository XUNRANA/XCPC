#include <bits/stdc++.h>
using namespace std;
long long n,m,k,s1,a[100],b[100];
void solve()
{
	cin>>n>>m>>k;
	s1=0;
	for(int i=1;i<=n;i++) cin>>a[i],s1+=a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	if(a[n]<=b[1])
	{
		if(k&1) cout<<s1-a[1]+b[m]<<"\n";
		else cout<<s1<<"\n";
		return ;
	}
	if(b[m]<=a[1])
	{
		if(k&1) cout<<s1<<"\n";
		else cout<<s1-a[n]+b[1]<<"\n";
		return ;
	}
	
	if(k&1) cout<<s1-a[1]+b[m]<<"\n";
	else cout<<s1-a[1]-a[n]+min(a[1],b[1])+min(a[n],b[m])<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
