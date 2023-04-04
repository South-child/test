#define  _CRT_SECURE_NO_WARNINGS 1

//暴力解决法
//1.遍历数组，每个数先平方
//2.在排序
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
        {
            nums[i] *= nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};

//双指针法
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //创建一个新的数组，存放平方后的数据
        vector<int> SquareArr(nums.size(), 0);
        //定义两个变量，分别指向数组的首和尾
            //因为数组时非递减顺序的，所以平方后的最大值在数组两端
        int left = 0;
        int right = nums.size() - 1;
        int k = nums.size() - 1;//记录新数组的下标 --- 让其指向最后结束位置
        //从后往前存放数据，数据平方后大的值存放在后面
        while (left <= right)
        {
            if (nums[left] * nums[left] < nums[right] * nums[right])
            {
                SquareArr[k] = nums[right] * nums[right];
                k--;
                right--;
            }
            else
            {
                SquareArr[k] = nums[left] * nums[left];
                k--;
                left++;
            }
        }
        return SquareArr;
    }
};