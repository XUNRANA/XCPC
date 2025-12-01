#include <bits/stdc++.h>
using namespace std;
int n;
int c[1000010];
int ans[200010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        int x;
        cin>>x;
        c[x]++;
    }
    
    for(int i=1;i<=1e6;i++)
    {
        if(c[i])
        {
            for(int j=2*i;j<=1e6;j+=i)
            c[i]+=c[j];


            //mex为0
            for(int j=1;j<=c[i];j++)
            {
                ans[j]=max(ans[j],i^0);
            }

            //mex为1、2
            if(c[0])
            for(int j=2;j<=c[i]+c[0];j++)
            {
                int x;
                if(i==1) x=2;
                else x=1; 
                ans[j]=max(ans[j],i^x);
            }

        }
    }

    int i=0;//最少多少个
    int s=0;//最多多少个
    while(c[i])
    {
        s+=c[i];
        i++;

    }

    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<"\n";
} 

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
