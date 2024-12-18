#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;
// cau truc ngan xep
typedef struct {
    struct Node *top;
    int size; 
} Stack;
// khoi tao ngan xep
void initStack(Stack *s) {
    s->top = NULL;
    s->size = 0;
}
// kiem tra rong
int isEmpty(Stack *s) {
    if (s->top == NULL) {
        printf("Ngan xep rong.\n");
        return 1; 
    }
    return 0;
}
// them
void push(Stack *s, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho\n");
        return;
    }
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
    s->size++; 
    printf("Da them %d vao ngan xep\n", value);
}
// xoa
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Ngan xep rong, khong the xoa\n");
        return -1;
    }
    Node *temp = s->top;
    int value = temp->data;
    s->top = s->top->next;
    free(temp);
    s->size--; 
    printf("Da xoa %d khoi ngan xep\n", value);
    return value;
}
// lay dau
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Ngan xep rong\n");
        return -1;
    }
    return s->top->data;
}
// in ra
void printStack(Stack *s) {
    if (isEmpty(s)) {
        printf("Ngan xep rong\n");
        return;
    }
    Node *temp = s->top;
    printf("Cac phan tu trong ngan xep:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
// kich thuoc
int size(Stack *s) {  
    return s->size;
}
// xoa tooan bo
void clear(Stack *s) {  
    while (!isEmpty(s)) {
        pop(s);
    }
}
// in dao nguoc
void reverseStack(Stack *s) {
    if (isEmpty(s)) {
        return;
    }
    Stack tempStack;
    initStack(&tempStack);
    while (!isEmpty(s)) {
        push(&tempStack, pop(s));
    }
    *s = tempStack; 
}

int main() {
    Stack stack;
    initStack(&stack);
    int value;

    do {
        printf("\n==============MENU=============\n");
        printf("1. Them phan tu vao ngan xep(push).\n");
        printf("2. Lay phan tu khoi ngan xep(pop).\n");
        printf("3. Kiem tra phan tu tren cung cua ngan xep(peek/top).\n");
        printf("4. Kiem tra ngan xep co rong khong(isEmpty).\n");
        printf("5. Lay kich thuoc ngan xep(size).\n");
        printf("6. In toan bo ngan xep(display).\n");
        printf("7. Xoa toan bo ngan xep(clear).\n");
        printf("8. In cac phan tu theo thu tu nguoc lai(reverse).\n");
        printf("9. Thoat.\n");
        int choice;
        printf("Nhap lua chon cua ban:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                value = peek(&stack); 
                if (value != -1) {
                    printf("Phan tu tren cung: %d\n", value);
                }
                break;
            case 4:
                if (isEmpty(&stack)) {
                    printf("Ngan xep rong.\n");
                } else {
                    printf("Ngan xep khong rong.\n");
                }
                break;
            case 5:
                printf("Kich thuoc ngan xep: %d\n", size(&stack));
                break;
            case 6:
                printStack(&stack);
                break;
            case 7:
                clear(&stack);
                printf("Ngan xep da duoc xoa.\n");
                break;
            case 8:
                reverseStack(&stack);
                printf("Ngan xep da duoc dao nguoc.\n");
                printStack(&stack); 
                break;
            case 9:
                exit(0);
            default:
                printf("Vui long nhap lai.\n");
        }
    } while (1 == 1);
    return 0;
}
