#include <iostream>
#include <string>
#define MaxLen 1000

using namespace std;

void getNext(string &t,int next[])
{
	int i=0,k=-1;
	next[i]=k;
	while (i<t.length())
	{
		if (k==-1||t[i]==t[k])
		{
			i++; k++;
			next[i]=k;
		}
		else k=next[k];
	}
}

void getNext2(string &t,int next[])
{
	int i=0,k=-1;
	next[i]=k;
	while (i<t.length())
	{
		if (k==-1||t[i]==t[k])
		{
			i++; k++;
			if (t[i]!=t[k]) next[i]=k;
			else next[i]=next[k];
		}
		else k=next[k];
	}
}

int KMP(string &s,string &t)
{
	int next[MaxLen]={},i=0,j=0;
	getNext(t,next);
	for (int i=0;i<t.length();i++) cout<<next[i]+1<<' ';
	cout<<endl;
	getNext2(t,next);
	for (int i=0;i<t.length();i++) cout<<next[i]+1<<' ';
	cout<<endl;
	while (i<(int)s.length()&&j<(int)t.length())
	{
		if (j==-1||s[i]==t[j])
		{
			i++; j++; 
		}
		else j=next[j];
	}
	if (j>=t.length()) return(i-t.length()+2);
	else return 0;
}

int main(int argc, char const *argv[])
{
	string s="aabaaaba";
	return 0;
}