/**
 * @file list.c
 * @author ht
 * @brief
 * @version 0.1
 * @date 2021-12-22
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct MyLinkedList {
    int val;
    struct MyLinkedList* next;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList* newList = malloc(sizeof(MyLinkedList));   // 错误1：未分配内存赋值会段错误
    newList->val = 0;
    newList->next = NULL;
    return newList;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    do {
        if (obj->next == NULL) {
            return -1;
        } else {
            obj = obj->next;
            index--;
        }
    } while (index > 0);
    return obj->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList* NewHead = myLinkedListCreate();   // 错误2：这里重复初始化
    NewHead->val = val;
    NewHead->next = obj;
    obj = NewHead;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {

}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {

}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {

}

void myLinkedListFree(MyLinkedList* obj) {

}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/

int main(int argc, char const *argv[])
{
    MyLinkedList* obj = myLinkedListCreate();
    myLinkedListAddAtHead(obj, 1);
    // 错误2：这里打印的obj值不会变，只会是0 因为这里的obj变量指向的地址还是原来的
    printf("obj.val: %p %d\n", obj, obj->val);
    myLinkedListAddAtHead(obj, 2);
    printf("obj.val: %p %d\n", obj, obj->val);
    myLinkedListAddAtHead(obj, 3);
    printf("obj.val: %p %d\n", obj, obj->val);
    int val = myLinkedListGet(obj, 0);
    printf("val: %d\n", val);
    val = myLinkedListGet(obj, 1);
    printf("val: %d\n", val);
    val = myLinkedListGet(obj, 2);
    printf("val: %d\n", val);
    return 0;
}
