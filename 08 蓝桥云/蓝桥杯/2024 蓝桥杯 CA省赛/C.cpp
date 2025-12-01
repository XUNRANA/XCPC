#include <bits/stdc++.h>
using namespace std;
long long n,s,ans,sum;
/*
3 6
5 2
2 4
3 2
*/
int main()
{
	cin>>n>>s;
	vector<pair<long long,long long>>v(n+1);
	for(int i=1;i<=n;i++) cin>>v[i].second>>v[i].first;
	sort(v.begin()+1,v.end());
	for(int i=1;i<=n;i++) v[i].second+=v[i-1].second;
	//for(int i=1;i<=n;i++) cout<<v[i].first<<" "<<v[i].second<<"\n";
	
	for(int i=1;i<=n;i++)
	{
		if(sum==v[i].first) continue;
		if(v[n].second-v[i-1].second>s)
		{
			ans+=(v[i].first-sum)*s;
			sum=v[i].first;
		}
		else 
		{
			for(int j=i;j<=n;j++) ans+=(v[i].first-sum)*(v[i].second-v[i-1].second);
			break;
		}
	}
	cout<<ans;
	return 0;
}
