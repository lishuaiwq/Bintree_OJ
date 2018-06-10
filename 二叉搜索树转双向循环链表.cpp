将二叉搜索树转换为双向循环链表

算法：使用二叉树的中序遍历序列，设置一个标志位指向当前位置的上一个结点，这里假设为pre，我们就可以将if(pre)
{
	(*pre)->right = pRoot;
}
pRoot->left = *pre;
pre = Proot;

//上面这是算法的核心代码,然后就是将上述代码插入的二叉树的中序遍历代码中去

代码：递归版本

/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == NULL)
			return NULL;
		TreeNode* pre = NULL;
		Trans(pRootOfTree, &pre);//因为只是改变指针内部的next不改变指针自身的内容，所以不需要传
		while (pRootOfTree->left)
		{
			pRootOfTree = pRootOfTree->left;
		}
		return pRootOfTree;
	}
	void Trans(TreeNode* pRoot, TreeNode** prev)
	{
		if (pRoot)
		{
			//if(pRoot->left!=NULL)
			Trans(pRoot->left, &(*prev));
			if (*prev)//prev不等于Null
			{
				(*prev)->right = pRoot;
			}
			pRoot->left = *prev;
			*prev = pRoot;
			//   if(pRoot->right!=NULL)
			Trans(pRoot->right, &(*prev));
		}
	}
};

代码：非递归的版本

主要是二叉树的中序非递归遍历

使用栈将根结点和左子全部压入栈中，while(cur){ s.push(cur);cur=cur->next }然后将元素弹出，判断是否有右子树，如果有的话，则让cur=cur->right否则让cur=NULL,

上述是二叉树的中序遍历非递归的核心代码，只需要将上述的核心代码插进去的就可以了

/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == NULL)
			return NULL;
		stack<TreeNode*> s;
		TreeNode* cur = pRootOfTree;
		TreeNode* prev = NULL;
		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->left;
			}
			cur = s.top();
			if (prev)
			{
				prev->right = cur;
			}
			cur->left = prev;
			prev = cur;
			s.pop();
			if (cur->right)
			{
				cur = cur->right;
			}
			else
			{
				cur = NULL;
			}
		}
		while (pRootOfTree->left != NULL)
		{
			pRootOfTree = pRootOfTree->left;
		}
		return pRootOfTree;
	}
};