#include <bits/stdc++.h>
using namespace std;
char a[10][10];
void solve()
{
	for(int i=1;i<=8;i++) for(int j=1;j<=6;j++) a[i][j]=' ';
	a[1][3]=a[2][3]=a[1][4]=a[2][4]='y';
	a[3][1]=a[3][2]=a[4][1]=a[4][2]='o';
	a[3][3]=a[3][4]=a[4][3]=a[4][4]='b';
	a[3][5]=a[3][6]=a[4][5]=a[4][6]='r';
	a[5][3]=a[5][4]=a[6][3]=a[6][4]='w';
	a[7][3]=a[7][4]=a[8][3]=a[8][4]='g';
//	for(int i=1;i<=8;i++,cout<<"\n") for(int j=1;j<=6;j++) cout<<a[i][j];
	int n;
	cin>>n;
	while(n--)
	{
		int x;
		cin>>x;
		if(x==1)
		{
			char c;
			cin>>c;
			if(c=='L') 
			{
				char t=a[7][3];
				for(int j=8;j>=3;j--) a[j][3]=a[j-2][3];
				a[1][3]=a[2][3]=t;
			}
			else
			{
				char t=a[1][4];
				for(int j=1;j<=6;j++) a[j][4]=a[j+2][4];
				a[7][4]=a[8][4]=t;
			}
		}
		else 
		{
			for(int i=1;i<=8;i++,cout<<"\n") for(int j=1;j<=6;j++) cout<<a[i][j];
		}
	}
}
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

