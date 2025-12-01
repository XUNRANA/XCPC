#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1010][1010];
void solve()
{
    int n,m;
    cin>>n>>m;
    set<int>st;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    set<int>st1;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            st1.insert(a[i][j]);
            int f=0;
            if(i+1<=n&&a[i][j]==a[i+1][j]) f=1;
            if(j+1<=m&&a[i][j]==a[i][j+1]) f=1;
            if(f==1)
            {
                if(st.count(a[i][j])) continue;
                st.insert(a[i][j]);
                cnt++;
            }
        }
    }
    if(cnt) cout<<st1.size()-1+cnt-1<<"\n";
    else cout<<st1.size()-1<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

