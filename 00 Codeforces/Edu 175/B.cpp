#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,x,k;
    string s;
    cin>>n>>x>>k;
    cin>>s;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='L') x--;
        else x++;
        if(x==0) 
        {
            k-=i+1;
            ans=1;
            break;
        }
    }
    if(!ans)
    {
        cout<<"0\n";
        return ;
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]=='L') x--;
        else x++;
        if(x==0)
        {
            ans+=k/(i+1);
            break;
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

