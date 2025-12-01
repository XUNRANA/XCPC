#include <bits/stdc++.h>
using namespace std;
#define int long long
set<int>st[6];
void solve()
{
    int n;
    cin>>n;

    for(int j=0;j<6;j++) 
    {
        st[j].clear();
        for(int i=1;i<=8;i++) st[j].insert(i);
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<6;j++)
        {
            int x;
            cin>>x;
            st[j].erase(x);
        }
    }

    int ans=0;
    for(int i=0;i<6;i++)
    {
        for(int j=i+1;j<6;j++)
        {
            for(int k=j+1;k<6;k++)
            {
                for(int l=3;l<=24;l++)
                {
                    for(int r=l;r<=24;r++)
                    {
                        int v1=0,v2=0;
                        for(auto i1:st[i])
                        {
                            for(auto j1:st[j])
                            {
                                for(auto k1:st[k])
                                {
                                    if(i1+j1+k1>=l&&i1+j1+k1<=r) v1++;
                                    else v2++;
                                }
                            }
                        }
                        ans=max(ans,min(v1,v2));
                    }
                }
            }
        }
    }
    cout<<(8-n)*(8-n)*(8-n)*((8-n)*(8-n)*(8-n)-ans)<<"\n";
} 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
