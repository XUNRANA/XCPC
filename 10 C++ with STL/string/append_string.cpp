#include <iostream>
#include <string>
using namespace std;
void pingjie_string()
{
	string str1="我";
	str1+="爱玩游戏";        //加字符串 
	cout<<str1<<endl;
	str1+=':';               //加一个字符 
	cout<<str1<<endl;
	
	string str2=" LOL DNF";
	str1+=str2;
	cout<<str1<<endl;
	
	string str3="I";
	str3.append(" love");
	str3.append(" you",2);//2表示取[0,2) 可写成 (" you",0,2)
	cout<<str3<<endl;
	
	str3.append("o");
	str3.append("u");     //不能写出'u'  
	cout<<str3<<endl;
	//str3=I love you
	str3.append(str2,4,7);//截取下标[4,7] 一个参数是变量 则必须有三个参数 
	cout<<str3<<endl; 
}
int main()
{
	pingjie_string();
}
