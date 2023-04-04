#include <stdio.h>

// O(2^N)
// 斐波那契额数列的递归写法完全一个实际没用的算法，因为太慢了
// 计算阶乘递归Fac的时间复杂度？
long long Fac(size_t N)
{
	if (0 == N)
		return 1;

	return Fac(N - 1)*N;
}

int main()
{
	printf("%lld\n", Fac(10000));

	return 0;
}