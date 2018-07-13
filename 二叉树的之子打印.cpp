请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。

算法1：这个问题和把二叉树打印成多行的算法是一样的，只不过需要加一个标志位来判断是奇数行还是偶数行
，第一行为奇数行，郑旭压进去就行了，如果是偶数行，则需要使用reverse()这个函数了，但是此算法的效率太低了，所以针对大量的数据就行不通了
下面给出算法代码：

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
		bool cgi = false;//奇数
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
			if (cgi == true)//偶数行
				reverse(s.begin(), s.end());
			v.push_back(s);
			cgi = !cgi;
		}
		return v;
	}
};

//优化后的方法核心思想是不使用reverse将整个vector逆置了，而是逆序遍历它就可以了。！