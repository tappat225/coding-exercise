
class LinkListNode:
    def __init__(self, next = None, val = 0) -> None:
        self.next = next
        self.val = val

def createLinkList(arr) -> LinkListNode:
    if arr == None or arr == []:
        return None

    head = LinkListNode()
    cur = head
    for elem in arr:
        cur.next = LinkListNode(val = elem)
        cur = cur.next
    
    return head

def printLinkList(HeadNode: LinkListNode) -> None:
    if HeadNode == None:
        raise ValueError("LinkList is empty")

    cur = HeadNode.next
    while cur != None:
        print(cur.val)
        cur = cur.next

def findElemInLinkList(HeadNode: LinkListNode) -> int:

    return -1

# Print LinkList
def testcase01():
    arrTest = [2, 4, 3, 1]
    LL1 = createLinkList(arrTest)
    printLinkList(LL1)

# Invalid value test
def testcase02():
    arrTest = []
    LL1 = createLinkList(arrTest)
    printLinkList(LL1)

if __name__ == "__main__":
    testcase02()
