#include <bits/stdc++.h>
using namespace std;
int n,a[200010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int j=2;
	for(int i=2;i<=n;i++) if(a[i]!=a[i-1]) a[j++]=a[i];
	
	for(int i=1;i<j;i++) 
	{
		if(a[i]!=i)
		{
			if(i&1) cout<<"Alice\n";
			else cout<<"Bob\n";
			return ;
		}
	}
	if(j&1) cout<<"Bob\n";
	else cout<<"Alice\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
