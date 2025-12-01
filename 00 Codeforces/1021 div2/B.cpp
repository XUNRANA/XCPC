#include <bits/stdc++.h>
using namespace std;
int a[100010];
int n,k;
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    if(k==0)
    {
        if(n&1) cout<<"1\n";
        else cout<<a[n/2+1]-a[n/2]+1<<"\n";
    }
    else
    {
        int l,r;
        if(n&1) 
        {
            k--;
            l=n/2;
            r=n/2+2;
        }
        else
        {
            l=n/2;
            r=n/2+1;
        }

        int c=k/2;
        l-=c;
        r+=c;
        cout<<a[r]-a[l]+1<<"\n";
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
