#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 15000000
int m[N];
vector<int>S[6];
int id(int st,string s)
{
	for(int i=s.size();i<5;i++)
	{
		if(st>>i&1) return -1;
	}
	
	int res=0,b=1;
	for(int i=0;i<s.size();i++)
	{
		if(st>>i&1) res+=b*(s[i]-'a'+1);//1-26
		b*=27;
	}
	return res;
}
void solve()
{
	for(int i=0;i<(1<<5);i++) 
	{
		//i二进制1的个数 __builtin_popcount(i)
		S[__builtin_popcount(i)].push_back(i);
	}
	
	int q;
	cin>>q;
	while(q--)
	{
		int op;
		string s;
		cin>>op>>s;
		if(op==1)
		{
			int x;
			cin>>x;
			for(int l=0;l<=s.size();l++)
			{
				for(auto st:S[l])
				{
					int now=id(st,s);
					if(now==-1) continue;
					if(!m[now]||m[now]>x) m[now]=x;
				}
			}
		}
		else
		{
			for(int l=s.size();l>=0;l--)
			{
				int res=1e18;
				for(auto st:S[l])
				{
					int now=id(st,s);
					if(now==-1) continue;
					if(m[now]) res=min(res,m[now]); 
				}
				if(res<1e18) 
				{
					cout<<res<<"\n";
					break;
				}
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
