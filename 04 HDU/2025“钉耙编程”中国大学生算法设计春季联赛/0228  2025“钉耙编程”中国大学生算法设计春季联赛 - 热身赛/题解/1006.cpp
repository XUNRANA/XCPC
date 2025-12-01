#include<bits/stdc++.h>
using namespace std;
template<class code>inline code read(const code &a){
	code x=0;bool fg=0;
	char c=getchar();
	while(!isdigit(c)){
		fg|=(c=='-');
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+(c-'0');
		c=getchar();
	}
	return fg?-x:x;
}
char s[200005];
int bj[200005],s1[200005][26],s2[200005][26];
long long jl1[200005],jl2[200005],sum1,sum2;
int check(int wz,char xg){
	long long p1=sum1,p2=sum2;
	if(s[wz]=='Y')p1-=jl2[wz+1];
	else if(s[wz]=='E')p1-=1ll*s1[wz-1]['Y'-'A']*s2[wz+1]['S'-'A'];
	else if(s[wz]=='S')p1-=jl1[wz-1];
	else if(s[wz]=='N')p2-=s2[wz+1]['O'-'A'];
	else if(s[wz]=='O')p2-=s1[wz-1]['N'-'A'];
	if(xg=='Y')p1+=jl2[wz+1];
	else if(xg=='E')p1+=1ll*s1[wz-1]['Y'-'A']*s2[wz+1]['S'-'A'];
	else if(xg=='S')p1+=jl1[wz-1];
	else if(xg=='N')p2+=s2[wz+1]['O'-'A'];
	else if(xg=='O')p2+=s1[wz-1]['N'-'A'];
	if(p1==p2)return 0;
	else if(p1>p2)return 1;
	return 2;
}
void solve(){
	scanf("%s",s+1);
	int l=strlen(s+1);
	sum1=0,sum2=0;
	for(int i=1;i<=l;i++){
		for(int j=0;j<26;j++)s1[i][j]=s1[i-1][j];
		s1[i][s[i]-'A']++;
	}
	memset(s2[l+1],0,sizeof(s2[l+1]));
	for(int i=l;i>=1;i--){
		for(int j=0;j<26;j++)s2[i][j]=s2[i+1][j];
		s2[i][s[i]-'A']++;
	}
	for(int i=1;i<=l;i++){
		jl1[i]=jl1[i-1];
		if(s[i]=='O')sum2+=s1[i-1]['N'-'A'];
		else if(s[i]=='E')sum1+=1ll*s1[i-1]['Y'-'A']*s2[i+1]['S'-'A'],jl1[i]+=s1[i-1]['Y'-'A'];
	}
	jl2[l+1]=0;
	for(int i=l;i>=1;i--){
		jl2[i]=jl2[i+1];
		if(s[i]=='E')jl2[i]+=s2[i+1]['S'-'A']; 
	}
	printf("%lld %lld\n",sum1,sum2);
	if(sum1==sum2){
		puts("DUI DUI DUIMA");
		return;
	}
	if(sum1<sum2){
		for(int i=1;i<=l;i++){
			int fg=(check(i,'Y')==1)||(check(i,'E')==1)||(check(i,'S')==1);
			if(fg){
				puts("O DUI DE");
				return;
			}
		}
	}else{
		for(int i=1;i<=l;i++){
			int fg=(check(i,'N')==2)||(check(i,'O')==2);
			if(fg){
				puts("O BUDUI BUDUI");
				return;
			}
		}
	}
	if(sum1<sum2)puts("BUDUI BUDUI");
	else puts("DUI DE");
}
int main(){
//	freopen("text.out","w",stdout);
	int t=read(t);
	while(t--)solve();
	return 0;
} 
