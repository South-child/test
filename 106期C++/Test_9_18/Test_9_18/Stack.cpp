#include "Stack.h"

namespace N1
{
	// ȱʡ���������ں��������Ͷ�����ͬʱ����
	 // ע�⣺��������붨��λ��ͬʱ���֣�ǡ������λ���ṩ��ֵ��ͬ���Ǳ��������޷�ȷ�����׸����Ǹ�ȱʡֵ��
	void StackInit(ST* ps, int defaultCP)
	{
		ps->a = (int*)malloc(sizeof(int) * defaultCP);
		assert(ps->a);
		ps->top = 0;
		ps->capacity = defaultCP;
	}

	void StackPush(ST* ps, int x)
	{}
}