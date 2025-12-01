#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,j=0,k=0;
	string s;
	cin>>n>>s;
	string t1="DFS",t2="dfs";
	for(auto i:s)
	{
		if(j<3&&i==t1[j]) j++;
		if(k<3&&i==t2[k]) k++;
	}
	cout<<(j==3? 1:0)<<" "<<(k==3? 1:0)<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
