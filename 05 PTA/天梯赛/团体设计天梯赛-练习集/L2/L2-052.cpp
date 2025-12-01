#include <bits/stdc++.h>
using namespace std;
int l,n,row[5],col[5],ans;
void backtrack(int x)
{
	if(x==n*n)
	{
		for(int i=0;i<n;i++) 
		if(row[i]!=l||col[i]!=l) return ;
		ans++;
		return ;
	}
	for(int i=0;i<=l;i++)
	{
		//剪枝1：当前行或列值不超过l
		if(row[x/n]+i>l||col[x%n]+i>l) break;
		row[x/n]+=i;
		col[x%n]+=i;
		//剪枝2：加上其他没有填的数（取最大）能达到l
		if(row[x/n]+l*(n-1-x%n)>=l&&col[x%n]+l*(n-1-x/n)>=l) backtrack(x+1);
		row[x/n]-=i;
		col[x%n]-=i;
	}
}
void solve()
{
	cin>>l>>n;
	backtrack(0);
	cout<<ans;
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

