#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int>v1={2,4,6,8,1,3,5,7};
vector<int>v2={6,3};
void solve()
{
	string s;
	cin>>s;
	vector<int>cnt(10,0);
	int sum=0;
	for(auto i:s) cnt[i-'0']++,sum+=i-'0';
	
	if(sum%9==0) cout<<"YES\n";
	else 
	{
		if(cnt[2]>=8) cout<<"YES\n";
		else
		{
			set<int>st;
			for(int i=0;i<cnt[2];i++) st.insert(v1[i]);
			for(int i=0;i<min(cnt[3],2ll);i++) 
			{
				st.insert(v2[i]);
				for(int j=0;j<cnt[2];j++) st.insert((v2[i]+v1[j])%9);
			}
//			cout<<sum%9<<"\n";
//			cout<<cnt[2]<<" "<<cnt[3]<<"\n";
//			for(auto i:st) cout<<i<<" ";
//			cout<<"\n";
			
			if(st.count(9-sum%9)) cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	
	

}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
