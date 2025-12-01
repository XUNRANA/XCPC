#include <bits/stdc++.h>
using namespace std;
#define int long long


int da[100000];
int nex[100000];
void solve()
{
    int h,n,k;
    cin>>h>>n>>k;
    while(n--)
    {
        int a,d,n;
        cin>>a>>d>>n;
        da[a]=d;
        nex[a]=n;
    }
    vector<array<int,2>>ans;
    int th=h;
    while(th!=-1)
    {
        if(da[th]<0) ans.push_back({th,da[th]});
        // cout<<data[th]<<" ";
        th=nex[th];
    }




    th=h;
    while(th!=-1)
    {
        if(da[th]>=0&&da[th]<=k) ans.push_back({th,da[th]});
        // cout<<data[th]<<" ";
        th=nex[th];
    }


    
    th=h;
    while(th!=-1)
    {
        if(da[th]>k) ans.push_back({th,da[th]});
        // cout<<data[th]<<" ";
        th=nex[th];
    }


    for(int i=0;i<ans.size();i++) 
    {
        if(i+1<ans.size()) 
        {
            printf("%05d %d %05d\n",ans[i][0],ans[i][1],ans[i+1][0]);
            // cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i+1][0]<<"\n";
        }
        else    printf("%05d %d %d\n",ans[i][0],ans[i][1],-1);
         
        // else cout<<ans[i][0]<<" "<<ans[i][1]<<" -1"<<"\n";

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
