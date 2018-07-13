从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。

注意：这个题的特点是返回值，和层序输出还有点不太一样


class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) //层序输出
	{
		vector<vector<int>> v;
		TreeNode* cur = NULL;
		queue<TreeNode*>  q;
		if (pRoot)//根结点不为空的话将根结点压入队列中
			q.push(pRoot);
		else
			return v;
		int i = 0;
		while (!q.empty())
		{
			int flag = 0;//核心算法在这里
			int n = q.size();//核心算法
			vector<int> s;
			while (flag++<n)
			{
				cur = q.front();//拿出队头的元素
				q.pop();
				s.push_back(cur->val);//将当前的值放入vector中  
				if (cur->left)q.push(cur->left);
				if (cur->right)q.push(cur->right);
			}
			v.push_back(s);
		}
		return v;
	}

};