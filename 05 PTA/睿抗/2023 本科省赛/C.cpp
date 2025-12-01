#include <bits/stdc++.h>
using namespace std;

int rk(array<int,5>x)
{//0 1 2 3 4
    sort(x.begin(),x.end());
    if(x[0]==x[4]) return 1;
    else if(x[1]==x[4]||x[0]==x[3]) return 2;
    else if((x[0]==x[1]&&x[2]==x[4])||(x[0]==x[2]&&x[3]==x[4])) return 3;
    else
    {
        set<int>st;
        for(int i=0;i<5;i++) st.insert(x[i]);
        if(st.size()==5) 
        {
            if(*st.begin()==2) return 4;
            else if(*st.rbegin()==5) return 5;
            else return 9;
        }
        else if(x[0]==x[2]||x[1]==x[3]||x[2]==x[4]) return 6;
        else if(st.size()==3) return 7;
        else if(st.size()==4) return 8;
        else return 9; 
    } 
}
array<int,5>b;
int f[5];
int mx;
int sum;
void dfs(array<int,5>b1,int i)
{
    if(i==5)
    {
        sum++; 
        if(rk(b1)<rk(b)) mx++;
        return ;
    }

    if(!f[i]) dfs(b1,i+1);
    else 
    {
        for(int j=1;j<=6;j++) 
        {
            b1[i]=j;
            dfs(b1,i+1);
        }
    }
}
void solve()
{
    for(int i=0;i<5;i++) cin>>b[i];
    int cc=0;
    int fz=0;
    int fm=1;
    for(int i=0;i<(1<<5);i++)
    {
        int c=0;
        for(int j=0;j<5;j++) 
        if(i>>j&1) f[j]=1,c++;
        else f[j]=0;

        mx=sum=0;
        dfs(b,0);

        int g=__gcd(mx,sum);
        mx/=g;
        sum/=g;
        if(mx*fm>fz*sum)
        {
            fz=mx;
            fm=sum;
            cc=c;
        }
        else if(mx*fm==fz*sum) cc=min(cc,c);
    }
    cout<<cc<<" "<<fz<<" "<<fm<<"\n";
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
