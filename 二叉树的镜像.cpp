题目描述
操作给定的二叉树，将其变换为源二叉树的镜像。
输入描述 :
二叉树的镜像定义：源二叉树
8
/ \
6   10
/ \ / \
5  7 9 11
镜像二叉树
8
/ \
10   6
/ \ / \
11 9 7  5

算法：

1.首先判断其根节点是否为空
2.判断根节点是否有左子树的同时也有右子树，有的话那么将根节点的左右子树交换
3.如果根有左子树，没有右子树，那么将其右子树赋值给左子树，将左子树赋值为空
4.如果有右子树没有左子树，则和3处理方式
5.递归到根节点左子树和右子树

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
	void Mirror(TreeNode *pRoot)
	{
		if (pRoot)
		{
			if (pRoot->left&&pRoot->right)
				swap(pRoot->left, pRoot->right);
			else if (pRoot->left&&pRoot->right == NULL)
			{
				pRoot->right = pRoot->left;
				pRoot->left = NULL;
			}
			else
			{
				pRoot->left = pRoot->right;
				pRoot->right = NULL;
			}
			if (pRoot->left)
				Mirror(pRoot->left);
			if (pRoot->right)
				Mirror(pRoot->right);
		}
	}
};