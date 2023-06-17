class Solution
{
public
    int rob(int[] nums)
    {
        if (nums.length == 1)
            return nums[0];
        int first = solve(nums, 0, nums.length - 2);
        int second = solve(nums, 1, nums.length - 1);
        if (first > second)
            return first;
        return second;
    }
public
    static int solve(int[] nums, int lo, int hi)
    {
        int include = 0, exclude = 0;
        for (int j = lo; j <= hi; j++)
        {
            int i = include, e = exclude;
            include = e + nums[j];
            exclude = Math.max(e, i);
        }
        return Math.max(include, exclude);
    }
}