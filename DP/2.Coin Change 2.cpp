class Solution
{
public
    int change(int amount, int[] coins)
    {
        HashMap<String, Integer> mp = new HashMap<>();
        return backtrack(0, amount, coins, mp);
    }
private
    int backtrack(int i, int amount, int[] coins, HashMap<String, Integer> mp)
    {
        if (amount == 0)
        {
            return 1;
        }
        if (amount < 0 || i == coins.length)
        {
            return 0;
        }
        String key = amount + "pritam" + i;
        if (mp.containsKey(key))
        {
            return mp.get(key);
        }
        int result = 0;
        for (int k = i; k < coins.length; k++)
        {
            if (amount >= coins[k])
            {
                result += backtrack(k, amount - coins[k], coins, mp);
            }
        }
        mp.put(key, result);
        return result;
    }
}