#include <stack>
#include <iostream>

using namespace std;

class StackElem
{
public:
	StackElem(int a,int b,int c) { rd=a; x=b; prev=c; }
	void setRd(int i) { rd=i; }
	void setX(int i) { x=i; }
	void setPrev(int i) { prev=i; }
	int getRd() { return rd; }
	int getX() { return x; }
	int getPrev() { return prev; }
private:
	int rd,x,prev;
};

int Fib(int n)
{
	int f,now=n,flag=0;
	stack<StackElem> myStack;
	while (1)
	{
		if (flag==0) 
		{
			if ()
		}
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	cout<<Fib(n)<<endl;
	return 0;
}	