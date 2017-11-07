//
//  main.cpp
//  SqStack
//
//  Created by 罗璞 on 2017/11/2.
//  Copyright © 2017年 Rbtoooooooooo. All rights reserved.
//

#include <iostream>
using namespace std;

#define MAXSIZE 5

typedef struct {
    int data[MAXSIZE];
    int top;
}SqStack;

/**
 初始化一个栈

 @param s 需要初始化的栈
 */
void initStack(SqStack &s) {
    s.top = -1;
}

/**
 进栈操作

 @param s 执行进栈操作的栈
 @param e 进栈的元素
 @return 进栈成功返回true，否则返回false
 */
bool push(SqStack &s, int e) {
    if (s.top != MAXSIZE - 1) {
        s.data[++s.top] = e;
        return true;
    }
    printf("栈满!无法进栈！\n");
    return false;
}

/**
 出栈操作

 @param s 执行出栈操作的栈
 @param x 出栈的元素
 @return 出栈成功返回true，否则返回false
 */
bool pop(SqStack &s, int &x) {
    if (s.top!=-1) {
        x = s.data[s.top--];
        return true;
    }
    printf("栈空!\n");
    return false;
}

/**
 打印栈

 @param s 需要打印的栈
 @param flag 1表示从栈顶开始打印，其余表示从栈底开始打印
 */
void print(SqStack s, int flag) {
    if (s.top == -1) {
        printf("栈空!无法打印！\n");
        return;
    }
    printf("该栈共%d个元素！\n", s.top+1);
    if (flag == 1) {
        for (int i = s.top; i>=0; i--) {
            printf("%d ", s.data[i]);
        }
    } else {
        for (int i = 0; i<=s.top; i++) {
            printf("%d ", s.data[i]);
        }
    }
    printf("\n");
}

bool stackEmpty(SqStack s) {
    return s.top == -1;
}

bool getTop(SqStack s, int &x) {
    if (s.top == -1) {
        return false;
    }
    x = s.data[s.top - 1];
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    SqStack s1;
    initStack(s1);
    int i = 0;
    while (push(s1, i++)) {
        print(s1, 1);
    }
    print(s1, 2);
    pop(s1, i);
    print(s1, 1);
    return 0;
}
