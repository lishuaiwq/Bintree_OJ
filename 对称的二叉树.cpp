��ʵ��һ�������������ж�һ�Ŷ������ǲ��ǶԳƵġ�
ע�⣬���һ��������ͬ�˶������ľ�����ͬ���ģ�������Ϊ�ԳƵġ�

�㷨��������ڵ�Ϊ�յĻ������ǶԳƵķ���true��Ȼ���ж����������������Ƿ���ȡ���������ȥ���

�ܵ����������ж��������������������������������Ƿ���ȣ����������������������������������������Ƿ���ȣ�

�ݹ飺
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

�ǵݹ�
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
			cur1 = q1.front();//������
			q1.pop();
			cur2 = q2.front();//������
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





