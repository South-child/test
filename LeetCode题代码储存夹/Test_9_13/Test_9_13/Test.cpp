#define  _CRT_SECURE_NO_WARNINGS 1

//�����ⷨ -- ʱ�临�Ӷ�: O(N^2)
//�����Ϲ�����ȥ���ᳬ��ʱ������
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT_MAX;//���ս��
        int sum = 0;//������ĺ�
        int subLenth = 0;//������ĳ���
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


//�������� -- ʱ�临�Ӷȣ�O(n)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT_MAX;//���շ��ص�������ĳ���
        int sum = 0;//�������ڵĺ�
        int i = 0;//�������ڵ���ʼλ��
        int SubLenth = 0; //�������ڵĳ���
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