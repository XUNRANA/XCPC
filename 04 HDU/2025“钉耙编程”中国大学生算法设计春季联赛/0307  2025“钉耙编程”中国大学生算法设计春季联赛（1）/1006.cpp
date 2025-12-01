#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n;
	cin>>n;
	map<int,int>mp;
	for(int i=1;i<=n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a>b) swap(a,b);
		if(b>c) swap(b,c);
		if(a>b) swap(a,b);
		
		if(a>0&&(c-b)%a==0) mp[(c-b)/a]+=i;
		if(a<0&&(b-c)%a==0) mp[(b-c)/a]+=i;
		
		if(b>0&&(c-a)%b==0) mp[(c-a)/b]+=i;
		if(b<0&&(a-c)%b==0) mp[(a-c)/b]+=i;
		
		if(c>0&&(b-a)%c==0) mp[(b-a)/c]+=i;
		if(c<0&&(a-b)%c==0) mp[(a-b)/c]+=i;
	} 
	int ans=0;
	for(auto i:mp) if(i.second==(1+n)*n/2) ans=i.first;
	cout<<ans<<"\n";
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

