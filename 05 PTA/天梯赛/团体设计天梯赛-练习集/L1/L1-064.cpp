#include<bits/stdc++.h>
using namespace std;
string str; 
string s1="can you",s11="I can";
string s2="could you",s22="I could";
string s31="I",s32="me",s33="yoU";
 
//isletter函数用来判断当前字符是否为字母，1代表为字母 
int isletter(char ch){
	if(ch>='A'&&ch<='Z'||ch>='a'&&ch<='z') return 1;
	return 0;
}
void solve()
{ 
	int N;cin>>N;getchar();
	for(int i=0;i<N;++i){
		getline(cin,str); 
		cout<<str<<endl;
		str=" "+str;
		//大写转小写 并格式化语句 
		for(int i=0;i<str.length();++i){
			if(str[i]==' '&&!isletter(str[i+1])&&!isdigit(str[i+1])){
				 str.erase(i,1);
				 i--;
			}
			if(str[i]>='A'&&str[i]<='Z'&&str[i]!='I') str[i]+=32;
			if(str[i]=='?'){
				 str[i]='!';
			}
		}
		//独立的 I 换成 you 	string s31="I",s32="me",s33="you";
		for(int i=0;i<str.length();++i){
			i=str.find(s31,i);
			if(i==-1) break;
			if(!(isletter(str[i-1])||isletter(str[i+s31.length()]))){
				str.replace(i,s31.length(),s33);
			}
		}
		//	cout<<"str换前:"+str<<"---------"<<endl; 
		//独立的 me 换成 you 	string s31="I",s32="me",s33="you";
		for(int i=0;i<str.length();++i){
			i=str.find(s32,i);
			if(i==-1) break;
			if(!(isletter(str[i-1])||isletter(str[i+s32.length()]))){
				str.replace(i,s32.length(),s33);
			}
		}
	//	cout<<"str换后:"+str<<"---------"<<endl; 
		// can you 换成 I can  		string s1="can you",s11="I can";
		for(int i=0;i<str.length();++i){
			i=str.find(s1,i);
			if(i==-1) break;
			if(!(isletter(str[i-1])||isletter(str[i+s1.length()]))){
				str.replace(i,s1.length(),s11); 
			}
		}
		// could you 换成 I could  		string s2="could you",s22="I could";
		for(int i=0;i<str.length();++i){
			i=str.find(s2,i);
			if(i==-1) break;
			if(!(isletter(str[i-1])||isletter(str[i+s2.length()]))){
				str.replace(i,s2.length(),s22);
			}
		}
		for(int i=0;i<str.length();++i){
			if(str[i]=='U') str[i]='u';
		}
		if(str[0]!=' ') str=" "+str; 
		cout<<"AI:"+str+"\n";
	}
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

