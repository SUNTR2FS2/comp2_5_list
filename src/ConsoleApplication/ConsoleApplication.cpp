// ConsoleApplication.cpp : このファイルには 'main' 関数が含まれています。
// プログラム実行の開始と終了がそこで行われます。
// ConsoleApplication.cpp : このファイルには 'main' 関数が含まれています。
// プログラム実行の開始と終了がそこで行われます。

#include <iostream>
#include <cstdio>
#include "../include/lib_func.h"

// 素数判定関数
bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main()
{
    // NUM までの素数を求める
    const int NUM = 10000;

    list lst;
    initialize_list(&lst);

    node nd[NUM]; // 素数だけを使うので NUM サイズ確保

    int count = 0;
    for (int i = 2; i <= NUM; i++) {
        if (is_prime(i)) {
            initialize_node(&nd[count], i);
            push_front(&lst, &nd[count]);
            count++;
        }
    }

    node* p = lst.header;
    while (p) {
        printf("%d, ", p->data);
        p = get_next(&lst, p);
    }
    printf("\n");

    return 0;
}