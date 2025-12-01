#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int a1,a2,b1,b2,ans=0;
	cin>>a1>>a2>>b1>>b2;
	if(a1>b1&&a2>=b2||a1>=b1&&a2>b2) ans+=2;
	if(a1>b2&&a2>=b1||a1>=b2&&a2>b1) ans+=2;
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

