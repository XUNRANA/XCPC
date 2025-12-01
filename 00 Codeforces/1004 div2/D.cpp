#include <bits/stdc++.h>
using namespace std;
#define int long long

int ask(int x,int y)
{
    cout<<"? "<<x<<" "<<y<<"\n";
    cout.flush();
    int res;
    cin>>res;
    return res;
}
void solve()
{
    int n,x;
    cin>>n;
    vector<int>idx(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        idx[x]=i;
    }
    int pos=0;
    for(int i=1;i<=n;i++) if(!idx[i]) pos=i;
    if(pos)
    {
        int res;
        if(pos==1) res=ask(1,n);
        else res=ask(pos,1);
        if(!res) cout<<"! A\n";
        else cout<<"! B\n";
    }
    else
    {
        int res1,res2;
        res1=ask(idx[1],idx[n]);
        if(res1<n-1) cout<<"! A\n";
        else if(res1>n-1) cout<<"! B\n";
        else
        {
            res2=ask(idx[n],idx[1]);
            if(res1!=res2) cout<<"! A\n";
            else cout<<"! B\n";
        }
    }
}

signed main() 
{
	// ios::sync_with_stdio(0);
	// cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

