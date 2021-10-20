//题目简介
// 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
// 示例 1：
// 输入：s = "We are happy."
// 输出："We%20are%20happy."
// 来源：剑指offer典型编程题




#include<iostream>
using namespace std;
class Solution {
public:
    string replaceSpace(string s) {
        for(int i=0;i<s.size();i++){
            if(s.substr(i,1)==" ")
            {
               s.replace(i,1,"%20");
            }
        }
        return s;
    }
};