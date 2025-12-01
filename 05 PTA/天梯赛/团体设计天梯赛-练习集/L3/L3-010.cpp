#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[30];
int val[1000010];
int L[1000010];
int R[1000010];
void insert(int id,int x)
{
    if(x>val[id])
    {
        if(L[id]==-1) 
        {
            L[id]=2*id;
            val[2*id]=x;
        }
        else insert(L[id],x);
    }
    else
    {
        if(R[id]==-1)
        {
            R[id]=2*id+1;
            val[2*id+1]=x;
        }
        else insert(R[id],x);
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<=1000000;i++) L[i]=R[i]=-1;
    for(int i=1;i<=n;i++) cin>>a[i];
    val[1]=a[1];
    for(int i=2;i<=n;i++) insert(1,a[i]);
   
    int f=0;
    for(int i=1;i<=1000000;i++) if(val[i])
    {
        if(f) cout<<" ";
        cout<<val[i];
        f=1;
    }
    cout<<"\n";
    f=0;
    for(int i=1;i<=n;i++) if(!val[i]) f=1;
    if(f) cout<<"NO\n";
    else cout<<"YES\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}