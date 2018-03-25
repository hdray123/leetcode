# 无重复字符的最长子串

>给定一个字符串，找出不含有重复字符的 **最长子串 **的长度。

>**示例：**

>给定 `"abcabcbb"` ，没有重复字符的最长子串是 `"abc"` ，那么长度就是3。

>给定 `"bbbbb"` ，最长的子串就是 `"b"` ，长度是1。

>给定 `"pwwkew"` ，最长子串是 `"wke"` ，长度是3。请注意答案必须是一>个**子串**，`"pwke"` 是 *子序列 *而不是子串。

代码

```c++
vector<int> dict(256, -1);
int maxLen = 0, start = -1;
for (int i = 0; i != s.length(); i++) {
  if (dict[s[i]] > start) {
    cout << s[i] << dict[s[i]] << "\n";
    start = dict[s[i]];
  }
  dict[s[i]] = i;
  maxLen = max(maxLen, i - start);
}
return maxLen;
```

#####  一个字符是一个字节，一个字节是2的8次就是256。所以创建一个256大的vector，值预先设为-1。 当dict[s[i]]>start,就是指s[i]的字符在遍历string时前面已经出现过相同的字符了。所以在start指向前一个相同字符：因为前一个相同字符到现在的字符这之中的字符串没有一个是重复的，这一段长度加上重复的一个字符等于i-start。 

