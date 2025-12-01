#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;
class Person
{
	public:
		Person(string name,double score)
		{
			this->m_Name=name;
			this->m_Score=score;
		}
		string m_Name;     //姓名 
		double m_Score;    //平均分 
};

void createPerson(vector<Person>&v)
{
	string nameSeed="ABCDE";
	for(int i=0;i<5;i++)
	{
		string name="选手";
		name+=nameSeed[i];
		double score=0;
		Person p(name,score);
		v.push_back(p);
	}
}

void setScore(vector<Person>&v)
{
	for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
	{
		//将评委分数 放入到deque容器中 
		deque<int>d;
		for(int i=0;i<10;i++)
		{
			int score=rand()%41+60; //60~100
			d.push_back(score);
		}
		cout<<it->m_Name<<" 打分："<<endl; 
		for(deque<int>::iterator dit=d.begin();dit!=d.end();dit++)
		cout<<*dit<<" ";
		cout<<endl;
		//排序 
		sort(d.begin(),d.end());
		//去除最高分 最低分 
		d.pop_back();
		d.pop_front();
		//计算平均分 
		int sum=0;
		for(deque<int>::iterator dit=d.begin();dit!=d.end();dit++)
		sum+=*dit;
		it->m_Score=sum*1.0/d.size();
		cout<<"平均分: "<<it->m_Score<<endl;
	}
}
void showScore(vector<Person>&v)
{
	for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
	cout<<(*it).m_Name<<" 得分： "<<(*it).m_Score<<endl;
}
int main()
{
	//随机数种子
	srand((unsigned int)time(NULL)); 
	vector<Person>v;
	createPerson(v);
	for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
	cout<<"姓名： "<<(*it).m_Name<<"  分数： "<<(*it).m_Score<<endl;
	setScore(v);
	showScore(v);
}
