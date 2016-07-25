L2-014. 列车调度
火车站的列车调度铁轨的结构如下图所示。

两端分别是一条入口（Entrance）轨道和一条出口（Exit）轨道，它们之间有N条平行的轨道。每趟列车从入口可以选择任意一条轨道进入，最后从出口离开。在图中有9趟列车，在入口处按照{8，4，2，5，3，9，1，6，7}的顺序排队等待进入。如果要求它们必须按序号递减的顺序从出口离开，则至少需要多少条平行铁轨用于调度？
输入格式：
输入第一行给出一个整数N (2 <= N <= 105)，下一行给出从1到N的整数序号的一个重排列。数字间以空格分隔。
输出格式：
在一行中输出可以将输入的列车按序号递减的顺序调离所需要的最少的铁轨条数。
输入样例：
9
8 4 2 5 3 9 1 6 7
输出样例：
4
分析：必须要车号大的先出，小的后出。所以列车排队的每一队必须是从大到小排列（从右往左看），才能保证开出去的车也是从大到小的。
对于每一个想要进入并列铁轨的车，如果车号大于每一队的队尾的车号，说明不能进入已经有的队伍，必须进入新的铁轨
否则，选择一个最接近它车号的尾部车号的队伍进入
其实无需保存每一个并行队列的所有值，只需要保存当前队伍的车尾（就是每一列最左边 即 每一列的最小值）即可
因为每一次都是需要排序比较大小的，所以用set自动排序
首先把set里面放入一个0值。每一次set的最后一个值s.rbegin()都是当前所有队列队尾的最大值.
如果当前想要进入排队队伍的t值比集合里面最大值小，就移除第一个比他大的值，然后把t插入集合中。表示的是将t值插入了最接近它车号的队伍的队尾
否则就直接插入进去t值。作为新的队伍。
因为一开始插入了一个没有的0，所以最后输出是s.size()-1;
#include <iostream>
#include <set>
using namespace std;
int main() {
    int n, t;
    cin >> n;
    set<int> s;
    s.insert(0);
    for(int i = 0; i < n; i++) {
        cin >> t;
        if(t < *s.rbegin()) {
            s.erase(*(s.upper_bound(t)));
        }
        s.insert(t);
    }
    cout << s.size() - 1;
    return 0;
}