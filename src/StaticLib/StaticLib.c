#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

// ノードを初期化
void initialize_node(node* p, int val)
{
    p->pNext = NULL;
    p->data = val;
}

// リストを初期化
void initialize_list(list* l)
{
    l->header = NULL;
}

// 先頭にデータを追加
void push_front(list* l, node* p)
{
    if (!l || !p) return;
    p->pNext = l->header;   // 今の先頭を次にする
    l->header = p;          // 新しいノードを先頭に
}

// pの次のノードを削除
void remove_next(list* l, node* p)
{
    if (!l || !p) return;
    node* target = p->pNext;
    if (target == NULL) return; // 次がない場合は何もしない
    p->pNext = target->pNext;   // 次の次を繋げる
    // メモリ解放は不要（テストではスタック変数を使っているため）
}

// pの次のノードを取得
node* get_next(list* l, node* p)
{
    (void)l; // lstは使わないが、インターフェースに含まれている
    if (!p) return NULL;
    return p->pNext;
}