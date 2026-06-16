"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:

        intervals.sort(key=lambda x:x.end)

        res = intervals

        count = 0

        while res:

            p_res = []
            prev_end = res[0].end
            for i in range(1,len(res)):

                if res[i].start<prev_end:
                    p_res.append(res[i])
                else:
                    prev_end = res[i].end

            res = p_res
            count+=1

        return count 
        