//����������һ�����

����һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�
ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ��

�㷨������㷨���������е�ɾ���Ƚ��񡣵������������������Ϊ�������������˳�����ģ����Կ��Ժ�����������


1.�����������Ϊ�գ���ȥ��������������ߵ���
2.���������Ϊ�գ����������丸��㣬����ǰ�Ľ���Ǹ������������Ļ�����ô�ͷ��ظ���㡣

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		//�ҵ�ǰ����������һ����㣬����
		//1.Ϊ���ڵ�
		//2.��Ϊ���ڵ�
		if (pNode == NULL)
			return NULL;
		TreeLinkNode* cur = NULL;
		if (pNode->right != NULL)
		{
			if (pNode->right != NULL)//Ϊ���ڵ�����������Ϊ��
			{
				cur = pNode->right;
				while (cur->left)
				{
					cur = cur->left;
				}
				return cur;
			}
		}
		TreeLinkNode* pparent = pNode->next; //�����丸�׽��
		while (pparent != NULL)
		{
			if (pparent->left == pNode)
				return pparent;
			pNode = pparent;//
			pparent = pNode->next;
		}
		return NULL;
	}
};