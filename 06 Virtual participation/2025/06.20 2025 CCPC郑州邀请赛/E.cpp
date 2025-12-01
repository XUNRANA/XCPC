#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s[200010];
int ch[200010][26][3];
int c[200010*26][3];
int cnt[3];
long long ans;
void insert(string t,int f)
{
    int now=0;
    for(auto i:t)
    {
        if(!ch[now][i-'a'][f]) ch[now][i-'a'][f]=++cnt[f];
        now=ch[now][i-'a'][f];
        if(!f) ans+=c[now][f];
        else ans-=c[now][f];
        c[now][f]++;
    }
}

int fx(string t,int f)
{
    int now=0;
    int res=0;
    for(auto i:t)
    {
        if(!ch[now][i-'a'][f]) return res;
        now=ch[now][i-'a'][f];
        res+=c[now][f];
    }
    return res;
}

void solve()
{
    cin>>n;
    for(int i=1;i<=2*n;i++)
    {
        cin>>s[i];
        insert(s[i],0);
    }

    sort(s+1,s+1+2*n);
    int cc=1;
    insert(s[1],1);
    for(int i=2;i<=2*n;i++)
    {
        if(cc<n&&fx(s[i],1)<fx(s[i],2)) 
        {
            insert(s[i],1);
            cc++;
        }
        else insert(s[i],2);
    }
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

