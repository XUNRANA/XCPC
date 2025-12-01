#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 2010
int n;
int x1[N],y1[N],x2[N],y2[N],x[N],y[N],r[N];
char ch[N];
int op[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		if(s=="Circle") op[i]=1;
		else if(s=="Rectangle") op[i]=2;
		else op[i]=3;
		if(op[i]==1) cin>>x[i]>>y[i]>>r[i]>>ch[i];		
		else if(op[i]==2) cin>>x1[i]>>y1[i]>>x2[i]>>y2[i]>>ch[i];
		else cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		if(op[i]==3)
		{			
			for(int j1=y2[i];j1>=y1[i];j1--)
			{
				for(int i1=x1[i];i1<=x2[i];i1++)
				{
					int f=0;
					for(int j=i-1;j>=1;j--)
					{
						if(op[j]==3) continue;
						if(op[j]==1)
						{
							if((i1-x[j])*(i1-x[j])+(j1-y[j])*(j1-y[j])<=r[j]*r[j])
							{
								cout<<ch[j];
								f=1;
								break;
							}
						}
						else
						{
							if(i1>=x1[j]&&i1<=x2[j]&&j1>=y1[j]&&j1<=y2[j])
							{
								cout<<ch[j];
								f=1;
								break;
							}
						}
					}
					if(!f) cout<<"."; 
				}
				cout<<"\n";
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
