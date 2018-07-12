给定一颗二叉搜索树，请找出其中的第k小的结点。例如， 5 / \ 3 7 / \ / \ 2 4 6 8 中，按结点数值大小序第三个结点的值为4。

采用中序遍历的思想，遍历整个二叉搜索树，将其元素插入到vector中，因为其中序遍历是顺序的，所以在
vector中也是有序的，所以只要范湖v[k - 1]就可以了，在这之前还需要判断if(k > v.size());

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