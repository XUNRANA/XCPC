#include <bits/stdc++.h>
using namespace std;
#define int long long
int p,a,b,q,c,d,m,t;
void solve()
{
	cin>>p>>a>>b;
	cin>>q>>c>>d;
	cin>>m>>t;
	while(t>b+d)
	{
		int x1=m/p;
		
		int x2=(t-b-d)/(a+c);
		
		if(!x1||!x2) break;
		
		int tm=min(x1,x2)*(q-p);//这一轮能获得的最大金币 
		
		if((m+tm)/p==m/p)//加上后还是能买这么多，考虑加速 
		{
			
			int tm1=(m/p+1)*p;
			
			int tt=tm1-m;
			
			int k1=(tt+tm-1)/tm;//至少这么多轮，之后多买一个 
			
			
			int k2=t/(min(x1,x2)*(a+c)+b+d);//考虑时间 
			
			int k=min(k1,k2);
			
			m+=k*tm;
			t-=k*(min(x1,x2)*(a+c)+b+d);
			
		}
		else 
		{
			m+=tm;
			t-=min(x1,x2)*(a+c)+b+d;
		}
	}
	cout<<m<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
