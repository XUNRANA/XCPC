#include <bits/stdc++.h>
using namespace std;
#define N 100010

int n,q,tr[N][6];

string s;

int lowbit(int x)
{
	return x&-x;
}

void update(int i,int j,int x)
{
	while(i<=n)
	{
		tr[i][j]+=x;
		i+=lowbit(i);
	}
}

int sum(int i,int j)
{
	int res=0;
	while(i)
	{
		res+=tr[i][j];
		i-=lowbit(i);
	}
	return res;
}


void solve()
{
	cin>>n>>q;
	cin>>s;
	s=" "+s;
    vector<vector<int>>res;
	res.push_back({1,2,3});
	res.push_back({1,3,2});
	res.push_back({2,1,3});
	res.push_back({2,3,1});
	res.push_back({3,1,2});
	res.push_back({3,2,1});
	//d e r 1 2 3
	//d r e
	//e d r
	//e r d
	//r d e
	//r e d
	for(int i=1;i<=n;i++)
	{
		int t;
		if(s[i]=='d') t=1;
		else if(s[i]=='e') t=2;
		else if(s[i]=='r') t=3;
		for(int j=0;j<6;j++)
		{
			if(t!=res[j][(i-1)%3]) update(i,j,1);
		}
	}
    
	while(q--)
	{
		int op,x,y;
		char ch;
		cin>>op;
		if(op==1)
		{
			cin>>x>>ch;
			int t;
			if(s[x]=='d') t=1;
			else if(s[x]=='e') t=2;
			else if(s[x]=='r') t=3;
			for(int j=0;j<6;j++)
			{
				if(t!=res[j][(x-1)%3]) update(x,j,-1);
			}
			
			if(ch=='d') t=1;
			else if(ch=='e') t=2;
			else if(ch=='r') t=3;
			for(int j=0;j<6;j++)
			{
				if(t!=res[j][(x-1)%3]) update(x,j,1);
			}
			s[x]=ch;
		}
		else
		{
			int ans=1e9;
			cin>>x>>y;
			for(int j=0;j<6;j++) ans=min(ans,sum(y,j)-sum(x-1,j));
			cout<<ans<<"\n";
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}


