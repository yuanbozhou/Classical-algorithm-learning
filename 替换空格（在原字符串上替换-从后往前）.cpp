//题目简介
// 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
// 示例 1：
// 输入：s = "We are happy."
// 输出："We%20are%20happy."
// 来源：剑指offer典型编程题




#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
// 从后往前一个个填入。首先先计算初始的字符串长度和应变为的长度（根据空格来增加长度）
//当输入为s=0。
void replaceSpace(string s) {
        //cout<<s.length()<<endl;//13,不包括结尾符号'\0'
        int startLength=0;  //初始字符串长度
        int endLength=0;  //结束时应变为的长度
        int blankNumber=0;
        int i=0;
        while(s[i]!='\0'){
            ++startLength;
             if(s[i]==' ')
            {
               blankNumber++;
            }
            ++i;
        }
        
        endLength=startLength+(blankNumber*2);
        // cout<<endLength;    //17
        // s.length()=endLength;//重新定义字符串的长度，不然会溢出
        int j=startLength-1;
        while(j>=0&&endLength>j){
            if(s[j]!=' ')
            {
                s[--endLength]=s[j];
            }
            else{
                s[--endLength]='0';
                s[--endLength]='2';
                s[--endLength]='%';
            }
            --j;
            // cout<<"j"<<j<<endl;
            // cout<<"endLength:"<<endLength<<" "<<s[endLength]<<endl;
        }
        
        for(int i=0;i<17;i++){
            cout<<s[i];
        }
       cout<<endl;
}



int main(){
    string str="We are happy.";
    replaceSpace(str);
    
}