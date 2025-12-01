#include <bits/stdc++.h>
using namespace std;
int query(int l,int r)
{
    cout<<"? "<<l<<" "<<r<<"\n";
    int x;
    cin>>x;
    return x;
}
int a[10010];
int ans[10010];
void solve()
{
    int n;
    cin>>n;
    for(int i=n-1;i>=1;i--)
    {
        int now=query(i,n);
        if(now)
        {
            ans[i]=0;
            for(int j=i+1;j<=n;j++)
            if(j-i<=now) ans[j]=1;
            else ans[j]=0;
            int p=1;
            for(int j=i-1;j>=1;j--)
            {
                int x=query(j,i+1);
                if(x>p) ans[j]=0;
                else ans[j]=1;
                p=x;
            }

            cout<<"! ";
            for(int j=1;j<=n;j++) cout<<ans[j];
            cout<<"\n";
            return ;
        }
    }
    cout<<"! IMPOSSIBLE\n";
}
int main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
