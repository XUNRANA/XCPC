#include <bits/stdc++.h>
using namespace std;
int n,a[10010];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n,greater<int>());
    int res=1e9,m1,n1;

    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if(n/i-i<res)
            {
                res=n/i-i;
                m1=n/i;
                n1=i;
            }
        }
    }

    int d=0;
    int i=1,j=1,k=1;
    //0 →
    //1 ↓
    //2 ←
    //3 ↑
    int a1=1,a2=n1;
    int a3=1,a4=m1;
    vector<vector<int>>ans(m1+1,vector<int>(n1+1));
    while(k<=n)
    {
        ans[i][j]=a[k++];
        if(d==0)
        {
            if(j==a2)
            {
                a3++;
                i++;
                d=1;
            }
            else j++;
        }
        else if(d==1)
        {
            if(i==a4)
            {
                a2--;
                j--;
                d=2;
            }
            else i++;
        }
        else if(d==2)
        {
            if(j==a1)
            {
                a4--;
                i--;
                d=3;
            }
            else j--;
        }
        else if(d==3)
        {
            if(i==a3)
            {
                a1++;
                j++;
                d=0;
            }
            else i--;
        }
    }
    for(int i=1;i<=m1;i++) for(int j=1;j<=n1;j++) cout<<ans[i][j]<<" \n"[j==n1];
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
