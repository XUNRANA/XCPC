#include <bits/stdc++.h>
using namespace std;
int n,a[300010],b[300010];
void solve()
{	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1,j=1,k=n;i<=n;i++)
	{
		if(a[i]==b[j]) j++;
		else if(a[i]==b[k]) k--;
		else 
		{
			cout<<"Alice\n";
			return ;
		}
	}
	for(int i=n,j=1,k=n;i>=1;i--)
	{
		if(a[i]==b[j]) j++;
		else if(a[i]==b[k]) k--;
		else 
		{
			cout<<"Alice\n";
			return ;
		}
	}
	
	cout<<"Bob\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

