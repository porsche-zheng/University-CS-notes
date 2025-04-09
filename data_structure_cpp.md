# **DataStructure**

## **fital errors**
1. 不可以 `NULL->xx` **!** , 需提前判断是否为空指针!;  
2. class中,变量和成员函数尽量避免名字相同,否则:`queue.front()`可能被认为是`queue.front`,然而front是private变量,不可访问
3. `queue<tree*>` 不能 `push(const tree* tr)`; 需改为`queue<const tree*>`  
4. STL中`stack``queue`可以有指针形式,如
    ```
    stack* st = new stack();
    ```
5. `doublespace()`条件一定要选取正确,数组从0开始。
6. priority_queue/heap 的实现中:
   1. `porcolate_down`部分,注意比较`array[child]`与 **temp**,不是 **~~arra[hole]~~**;  
   2. `porcolate_down`部分,注意简化代码,比较`array[child]`与`array[child+1]`,改变*child*的值;再与**temp**比较;
   3. 注意 ***5.*** 即 `doublespace()` 的条件;

## **advanced DS**
1. ***monotonic stack 单调栈*** 
    - **introduction(介绍)：**  
    确保栈内元素单调递增(或减)  
    - **Implement(实现):**  
    遇到<(<=,>,>=……)top的元素,得出结论(更新数组),并执行pop操作直到top<该元素;  
    遇到>top的元素,push进去。
    - **application(用途)：**
    得出一个一维数组中所有元素与第一个<(<=……>)的元素间的距离。
    - **codes(代码)：**     
    `abc`  
    <abc>  
    > 总结 
    >> 123
    >>> 396
    ```  
    monotonic_stack stack;
    for(i=0;i'<'n;++i){ 
        if(stack.top()'<'arr[i]){  

        }  
    }  
    ```  
2. ***minStack 最小栈*** 
   - **Introduction(介绍):**  
    O(1)时间内找到某栈的最小值。
   - **Implement(实现):**  
    准备两个栈s,t;s用来储存所有元素,t栈在t.top() > value时push,即比top小的元素入栈,其余出栈,实现了单减,相对位置不变,并且当pop后t.top()仍然是剩余栈内的最小值
3. ***monotonicQueue 单调队列***
   - **Introduction():**  
    处理滑动窗口最值问题,一种自己维护的数据结构。  
   - **Implement():**   
    
## **algorithm**  
1. DFS  
2. BFS
3. 前缀和
4. 常见O(n)算法:
    1. 双指针  
    2. 单调栈(队列)  
    3. n次并查集  
5. 