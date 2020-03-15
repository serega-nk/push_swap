# GROUP_SIZE = 10

# from itertools import groupby
# from operator import itemgetter

# import random
# nums = list(range(50))
# random.shuffle(nums)

# nums = [(value, index) for index, value in enumerate(nums)]
# nums = sorted(nums, key=itemgetter(0))
# nums = [(value, position, position // GROUP_SIZE) for position, (value, _) in enumerate(nums)]
# #nums = sorted(nums, key=itemgetter(1))
# #print(nums)


# def get_positions(iterable, count_group):
#     result = []
#     curr = 0
#     pos0 = 0
#     pos1 = 0
#     for index, (_, _, group) in enumerate(iterable):
#         while (curr < group):
#             result.append((curr, pos0, pos1))
#             pos0 = pos1
#             curr += 1
#         pos1 = index + 1
#     while (curr < count_group):
#         result.append((curr, pos0, pos1))
#         pos0 = pos1
#         curr += 1
#     return result


# nums = filter(lambda x: x[2] != 3, nums)
# res = get_positions(nums, 7)
# print(res)

from itertools import groupby
from operator import itemgetter

def get_positions(iterable, count):

    def _fold(iterable):
        lst = list(iterable)
        count = len(lst)
        for _ in range(len(lst)):
            if lst[-1][0] > lst[0][0]:
                break
            lst.append(lst.pop(0))
        res = []
        curr = None
        for group, index in lst:
            if curr != group:
                if curr != None:
                    res.append((curr, pos0, pos1))
                curr = group
                pos0 = index
            pos1 = (index + 1) % count
        if curr != None:
            res.append((curr, pos0, pos1))
        return res

    def _expand(lst, count):
        res = []
        curr = 0
        prev = lst[-1][2]
        for group, pos0, pos1 in lst:
            while (curr < group):
                res.append((curr, prev, pos0))
                curr += 1
            res.append((curr, pos0, pos1))
            curr += 1
            prev = pos1
        while (curr < count):
            res.append((curr, prev, prev))
            curr += 1
        return res

    lst = _fold(iterable)
    lst = _expand(lst, count)
    res = {group: (pos0, pos1) for group, pos0, pos1 in lst}
    return res

res = [
    (4, 0),
    (5, 1),
    (5, 2),
    (2, 3),
    (2, 4),
    (2, 5),
    (2, 6),
]

res = get_positions(res, 8)
print(res)




#         nums = sorted(nums, key=lambda item: item[1])
#         nums = [(value, index, group) for value, _, index, group in nums]

# iterable = nums
# for key, item in groupby(iterable, key=itemgetter(2)):
#     print(key, list(item))
