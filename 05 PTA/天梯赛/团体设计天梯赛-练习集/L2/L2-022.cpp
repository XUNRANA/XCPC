#include <bits/stdc++.h>
using namespace std;
#define int long long
int nxt[100000];
int val[100000];
void solve()
{
	int head,n;
	cin>>head>>n;
	while(n--)
	{
		int addr,data,next;
		cin>>addr>>data>>next;
		nxt[addr]=next;
		val[addr]=data;
	}


	vector<pair<int,int>>v,u;
	while(nxt[head]!=-1) 
	{
		v.push_back({val[head],head});
		head=nxt[head];
	}
	v.push_back({val[head],head});
	for(int i=v.size()-1,j=0;i>=j;i--,j++)
	{
		u.push_back(v[i]);
		if(j!=i) u.push_back(v[j]);
	}
	for(int i=0;i<u.size();i++) 
	{
		int addr=u[i].second;
		int data=u[i].first;
		int nx;
		if(i+1<u.size()) nx=u[i+1].second;
		else nx=-1;
		
		if(i+1<u.size()) printf("%05d %d %05d\n",addr,data,nx);
		else printf("%05d %d %d\n",addr,data,nx);
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

