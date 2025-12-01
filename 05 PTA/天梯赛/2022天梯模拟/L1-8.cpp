#include<bits/stdc++.h>
using namespace std;

int f[1000010];
vector<int>p;
void init()
{
	for(int i=2;i<=1000000;i++)
	if(!f[i])
	{
		if(i<=1000) p.push_back(i);
		for(int j=i+i;j<=1000000;j+=i) f[j]=1;
	}
}
int is(int x)
{
	return f[x]^1;
}
void solve()
{
	init();
	int m,n;
	cin>>m>>n;
	int cnt=0;
	for(int i=0;i<p.size();i++)
	{
		for(int j=i+1;j<p.size();j++)
		{
			for(int k=j+1;k<p.size();k++)
			{
				if(p[i]>=m&&p[k]<=n)
				{
					if(is(p[i]*p[j]+p[k])&&is(p[i]*p[k]+p[j])&&is(p[j]*p[k]+p[i])) cnt++;
				}
			}
		}
	}
	cout<<cnt<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
//    cin>>T;
    while(T--) solve();
}


