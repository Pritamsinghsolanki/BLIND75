class Solution
{
public
    int[][] insert(int[][] intervals, int[] newInterval)
    {
        ArrayList<int[]> list = new ArrayList<>();
        int idx = 0;
        int n = intervals.length;

        while (idx < n)
        {
            if (intervals[idx][1] < newInterval[0])
            {
                list.add(intervals[idx]);
                idx++;
            }
            else
            {
                break;
            }
        }

        int[] interval = newInterval;

        while (idx < n && intervals[idx][0] <= interval[1])
        {
            interval[0] = Math.min(interval[0], intervals[idx][0]);
            interval[1] = Math.max(interval[1], intervals[idx][1]);
            idx++;
        }

        list.add(interval);

        while (idx < n)
        {
            list.add(intervals[idx]);
            idx++;
        }

        return list.toArray(new int[list.size()][2]);
    }
}