#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q,p[200010];
int g[200010];     
int f[200010];
string s;               
bool ck(int i)
{
	return s[i]=='R'||s[i+1]=='L';
}
bool ck2(int i)//坏点 
{
	return g[i]&&(!f[i]);
} 
void solve()
{
	cin>>n>>q;
	int mx=0,ans=0;
	//g[1]==1表示，可以交换p[1],p[2] 
	for(int i=1;i<=n;i++) 
	{
		cin>>p[i];
		mx=max(mx,p[i]);
		if(mx>i) g[i]=1;//表示需要开放这个通道 
		else g[i]=0;
	}
	cin>>s;
	s="&"+s;
	//f[1]=1，代表可以从1到2 
	for(int i=1;i<n;i++) f[i]=ck(i);
	for(int i=1;i<n;i++) if(ck2(i)) ans++;
	while(q--)
	{
		int x;
		cin>>x;
		if(s[x]=='L') s[x]='R';
		else s[x]='L'; 
		ans-=ck2(x-1);
		ans-=ck2(x);
		
		f[x-1]=ck(x-1);
		f[x]=ck(x);
		
		ans+=ck2(x-1);
		ans+=ck2(x);
		
		if(!ans) cout<<"YES\n";//坏点为0 
		else cout<<"NO\n";
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
