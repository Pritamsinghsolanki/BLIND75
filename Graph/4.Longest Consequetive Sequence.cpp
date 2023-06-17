class Solution
{
public
    int longestConsecutive(int[] nums)
    {
        HashSet<Integer> st = new HashSet<>();

        for (int i : nums)
        {
            st.add(i);
        }

        int max_len = 0;

        for (int a : nums)
        {
            if (!st.contains(a - 1))
            {
                int currnum = a;
                int currentstreak = 1;
                while (st.contains(currnum + 1))
                {
                    currnum++;
                    currentstreak++;
                }
                max_len = Math.max(max_len, currentstreak);
            }
        }

        return max_len;
    }
}