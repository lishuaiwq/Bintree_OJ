
�������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ�����������Ĳ������

�㷨˼�룺��ȡ���У����ȴ�ӡ���ڵ㣬Ȼ�����ν��������������������������

void PrintFromTopToBottom()
{
	PNode cur = _pRoot;
	queue<PNode> q;
	cout << cur->_data << " ";
	q.push(cur->_left);
	q.push(cur->_right);
	while (!q.empty())
	{
		cur = q.front();
		cout << cur->_data << " ";
		q.pop();
		if (cur->_left)
			q.push(cur->_left);
		if (cur->_right)
			q.push(cur->_right);
	}
}
