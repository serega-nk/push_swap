import sys

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
        getattr(self, 'play_' + cmd)()
        self.count += 1

    def run(self, iterable):
        for line in iterable:
            self.execute(line.rstrip())
            print('cmd =', line)
            print(self)

    def __repr__(self):
        return f'A = {self.stack_a}\nB = {self.stack_b}\ncount = {self.count}'


class Play2(Play):
    def __init__(self, nums):
        count = 10
        nums = [(num, i) for i, num in enumerate(nums)]
        nums = sorted(nums, key=lambda item: item[1])
        nums = [(item[0], item[1], i, i // count) for i, item in enumerate(nums)]
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

    nums = '1 5 10 19 12 13 17 2 9 14 6 3 8 4 11 18 20 16 15 7'
    cmds = 'ra ra ra pb ra ra pb rb pb pb rb ra pb pb pb pb pb rb ra ra pb rb pb rb pb rr pa rb pa rb pa rra rra pa rra pa rb rb pa pa rrr rra rra pa rra pa ra pa rra pa ra ra ra pa rra rra rra rra rra rra rra rra'

    nums = list(map(int, nums.split(' ')))
    cmds = cmds.split(' ')

    play = Play2(nums)
    print(play)
    play.run(cmds)



# call the "main" function if running this script
if __name__ == '__main__': main()
