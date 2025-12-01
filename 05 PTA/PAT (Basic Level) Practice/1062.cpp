#include <bits/stdc++.h>
using namespace std;
#define int long long
int a,b,c,d,e;
bool ck(int a,int b,int c,int d)
{
	return a*d>b*c;
}
void solve()
{
	scanf("%lld/%lld",&a,&b);
	scanf("%lld/%lld",&c,&d);
	scanf("%lld",&e);
    if(ck(a,b,c,d))
    {
        swap(a,c);
        swap(b,d);
    }
	int f=0;
	for(int i=1;i<=e;i++)
	if(__gcd(i,e)==1)
	{
		if(ck(i,e,a,b)&&ck(c,d,i,e))
		{
			if(f) cout<<" ";
			cout<<i<<"/"<<e;
			f=1;
		}
	}
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
