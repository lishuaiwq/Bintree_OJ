��ʵ��һ����������֮���δ�ӡ������������һ�а��մ����ҵ�˳���ӡ���ڶ��㰴�մ��������˳���ӡ�������а��մ����ҵ�˳���ӡ���������Դ����ơ�

�㷨1���������ͰѶ�������ӡ�ɶ��е��㷨��һ���ģ�ֻ������Ҫ��һ����־λ���ж��������л���ż����
����һ��Ϊ�����У�֣��ѹ��ȥ�����ˣ������ż���У�����Ҫʹ��reverse()��������ˣ����Ǵ��㷨��Ч��̫���ˣ�������Դ��������ݾ��в�ͨ��
��������㷨���룺

class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int>> v;
		queue<TreeNode*> q;
		TreeNode* cur = NULL;
		if (pRoot)
			q.push(pRoot);
		else
			return v;
		bool cgi = false;//����
		while (!q.empty())
		{
			int flag = 0;
			int n = q.size();
			vector<int> s;
			while (flag++<n)
			{
				cur = q.front();
				q.pop();
				s.push_back(cur->val);
				if (cur->left)q.push(cur->left);
				if (cur->right)q.push(cur->right);
			}
			if (cgi == true)//ż����
				reverse(s.begin(), s.end());
			v.push_back(s);
			cgi = !cgi;
		}
		return v;
	}
};

//�Ż���ķ�������˼���ǲ�ʹ��reverse������vector�����ˣ���������������Ϳ����ˡ���