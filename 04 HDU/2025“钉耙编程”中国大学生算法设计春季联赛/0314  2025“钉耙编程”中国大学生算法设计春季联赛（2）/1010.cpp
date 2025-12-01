#include <bits/stdc++.h>
using namespace std;
unsigned long long Seed;
unsigned myrand(){Seed^=Seed>>5;Seed^=Seed<<3;return Seed;}
//template< typename T >void swap(T u,T v){T t=u;u=v;v=t;} //如选手未调用 algorithm 库，请取消注释本行
template< typename T >void generate(int k,T p[]){//k 为题目中的 k，p[] 为产生的排列存储位置，下标从 1 开始
    auto *q=p+1;
    for(int i=1;i<=k;i++)p[i]=i;
    for(int i=k-1;i>0;i--)swap(q[i],q[myrand()%i]);
}
int n,m,k;
struct perm
{
	char p[30+1];
	perm()
	{
		iota(p+1,p+k+1,1);
	}
	perm inv()
	{
		perm res;
		for(int i=1;i<=k;i++)
		{
			res.p[p[i]]=i;
		}
		return res;
	}
};
perm operator *(perm a,perm b)
{
	perm c;
	for(int i=1;i<=k;i++)
	{
		c.p[i]=a.p[b.p[i]];
	}
	return c;
}
struct t1
{
	int l,r,bj;
	perm k[30+1];
}t[400005];
int tot;
int build(int p,int l,int r)
{
	if(!p)
	{
		p=++tot;
		t[p].bj=0;
	}
	if(l==r)
	{
		generate(k,t[p].k[0].p);
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=k;j++)
			{
				t[p].k[t[p].k[0].p[i]].p[j]=t[p].k[0].p[(i+j-2)%k+1];
			}
		}
		return p;
	}
	int mid=(l+r)>>1;
	t[p].l=build(0,l,mid);
	t[p].r=build(0,mid+1,r);
	t[p].k[0]=t[t[p].l].k[0]*t[t[p].r].k[0];
	for(int i=1;i<=k;i++)
	{
		t[p].k[i]=t[t[p].l].k[i]*t[t[p].r].k[i];		
	}
	return p;
}
void spread(int p)
{
	if(t[p].bj)
	{
		t[t[p].l].bj=t[p].bj;
		t[t[p].r].bj=t[p].bj;
		t[t[p].l].k[0]=t[t[p].l].k[t[p].bj];
		t[t[p].r].k[0]=t[t[p].r].k[t[p].bj];
		t[p].bj=0;
	}
}
perm ask(int p,int l,int r,int u,int v)
{
	if(u>v)
	{
		return *new perm;
	}
	if(u<=l&&v>=r)
	{
		return t[p].k[0];
	}
	spread(p);
	int mid=(l+r)>>1;
	perm res;
	if(u<=mid)
	{
		res=res*ask(t[p].l,l,mid,u,v);
	}
	if(v>mid)
	{
		res=res*ask(t[p].r,mid+1,r,u,v);
	}
	return res;
}
void change(int p,int l,int r,int u,int v,int z)
{
	if(u<=l&&v>=r)
	{
		t[p].k[0]=t[p].k[z];
		t[p].bj=z;
		return;
	}
	spread(p);
	int mid=(l+r)>>1;
	if(u<=mid)
	{
		change(t[p].l,l,mid,u,v,z);
	}
	if(v>mid)
	{
		change(t[p].r,mid+1,r,u,v,z);
	}
	t[p].k[0]=t[t[p].l].k[0]*t[t[p].r].k[0];
}
void output(perm x)
{
	for(int i=1;i<=k;i++)
	{
		cout<<(int)x.p[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k>>Seed;
	build(0,1,n);
	for(int i=1;i<=m;i++)
	{
		int op,l,r,z;
		cin>>op>>l>>r>>z;
		if(op==1)
		{
			perm ans=ask(1,1,n,1,l-1).inv()*ask(1,1,n,1,r);
			cout<<(int)ans.p[z]<<"\n";
		}
		else
		{
			change(1,1,n,l,r,z);
		}
	}
	return 0;
}
