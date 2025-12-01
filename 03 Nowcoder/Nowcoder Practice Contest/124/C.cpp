#include <bits/stdc++.h>
using namespace std;
pair<int,int>a[100100];
int main()
{
	long long n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
	sort(a+1,a+n+1);
	long long ans=0;
	priority_queue<int>q;//默认降序
	for(int i=n;i>=1;i--)
    {
		q.push(a[i].second);
		if(q.size()>k) q.pop();//每次pop右端点最右的
		if(q.size()==k) ans+=(a[i].first-a[i-1].first)*(m-q.top()+1);
	}
	cout<<ans;
}