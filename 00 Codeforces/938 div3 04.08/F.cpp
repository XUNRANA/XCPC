#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int a,b,c,d,ans;
	cin>>a>>b>>c>>d;
	ans=d/2;
	if(a%2==1&&b%2==1&&c%2==1) ans+=1+a/2+b/2+c/2;
	else ans+=a/2+b/2+c/2; 
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
