#include <bits/stdc++.h>
using namespace std;
#define int long long
int l[100010],r[100010];
void solve()
{
	int n,f=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
	
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum++;
		l[i]-=sum;
		r[i]-=sum;
		if(l[i]<=0&&r[i]>=0) continue;
		else if(r[i]<0) 
		{
			cout<<"-1\n";
			return ;
		}
		else if(l[i]>=0) sum+=l[i];
	}
	cout<<sum+1<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
