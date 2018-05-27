输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

算法：

首先判断起始结点是否相等，如果相等则将proot1和proot2扔进去直接判断
如果不相等则在主树的左子树中找proot2
如果左子树没找到则去其右子树找

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
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == NULL || pRoot2 == NULL)
			return false;
		bool result = false;
		if (pRoot1->val == pRoot2->val)
			result = IsSubtree(pRoot1, pRoot2);
		if (!result)
			result = HasSubtree(pRoot1->left, pRoot2);
		if (!result)
			result = HasSubtree(pRoot1->right, pRoot2);
		return result;
	}
private:
	bool IsSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		//注意这个if语句不能反
		if (!pRoot2)//pRoot2等于null不管proot1是不是Null都是子结构
			return true;
		if (!pRoot1)
			return false;
		if (pRoot1->val == pRoot2->val)
		{
			return IsSubtree(pRoot1->left, pRoot2->left) && IsSubtree(pRoot1->right, pRoot2->right);
		}
		return false;
	}
};