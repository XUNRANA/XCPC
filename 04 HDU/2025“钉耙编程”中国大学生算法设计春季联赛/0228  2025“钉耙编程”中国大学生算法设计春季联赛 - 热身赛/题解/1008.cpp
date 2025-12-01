#include<bits/stdc++.h>
using namespace std;
char s[1005];
void solve(){
	int n;
	scanf("%d",&n);
	int s1=0,s2=0,s3=0;
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		if(s[0]=='A'&&s[1]=='u')++s1;
		else if(s[0]=='A'&&s[1]=='g')++s2;
		else if(s[0]=='C'&&s[1]=='u')++s3;
	}
	printf("%d\n",s1+min(s2,s3));
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
} 
