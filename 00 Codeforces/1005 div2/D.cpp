#include <bits/stdc++.h>
using namespace std;

int a[200010];
int p[200010];
int nxt[200010][30];
int fx(int x)
{
    for(int j=29;j>=0;j--) if(x>>j&1) return j;
    return 0;
}
void solve()
{
    int n,q,x;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) p[i]=p[i-1]^a[i];
    vector<int>idx(30,0);
    for(int i=1;i<=n;i++)
    {
        int h=log2(a[i]);//最高位
        // cout<<a[i]<<" "<<h<<"\n";
        idx[h]=i;//更新
        nxt[i][29]=idx[29];
        for(int j=28;j>=0;j--) nxt[i][j]=max(nxt[i][j+1],idx[j]);
    }





    // for(int i=1;i<=n;i++) 
    // {
    //     cout<<i<<"!\n";
    //     for(int j=0;j<=3;j++) cout<<nxt[i][j]<<" ";
    //     cout<<"\n?";
    // }


    while(q--)
    {
        cin>>x;
        int now=n;
        while(now>=1)
        {
            int h;
            if(!x) h=0;
            else h=log2(x);

            int j=nxt[now][h];
            if(!j)
            {
                now=0;
                break;
            }

            x^=p[now]^p[j];
            
            now=j;
            if(x<a[j]) break;
            x^=a[j];
            now--; 
        }
        cout<<n-now<<" ";
    }
    cout<<"\n";
}     

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

