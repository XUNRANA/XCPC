#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	string s;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		int ans=0;
		int cnt=m;
		int c1=0;//工厂数量 
		if(s[i]=='0') 
		{
			if(cnt)
			{
				cnt--;
				c1++;
			}
		}
		else c1++;
		
		for(int j=1;j&&c1<k;j++)
		{
			int l=i-j;
			int r=i+j;
			if(l>=1)
			{
				if(c1<k) 
				{
					if(s[l]=='1')
					{
						c1++;
						ans+=j;
					}
					else
					{
						if(cnt)
						{
							cnt--;
							c1++;
							ans+=j;
						}
					}
				}
			}
			if(r<=n)
			{
				if(c1<k) 
				{
					if(s[r]=='1')
					{
						c1++;
						ans+=j;
					}
					else
					{
						if(cnt)
						{
							cnt--;
							c1++;
							ans+=j;
						}
					}
				}
			}
		}
		cout<<ans<<" ";
	}
	cout<<"\n";
	
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

