#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 10007
bool ck(int x)
{
    while(x)
    {
        if(x%27==0) return 0;
        x/=27;
    }
    return 1;
}
string change(int x)
{
    string s;
    while(x)
    {
        s+=char(x%27+'a'-1);
        x/=27;
    }
    return s;
}
int A(string s)
{
    int p10=1;
    int res=0;
    for(auto i:s)
    {
        res+=(i-'a'+1)*p10;
        p10=p10*27;
    }
    return res;
}
int B(string s)
{
    int p10=1;
    int res=0;
    for(auto i:s)
    {
        res+=(i-'a'+1)*p10;
        p10=p10*10;
    }
    return res%P;
}
int k,c,d,e,f;
int fx(int x)
{
    return x*x*x*c+x*x*d+x*e+f;
}
void solve()
{
    cin>>k>>c>>d>>e>>f;
    int ans=0;
    int limit=pow(27,k)-1;
    for(int bs=1;bs<10007;bs++)
    {
        int as=fx(bs);
        if(ck(as)&&as<=limit)
        {
            string s=change(as);
            if(B(s)==bs)
            {
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
