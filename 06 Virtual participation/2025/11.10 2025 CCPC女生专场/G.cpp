#include <bits/stdc++.h>
using namespace std;
bool f[300010];
vector<int>p;
void init(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!f[i]) p.push_back(i);
		for(int j=0;j<p.size()&&p[j]*i<=n;j++)
		{
			f[p[j]*i]=1;
			if(i%p[j]==0) break;
		}
	}
}
void solve()
{
    int n,k;
    cin>>n>>k;
    init(n);
    vector<int>p1;
    p1.push_back(1);
    for(auto i:p) p1.push_back(i);

    if(k>p1.size()) cout<<"NO\n";
    else 
    {
        cout<<"YES\n";
        for(auto i:p1)
        {
            if(k==0) 
            {
                cout<<"\n";
                return ;
            }
            cout<<i<<" ";
            k--;
        }
    }
}
int main() 
{ 
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}