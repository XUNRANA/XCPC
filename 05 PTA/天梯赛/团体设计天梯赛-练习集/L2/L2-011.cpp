#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int zhong[100],qian[100];
vector<int>level(1000000,-1);
void fx(int r,int s,int e,int idx)
{
	if(s>e) return ;
	int i=s;
	while(s<=e&&zhong[i]!=qian[r]) i++;//寻找在中序中的位置
	level[idx]=qian[r];
	fx(r+1,s,i-1,2*idx+2);//右 
	fx(r+i-s+1,i+1,e,2*idx+1);//左 
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>zhong[i];//中序 
	for(int i=1;i<=n;i++) cin>>qian[i];//前序 
	fx(1,1,n,1);
	int f=0;
	for(int i=1;i<level.size();i++) 
	{
		if(level[i]!=-1)
		{	
			if(f) cout<<" ";
			cout<<level[i];
			f=1;
		}	
	}
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

