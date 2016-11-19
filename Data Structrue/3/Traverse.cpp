#include <iostream>
#define MaxV 1000

using namespace std;

typedef struct tn
{
	int data;
	struct tn *lchild,*rchild;
}TreeNode,*Tree;

int PreOrder[MaxV],InOrder[MaxV],pos[MaxV],v;  //前两个数组储存遍历结果，v表示节点个数

void InitOrder()
{
	cin>>v;
	for (int i=1;i<=v;i++) cin>>PreOrder[i];
	for (int i=1;i<=v;i++)
	{
		cin>>InOrder[i];
		pos[InOrder[i]]=i;   //记录节点 i 在中序遍历中的下标
	}
}

void CreatBiTree(Tree &t, int PreLeft, int PreRight, int InLeft, int InRight)
{
	int i=PreOrder[PreLeft];
	if (!(t=new TreeNode)) cerr<<"Overflow!!"<<endl;
	t->data=i;
	int LeftSize=pos[i]-InLeft, RightSize=InRight-pos[i];      //LeftSize表示左子树的节点数目
	if (LeftSize>0)  CreatBiTree(t->lchild, PreLeft+1, PreLeft+LeftSize, InLeft, pos[i]-1);      //pos[i]表示节点 i 在中序遍历中的下标
	if (RightSize>0) CreatBiTree(t->rchild, PreLeft+LeftSize+1, PreRight, pos[i]+1, InRight);
}

void PrintBiTree(Tree t, int SpaceNum)  //用凹入表输出树
{
	for (int i=1;i<=SpaceNum;i++) cout<<" ";  
	cout<<t->data<<endl;
	if (NULL!=t->lchild) PrintBiTree(t->lchild,SpaceNum+1);
	if (NULL!=t->rchild) PrintBiTree(t->rchild,SpaceNum+1);
}

void DestroyTree(Tree &t)    // 删除一个已存在的树
{
	if (NULL!=t->lchild) DestroyTree(t->lchild);
	if (NULL!=t->rchild)	DestroyTree(t->rchild);
	delete t;
}

int main(int argc, char const *argv[])
{
	Tree MyTree;
	InitOrder();
	CreatBiTree(MyTree,1,v,1,v);
	PrintBiTree(MyTree,0);
	DestroyTree(MyTree);
	return 0;
}

