#include <bits/stdc++.h>
using namespace std;
#define int long long

int n1,n2,n3,q;
int a[1010];
int b[1010];
int c[1010];
void solve()
{
    cin>>n1>>n2>>n3;
    for(int i=1;i<=n1;i++) cin>>a[i];
    for(int i=1;i<=n2;i++) cin>>b[i];
    for(int i=1;i<=n3;i++) cin>>c[i];
    int h1,h2,m1,m2;
    string s1,s2;
    cin>>s1>>s2;
    h1=stoi(s1.substr(0,2));
    m1=stoi(s1.substr(3,2));
    h2=stoi(s2.substr(0,2));
    m2=stoi(s2.substr(3,2));
    cin>>q;
    int x=h2*60-h1*60+m2-m1;
    while(q--)
    {
        int k;
        cin>>k;
        int f=0;
        int sum=0;
        for(int i=1;i<=k;i++)
        {
            string s;
            cin>>s;
            int id=stoi(s.substr(1));
            if(s[0]=='Z') sum+=a[id],f|=1;
            else if(s[0]=='P') sum+=b[id],f|=2;
            else sum+=c[id],f|=4;
        }
        if(sum<=x&&f==7) cout<<"Yes\n";
        else cout<<"No\n"; 
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}

