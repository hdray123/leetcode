# 11.盛最多水的容器

>给定 *n* 个正整数 *a*1，*a*2，...，*a*n，其中每个点的坐标用（*i*, *a*i）表示。 画 *n* 条直线，使得线 *i* 的两个端点处于（i，ai）和（i，0）处。请找出其中的两条直线，使得他们与 X 轴形成的容器能够装最多的水。

 

> **注意：**你不能倾斜容器，n 至少是2。

代码：

```c++
#include <iostream>
#include <vector>

using namespace std;
int main() {
    vector<int> height;
    height.push_back(1);height.push_back(2);height.push_back(3);height.push_back(4);height.push_back(2);
    height.push_back(3);
    int max_water=0;
    int s=0;
    int e=height.size()-1;
    int h;
    while(s<e){
        h=min(height[s],height[e]);
        max_water=max(max_water,h*(e-s));
        while(height[s]<=h && s<e) s++;
        while(height[e]<=h && s<e) e--;
    }
    cout<<max_water;


    return 0;
}
```

### 想法

s(start)和e(end)表示vector的首尾两端，然后不断向中间靠拢。

