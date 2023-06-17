class Solution
{
public
    int rob(int[] nums)
    {
        int n = nums.length;
        if (n == 0)
            return 0;
        int bbr = 0;
        int br = nums[0];
        for (int i = 1; i < n; i++)
        {
            int tmp = br;
            br = Math.max(br, nums[i] + bbr);
            bbr = tmp;
        }
        return Math.max(br, bbr);
    }
}