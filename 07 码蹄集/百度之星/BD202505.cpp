#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[2000010];
int c[2000010];
int vt[2000010];
void cl()
{
    for(int i=1;i<=n;i++) c[a[i]]--,vt[a[i]]=0;
}
bool is(int x)
{
    for(int i=0;i<30;i++)
    {
        if(x==(1ll<<i)-1) return 1;
    }
    return 0;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],c[a[i]]++;
    for(int i=1;i<=n;i++)
    {
        if(c[a[i]]%2==0) 
        {
            cl();
            cout<<"No\n";
            return ;
        }
    }

    vector<int>x;
    vector<int>cx;
    for(int i=1;i<=n;i++)
    {
        if(x.empty()||x.back()!=a[i]) 
        {
            x.push_back(a[i]);
            cx.push_back(1);
        }
        else 
        {
            cx.back()++;
        }
    }
    
    for(auto i:cx)
    {
        if(!is(i)) 
        {
            cl();
            cout<<"No\n";
            return ;
        }
    }
    for(auto i:x)
    {
        if(vt[i])
        {
            cl();
            cout<<"No\n";
            return ;
        }
        vt[i]=1;
    }
    cout<<"Yes\n";
    cl();

}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
