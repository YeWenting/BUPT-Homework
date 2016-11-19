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
	StackElem now(0,n,0);
	int f,where;
	stack<StackElem> myStack;
	zero:if (1>=now.getX()) f=now.getX();
	else 
	{
		cout<<now.getX()<<endl;
		now.setRd(1);
		myStack.push(now);
		now.setX(now.getX()-1);
		goto zero;
		first:myStack.top().setPrev(f);
		myStack.top().setRd(2);
		now.setX(now.getX()-2);
		goto zero;
		second:f+=myStack.top().getPrev();
		if (now.getX()==n) return (f);
	}
	if (!myStack.empty())
	{
		cout<<"x: "<<now.getX()<<" where:"<<now.getRd()<<"here are we!"<<endl;
		now=myStack.top();
		where=now.getRd();
		myStack.pop();
		if (now.getX()==0) cout<<2132<<endl;
		if (1==where) goto first;
			else if (2==where) goto second;
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	cout<<Fib(n)<<endl;
	return 0;
}	