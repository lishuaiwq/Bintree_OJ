����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��������������Yes, �������No���������������������������ֶ�������ͬ��

�㷨��

//��Ϊ�������������ĺ����������������
//�����һ��һ��Ϊ���ڵ㣬���������������е�Ԫ�ض��󣬵��Ǳ������е�������Ԫ�ض���
//�������Ǵ���ʼԪ��������sequence[i++] < sequence[size],��ǰ���������ҵ���һ���ȸ��ڵ���Ԫ�صĻ�����ζ�ŵ����������ˣ�
//���Դ�ʱ��������Ӧ�ö������while (sequence[i++]>sequence[size]);������ߵ�ͷӦ��i=size�����Լ����Լ���
//���i<size������֤�������Ϻ���������˳��
//�����Դ����ƣ��������е����
class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		int size = sequence.size();
		if (0 == size)
			return false;
		int i = 0;
		while (--size)
		{
			while (sequence[i++] < sequence[size]);
			while (sequence[i++]>sequence[size]);

			if (i < size)
				return false;
			i = 0;
		}
		return true;
	}
};