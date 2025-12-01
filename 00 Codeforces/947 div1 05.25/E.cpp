#include <bits/stdc++.h>
using namespace std;
int n,a[110];
bool ck(int i)
{
	//i i+n-1
	for(int j=i+1;j<=i+n-1;j++)
	{
		if(a[j+1]<a[j]) return 0;
	}
	return 1;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],a[i+n]=a[i];
	for(int i=1;i<=n;i++) 
	if(ck(i))
	{
		cout<<"Yes\n";
		return ;
	}
	cout<<"No\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
