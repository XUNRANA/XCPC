#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node
{
    int b,c,a;
}a[200010];
int n,m,k,x;
bool cmp(node a1,node a2)
{
    return (a1.c-k*a1.b)>(a2.c-k*a2.b);
}
void solve()
{
    //ac+k*aa
    //bc+k*ab
    
    //k*aa+ac-k*ab>bc

    //k*aa+a(c-k*b)>bc
    cin>>n>>m>>k>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].b>>a[i].c;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        if(m>x)
        {
            a[i].a=x;
            m-=x;
        }
        else
        {
            a[i].a=m;
            m-=m;
        }
    }
    if(m>0)
    {
        cout<<"NO\n";
        return ;
    }
    __int128 s1=0,s2=0;
    for(int i=1;i<=n;i++)
    {
        s1+=a[i].a*(a[i].c+k*a[i].a);
        s2+=a[i].b*(a[i].c+k*a[i].a);
    }

    if(s1>s2) cout<<"YES\n";
    else cout<<"NO\n";
}
signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}
