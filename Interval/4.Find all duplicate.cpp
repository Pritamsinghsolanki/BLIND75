class Solution
{
public
    List<Integer> findDuplicates(int[] nums)
    {
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < nums.length; i++)
        {
            int num = Math.abs(nums[i]); // get the original number by removing - sign if visited
            if (nums[num - 1] > 0)
                nums[num - 1] = -nums[num - 1]; // sign change to negative (visit)
            else
                list.add(num); // if sign has been already changed(visited) then current number is duplicate
        }
        return list;
    }
}