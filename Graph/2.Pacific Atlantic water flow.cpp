class Solution
{
    static int[][] dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    static int m;
    static int n;
public
    static void dfs(int[][] heights, boolean[][] vis, int height, int x, int y)
    {
        if (x < 0 || y < 0 || x >= m || y >= n || vis[x][y] == true || heights[x][y] < height)
            return;
        vis[x][y] = true;

        for (int[] d : dir)
        {
            dfs(heights, vis, heights[x][y], x + d[0], y + d[1]);
        }
    }
public
    List<List<Integer>> pacificAtlantic(int[][] heights)
    {
        List<List<Integer>> ans = new ArrayList<>();
        m = heights.length;
        n = heights[0].length;

        //         Queue<int[]> p_q=new LinkedList<>();
        //         Queue<int[]> a_q=new LinkedList<>();

        boolean[][] vp = new boolean[m][n];
        boolean[][] va = new boolean[m][n];

        //         for(int i=0;i<n;i++){
        //             p_q.add(new int[]{0,i});
        //             a_q.add(new int[]{m-1,i});

        //             vp[0][i]=true;
        //             va[m-1][i]=true;
        //         }

        //         for(int i=0;i<m;i++){
        //             p_q.add(new int[]{i,0});
        //             a_q.add(new int[]{i,n-1});

        //             vp[i][0]=true;
        //             va[i][n-1]=true;
        //         }

        for (int j = 0; j < n; j++)
        {
            dfs(heights, vp, Integer.MIN_VALUE, 0, j);
            dfs(heights, va, Integer.MIN_VALUE, m - 1, j);
        }

        for (int j = 0; j < m; j++)
        {
            dfs(heights, vp, Integer.MIN_VALUE, j, 0);
            dfs(heights, va, Integer.MIN_VALUE, j, n - 1);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (va[i][j] == true && vp[i][j] == true)
                {
                    List<Integer> ans1 = new ArrayList<>();
                    ans1.add(i);
                    ans1.add(j);
                    ans.add(ans1);
                }
            }
        }

        return ans;
    }
}