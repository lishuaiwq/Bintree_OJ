
从上往下打印出二叉树的每个节点，同层节点从左至右打印。即二叉树的层序遍历

算法思想：采取队列，首先打印根节点，然后依次将其左子树和右子树放入队列中

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
