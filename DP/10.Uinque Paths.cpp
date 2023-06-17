class Solution
{
public
    static int solve(int m, int n, int[][] dp)
    {
        if (m < 1 || n < 1)
            return 0;
        if (m == 1 || n == 1)
            return 1;
        // System.out.println(m+" "+n);
        if (dp[m][n] != 0)
            return dp[m][n];
        return dp[m][n] = solve(m - 1, n, dp) + solve(m, n - 1, dp);
    }
public
    int uniquePaths(int m, int n)
    {

        int[][] dp = new int[m + 1][n + 1];
        for (int i = 1; i <= m; i++)
        {
            dp[i][1] = 1;
        }
        for (int j = 1; j <= n; j++)
        {
            dp[1][j] = 1;
        }

        for (int i = 2; i <= m; i++)
        {
            for (int j = 2; j <= n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        // return solve(m,n,dp);
        return dp[m][n];
    }
}