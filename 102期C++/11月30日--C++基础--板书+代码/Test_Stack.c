// C 项目
#include "../../DS/DS/Stack.h"

bool isValid(char * s){
	ST st;
	StackInit(&st);
	while (*s)
	{
		if (*s == '('
			|| *s == '{'
			|| *s == '[')
		{
			StackPush(&st, *s);
			++s;
		}
		else
		{
			// 遇到右括号了，但是栈里面没有数据，说明
			// 前面没有左括号，不匹配，返回false
			if (StackEmpty(&st))
			{
				StackDestroy(&st);
				return false;
			}

			STDataType top = StackTop(&st);
			StackPop(&st);
			if ((*s == '}' && top != '{')
				|| (*s == ']' && top != '[')
				|| (*s == ')' && top != '('))
			{
				StackDestroy(&st);
				return false;
			}
			else
			{
				++s;
			}
		}
	}

	// 如果栈不是空，说有栈中还有左括号未出
	// 没有匹配，返回是false
	bool ret = StackEmpty(&st);
	StackDestroy(&st);
	return ret;
}

int main()
{
	//cout << isValid("{[]}") << endl;
	//cout << isValid("([)]") << endl;
	printf("%d\n", isValid("{[]}"));
	printf("%d\n", isValid("([)]"));

	return 0;
}