#include <bits/stdc++.h>
using namespace std;
#define int long long

bool ck(int a,int b,int c,int k)
{
    if(k==1) return 0;
    while(a||b||c)
    {
        if((a%k+b%k)%k!=c%k) return 0;
        a/=k;
        b/=k;
        c/=k;
    }
    return 1;
}
void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a+b==c) cout<<"-1\n";
    else if(a+b>c)
    {
        int d=a+b-c;
        int ans=0;
        for(int i=1;i*i<=d;i++)
        {
            if(d%i==0) 
            {
                if(ck(a,b,c,i)) 
                {
                    // cout<<i<<"?\n";
                    ans++;
                }
                if(d/i!=i&&ck(a,b,c,d/i)) 
                {
                    // cout<<d/i<<"?\n";
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    else if(a+b<c) cout<<"0\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
