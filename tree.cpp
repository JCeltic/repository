#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

//C++语言下的树型数据结构
typedef struct Node
{
    char data; //事出紧急，没用模板搞数据
    struct Node* left;//左子树
    struct Node* right;//右子树
} BTree;





//访问节点操作
void visit(BTree* p)
{
    std::cout<<p->data;
}
 //先序遍历递归
void preorder(BTree* bt)
{
    if(bt!=NULL)
    {
        visit(bt);
        preorder(bt->left);
        preorder(bt->right);
    }
}

//中序遍历递归
void inorder(BTree* bt)
{
    if(bt!=NULL)
    {
        inorder(bt->left);
        visit(bt);
        inorder(bt->right);
    }
}

//后序遍历递归
void postorder(BTree* bt)
{
    if(bt!=NULL)
    {
        postorder(bt->left);
        postorder(bt->right);
        visit(bt);
    }
}

//求树高的算法递归
int getDepth(BTree* bt)
{
    //分别求出左右子树的高度，并取其中的最大值，然后加一即为树高
    int LD,RD;
    //默认空树树高为零
    if(bt==NULL) return 0;
    LD=getDepth(bt->left);
    RD=getDepth(bt->right);
    return LD>RD?LD:RD;
}

//遍历的非递归形式
void pre(BTree *bt)
{
    stack<BTree*> s;
    BTree* p=bt;
    while (p||!s.empty())
    {
        if(p)
        {
            visit(p);
            s.push(p);
            p=p->left;
        }
        else
        {
            p=s.top();
            s.pop();
            p=p->right;
        }   
    }
}


void inorder(BTree* bt)
{
    stack<BTree *> s;
    BTree* p=bt;
    if(p||!s.empty())
    {
        s.push(p);
        p->left;

    }else
    {
        p=s.top();
        s.pop();
        visit(p);
        p=p->right;
    }
    
}

void postorder(BTree *bt)
{
    stack<BTree*> s;
    BTree* r;BTree* p=bt;
    while (p||!s.empty())
    {
        if(p)
        {
            s.push(p);
            p=p->left;
        }
        else
        {
            p=s.top();
            if(p->right&&p->right!=r)
            {
                p=p->right;
                s.push(p);
                p=p->left;
            }
            else
            {
                p=s.top();
                s.pop();
                visit(p);
                r=p;

            }
        }
        
    }
    
}

//树的层序遍历
void Levelorder(BTree* bt)
{
    queue<BTree*> q;
    q.push(bt);
    while (!q.empty())
    {
        bt=q.front();
        visit(bt);
        if(bt->left) q.push(bt->left);
        if(bt->right) q.push(bt->right);
    }
    
}
//非递归求树高的算法
int getDepth2(BTree* bt)
{
    int front=-1,rear=-1,level=0;
    int last = rear;
    if(bt==NULL) return level;
    vector<BTree*> q;
    q[++rear]=bt;
    while (front<rear)
    {
        bt=q[++front];
        if(bt->left) q[++rear]=bt->left;
        if(bt->right) q[++rear]=bt->right;
        if(front==last)
        {
            level++;
            last=rear;
        }
    }
    return level;
}



