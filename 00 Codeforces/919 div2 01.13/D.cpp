#include <bits/stdc++.h>
using namespace std;
#define int long long
int inf=1e18,n,q,b,x,k;
void solve()
{
	cin>>n>>q;
	vector<vector<int>>app(1);
	vector<int>mul{1};
	vector<int>len{0};
	while(n--)
	{
		cin>>b>>x;
		if(b==1) app.back().push_back(x);
		else if(len.back()<inf)
		{
			len.push_back(len.back()<=inf/mul.back()? len.back()*mul.back()+app.back().size():inf);
			mul.push_back(x+1);
			app.push_back({});
		}
	}
	while(q--)
	{
		cin>>k;
		k--;
		for(int i=app.size()-1;i>=0;i--)
		{
			if(k/mul[i]>=len[i])
			{
				cout<<app[i][k-mul[i]*len[i]]<<" ";
				break;
			}
			k%=len[i];
		}
	}
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
} 
