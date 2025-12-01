#include <bits/stdc++.h>
using namespace std;
#define int long long
const int P=1e18+3;
const int P1=1e9+7;
int n,m,k,B;
int p[300010][26];
int sum;
int ans[300010];
int hz[300010];
struct node
{
	int l,r,id;
}q[300010];

bool cmp(node q1,node q2)//按l/B、r排序 
{
	if(q1.l/B!=q2.l/B) return q1.l<q2.l;
	return q1.r<q2.r;
}
int cnt[300010];

void add(int idx)//扩展一个数 
{
    sum+=cnt[hz[idx]];
    cnt[hz[idx]]++;
}

void del(int idx)//删除一个数 
{
    cnt[hz[idx]]--;
    sum-=cnt[hz[idx]];
    
}
void solve()
{
	
    cin>>n>>k>>m;
	B=sqrt(n);//块的大小 

	for(int i=1;i<=n;i++) 
    {
        char ch;
        cin>>ch;
        for(int j=0;j<26;j++) p[i][j]=p[i-1][j];
        p[i][ch-'a']++;
    }
    unordered_map<int,int>mp;
    for(int i=0;i<=n;i++)
    {
        hz[i]=1;
        for(int j=0;j<26;j++) hz[i]=(hz[i]*P1%P+p[i][j]%k)%P;
        mp[hz[i]]=1;
    }
    int idx=0;
    for(auto &i:mp) i.second=idx++;
    for(int i=0;i<=n;i++) hz[i]=mp[hz[i]];
	for(int i=1;i<=m;i++)
	{
		cin>>q[i].l>>q[i].r;
        q[i].l--;
		q[i].id=i;
	}
	sort(q+1,q+1+m,cmp);
	for(int i=1,l=1,r=0;i<=m;i++)
	{
		while(l>q[i].l) add(--l);//左扩展 
		while(r<q[i].r) add(++r);//右扩展 
		while(l<q[i].l) del(l++);//左删除 
		while(r>q[i].r) del(r--);//右删除 
		ans[q[i].id]=sum;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
