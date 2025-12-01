#include <bits/stdc++.h>
using namespace std;
long long n,ans,sum,a[1000010];
void solve() 
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	map<int,int>f,e,c;
	for(int i=1;i<=n;i++)
	{
		if(c[a[i]]==0)
		{
			c[a[i]]++;
			f[a[i]]=i;
			e[a[i]]=i;
		}
		else e[a[i]]=i;
	}
	ans=sum=0;
	for(int i=1;i<=n;i++)
	{
		if(f[a[i]]==i) sum++;
		if(e[a[i]]==i) ans+=sum;
	}
	cout<<ans<<"\n";
}
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
	cin>>t;
    while(t--) solve();
}
