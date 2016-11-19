#include <iostream>

using namespace std;

typedef struct tn
{
	char data;
	struct tn *lchild,*rchild;
}TreeNode,*Tree;

int LeafNum=0;

void CreatBiTree(Tree &t)
{
	char ch;
	cin>>ch;
	if ('*'==ch) t=NULL;
	else 
	{
		if (!(t=new TreeNode)) cout<<"Overflow!"<<endl;
		t->data=ch;
		CreatBiTree(t->lchild); CreatBiTree(t->rchild);
	}
}

void PrintBiTree(Tree t,int SpaceNum)
{
	for (int i=1;i<=SpaceNum;i++) cout<<" ";
	cout<<t->data<<endl;
	if (NULL!=t->lchild) PrintBiTree(t->lchild,SpaceNum+1);
	if (NULL!=t->rchild) PrintBiTree(t->rchild,SpaceNum+1);
}

void FindLeaf(Tree t)
{
	if ((NULL==t->lchild)&&(NULL==t->rchild)) LeafNum++;
	else 
	{
		if (NULL!=t->lchild) FindLeaf(t->lchild);
		if (NULL!=t->rchild) FindLeaf(t->rchild);
	}
}

void DestroyTree(Tree &t)   // 删除一个已存在的树
{
	if (NULL!=t->lchild) DestroyTree(t->lchild);
	if (NULL!=t->rchild)	DestroyTree(t->rchild);
	delete t;
}

int main(int argc, char const *argv[])
{
	Tree MyTree;
	CreatBiTree(MyTree);
	FindLeaf(MyTree);
	cout<<"The number of leaves:"<<LeafNum<<endl;
	PrintBiTree(MyTree,0);
	DestroyTree(MyTree);
	return 0;
}