题目描述
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{ 1, 2, 4, 7, 3, 5, 6, 8 }和中序遍历序列{ 4, 7, 2, 1, 5, 3, 8, 6 }，则重建二叉树并返回。


算法：

前序序列可以确定二叉树的根结点，结合中序遍历顺序。可以缺点出根节点的左子树和右子树的前序遍历和中序遍历序列

举个例子：上题中前序为1，那么根结点为1，在参考中序顺序，可以得出左子树为4 7 2 右子树为5 3 8 6
那么左子树的前序序列就是2 4 7 中序为4 7 2 右子树的前序序列为3 5 6 8，中序序列为5 3 8 6

下面给出代码

/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		size_t len = vin.size();
		if (len == 0)
			return NULL;
		TreeNode* head = new TreeNode(pre[0]);//创建根节点
		vector<int> left_pre, left_in, right_pre, right_in;
		int index = 0;
		for (int i = 0; i<len; ++i)
		{
			if (pre[0] == vin[i])
			{
				index = i;//记录根节点在中序遍历中的位置
				break;
			}
		}
		for (int i = 0; i<index; i++)//找根结点左子树的前序和中序
		{
			left_pre.push_back(pre[i + 1]);//前序
			left_in.push_back(vin[0]);//中序
		}
		for (int i = index + 1; i<len; i++)
		{
			right_pre.push_back(pre[i]);
			right_in.push_back(vin[i]);
		}
		head->left = reConstructBinaryTree(left_pre, left_in);
		head->right = reConstructBinaryTree(right_pre, right_in);
		return head;
	}
};