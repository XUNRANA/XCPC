#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef struct node
{
	string mail;
	int x;
}node;

bool cmp(node n1,node n2)
{
	if(n1.x==n2.x) return n1.mail<n2.mail;
	return n1.x>n2.x;
}

void solve()
{
	int n,g,k;
	cin>>n>>g>>k;
	vector<node>v;
	while(n--)
	{
		string s;
		int x;
		cin>>s>>x;
		v.push_back({s,x});
	}
	sort(v.begin(),v.end(),cmp);
	int ans=0;
	for(auto i:v)
	{
		if(i.x>=g) ans+=50;
		else if(i.x>=60) ans+=20;
	}
	cout<<ans<<"\n";
	int r=1;
	int p=101;
	for(int i=0;i<v.size();i++)
	{
		if(v[i].x!=p) r=i+1;
        if(r<=k) cout<<r<<" "<<v[i].mail<<" "<<v[i].x<<"\n";
		p=v[i].x;
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

