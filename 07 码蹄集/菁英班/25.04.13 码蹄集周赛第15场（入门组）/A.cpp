#include <bits/stdc++.h>
using namespace std;
#define int long long
int x[500];
int y[500];
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
	if(m==1) cout<<"-1\n";
	else 
	{
		set<pair<int,int>>st;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int cnt=2;
				int m1=i;
				int m2=j;
				for(int k=1;k<=n;k++)
				{
					if(k==i||k==j) continue;
					int x1=x[i];
					int x2=x[j];
					int x3=x[k];
					int y1=y[i];
					int y2=y[j];
					int y3=y[k];
					if((y2-y1)*(x3-x2)==(y3-y2)*(x2-x1)) 
					{
						cnt++;
						if(k<m1)
						{
							m2=m1;
							m1=k;
						}
						else if(k<m2) m2=k;
					}
				}
				if(cnt>=m) st.insert({m1,m2});
			}
		}
		cout<<st.size()<<"\n";
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
