#include <bits/stdc++.h>
using namespace std;
int n,k,a[2000010],tr[2000010];

int lowbit(int x)
{
	return x&-x;
}

void add(int i,int x)
{
	while(i<=(1<<n))
	{
		tr[i]+=x;
		i+=lowbit(i);
	}
}

int sum(int i)
{
	int res=0;
	while(i)
	{
		res+=tr[i];
		i-=lowbit(i);
	}
	return res;
}
/*
 4 1
 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
*/
int ans[2000010];
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=(1<<n);i++) cin>>a[i],ans[i]=0;
	vector<pair<int,int>>res;
	for(int i=1;i<=n;i++)
	{
		int len=(1<<i);
		for(int j=1;j<=(1<<n);j+=len) res.push_back({j,j+len-1});
	}
	
	for(auto i:res)
	{
		int l=i.first;
		int r=i.second;
		int len=r-l+1;
		for(int j=l;j<=r;j++) add(a[j],1);
		for(int j=l;j<=r;j++)
		{
			int small=sum(a[j]-1);//比它小的数量 
			int big=sum(1<<n)-sum(a[j]);//比它大的数量 
			//比它小的+min(最多移进的数量，最多移动k次，最多移出的数量） 
			if(small+min({k,big,a[j]-1-small})>=len-1) ans[j]=log2(len);
		}	
		for(int j=l;j<=r;j++) add(a[j],-1);
	}
	
	for(int i=1;i<=(1<<n);i++) cout<<ans[i]<<" ";
	cout<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
//    cin>>T;
    while(T--) solve();
}
