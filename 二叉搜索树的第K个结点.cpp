����һ�Ŷ��������������ҳ����еĵ�kС�Ľ�㡣���磬 5 / \ 3 7 / \ / \ 2 4 6 8 �У��������ֵ��С�����������ֵΪ4��

�������������˼�룬������������������������Ԫ�ز��뵽vector�У���Ϊ�����������˳��ģ�������
vector��Ҳ������ģ�����ֻҪ����v[k - 1]�Ϳ����ˣ�����֮ǰ����Ҫ�ж�if(k > v.size());

class Solution {
public:
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		if (pRoot == NULL || k <= 0)
		{
			return NULL;
		}
		vector<TreeNode*> s;
		InOrder(pRoot, s);
		if (k>s.size())
		{
			return NULL;
		}
		return s[k - 1];
	}
	void InOrder(TreeNode* pRoot, vector<TreeNode*>& v)
	{
		if (pRoot)
		{
			InOrder(pRoot->left, v);
			v.push_back(pRoot);
			InOrder(pRoot->right, v);
		}
	}
};