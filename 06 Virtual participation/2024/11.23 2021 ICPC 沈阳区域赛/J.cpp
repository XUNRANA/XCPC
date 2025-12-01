#include <bits/stdc++.h>
using namespace std;
#define int long long

map<string,int>mp;
void init()
{
	queue<string>q;
	q.push("0000");
	mp["0000"]=0;
	while(!q.empty())
	{
		string s=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			string t1,t2;
			t1=t2=s;
			for(int j=i;j<4;j++)
			{
				for(int k=i;k<=j;k++)
				{
					t1[k]=(s[k]-'0'+1)%10+'0';
					t2[k]=(s[k]-'0'+9)%10+'0';
					if(mp.find(t1)==mp.end()) q.push(t1),mp[t1]=mp[s]+1;
					if(mp.find(t2)==mp.end()) q.push(t2),mp[t2]=mp[s]+1;
				}
			}
		}
	}
}
void solve()
{
	string a,b;
	cin>>a>>b;
	for(int i=0;i<4;i++) a[i]=(b[i]-a[i]+10)%10+'0';
//	cout<<a<<"\n";
	cout<<mp[a]<<"\n";
}
signed main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
