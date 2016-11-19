#include <iostream>
#define MaxN 100

using namespace std;

class QueueElem
{
	public:
		QueueElem() { data=0; next=NULL; }
		QueueElem(int x) { data=x; next=NULL; }
		int getData() const { return data; }
		QueueElem *getNext() const { return next; } 
		void setData(const int x) { data=x; }
		void setNext(QueueElem* q) { next=q; }
	private:
		int data;
		QueueElem *next;
};

void ClearQueue(QueueElem * const rear)
{
	QueueElem *iptr=rear,*jptr=rear->getNext();
	while (NULL!=iptr)
	{
		delete iptr;
		iptr=jptr;
		if (NULL!=jptr) jptr=jptr->getNext();
	}
}

bool QueueEmpty(const QueueElem * const rear)
{
	if (rear->getNext()==rear) return 1;
	else return 0;
}

void EnQueue(QueueElem * const rear,QueueElem *&p)
{
	if (QueueEmpty(rear))
	{
		int x=p->getData();
		p->setData(0);
		p->setNext(rear);
		rear->setData(x);
		rear->setNext(p);
	}
	else 
	{
		QueueElem *iptr=rear->getNext(),*jptr=iptr->getNext();
		iptr->setNext(p);
		p->setNext(jptr);	
	}
}

void DeQueue(QueueElem *&rear)  //the premise of use it is nonempty
{
	if (QueueEmpty(rear)) 
	{
		cout<<"Overflow!!"<<endl;
		return;
	}
	QueueElem *iptr=rear->getNext();     //prevptr should be the head pointer.
	while (iptr->getNext()!=rear) iptr=iptr->getNext();
	iptr->setNext(rear->getNext());
	delete rear;
	rear=iptr;
}

void PrintQueue(const QueueElem * const rear)
{
	QueueElem *iptr=(rear->getNext())->getNext();
	cout<<"The current queue is:";
	while (iptr->getData()) 
	{
		cout<<iptr->getData()<<' ';
		iptr=iptr->getNext();		
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	const int a[5]={5,7,3,8,55};
	QueueElem *rear=new QueueElem(0),*subrear;
	rear->setNext(rear);
	for (int i=0;i<5;i++)
	{
		QueueElem *x=new QueueElem(a[i]);
		EnQueue(rear,x);
	}
	PrintQueue(rear);
	for (int i=0;i<2;i++)
		DeQueue(rear);
	PrintQueue(rear);
	for (int i=0;i<3;i++)
		DeQueue(rear);
	PrintQueue(rear);
	DeQueue(rear);
	PrintQueue(rear);
	return 0;
}