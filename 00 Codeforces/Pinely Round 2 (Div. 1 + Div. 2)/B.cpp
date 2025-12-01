#include <bits/stdc++.h>
using namespace std;
int a[100010];
void solve()
{
	int n;
	cin>>n;
	int ans=0;
	int x;
	for(int i=1;i<=n;i++) cin>>x,a[x]=i;
	for(int i=1;i<n;i++) ans+=a[i]>a[i+1];
	cout<<ans<<"\n";
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}


