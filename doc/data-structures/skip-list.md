## 跳跃表

我们能比 O(n) 更快的时间搜索一个已排序链表吗？

不能。一个已排序链表的搜索时间是 O(n)，因为我们只能线性地搜索所有结点，不能跳过任何一个。对一个平衡的二叉搜索树，我们每比较一次就会扔掉近一半的元素；对一个已排序数组，我们可以通过随机寻址来实现二分查找。

我们能调整已排序链表来让搜索更快吗？答案是跳跃表。跳跃表的基本思想是很简单的：我们通过创建许多层链表来跳过某些结点。下图是一个 2 层 16 个结点的跳跃表，就像地铁线路，上面一层是快速线，它只在某些站台停靠，下面一层是普通线，它每一层都停靠。假如我们要搜索 50，我们从快速线的第一个结点开始，沿着快速线一直搜索，直到遇到第一个 next 结点值大于 50。一旦我们找到这个结点（本例中的 30），我们下降一层到普通线继续查找，降到最底层之后直接线性地查找，在这里我们找到了 50。

![](../assets/images/part2/skip-list1.png)

这两层加起来的时间复杂度是多少呢？最坏情况下搜索的结点是快速线上的结点数加上普通线上区间（这里定义区间为快速线两个结点之间的那一段普通线）。所以如果我们在普通线上有 n 个结点，快速线上有 √n 个结点，并且快速线是将普通线平均分的，那么我们在普通线区间上有 √n 个结点。√n 是 2 层的最好划分，在这种情况下，搜索的时间就是 O(√n)，因此，只需 O(√n) 的额外空间，我们就能将搜索时间从 O(n) 降到 O(√n)。

通过增加更多的层，我们可以进一步改善跳跃表的搜索。当每层结点数是上层的平方，总层数为 lgn 时，跳跃表的性能达到了最佳，此时只需 O(n) 的额外空间我们就可以将 search、insert 和 delete 的时间复杂度降到 O(lgn)。

```java
class SipList {
    int maxLevel;
    double p;
    int currentLevel;
    Node head;

    class Node {
        int key;
        Node[] forward;

        Node(int key, int level) {
            this.key = key;
            forward = new Node[level + 1];
        }
    }
    
    SkipList(int maxLevel, double p) {
        this.maxLevel = maxLevel;
        this.p = p;
        currentLevel = 0;
        head = new Node(-1, maxLevel);
    }
}
```

currentLevel 代表跳跃表目前的层数。

maxLevel 属性是跳跃表的最大层数，它可以通过以下公式计算得到：

> L(n) = log<sub>2</sub><sup>n</sup> 

每个结点都有一个 forward[0...level+1] 属性，结点在第 i 层的 next 结点存储在 forward[i] 中。例如，对于结点 30 来说，其 forward[0] 存储了第 0 层的 next 结点 43，forward[1] 存储了第 1 层的 next 结点 57。

### 插入

跳跃表中每个结点的层数是随机的，它的层数和结点中存储的关键字值的大小无关，下面的过程产生一个随机的层数：

```java
int randomLevel() {
    int temp = 0;
    while (Math.random() < p && temp < maxLevel) {
        temp++;
    }
    return temp;
}
```

假如我们需要将关键字为 k 的新结点插入到跳跃表中，我们从最高层开始，逐个比较当前结点的 next 结点的关键字 k'（如果当前结点 current 在第 i 层，则 k' = current.forward[i].key）：

1. 如果 k' < k，我们在当前层继续移动。

2. 如果 k' > k，我们把当前结点存储在一个数组 update[1...currentLevel] 中，然后下降一层继续搜索，也就是说，我们在第 i 层的 update[i] 结点处下降了一层。

在第 0 层，我们一定会找到这个结点应该待的位置，然后将它插入到这个位置。

```java
void insert(int key) {
    Node current = head;

    // Create update array and initialize it
    Node[] update = new Node[maxLevel + 1];

    // Start from highest level of skip list, move the current pointer forward
    // while key is greater than key of node next to current.
    // Otherwise inserted current in update and move one level down and continue search
    for (int i = currentLevel; i >= 0; i--) {
        while (current.forward[i] != null && current.forward[i].key < key) {
            current = current.forward[i];
        }
        update[i] = current;
    }

    // Reached level 0 and forward pointer to right, which is desired position to insert key
    current = current.forward[0];

    // If current is null that means we have reached to end of the level
    // or current's key is not equal to key to insert that means
    // we have to insert node between update[0] and current node
    if (current == null || current.key != key) {
        // Generate a random level for node
        int rLevel = randomLevel();

        // If random level is greater than list's current level
        // (node with highest level inserted in list so far),
        // initialize update value with pointer to head for further use
        if (rLevel > currentLevel) {
            for (int i = currentLevel + 1; i <= rLevel; i++) {
                update[i] = head;
            }
            // Update the list current level
            currentLevel = rLevel;
        }

        // Create new node with random level generated
        Node node = new Node(key, rLevel);

        // Insert node by rearranging pointers
        for (int i = 0; i <= rLevel; i++) {
            node.forward[i] = update[i].forward[i];
            update[i].forward[i] = node;
        }
    }
}
```

### 搜索

跳跃表搜索一个结点的过程类似于插入过程中查找一个新结点该待的位置。假如我们搜索的关键字为 k，我们从最高层开始，逐个比较当前结点的 next 结点的关键字 k'（如果当前结点 current 在第 i 层，则 k' = current.forward[i].key）：
                                 
1. 如果 k' < k，我们在当前层继续移动。

2. 如果 k' > k，我们下降一层继续搜索。

在第 0 层，我们一定会找到这个结点应该待的位置，或者发现它不在表中。

```java
Node search(int key) {
    Node current = head;
    // Start from highest level of skip list, move the current pointer forward
    // while key is greater than key of node next to current.
    // Otherwise inserted current in update and move one level down and continue search
    for (int i = currentLevel; i >= 0; i--) {
        while (current.forward[i] != null && current.forward[i].key < key) {
            current = current.forward[i];
        }
    }

    // Reached level 0 and advance pointer to right, which is possibly our desired node
    current = current.forward[0];

    // If current node have key equal to search key, we have found our target node
    if (current != null && current.key == key) {
        return current;
    } else {
        return null;
    }
}
```

### 删除

删除的过程和插入类似，我们只是在找到这个结点的过程中维护一些指针，并在删除后更新这些指针。

```java
void delete(int key) {
    Node current = head;

    // Create update array and initialize it
    Node[] update = new Node[maxLevel + 1];

    // Start from highest level of skip list, move the current pointer forward
    // while key is greater than key of node next to current
    // Otherwise inserted current in update and move one level down and continue search
    for (int i = currentLevel; i >= 0; i--) {
        while (current.forward[i] != null && current.forward[i].key < key) {
            current = current.forward[i];
        }
        update[i] = current;
    }

    // Reached level 0 and forward pointer to right, which is possibly our desired node
    current = current.forward[0];

    // If current node is target node
    if (current != null && current.key == key) {
        // Start from lowest level and rearrange pointers just like we do in singly linked list
        // to remove target node
        for (int i = 0; i <= currentLevel; i++) {
            // If at level i, next node is not target node,
            // break the loop, no need to move further level
            if (update[i].forward[i] != current) {
                break;
            }
            update[i].forward[i] = current.forward[i];
        }

        // Remove levels having no elements
        while (currentLevel > 0 && head.forward[currentLevel] == null) {
            currentLevel--;
        }
    }
}
```
