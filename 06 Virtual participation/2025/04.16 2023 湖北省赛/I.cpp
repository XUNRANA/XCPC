#include <bits/stdc++.h>
using namespace std;
#define int long long
int lcm(int x,int y)
{
    int g=__gcd(x,y);
    return x/g*y;
}


//a*x+b*y==gcd(a,b)
int exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	int res=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return res;
}

void solve() 
{
    int n;
    cin>>n;
    int l=1;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        l=lcm(x,l);
    }
    // cout<<l<<"\n";
    l*=2;
    vector<int>a;
    for(int i=2;i*i<=l;i++)
    {
        if(l%i==0)
        {
            int s=1;
            while(l%i==0) l/=i,s*=i;
            a.push_back(s);
        }
    } 
    if(l!=1) a.push_back(l);
    int ans=1e18;
    int len=a.size();
    for(int i=0;i<(1<<len);i++)
    {
        int a1=1,b1=1;
        for(int j=0;j<len;j++)
        {
            if(i>>j&1) a1=a1*a[j];
            else b1=b1*a[j];
        }
        int x1,y1;
        exgcd(a1,b1,x1,y1);
        x1=-x1;//-x1*a1+y1*b1==1
        x1=(x1%b1+b1)%b1;//最小的x满足
        if(x1!=0) ans=min(ans,a1*x1);
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