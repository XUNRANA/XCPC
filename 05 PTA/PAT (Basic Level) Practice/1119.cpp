#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[10010];
int l[10010];
int r[10010];

void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==1) 
    {
        cout<<"200\n";
        return ;
    }
    for(int i=2;i<=n;i++)
    {
        if(a[i-1]<a[i]) l[i]=l[i-1]+1;
        else if(a[i-1]==a[i]) l[i]=l[i-1];
    }

    for(int i=n-1;i>=1;i--)
    {
        if(a[i]>a[i+1]) r[i]=r[i+1]+1;
        else if(a[i]==a[i+1]) r[i]=r[i+1];
    }

    int ans=0;
    for(int i=1;i<=n;i++) ans+=max(l[i],r[i])*100+200;
    cout<<ans<<"\n";
} 

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
