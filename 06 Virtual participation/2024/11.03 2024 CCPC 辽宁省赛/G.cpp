#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[1000010][30];
int a[1000010];
int get(int l,int r)
{
    int k=log2(r-l+1);
    return max(f[l][k],f[r-(1<<k)+1][k]);
}
bool ck(int l,int r,int x)
{
    return get(l,r)==x;
}
void solve()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    
    if(k==1)
    {
        cout<<n*(n+1)/2<<"\n";
        return ;
    }
    
    for(int i=1;i<=n;i++) f[i][0]=a[i];
    
    for(int i=1;i<=21;i++)
    for(int j=1;j+(1<<i)-1<=n;j++) f[j][i]=max(f[j][i-1],f[j+(1<<(i-1))][i-1]);
    
	map<int,vector<int>>mp;
	for(int i=1;i<=n;i++) mp[a[i]].push_back(i);
    
	int ans=0;
    
    for(auto i:mp)
    {
        int x=i.first;
        
        auto vt=i.second;
        
		if(vt.size()<k) continue;
        
		for(int i=0;i<vt.size();i++)
        {
        
            if(i+k-1>=vt.size()) break;

            int l=vt[i],r=vt[i+k-1];

            if(get(l,r)!=x) continue;
            
            int l1=1,r1=l;
            
            while(l1<=r1)
            {
                int m1=l1+r1>>1;
                if(ck(m1,r,x)) r1=m1-1;
                else l1=m1+1; 
            }
            


            int l2=r,r2=n;

            if(i+k<vt.size()) r2=min(r2,vt[i+k]-1);
            

            while(l2<=r2)
            {
                int m2=l2+r2>>1;
                if(ck(r,m2,x)) l2=m2+1;
                else r2=m2-1; 
            }
            
            l2--;
            
            ans+=(l-l1+1)*(l2-r+1);
        }
    }
    cout<<ans<<"\n";
}

//5 4 3 2 1 
/*
 2
 5 2
 1 3 3 2 2
 4 3
 1 4 2 1
*/

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
