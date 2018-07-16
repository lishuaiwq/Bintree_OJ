//二叉树的下一个结点

给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针

算法：这个算法和搜索树中的删除比较像。但是在这里更好做，因为按照中序遍历的顺序来的，所以可以忽略左子树。


1.如果右子树不为空，则去右子树找其最左边的树
2.如果右子树为空，则依次找其父结点，当当前的结点是父结点的左子树的话，那么就返回父结点。

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		//找当前结点中序的下一个结点，不难
		//1.为根节点
		//2.不为根节点
		if (pNode == NULL)
			return NULL;
		TreeLinkNode* cur = NULL;
		if (pNode->right != NULL)
		{
			if (pNode->right != NULL)//为根节点且右子树不为空
			{
				cur = pNode->right;
				while (cur->left)
				{
					cur = cur->left;
				}
				return cur;
			}
		}
		TreeLinkNode* pparent = pNode->next; //等于其父亲结点
		while (pparent != NULL)
		{
			if (pparent->left == pNode)
				return pparent;
			pNode = pparent;//
			pparent = pNode->next;
		}
		return NULL;
	}
};