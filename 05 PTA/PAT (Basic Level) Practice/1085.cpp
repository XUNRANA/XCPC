#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node
{
    string name;
    int cnt;
    int s;
    int r;
}a[100010];
bool cmp(node a1,node a2)
{
    if(a1.s==a2.s)
    {
        if(a1.cnt==a2.cnt) return a1.name<a2.name;
        return a1.cnt<a2.cnt;
    }
    return a1.s>a2.s;

}
void solve()
{
    int n;
    cin>>n;
    map<string,int>mp[3];
    map<string,int>st;
    for(int i=1;i<=n;i++)
    {
        string a,b;
        int x;
        cin>>a>>x>>b;
        for(auto &i:b) if(isupper(i)) i=tolower(i);
        
        st[b]++; 
        if(a[0]=='A') mp[0][b]+=x;//甲级
        else if(a[0]=='B') mp[1][b]+=x;//乙级
        else mp[2][b]+=x;//顶级 
    }
    int j=0;
    for(auto i:st)
    {
        a[++j].name=i.first;
        a[j].cnt=i.second;
        a[j].s=(mp[0][i.first]*6+mp[1][i.first]*4+mp[2][i.first]*9)/6;
    }

    sort(a+1,a+1+j,cmp);

    
    cout<<j<<"\n";
    int p=-1;
    for(int i=1;i<=j;i++) 
    {
        if(a[i].s!=p) a[i].r=i;
        else a[i].r=a[i-1].r;
    
        cout<<a[i].r<<" "<<a[i].name<<" "<<a[i].s<<" "<<a[i].cnt<<"\n";
        p=a[i].s;
    }
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
