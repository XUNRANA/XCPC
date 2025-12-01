#include <bits/stdc++.h>
using namespace std;
int n,t,b[100010];
int main()
{
	cin>>n;
	map<int,int>m;
	for(int i=1;i<=n;i++) cin>>t,m[t]=i;
	for(int i=1;i<=n;i++) cin>>t,b[i]=m[t];
	vector<int>ans;
	for(int i=1;i<=n;i++)
	{
		auto it=upper_bound(ans.begin(),ans.end(),b[i]);
		if(it==ans.end()) ans.push_back(b[i]);
		else *it=b[i];
	}
	cout<<ans.size();
} 













/*

#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int>a(n+1),b(n+1);
	vector<vector<int>>d(n+1,vector<int>(n+1)); //n2µÄÆÓËØ½â·¨ 
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
			else d[i][j]=max(d[i-1][j],d[i][j-1]);
		}
	}
	cout<<d[n][n];
}

*/
