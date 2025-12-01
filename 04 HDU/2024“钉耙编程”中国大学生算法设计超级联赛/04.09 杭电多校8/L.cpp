#include <bits/stdc++.h>
using namespace std;
#define int long long
string a,b,c;
int n,ans,x,y,z;
void solve()
{
    cin>>n;
    cin>>a>>b>>c;
    ans=0;
    x=y=z=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==b[i]&&b[i]==c[i]) ans++;
        else if(a[i]==b[i]) x++;
        else if(a[i]==c[i]) y++;
        else z++;
    }
    if(x>y) swap(x,y);
    if(y>z) swap(y,z);
    if(x>y) swap(x,y);
    cout<<ans+x+y+(z-y)/2<<"\n";
}


signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
