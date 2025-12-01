#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200010];
int b[200010];
int mi[200010];
int n;
bool ck()
{
    int j=0;
    int f=1;
    for(int i=1;i<=n;i++) 
    if(a[i]) b[++j]=a[i];
    else if(f&&!a[i])
    {
        b[++j]=a[i];
        f=0;
    }
    
    mi[1]=b[1];
    for(int i=2;i<=j;i++) mi[i]=min(mi[i-1],b[i]);
    int m=0;
    map<int,int>mp;
    for(int i=j;i>=2;i--)
    {
        mp[b[i]]++;
        while(mp[m]) m++;
        if(mi[i-1]<m) return 0;
    }
    return 1;
}
void solve()
{
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        if(a[i]) cnt++;
    }
    if(cnt==n) cout<<cnt<<"\n";
    else if(ck()) cout<<cnt+1<<"\n";
    else cout<<cnt<<"\n";
}     

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

