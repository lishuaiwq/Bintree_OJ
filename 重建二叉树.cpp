��Ŀ����
����ĳ��������ǰ���������������Ľ�������ؽ����ö����������������ǰ���������������Ľ���ж������ظ������֡���������ǰ���������{ 1, 2, 4, 7, 3, 5, 6, 8 }�������������{ 4, 7, 2, 1, 5, 3, 8, 6 }�����ؽ������������ء�


�㷨��

ǰ�����п���ȷ���������ĸ���㣬����������˳�򡣿���ȱ������ڵ������������������ǰ������������������

�ٸ����ӣ�������ǰ��Ϊ1����ô�����Ϊ1���ڲο�����˳�򣬿��Եó�������Ϊ4 7 2 ������Ϊ5 3 8 6
��ô��������ǰ�����о���2 4 7 ����Ϊ4 7 2 ��������ǰ������Ϊ3 5 6 8����������Ϊ5 3 8 6

�����������

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
		TreeNode* head = new TreeNode(pre[0]);//�������ڵ�
		vector<int> left_pre, left_in, right_pre, right_in;
		int index = 0;
		for (int i = 0; i<len; ++i)
		{
			if (pre[0] == vin[i])
			{
				index = i;//��¼���ڵ�����������е�λ��
				break;
			}
		}
		for (int i = 0; i<index; i++)//�Ҹ������������ǰ�������
		{
			left_pre.push_back(pre[i + 1]);//ǰ��
			left_in.push_back(vin[0]);//����
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