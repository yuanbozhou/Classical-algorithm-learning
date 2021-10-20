//题目简介
// 在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
// 示例:
// 现有矩阵 matrix 如下：
// [
//   [1,   4,  7, 11, 15],
//   [2,   5,  8, 12, 19],
//   [3,   6,  9, 16, 22],
//   [10, 13, 14, 17, 24],
//   [18, 21, 23, 26, 30]
// ]
// 给定 target = 5，返回 true。
// 给定 target = 20，返回 false。
// 来源：剑指offer典型编程题




//关键报错：输入为空时的判断。当rows=0的时候，数组不存在元素，也就不存在matrix[0]，matrix[0]产生越界。
// 二维数组的形参传入：
//vector<vector<int>>& matrix,
// 二维数组的行列求法：
// 行数 int rows=matrix.size();
//列数 int columns=matrix[0].size();
// //总行数为rows，总列数为columns；
// //从左下角开始扫描，（定位出row=总行数-1，column=0）
// //从左下角开始扫描，比目的数字小，则行-1；比目的数字大，列+1。
// //循环，结束的条件是行小于0或列大于（总列数-1）
#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target){
         bool temp=false;//默认没有找到
         int rows=matrix.size();
                 
        if(rows==0)
         {
             return false;
         }
         //再访问matrix[0]就不会越界了
         int columns=matrix[0].size();
         if(columns==0)
         {
             return false;
         }
         cout<<rows<<"    "<<columns;
         if(rows>=0 && columns>=0)
         {
             int row=rows-1;//从大到小
             int column=0;//从小到大
             //进入循环的条件
             while(row>=0&&column<columns)
             {
                 //相等
                 if(matrix[row][column]==target)
                 {
                     temp=true;
                     
                     break;
                 }
                 //从左下角开始扫描，比目的数字小，列+1
                 else if(matrix[row][column]<target)
                 {
                     ++column;
                 }
                 //从左下角开始扫描，比目的数字大，则行-1
                 else 
                 {
                    --row;
                 }

            }
         }
         return temp;

    }
};