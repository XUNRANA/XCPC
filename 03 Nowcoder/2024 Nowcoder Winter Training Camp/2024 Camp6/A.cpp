#include <bits/stdc++.h>
using namespace std;
int l,r,ans,a[101];
void init()
{
	a[30]=a[42]=a[66]=a[70]=a[78]=1;
}
void solve()
{
	init();
	cin>>l>>r;
	for(int i=l;i<=r;i++) 
    if(a[i]) 
	{
		cout<<i<<"\n";
		return ;
	}
	cout<<-1<<"\n";
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
