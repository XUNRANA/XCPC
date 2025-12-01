#include <bits/stdc++.h>
using namespace std;
#define l(x) tree[x].l
#define r(x) tree[x].r
#define sum(x) tree[x].sum
#define add(x) tree[x].add
struct SegmentTree{
	int l,r;
	int sum,add;
}tree[300010*4];

int a[300010],n,q;
void build(int p,int l,int r)
{
	l(p)=l;
	r(p)=r;
	if(l==r)
	{
		sum(p)=a[l];
		return ;
	}
	int mid=l+r>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	sum(p)=sum(p*2)+sum(p*2+1);
}
void spread(int p)
{
	if(add(p))
	{
		sum(p*2)+=add(p)*(r(p*2)-l(p*2)+1);
		sum(p*2+1)+=add(p)*(r(p*2+1)-l(p*2+1)+1);
		add(p*2)+=add(p);
		add(p*2+1)+=add(p);
		add(p)=0;
	}	
}

void change(int p,int l,int r,int d)
{
	if(l<=l(p)&&r>=r(p))
	{
		sum(p)+=(long long)d*(r(p)-l(p)+1);
		add(p)+=d;
		return ;
	}	
	spread(p);
	int mid=(l(p)+r(p))/2;
	if(l<=mid) change(p*2,l,r,d);
	if(r>mid) change(p*2+1,l,r,d);
	sum(p)=sum(p*2)+sum(p*2+1);
}
/*
5 5
10101
2 1 5
1 2 3
2 1 5
2 1 3
2 2 3


0
2
1
0
*/
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);


}
