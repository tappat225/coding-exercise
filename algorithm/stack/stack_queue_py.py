
class QueueWithTwoStacks:
    def __init__(self):
        # 用于入队操作的栈
        self.stack_in = []
        # 用于出队操作的栈
        self.stack_out = []

    def enqueue(self, item):
        """
        将元素入队，直接添加到stack_in中
        """
        self.stack_in.append(item)

    def dequeue(self):
        """
        将元素出队
        如果stack_out为空，先将stack_in中的元素全部转移到stack_out中
        然后从stack_out中弹出元素
        """
        if not self.stack_out:
            while self.stack_in:
                self.stack_out.append(self.stack_in.pop())

        if not self.stack_out:
            raise IndexError("队列已空，无法出队")

        return self.stack_out.pop()

    def is_empty(self):
        """
        判断队列是否为空，当两个栈都为空时，队列即为空
        """
        return not self.stack_in and not self.stack_out

def testcase():
    queue = QueueWithTwoStacks()

    queue.enqueue(1)
    queue.enqueue(2)
    queue.enqueue(3)

    print(queue.dequeue())  # 输出: 1
    print(queue.dequeue())  # 输出: 2
    queue.enqueue(5)
    print(queue.is_empty())
    print(queue.dequeue())
    print(queue.dequeue())


if __name__ == "__main__":
    testcase()
