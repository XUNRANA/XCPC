#include <bits/stdc++.h>
using namespace std;
vector<int>p;
int f[50010];
void init()
{
	for(int i=2;i<=5e4;i++)
	{
		if(!f[i])
		{
			p.push_back(i);
			for(int j=i+i;j<=5e4;j+=i) f[j]=1;
		}
	}
}
void solve()
{
	int n;
	cin>>n;
    if(n<=9)
    {
        cout<<"-1\n";
        return ;
    }
	for(int i=0;i<p.size();i++)
	{
		for(int j=i;j<p.size();j++)
		{
			for(int k=j;k<p.size();k++)
			{
				if(p[i]+p[j]+p[k]>n) break;
				else if(p[i]+p[j]+p[k]==n)
				{
					cout<<p[i]<<" "<<p[j]<<" "<<p[k]<<"\n";
					return ;
				}
			}
		}
	}
} 
int main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
