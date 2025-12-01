#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[50010];
int cnt;
//2 8 24 6

void solve()
{
	cin>>n>>k;
	int mi=1e9;
	for(int i=1;i<=n;i++) cin>>a[i],mi=min(mi,a[i]);
//	cnt++;
//	if(cnt==2&&n!=2)
//	{
//		cout<<n<<" "<<k<<"\n";
//		for(int i=1;i<=n;i++) cout<<a[i]<<" ";
//		cout<<"\n";
//		return ;
//	}
	int g=0;
	for(int i=2;i<=n;i++) g=__gcd(g,abs(a[i]-a[i-1]));
	
	if(g==0) cout<<k<<" "<<k*(k+1)/2<<"\n";
	else if(g==1) cout<<"0 0\n";
	else
	{
		vector<int>res;
		for(int i=1;i*i<=g;i++)
		if(g%i==0)
		{
			if(i>mi&&i<=mi+k) res.push_back(i);
			if(g/i!=i) 
			{
				if(g/i>mi&&g/i<=mi+k)
				res.push_back(g/i);
			}
		}
		
		int ans=0,cnt=0;
		for(auto i:res)
		{
			int k1=i-mi;
			int f=0;
			for(int j=2;j<=n;j++)
			{
				int pre=a[j-1]+k1;
				int now=a[j]+k1;
				if(pre%now!=0&&now%pre!=0)
				{
					f=1;
					break;
				}
			}
			if(!f) ans+=k1,cnt++; 
		}
		
		cout<<cnt<<" "<<ans<<"\n";
	}
	
	
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
