class Solution
{
public
    int lengthOfLIS(int[] nums)
    {
        int n = nums.length;
        // int[][] dp=new int[n][n+1];
        // for(int[] row: dp) Arrays.fill(row,-1);
        // return solve(nums,-1,0,n,dp);
        //         int[][] dp=new int[n+1][n+1];

        //         for(int i=n-1;i>=0;i--){
        //             for(int prev=i-1;prev>=-1;prev--){
        //                  int length=0+ dp[i+1][prev+1];

        //                  if(prev==-1 || nums[i]> nums[prev]){
        //                      length=Math.max(length,1+ dp[i+1][i+1]);
        //                  }

        //                 dp[i][prev+1]=length;

        //             }
        //         }
        //         return dp[0][0];

        int[] dp = new int[n + 1];
        int[] after = new int[n + 1];

        for (int i = n - 1; i >= 0; i--)
        {
            for (int prev = i - 1; prev >= -1; prev--)
            {
                int length = 0 + after[prev + 1];
                if (prev == -1 || nums[i] > nums[prev])
                {
                    length = Math.max(length, 1 + after[i + 1]);
                }
                dp[prev + 1] = length;
            }
            after = dp;
        }

        return after[0];
    }
public
    static int solve(int[] nums, int prev, int idx, int n, int[][] dp)
    {
        if (idx == n)
            return 0;
        if (dp[idx][prev + 1] != -1)
            return dp[idx][prev + 1];

        int length = 0 + solve(nums, prev, idx + 1, n, dp);

        if (prev == -1 || nums[idx] > nums[prev])
        {
            length = Math.max(length, 1 + solve(nums, idx, idx + 1, n, dp));
        }

        return dp[idx][prev + 1] = length;
    }
}