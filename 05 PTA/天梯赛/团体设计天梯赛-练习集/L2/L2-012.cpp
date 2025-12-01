#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,x,idx;
int t[1010];
map<int,int>p;
void create(int x)
{
	t[++idx]=x;
	int i=idx;
	while(i>1&&t[i/2]>t[i])
	{
		swap(t[i/2],t[i]);
		i/=2;
	}
	t[i]=x;
}

void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>x;
		create(x);
	}
	for(int i=1;i<=n;i++) p[t[i]]=i;
	while(m--)
	{
		int x,y;
		string s;
		cin>>x>>s;
		if(s[0]=='a')
		{
			cin>>y>>s>>s;
			if(p[x]/2==p[y]/2) cout<<"T\n";
			else cout<<"F\n";
		}
		else
		{
			cin>>s>>s;
			if(s[0]=='c')
			{
				cin>>s>>y;
				if(p[x]/2==p[y]) cout<<"T\n";
				else cout<<"F\n";
			}
			else if(s[0]=='r') 
			{
				if(p[x]==1) cout<<"T\n";
				else cout<<"F\n";
			}
			else if(s[0]=='p')
			{
				cin>>s>>y;
				if(p[x]==p[y]/2) cout<<"T\n";
				else cout<<"F\n";
			}
		}
	}
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

