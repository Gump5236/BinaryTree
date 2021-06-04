#include<iostream>
#include<queue>
using namespace std;
typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
//构造二叉树
void CreateBiTree(BiTree *T)
{
    char ch;
    cin>>ch;
    if(ch=='#')
    *T=NULL;
    else
    {
        *T=new BiTNode;
        if(!*T)
        cout<<"Error!"<<endl;
        (*T)->data=ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}
//前序遍历
void PreOrderTraverse(BiTree T)
{
    if(T==NULL)
    return;
    cout<<T->data;
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}
//中序遍历
void InOrderTraverse(BiTree T)
{
    if(T==NULL)
    return;
    InOrderTraverse(T->lchild);
    cout<<T->data;
    InOrderTraverse(T->rchild);
}
//后序遍历
void PostOrderTraverse(BiTree T)
{
    if(T==NULL)
    return;
    InOrderTraverse(T->lchild);
    InOrderTraverse(T->rchild);
    cout<<T->data;
}
//层次遍历
void LevelOrderTraverse(BiTree T)
{
    BiTree p=T;
    queue<BiTree>Q;
    Q.push(p);
    while(!Q.empty())
    {
        p=Q.front();
        cout<<p->data;
        Q.pop();
        if(p->lchild)
        Q.push(p->lchild);
        if(p->rchild)
        Q.push(p->rchild);
    }
}
//树节点数
int CountNodes(BiTree T)
{
    if(T==NULL)
    return 0;
    return(CountNodes(T->lchild)+CountNodes(T->rchild)+1);
}
//树叶子数
int CountLeaves(BiTree T)
{
    if(T==NULL)
    return 0;
    if(!T->lchild && !T->rchild)
    return 1;
    return(CountLeaves(T->lchild)+CountLeaves(T->rchild));
}
//树的深度
int GetDepth(BiTree T)
{
    if(T==NULL)
    return 0;
    int left_depth=GetDepth(T->lchild)+1;
    int right_depth=GetDepth(T->rchild)+1;
    return left_depth>right_depth?left_depth:right_depth;
}
//二叉树第K层结点数
int GetKLevel(BiTree T,int k)
{
    if(T==NULL)
    return 0;
    if(k==1)
    return 1;
    return GetKLevel(T->lchild,k-1)+GetKLevel(T->rchild,k-1);
}
//判断两棵二叉树是否相同
bool StructureCmp(BiTree T1,BiTree T2)
{
    if(T1==NULL && T2==NULL)
    return true;
    else if (T1==NULL || T2==NULL)
    {
        return false;
    }
    return StructureCmp(T1->lchild,T2->lchild)&&StructureCmp(T1->rchild,T2->rchild);
}
//二叉树的镜像
void Mirror(BiTree T)
{
    if(T==NULL)
    return;
    BiTree temp=T->lchild;
    T->lchild=T->rchild;
    T->rchild=temp;
    Mirror(T->lchild);
    Mirror(T->rchild);
}
//两个结点最近祖先
BiTree FindLCA(BiTree T,BiTree t1,BiTree t2)
{
    if(T==NULL)
    return NULL;
    if(T==t1 || T==t2)
    return T;
    BiTree left=FindLCA(T->lchild,t1,t2);
    BiTree right=FindLCA(T->rchild,t1,t2);
    if(left && right)
    return T;
    return left?left:right;
}
//任意两点距离
int FindLevel(BiTree T, BiTree t)
{
    if (T==NULL)
    return -1;
    if (T==t)
    return 0;
    int level = FindLevel(T->lchild, t);  
    if (level == -1)
    level = FindLevel(T->rchild, t); 
    if (level != -1)
    return level + 1;
    return -1;
}
int DistanceNodes(BiTree T, BiTree t1, BiTree t2)
{
    BiTree lca = FindLCA(T,t1,t2);
    int level1 = FindLevel(lca, t1); 
    int level2 = FindLevel(lca, t2);
    return level1 + level2;
}
//某个结点所有祖先
bool FindAllAncestors(BiTree T, BiTree t)
{
    if (T==NULL)
    return false;
    if (T==t)
    return true;
    if (FindAllAncestors(T->lchild, t) || FindAllAncestors(T->rchild, t))
    {
        cout<<T->data;
        return true; 
    }
    return false; 
}
//判断是不是完全二叉树
bool IsCBT(BiTree T)
{
    bool flag = false;
    queue<BiTree>Q;
    Q.push(T);
    while (!Q.empty())
    {
        BiTree p=Q.front();
        Q.pop();
        if (flag)
        {
            if (p->lchild || p->rchild)
            return false;
        }
        else
        {
            if (p->lchild && p->rchild)
            {
                Q.push(p->lchild);
                Q.push(p->rchild);
            }
            else if (p->rchild)  
                return false;
            else if (p->lchild)   
            {
                Q.push(p->lchild);
                flag = true;
            }
            else  
            flag = true;
        }
    }
    return true;
}
