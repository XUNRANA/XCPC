#include <bits/stdc++.h>
using namespace std;
long long a,b,c,ans;
int lowbit(int x)
{
	return x&-x;
}
void solve()
{
	cin>>a>>b;
	if(a%b==0)
	{
		cout<<"0\n";
		return ;
	}
	a%=b;
	c=__gcd(a,b);
	if(lowbit(b/c)==b/c)
	{
		ans=0;
		while(a)
		{
			ans+=a;
			a*=2;
			a%=b;
		}
		cout<<ans<<"\n";
	} 
	else cout<<"-1\n";
}
int main()
{
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
