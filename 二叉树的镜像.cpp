��Ŀ����
���������Ķ�����������任ΪԴ�������ľ���
�������� :
�������ľ����壺Դ������
8
/ \
6   10
/ \ / \
5  7 9 11
���������
8
/ \
10   6
/ \ / \
11 9 7  5

�㷨��

1.�����ж�����ڵ��Ƿ�Ϊ��
2.�жϸ��ڵ��Ƿ�����������ͬʱҲ�����������еĻ���ô�����ڵ��������������
3.���������������û������������ô������������ֵ��������������������ֵΪ��
4.�����������û�������������3����ʽ
5.�ݹ鵽���ڵ���������������

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
	void Mirror(TreeNode *pRoot)
	{
		if (pRoot)
		{
			if (pRoot->left&&pRoot->right)
				swap(pRoot->left, pRoot->right);
			else if (pRoot->left&&pRoot->right == NULL)
			{
				pRoot->right = pRoot->left;
				pRoot->left = NULL;
			}
			else
			{
				pRoot->left = pRoot->right;
				pRoot->right = NULL;
			}
			if (pRoot->left)
				Mirror(pRoot->left);
			if (pRoot->right)
				Mirror(pRoot->right);
		}
	}
};