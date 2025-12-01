#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define P 998244353
int ksm(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%P;
		a=a*a%P;
		b>>=1;
	}
	return res;
}
int inv(int x)
{
	return ksm(x,P-2)%P;
}
int x1,y1,x2,y2;
void solve()
{
	int x,y;
	cin>>x>>y;
	if(x==y) cout<<inv(2)<<" "<<inv(2)<<"\n";
	else 
	{
		if(x<y)
		{
			int cnt=0;
			while(x<y)
			{
				cnt++;
				y-=x;
				x+=x;
			}
			x1=1,y1=(1<<(cnt+1));
			x2=y1-x1,y2=y1;
			cout<<x1*inv(y1)%P<<" "<<x2*inv(y2)%P;
		}
		else
		{
			int cnt=0;
			while(x>y)
			{
				cnt++;
				x-=y;
				y+=y;
			}
			x2=1,y2=(1<<(cnt+1));
			x1=y2-x2,y1=y2;
			cout<<x1*inv(y1)%P<<" "<<x2*inv(y2)%P;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
