#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
//
//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//
//	printf("%d\n", strlen(arr));//���ֵ
//	printf("%d\n", strlen(arr + 0));//���ֵ
//	//printf("%d\n", strlen(*arr));//*arr - 'a' - 97 - err
//	//strlen����Ϊ��������'a'��ascii��ֵ97���ǵ�ַ
//	//printf("%d\n", strlen(arr[1]));//'b' - 98 - err
//
//	printf("%d\n", strlen(&arr));//���ֵ
//	//char(*)[6]
//	//char*
//	printf("%d\n", strlen(&arr + 1));//���ֵ
//	printf("%d\n", strlen(&arr[0] + 1));//���ֵ
//
//	//printf("%d\n", sizeof(arr));
//	//printf("%d\n", sizeof(arr + 0));
//	//printf("%d\n", sizeof(*arr));
//	//printf("%d\n", sizeof(arr[1]));
//	//printf("%d\n", sizeof(&arr));
//	//printf("%d\n", sizeof(&arr + 1));
//	//printf("%d\n", sizeof(&arr[0] + 1));
//
//	return 0;
//}
//
//
//
//int main()
//{
//	//char arr1[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; //6
//	//[a b c d e f]
//
//	char arr[] = "abcdef";//7
//	//[a b c d e f \0]
//
//	printf("%d\n", strlen(arr));//6
//	printf("%d\n", strlen(arr + 0));//6
//	//printf("%d\n", strlen(*arr));//err
//	//printf("%d\n", strlen(arr[1]));//err
//
//	printf("%d\n", strlen(&arr));//6
//	printf("%d\n", strlen(&arr + 1));//���ֵ
//	printf("%d\n", strlen(&arr[0] + 1));//5
//
//
//	//printf("%d\n", sizeof(arr));//7 �ֽ�
//	//printf("%d\n", sizeof(arr + 0));//arr����Ԫ�صĵ�ַ 4/8
//	//printf("%d\n", sizeof(*arr));//arr����Ԫ�صĵ�ַ,*arr������Ԫ�� 1
//	//printf("%d\n", sizeof(arr[1]));//arr[1]���ǵڶ���Ԫ��  1
//	//printf("%d\n", sizeof(&arr));//&arr ������ĵ�ַ������ĵ�ַҲ�ǵ�ַ������4/8�ֽ�
//	//printf("%d\n", sizeof(&arr + 1));//&arr ������ĵ�ַ,&arr+1 ���������������ĵ�ַ 4/8
//	//printf("%d\n", sizeof(&arr[0] + 1));//&arr[0] + 1 �ǵڶ���Ԫ�صĵ�ַ��4/8
//
//	return 0;
//}
//
//int main()
//{
//	const char* p = "abcdef";
//
//	printf("%d\n", strlen(p));//6
//	printf("%d\n", strlen(p + 1));//5
//	//printf("%d\n", strlen(*p));//err
//	//printf("%d\n", strlen(p[0]));//err
//	printf("%d\n", strlen(&p));//���ֵ
//	printf("%d\n", strlen(&p + 1));//���ֵ
//	printf("%d\n", strlen(&p[0] + 1));//5
//
//	//printf("%d\n", sizeof(p));//p��һ��ָ����� 4/8
//	//printf("%d\n", sizeof(p + 1));//p+1 ���ַ�b�ĵ�ַ 4/8
//	//printf("%d\n", sizeof(*p));//1
//	//printf("%d\n", sizeof(p[0]));//p[0]-->*(p+0) --> *p 1
//	//printf("%d\n", sizeof(&p));//4/8
//	//printf("%d\n", sizeof(&p + 1));
//	//printf("%d\n", sizeof(&p[0] + 1));
//
//	return 0;
//}
//
//int main()
//{
//	int a[3][4] = { 0 };
//	//printf("%p\n", &a[0][0]);
//	//printf("%p\n", a[0]+1);
//
//	printf("%d\n", sizeof(a));
//	printf("%d\n", sizeof(a[0][0]));
//	printf("%d\n", sizeof(a[0]));//a[0]�ǵ�һ�е�����������������������sizeof�ڲ�
//	printf("%d\n", sizeof(a[0] + 1));//4/8
//	//arr[0]�ǵ�һ�е����������������û�е�������sizeof�ڲ���Ҳû��&������arr[0]��ʾ��Ԫ�صĵ�ַ
//	//���ǵ�һ����������һ��Ԫ�صĵ�ַ
//	//����a[0] + 1���ǵ�һ�У��ڶ���Ԫ�صĵ�ַ
//
//	printf("%d\n", sizeof(*(a[0] + 1)));//*(a[0] + 1)���ǵ�һ�еڶ���Ԫ�� 4
//	printf("%d\n", sizeof(a + 1));//4/8
//	//������a����û�е�������sizeof�ڲ���Ҳû��&������a��ʾ��Ԫ�أ���һ�У��ĵ�ַ
//	//����a+1�����ǵڶ��еĵ�ַ
//	//int(*)[4]
//	//a+1 -> &a[1]
//
//	printf("%d\n", sizeof(*(a + 1)));//*(a+1)���ǵڶ��� - 16
//	//*(a + 1) --> a[1]
//
//	printf("%d\n", sizeof(&a[0] + 1));//4/8
//	//a[0]�ǵ�һ�е�������
//	//&a[0] �õ����ǵ�һ�еĵ�ַ
//	//&a[0]+1,���ǵڶ��еĵ�ַ
//	//int(*)[4]
//
//	printf("%d\n", sizeof(*(&a[0] + 1)));//16
//	//*(&a[0] + 1) - �ڶ��� -- a[1]
//	//*(&a[0]+1) --> *(&a[1]) --> a[1]
//
//	printf("%d\n", sizeof(*a));
//	//a��ʾ��Ԫ�أ���һ�У��ĵ�ַ
//	//*a - ��һ�� - ��һ�е�������
//	//*a -> *(a+0) ->a[0]
//
//	printf("%d\n", sizeof(a[3]));
//	//a[3]������ڣ����ǵ����е���������sizeof(a[3])�����൱�ڰѵ����е���������������sizeof�ڲ�
//
//	printf("%d\n", sizeof(int));
//	return 0;
//}

//int main()
//{
//    int a[5] = { 1, 2, 3, 4, 5 };
//    int* ptr = (int*)(&a + 1);
//
//    printf("%d,%d", *(a + 1), *(ptr - 1));
//
//    return 0;
//}


struct Test
{
	int Num;
	char* pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;

//����p ��ֵΪ0x100000�� ���±���ʽ��ֵ�ֱ�Ϊ���٣�
//��֪���ṹ��Test���͵ı�����С��20���ֽ�

int main()
{
	//struct Test*      --  int
	p = (struct Test*)0x100000;//

	//printf("0x%p\n", p + 0x1);
	//printf("0x%p\n", (unsigned long)p + 0x1);
	//printf("0x%p\n", (unsigned int*)p + 0x1);

	printf("%p\n", p + 0x1);
	printf("%p\n", (unsigned long)p + 0x1);
	printf("%p\n", (unsigned int*)p + 0x1);

	return 0;
}