#include <bits/stdc++.h>
using namespace std;

int n,nq,a[200010],ans[200010],B,cnt;
int mp[1000001];//别用umap，TLE！！！！ 
//unordered_map<int,int>mp;
struct node
{
	int l,r,id;
}q[200010];
bool cmp(node q1,node q2)//按l/B、r排序 
{
	if(q1.l/B!=q2.l/B) return q1.l<q2.l;
	return q1.r<q2.r;
}
void add(int x)//扩展一个数 
{
	mp[x]++;
	if(mp[x]&1) cnt++;
	else cnt--;
}
void del(int x)//删除一个数 
{
	mp[x]--;
	if(mp[x]&1) cnt++;
	else cnt--;
}


void solve()
{
	cnt=0;
	cin>>n>>nq;
	B=sqrt(n);
	for(int i=1;i<=n;i++) cin>>a[i],mp[a[i]]=0;
	for(int i=1;i<=nq;i++) 
	{
		cin>>q[i].l>>q[i].r;
		q[i].id=i;
	}
	sort(q+1,q+1+nq,cmp);
	for(int i=1,l=1,r=0;i<=nq;i++)
	{
		while(l>q[i].l) add(a[--l]);//左扩展 
		while(r<q[i].r) add(a[++r]);//右扩展 
		while(l<q[i].l) del(a[l++]);//左删除 
		while(r>q[i].r) del(a[r--]);//右删除 
		ans[q[i].id]=cnt;
	}
	
	for(int i=1;i<=nq;i++) if(!ans[i]) cout<<"YES\n";
	else cout<<"NO\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}





/*

#include <bits/stdc++.h>
using namespace std;
unsigned long long v[1000010],a[200010];
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
void init()
{
	for(int i=1;i<=1000000;i++) v[i]=rng();
}
void solve()
{
	int n,q,l,r;
	cin>>n>>q;

	for(int i=1;i<=n;i++) cin>>a[i],a[i]=v[a[i]],a[i]^=a[i-1];

	while(q--)
	{
		cin>>l>>r;
		if((a[r]^a[l-1])==0&&(r-l+1)%2==0) cout<<"YES\n";
		else cout<<"NO\n";
	}	
}
int main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}

*/
