#include <bits/stdc++.h>
using namespace std;
char ch[20][20],op;
int a,b,a1;
int main()
{
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=10;j++)
        {
            scanf("%c",&ch[i][j]);
        }
        getchar();
    }
    a=ch[2][1]-'0';
    b=ch[4][1]-'0';
    a1=ch[3][1]-'0';
    op=ch[3][6];
    if(op=='&') 
    {
        if(a==0||b==0) cout<<"0";
        else cout<<"1";
    }
	else if(op=='=') 
    {
        if(a==1||b==1) cout<<"1";
        else cout<<"0";
    }
	else if(op=='1') 
    {
        if(a1==1) cout<<0;
        else cout<<1;
    }
}