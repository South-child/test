#define  _CRT_SECURE_NO_WARNINGS 1

//���������
//1.�������飬ÿ������ƽ��
//2.������
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

//˫ָ�뷨
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //����һ���µ����飬���ƽ���������
        vector<int> SquareArr(nums.size(), 0);
        //���������������ֱ�ָ��������׺�β
            //��Ϊ����ʱ�ǵݼ�˳��ģ�����ƽ��������ֵ����������
        int left = 0;
        int right = nums.size() - 1;
        int k = nums.size() - 1;//��¼��������±� --- ����ָ��������λ��
        //�Ӻ���ǰ������ݣ�����ƽ������ֵ����ں���
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