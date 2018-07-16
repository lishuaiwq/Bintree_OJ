请实现一个函数，用来判断一颗二叉树是不是对称的。
注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。

算法：如果根节点为空的话，则是对称的返回true，然后判断左子树很右子树是否相等。给出代码去理解

总的来看就是判断左子树的左子树和右子树的左子树是否相等，右子树的右子树和左子树的左子树的左子树是否相等！

递归：
class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (pRoot == NULL)
			return true;
		return isSymmetrical(pRoot->left, pRoot->right);
	}
	bool isSymmetrical(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == NULL&&pRoot2 == NULL)
			return true;
		if (pRoot1 == NULL || pRoot2 == NULL)
			return false;
		if (pRoot1->val != pRoot2->val)
			return false;
		return isSymmetrical(pRoot1->left, pRoot2->right) && isSymmetrical(pRoot1->right, pRoot2->left);
	}
};

非递归
class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (pRoot == NULL)
			return true;
		queue<TreeNode*> q1;
		queue<TreeNode*> q2;
		TreeNode* cur1 = NULL;
		TreeNode* cur2 = NULL;
		q1.push(pRoot->left);
		q2.push(pRoot->right);
		while (!q1.empty() && !q2.empty())
		{
			cur1 = q1.front();//左子树
			q1.pop();
			cur2 = q2.front();//右子树
			q2.pop();
			if (cur1 == NULL&&cur2 == NULL)
				continue;
			if (cur1 == NULL || cur2 == NULL)
				return false;
			if (cur1->val != cur2->val)
				return false;
			q1.push(cur1->left);
			q1.push(cur1->right);
			q2.push(cur2->right);
			q2.push(cur2->left);
		}
		return true;
	}

};





