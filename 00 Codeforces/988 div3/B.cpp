#include <bits/stdc++.h>
using namespace std;
int cnt[200010];
void solve()
{
    int k;
    cin>>k;
    for(int i=1;i<=k;i++) cnt[i]=0;
    for(int i=1;i<=k;i++) 
    {
        int x;
        cin>>x;
        cnt[x]++;
    }
    k-=2;
    for(int i=1;i<=k;i++)
    {
        if(k%i==0)
        {
            if(i==k/i)
            {
                if(cnt[i]>=2) 
                {
                    cout<<i<<" "<<i<<"\n";
                    return ; 
                }
            }
            else 
            {
                if(cnt[i]&&cnt[k/i])
                {
                    cout<<i<<" "<<k/i<<"\n";
                    return ;
                }
            }
        }
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
