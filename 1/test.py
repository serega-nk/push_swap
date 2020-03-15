import sys
from itertools import groupby
from operator import itemgetter

def get_positions(iterable, count):

    def _fold(iterable):
        lst = [(group, index) for index, (_, _, group) in enumerate(iterable)]
        count = len(lst)
        if count == 0:
            return []
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
        prev = lst[-1][2] if lst else 0
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

GROUP_SIZE = 100

class Stack:
    def __init__(self, nums=[]):
        self._stack = nums.copy()

    def push(self, item):
        if item:
            self._stack.insert(0, item)

    def pop(self):
        if len(self._stack) > 0:
            return self._stack.pop(0)

    def swap(self):
        if len(self._stack) > 1:
            self._stack.insert(1, self._stack.pop(0))

    def rotate(self):
        if len(self._stack) > 1:
            self._stack.append(self._stack.pop(0))

    def reverse(self):
        if len(self._stack) > 1:
            self._stack.insert(0, self._stack.pop())

    def __repr__(self):
        lst = list(map(lambda i: i[0], self._stack))
        return f'Stack({lst})'

class Play:
    def __init__(self, nums):
        self.stack_a = Stack(nums)
        self.stack_b = Stack()
        self.count = 0

    def play_pa(self):
        self.stack_a.push(self.stack_b.pop())

    def play_pb(self):
        self.stack_b.push(self.stack_a.pop())

    def play_ra(self):
        self.stack_a.rotate()

    def play_rb(self):
        self.stack_b.rotate()

    def play_rr(self):
        self.stack_a.rotate()
        self.stack_b.rotate()

    def play_rra(self):
        self.stack_a.reverse()

    def play_rrb(self):
        self.stack_b.reverse()

    def play_rrr(self):
        self.stack_a.reverse()
        self.stack_b.reverse()

    def play_sa(self):
        self.stack_a.swap()

    def play_sb(self):
        self.stack_b.swap()

    def play_ss(self):
        self.stack_a.swap()
        self.stack_b.swap()

    def execute(self, cmd):
        print(cmd)
        getattr(self, 'play_' + cmd)()
        self.count += 1

    def run(self, iterable):
        for line in iterable:
            self.execute(line.rstrip())
            #print('cmd =', line)
            #print(self)

    def __repr__(self):
        return f'A = {self.stack_a}\nB = {self.stack_b}\ncount = {self.count}'

class Play2(Play):
    def __init__(self, nums):
        nums = [(num, i) for i, num in enumerate(nums)]
        nums = sorted(nums, key=lambda item: item[0])
        nums = [(item[0], item[1], i, i // GROUP_SIZE) for i, item in enumerate(nums)]
        nums = sorted(nums, key=lambda item: item[1])
        nums = [(value, index, group) for value, _, index, group in nums]
        #print(nums)
        super().__init__(nums)


def main():
    #nums = list(map(int, filter(lambda x: x, ' '.join(sys.argv[1:]).split(' '))))
    #import random; nums = list(range(20)); random.shuffle(nums)
    #print(nums)
    #play = Play(nums)
    #print(f'{play.stack_a}\n{play.stack_b}\ncount = {play.count}')
    #play.run(sys.stdin)
    #play.run(('pb\n', 'pb\n'))
    #print(f'{play.stack_a}\n{play.stack_b}\ncount = {play.count}')

    import random; nums = list(range(500)); random.shuffle(nums); nums =' '.join(map(str, nums))
    print(nums)
    #nums = '1 5 10 19 12 13 17 2 9 14 6 3 8 4 11 18 20 16 15 7'
    #cmds = 'ra ra ra pb ra ra pb rb pb pb rb ra pb pb pb pb pb rb ra ra pb rb pb rb pb rr pa rb pa rb pa rra rra pa rra pa rb rb pa pa rrr rra rra pa rra pa ra pa rra pa ra ra ra pa rra rra rra rra rra rra rra rra'

    nums = list(map(int, nums.split(' ')))
    #    cmds = cmds.split(' ')

    play = Play2(nums)
    # print(play)
    #play.run(cmds)
    test1(play)


def test5(play, save):
    res_0, res_1, res_2, res_3, res_4, pos_a, pos_b, rev_a, rev_b = save

    if res_0 == res_1:
        rev_a = 0
        rev_b = 0
    elif res_0 == res_2:
        pos_a = 0
        pos_b = 0
    elif res_0 == res_3:
        pos_b = 0
        rev_a = 0
    elif res_0 == res_4:
        pos_a = 0
        rev_b = 0

    while pos_a > 0 and pos_b > 0:
        play.execute('rr')
        pos_a -= 1
        pos_b -= 1

    while rev_a > 0 and rev_b > 0:
        play.execute('rrr')
        rev_a -= 1
        rev_b -= 1

    while pos_a > 0:
        play.execute('ra')
        pos_a -= 1

    while pos_b > 0:
        play.execute('rb')
        pos_b -= 1

    while rev_a > 0:
        play.execute('rra')
        rev_a -= 1

    while rev_b > 0:
        play.execute('rrb')
        rev_b -= 1

    play.execute('pb')


def test2(play, count_group):
    res = get_positions(play.stack_b._stack, count_group)
    len_a = len(play.stack_a._stack)
    len_b = len(play.stack_b._stack)

    save = (0, 0, 0, 0, 0, 0, 0, 0, 0)
    lst = list(play.stack_a._stack)
    for pos_a, (_, _, group) in enumerate(lst):
        pos0, pos1 = res[group]
        if pos0 > pos1:
            pos0 = pos1 = 0
        pos_b = min(pos0, pos1)
        rev_a = len_a - pos_a
        rev_b = min(len_b - pos0, len_b - pos1)

        res_1 = max(pos_a, pos_b)
        res_2 = max(rev_a, rev_b)
        res_3 = pos_a + rev_b
        res_4 = pos_b + rev_a
        res_0 = min(res_1, res_2, res_3, res_4)

        if pos_a == 0 or save[0] > res_0:
            save = (res_0, res_1, res_2, res_3, res_4, pos_a, pos_b, rev_a, rev_b)
    return (save)

def test1(play):
    count_group = len(play.stack_a._stack) / GROUP_SIZE

    #print(play)
    while (len(play.stack_a._stack) > 0):
        test5(play, test2(play, count_group))
    #print(play)

    #print(play.stack_b._stack)

    print(play.count)


# 		temp->pos_a = greedy_place(self, temp->value);
# 		temp->rev_a = temp->len_a - temp->pos_a;
# 		temp->rev_b = temp->len_b - temp->pos_b;
# 		temp->res_1 = ft_max(temp->pos_a, temp->pos_b);
# 		temp->res_2 = ft_max(temp->rev_a, temp->rev_b);
# 		temp->res_3 = temp->pos_a + temp->rev_b;
# 		temp->res_4 = temp->rev_a + temp->pos_b;
# 		temp->result = ft_min(
# 			ft_min(temp->res_1, temp->res_2),
# 			ft_min(temp->res_3, temp->res_4));
# 		if (temp->pos_b == 0 || save->result > temp->result)
# 			ft_memcpy((void *)save, (void *)temp, sizeof(t_greedy));
# 		if (save->result == 0)
# 			return ;
# 		temp->pos_b++;
# 	}
# }

# static void		greedy_fixx(t_app *self, t_greedy *save)
# {
# 	if (self)
# 	{
# 		if (save->result == save->res_1)
# 		{
# 			save->rev_a = 0;
# 			save->rev_b = 0;
# 		}
# 		else if (save->result == save->res_2)
# 		{
# 			save->pos_a = 0;
# 			save->pos_b = 0;
# 		}
# 		else if (save->result == save->res_3)
# 		{
# 			save->pos_b = 0;
# 			save->rev_a = 0;
# 		}
# 		else if (save->result == save->res_4)
# 		{
# 			save->pos_a = 0;
# 			save->rev_b = 0;
# 		}
# 	}
# }




    # # play.play_rb()

    # print(play.stack_b._stack)
    # poss = get_positions()

    # res = get_positions(play.stack_b._stack, 8)
    # [value, index, position, group]


    # print(res)

    #res = [(i, item[3]) for i, item in enumerate(play.stack_b._stack)]


    #print(play)

    #print([i[3] for i in play.stack_b._stack])

    #group = 2
    #res = [(i, item[3]) for i, item in enumerate(play.stack_b._stack)]
    #print(res)

    # for key, item in groupby(res, key=lambda x: x[1]):
    #     print(key)
    #     a = [i for i in item]
    #     print(a)


# call the "main" function if running this script
if __name__ == '__main__': main()
