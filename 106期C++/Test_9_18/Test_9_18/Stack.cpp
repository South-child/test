#include "Stack.h"

namespace N1
{
	// 缺省参数不能在函数声明和定义中同时出现
	 // 注意：如果声明与定义位置同时出现，恰巧两个位置提供的值不同，那编译器就无法确定到底该用那个缺省值。
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