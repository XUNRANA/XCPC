#include <bits/stdc++.h>
using namespace std;
#define int long long
string d[]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
void solve()
{
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    int a=-1,b=-1,c=-1;
    for(int i=0;i<min(s1.size(),s2.size());i++) 
    if(s1[i]==s2[i])
    {
        if(s1[i]>='A'&&s1[i]<='G'&&a==-1) a=s1[i]-'A';
        else if(a!=-1)
        {
            if(b==-1)
            {
                if(isdigit(s1[i])) b=s1[i]-'0';
                else if(s1[i]>='A'&&s1[i]<='N') b=s1[i]-'A'+10;
            }
        }
    }
    for(int i=0;i<min(s3.size(),s4.size());i++) 
    if(s3[i]==s4[i]&&(isupper(s3[i])||islower(s3[i])))
    {
        if(c==-1) c=i;
    }
    printf("%s %02d:%02d",d[a].c_str(),b,c);
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}