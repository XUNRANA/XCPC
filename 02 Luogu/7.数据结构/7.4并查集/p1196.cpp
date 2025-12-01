#include <bits/stdc++.h>
using namespace std;
int fa[30010],front[30010],num[30010];
int t,i,j,fi,fj;
char op;
int find(int x)
{
	if(fa[x]==x) return x;
	int fx=find(fa[x]);
	front[x]+=front[fa[x]];//更新 
	return fa[x]=fx;
}
int main()
{
	cin>>t;
	for(int i=1;i<=30000;i++) 
	{
		fa[i]=i;
		front[i]=0;
		num[i]=1;
	}
	while(t--)
	{
		cin>>op>>i>>j;
		fi=find(i);
		fj=find(j);
		if(op=='M')
		{
			front[fi]+=num[fj];//更新i的队头 
			fa[fi]=fj;//更新i的祖先 
			num[fj]+=num[fi];//更新j队列的长度 
			num[fi]=0;//更新i队列的长度 
		}
		else
		{
		    if(fi!=fj) cout<<-1<<"\n";
		    else cout<<abs(front[i]-front[j])-1<<"\n";	
		}
	}
}
