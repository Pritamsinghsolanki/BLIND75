class Solution
{
public
    int climbStairs(int n)
    {
        return climb(n);
    }
public
    static int climb(int n)
    {
        int[] dp = new int[n + 1];
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (i + 2 <= n)
            {
                dp[i] = dp[i + 1] + dp[i + 2];
            }
            else if (i + 1 <= n)
            {
                dp[i] = dp[i + 1];
            }
        }
        return dp[0];
    }
}