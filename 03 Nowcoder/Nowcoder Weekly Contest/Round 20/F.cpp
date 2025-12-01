#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
int ans,c2[N],c5[N],ct2[N],ct5[N],sm2[N],sm5[N];
int lowbit(int x)
{
	return x&-x;
}
void add(int tr[],int n,int i,int x)
{
	while(i<=n)
	{
		tr[i]+=x;
		i+=lowbit(i);
	}
}
int query(int tr[],int i)
{
	int res=0;
	while(i)
	{
		res+=tr[i];
		i-=lowbit(i);
	}
	return res;
}

void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        int t;
        cin>>t;
        while(t%2==0) t/=2,c2[i]++;
        while(t%5==0) t/=5,c5[i]++;
        c2[i]+=c2[i-1];
        c5[i]+=c5[i-1];
    }
    vector<int>a;
    for(int i=1;i<=n;i++) a.push_back(c2[i]-c5[i]);
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    int pos=lower_bound(a.begin(),a.end(),0)-a.begin()+1;
    int m=a.size();
    add(ct2,m,pos,1);
    add(ct5,m,pos,1);
    
    for(int i=1;i<=n;i++)
    {
        int pos=lower_bound(a.begin(),a.end(),c2[i]-c5[i])-a.begin()+1;
        ans+=c5[i]*query(ct5,pos)-query(sm5,pos);
        ans+=c2[i]*(query(ct2,m)-query(ct2,pos))-(query(sm2,m)-query(sm2,pos));
        add(ct2,m,pos,1);
        add(ct5,m,pos,1);
        add(sm2,m,pos,c2[i]);
        add(sm5,m,pos,c5[i]);
    }
    cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
