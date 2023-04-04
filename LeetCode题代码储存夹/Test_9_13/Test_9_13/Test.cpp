#define  _CRT_SECURE_NO_WARNINGS 1

//暴力解法 -- 时间复杂度: O(N^2)
//力扣上过不过去，会超出时间限制
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT_MAX;//最终结果
        int sum = 0;//子数组的和
        int subLenth = 0;//子数组的长度
        for (int i = 0; i < nums.size(); ++i)
        {
            sum = 0;
            for (int j = i; j < nums.size(); ++j)
            {
                sum += nums[j];
                if (sum >= target)
                {
                    subLenth = j - i + 1;
                    result = result < subLenth ? result : subLenth;
                    break;
                }
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};


//滑动窗口 -- 时间复杂度：O(n)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT_MAX;//最终返回的子数组的长度
        int sum = 0;//滑动窗口的和
        int i = 0;//滑动窗口的起始位置
        int SubLenth = 0; //滑动窗口的长度
        for (int j = 0; j < nums.size(); ++j)
        {
            sum += nums[j];

            while (sum >= target)
            {
                SubLenth = j - i + 1;
                result = result < SubLenth ? result : SubLenth;

                sum -= nums[i++];
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};