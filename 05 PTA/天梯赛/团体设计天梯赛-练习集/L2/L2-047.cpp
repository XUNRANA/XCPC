#include <bits/stdc++.h>
using namespace std;


int lose[20][1<<20];
int win[20][1<<20]; 
int ans[1<<20];

void solve()
{
	int k;
	cin>>k;
	int mx=0;
	for(int i=0;i<k;i++)
	{
		int n=(1<<k-i-1);
		for(int j=0;j<n;j++)
		{
			cin>>lose[i][j];
			if(!i)
			{
				ans[j<<1]=lose[i][j];
				win[i][j]=j<<1|1;//´æÏÂ±ê 
			}
			else 
			{
				if(lose[i][j]<min(lose[i-1][j<<1],lose[i-1][j<<1|1]))
				{
					cout<<"No Solution\n";
					return ;
				}
				else if(lose[i][j]>=lose[i-1][j<<1])
				{
					ans[win[i-1][j<<1]]=lose[i][j];
					win[i][j]=win[i-1][j<<1|1];
				}
				else
				{
					ans[win[i-1][j<<1|1]]=lose[i][j];
					win[i][j]=win[i-1][j<<1];
				}
			}
			lose[i][j]=max({lose[i][j],lose[i-1][j<<1],lose[i-1][j<<1|1]}); 
		}
	}
	int w;
	cin>>w;
	if(lose[k-1][0]>w) cout<<"No Solution\n";
	else 
	{
		ans[win[k-1][0]]=w;
		for(int i=0;i<(1<<k);i++) cout<<ans[i]<<" \n"[i==(1<<k)-1];
	}
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

