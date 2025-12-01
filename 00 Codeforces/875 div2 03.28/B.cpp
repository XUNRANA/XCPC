#include <bits/stdc++.h>
using namespace std;
int n,a[200010],b[200010],ans,c;
void solve()
{
	cin>>n;
	map<int,int>la,lb;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	
	c=1;
	for(int i=2;i<=n;i++) 
	if(a[i]==a[i-1]) c++;
	else 
	{
        la[a[i-1]]=max(la[a[i-1]],c);
		c=1;
	}
    la[a[n]]=max(la[a[n]],c);
	
	c=1;
	for(int i=2;i<=n;i++) 
	if(b[i]==b[i-1]) c++;
	else 
	{
        lb[b[i-1]]=max(lb[b[i-1]],c);
		c=1;
	}
    lb[b[n]]=max(lb[b[n]],c);
	
	ans=1;
	for(auto i:la) ans=max(i.second+lb[i.first],ans);
    for(auto i:lb) ans=max(i.second+la[i.first],ans);
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
