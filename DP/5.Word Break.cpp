class Solution
{
public
    boolean wordBreak(String s, List<String> wordDict)
    {
        byte[] dp = new byte[s.length()]; // dp[i] = if possible to use words from wordDict to make s up to index i
        Arrays.fill(dp, (byte)-1);        // initialize all to -1 to indicate not calculated yet

        return wordBreak(s, 0, wordDict, dp);
    }

private
    boolean wordBreak(String s, int index, List<String> wordDict, byte[] dp)
    {
        if (index >= s.length()) // index past entire string already, means we found a solution
            return true;

        if (dp[index] != -1)
            return dp[index] == 1; // decision here was using 1 to represent true, and 0 to represent false

        byte match = 0;
        for (int i = 0; i < wordDict.size(); i++)
        {
            String word = wordDict.get(i);
            if (s.startsWith(word, index) && wordBreak(s, index + word.length(), wordDict, dp))
            { // if the word starts at index, we recursively look for solution down this path
                match = 1;
                break; // found a solution already so can break and skip work
            }
        }

        dp[index] = match; // save result in dp for future use

        return match == 1;
    }
}