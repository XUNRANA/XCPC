#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200010];
void solve()
{
    int n,k;
    string s;
    cin>>n>>k;
    cin>>s;
    s=" "+s;
    int c1=s.back()=='1';
    int c0=s.back()=='0';
    for(int i=n-1;i>=1;i--)
    {
        a[i]=c1-c0;
        c1+=s[i]=='1';
        c0+=s[i]=='0';
    }
    sort(a+1,a+1+n-1,greater<int>());

    for(int i=1;i<=n-1&&a[i]>0;i++)
    {
        if(k>a[i])
        {
            k-=a[i];
        }
        else
        {
            cout<<i+1<<"\n";
            return ;
        }
    }
    cout<<"-1\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}