#include <bits/stdc++.h>
using namespace std;

int n,a[200010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int s=a[1];
    int t=a[n];
    sort(a+1,a+1+n);
    if(2*s>=t) cout<<"2\n";
    else
    {
        int ans=2;
        while(2*s<t)
        {
            int i=upper_bound(a+1,a+1+n,2*s)-a-1;
            if(a[i]==s) 
            {
                cout<<"-1\n";
                return ;
            }
            s=a[i];
            ans++;
        }
        cout<<ans<<"\n";
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
