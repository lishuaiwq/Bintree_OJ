���ϵ��°����ӡ��������ͬһ����������������ÿһ�����һ�С�

ע�⣺�������ص��Ƿ���ֵ���Ͳ���������е㲻̫һ��


class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) //�������
	{
		vector<vector<int>> v;
		TreeNode* cur = NULL;
		queue<TreeNode*>  q;
		if (pRoot)//����㲻Ϊ�յĻ��������ѹ�������
			q.push(pRoot);
		else
			return v;
		int i = 0;
		while (!q.empty())
		{
			int flag = 0;//�����㷨������
			int n = q.size();//�����㷨
			vector<int> s;
			while (flag++<n)
			{
				cur = q.front();//�ó���ͷ��Ԫ��
				q.pop();
				s.push_back(cur->val);//����ǰ��ֵ����vector��  
				if (cur->left)q.push(cur->left);
				if (cur->right)q.push(cur->right);
			}
			v.push_back(s);
		}
		return v;
	}

};