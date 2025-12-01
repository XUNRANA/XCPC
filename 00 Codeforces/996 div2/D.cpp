#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,l;
int a[200010];
void solve()
{
    cin>>n>>k>>l;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        a[i]*=2;
    }
    k*=2;
    l*=2;
    int now=a[1];
    int pos=k;
    
    for(int i=2;i<=n;i++)
    {
        if(a[i]+now<pos) pos=max(pos,a[i]+now+k);
        else
        {
            if(pos>=a[i]-now) pos+=k;
            else 
            {
                int x=a[i]-now-pos;
                now+=x/2;
                pos+=k+x/2;
            }
        }
    }
    cout<<now+max(0ll,l-pos)<<"\n";
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
