from typing import List


class Solution:
    def intersection(
            self,
            start1: List[int],
            end1: List[int],
            start2: List[int],
            end2: List[int]) -> List[float]:
        """
        给定两条线段（表示为起点start = {X1, Y1}和终点end = {X2, Y2}），如果它们有交点，请计算其交点，没有交点则返回空值。
        要求浮点型误差不超过10^-6。若有多个交点（线段重叠）则返回 X 值最小的点，X 坐标相同则返回 Y 值最小的点。
        来源：力扣（LeetCode）
        链接：https://leetcode-cn.com/problems/intersection-lcci
        著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
        :param start1: 线段1起点
        :param end1: 线段1终点
        :param start2: 线段2起点
        :param end2: 线段2终点
        """
        def inside(x1, y1, x2, y2, xk, yk):
            return ((x1 == x2) or min(x1, x2) <= xk <= max(x1, x2)) and \
                   ((y1 == y2) or min(y1, y2) <= yk <= max(y1, y2))

        def update(ans, xk, yk):
            if not ans or [xk, yk] < ans:
                return [xk, yk]
            else:
                return ans

        x1, y1 = start1
        x2, y2 = end1
        x3, y3 = start2
        x4, y4 = end2

        ans = list()

        if (y2 - y1) * (x4 - x3) == (y4 - y3) * (x2 - x1):
            if (y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1):
                if inside(x1, y1, x2, y2, x3, y3):
                    ans = update(ans, x3, y3)
                if inside(x1, y1, x2, y2, x4, y4):
                    ans = update(ans, x4, y4)
                if inside(x3, y3, x4, y4, x1, y1):
                    ans = update(ans, x1, y1)
                if inside(x3, y3, x4, y4, x2, y2):
                    ans = update(ans, x2, y2)
        else:
            t1 = (x3 * (y4 - y3) + y1 * (x4 - x3) - y3 * (x4 - x3) - x1 *
                  (y4 - y3)) / ((x2 - x1) * (y4 - y3) - (x4 - x3) * (y2 - y1))
            t2 = (x1 * (y2 - y1) + y3 * (x2 - x1) - y1 * (x2 - x1) - x3 *
                  (y2 - y1)) / ((x4 - x3) * (y2 - y1) - (x2 - x1) * (y4 - y3))
            if 0.0 <= t1 <= 1.0 and 0.0 <= t2 <= 1.0:
                ans = [x1 + t1 * (x2 - x1), y1 + t1 * (y2 - y1)]

        return ans



def main():
    ans = Solution().intersection([1, 0],[1, 1],[-1, 0],[3, 2])
    print(ans)

if __name__ == '__main__':
    main()
