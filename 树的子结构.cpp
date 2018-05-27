�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��

�㷨��

�����ж���ʼ����Ƿ���ȣ���������proot1��proot2�ӽ�ȥֱ���ж�
����������������������������proot2
���������û�ҵ���ȥ����������

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
		//ע�����if��䲻�ܷ�
		if (!pRoot2)//pRoot2����null����proot1�ǲ���Null�����ӽṹ
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