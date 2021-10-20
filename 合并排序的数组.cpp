//题目简介
//给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。
// 初始化 A 和 B 的元素数量分别为 m 和 n。
// 来源：剑指offer典型编程题




#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        // for(int i=0;i<A.size();i++){
        //     cout<<A[i];
        // }
        int A1=A.size()-1;
        //循环的条件是m，n
        while(m>0&&n>0){
            if(A[m-1]>B[n-1]){
                A[A1]=A[m-1]; //把大的放在尾部
                --m;
            }
            else{
                A[A1]=B[n-1]; //把大的放在尾部
                --n;
            }
            // cout<<A1<<" "<<A[A1]<<endl;
            A1--;
        }
        // cout<<m<<n<<endl;
        if(m==0&&n!=0){
            for(int i=n-1;i>=0;--i){
                A[A1--]=B[i]; 
            }
        }
        if(n==0&&m!=0){
            for(int i=m-1;i>=0;--i){
                A[A1--]=A[i]; 
            }
        }

        cout<<"["<<A[0];
     for(int i=1;i<A.size();i++){
            cout<<','<<A[i];
        }    
        cout<<"]";
    }
    int main(){
        int a[6] = {1,2,3,0,0,0};
        vector<int> A(a,a+6);
        int m = 3;
        int b[3] = {2,5,6};
        vector<int> B(b,b+3);
        int n = 3;
        merge(A,m,B,n);
    }
