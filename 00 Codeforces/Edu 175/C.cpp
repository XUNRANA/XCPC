#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
string s;
int a[300010];
bool ck(int x)
{
    int f=0,cnt=0;
    for(int i=1;i<=n;i++)
    if(a[i]>x)
    {
        if(s[i]=='B'&&f==0)
        {
            f=1;//起点确定
        }
        else if(s[i]=='R')
        {
            if(f)//终点确定
            {   
                cnt++;
                f=0;
            }
        }
    }
    if(f) cnt++;
    return cnt<=k;
}
void solve()
{
    cin>>n>>k>>s;
    s=" "+s;
    for(int i=1;i<=n;i++) cin>>a[i];
    int l=0,r=1e9;
    while(l<=r)
    {
        int m=l+r>>1;
        if(ck(m)) r=m-1;
        else l=m+1;
    }
    cout<<l<<"\n";

}
// B R B R B B R R B R
// 5 1 2 4 5 3 6 1 5 4


signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

