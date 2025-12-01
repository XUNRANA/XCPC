#include <bits/stdc++.h>
using namespace std;
int n,s,k,a[100010];
void solve()
{
	cin>>n>>s>>k;
	if(2*k+1>n||k&&s<n+k+1)
	{
		cout<<"-1\n";
		return ;
	}
    for(int i=1;i<=n;i++) a[i]=1;
    s-=n;
    if(k)
    {
        //2 1 2 1 2
        for(int i=1;i<=2*k+1;i+=2) a[i]+=s/(k+1);
        s%=(k+1);
        if(k*2+1==n)
        {
            if(a[1]==a[2]+1&&s)
            {
                cout<<"-1\n";
                return ;
            }
            for(int i=2;i<=s*2;i+=2) a[i]++;
        }
        else a[k*2+2]+=s;
    }
    else a[1]+=s;
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<"\n";
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
