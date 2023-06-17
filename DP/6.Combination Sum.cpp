class Solution
{
public
    List<List<Integer>> combinationSum(int[] candidates, int target)
    {
        List<List<Integer>> list = new ArrayList<>();
        Arrays.sort(candidates);
        backtrack(list, candidates, new ArrayList<>(), target, 0);
        return list;
    }
public
    static void backtrack(List<List<Integer>> list, int[] cand, List<Integer> tmp_list, int remain, int start)
    {
        if (remain < 0)
            return;
        if (remain == 0)
            list.add(new ArrayList<>(tmp_list));
        for (int i = start; i < cand.length; i++)
        {
            tmp_list.add(cand[i]);
            backtrack(list, cand, tmp_list, remain - cand[i], i);
            tmp_list.remove(tmp_list.size() - 1);
        }
    }
}