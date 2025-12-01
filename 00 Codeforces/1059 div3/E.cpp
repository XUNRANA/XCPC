#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[400010];

int b[200010];
// 3

// 2 3 1 2 1 3 2 1 3 2  
// 1 2 3 1 2 3 1 2 3 1 2 3 1 2 3
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        b[i]=0;
    } 
    for(int i=1;i<=n;i++) b[a[i]]=1;
    
    vector<int>c;
    for(int i=1;i<=n;i++) 
    if(!b[i]) c.push_back(i);
    

    
    if(!c.size())
    {
        for(int i=n+1;i<=n+k;i++) a[i]=a[i-3];
    }
    else if(c.size()==1)
    {
        a[n+1]=c[0];
        int y=-1;
        for(int i=1;i<=n;i++) if((i!=a[n+1])&&(i!=a[n])) y=i;
        if(y!=-1) a[n+2]=y;
        else a[n+2]=a[1];

        for(int i=n+3;i<=n+k;i++) a[i]=a[i-3];
    }
    else 
    {
        a[n+1]=c[0];
        a[n+2]=c[1];
        
        for(int i=n+3;i<=n+k;i++) a[i]=a[i-3];
    }

    for(int i=n+1;i<=n+k;i++) cout<<a[i]<<" ";
    cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
