#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
struct item {
    char id[20];
    char name[20];
    double scores;
};
struct Node {
    item key; //truong key cua du lieu
    Node *Left, *Right; //con trai va con phai
};
typedef Node *Tree;  //cay
 
int compare(item x, item y) { // so sanh 2 item theo key
    return strcmp(x.id, y.id);
}
 
item inputItem() {  // nhap 1 item
    item x;
    char id[20];
    printf("Enter id of student (q to quit): ");
    gets(x.id);
 
    if (strcmp(x.id, "q") == 0 || strcmp(x.id, "Q") == 0) {
        return x;
    }
 
    printf("Enter name of student: ");
    gets(x.name);
 
    printf("Enter scores of student:");
    scanf("%lf", &x.scores);
 
    //fflush(stdin);
    while (getchar() != '\n');
 
    return x;
}
 
void outItem(item x) {
    printf("%-20s %-20s %-3.2f \n", x.id, x.name, x.scores);
}
 
int insertNode(Tree &T, item x) // chen 1 Node vao cay
        {
    if (T != NULL) {
        if (compare(T->key, x) == 0)
            return -1;  // Node nay da co
        if (compare(T->key, x) > 0)
            return insertNode(T->Left, x); // chen vao Node trai
        else if (compare(T->key, x) < 0)
            return insertNode(T->Right, x);   // chen vao Node phai
    }
    T = (Node *) malloc(sizeof(Node));
    if (T == NULL)
        return 0;    // khong du bo nho
    T->key = x;
    T->Left = T->Right = NULL;
    return 1;   // ok
}
 
void CreateTree(Tree &T)        // nhap cay
        {
    item x;
    while (1) {
        printf("Enter a student: ");
        x = inputItem();
        if (strcmp(x.id, "q") == 0 || strcmp(x.id, "Q") == 0)
            break;  // x = 0 thi thoat
        int check = insertNode(T, x);
        if (check == -1)
            printf("Student is exits!");
        else if (check == 0)
            printf("Memory full");
 
    }
}
 
// Duyet theo LNR
void LNR(Tree T) {
    if (T != NULL) {
        LNR(T->Left);
        outItem(T->key);
        LNR(T->Right);
    }
}
 
Node* searchScores(Tree T, int scores)     // tim nut co diem < 4
        {
    if (T != NULL) {
        if (T->key.scores < scores) {
            Node *P = T;
            return P;
        }
        if (T->key.scores >= scores) {
            Node *node = searchScores(T->Left, scores);
            if (node != NULL)
                return node;
            else {
                return searchScores(T->Right, scores);
            }
        }
    }
    return NULL;
}
 
int delKey(Tree &T, item x)     // xoa nut co key x
        {
    if (T == NULL)
        return 0;
    else if (compare(T->key, x) > 0)
        return delKey(T->Left, x);
    else if (compare(T->key, x) < 0)
        return delKey(T->Right, x);
    else // T->key == x
    {
        Node *P = T;
        if (T->Left == NULL)
            T = T->Right;    // Node chi co cay con phai
        else if (T->Right == NULL)
            T = T->Left;   // Node chi co cay con trai
        else // Node co ca 2 con
        {
            Node *S = T, *Q = S->Left;
            // S la cha cua Q, Q la Node phai nhat cua cay con trai cua P
            while (Q->Right != NULL) {
                S = Q;
                Q = Q->Right;
            }
            P->key = Q->key;
            S->Right = Q->Left;
            delete Q;
        }
    }
    return 1;
}
 
int main() {
    Tree T;
    T = NULL; //Tao cay rong
 
    CreateTree(T); //Nhap cay
    //duyet cay
    printf("LNR: \n");
    LNR(T);
    printf("\n");
 
    // them sinh vien
    item x;
    printf("Enter id of student to add: ");
    x = inputItem();
    if (insertNode(T, x) == -1) {
        printf("add failt!");
    } else {
        printf("add success:\n");
        printf("LNR after add item: \n");
        LNR(T);
        printf("\n");
    }
 
    // xoa sinh vien co diem nho hon 4
    int del = 1;
    while (del) {
        Node* node = searchScores(T, 4);
        if (node != NULL) {
            printf("del");
            del = delKey(T, node->key);
        } else {
            printf("null");
            del = 0;
        }
    }
    printf("LNR after delete item: \n");
    LNR(T);
    printf("\n");
    return 0;
}

