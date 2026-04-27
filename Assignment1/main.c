#include <stdio.h>
#include <string.h>

#define MAX 5   // صغير لحتى يبين overflow

typedef struct {
    char data[MAX];
    int front;
    int rear;
    int used;
} Buffer;

// تهيئة
void setup(Buffer *b) {
    b->front = 0;
    b->rear = 0;
    b->used = 0;
}

// هل فاضي؟
int isEmpty(Buffer *b) {
    return b->used == 0;
}

// هل مليان؟
int isFull(Buffer *b) {
    return b->used == MAX;
}

// إدخال
int push(Buffer *b, char c) {
    if (isFull(b)) {
        printf("Overflow!\n");
        return 0;
    }

    b->data[b->rear] = c;
    b->rear = (b->rear + 1) % MAX; // حركة دائرية
    b->used++;

    return 1;
}

// إخراج
char pop(Buffer *b) {
    if (isEmpty(b)) {
        printf("Underflow!\n");
        return '\0';
    }

    char c = b->data[b->front];
    b->front = (b->front + 1) % MAX;
    b->used--;

    return c;
}

int main() {

    Buffer b;
    setup(&b);

    char input[50];

    printf("Enter name: ");
    scanf("%49s", input);

    // إضافة النص المطلوب
    strcat(input, "CE-ESY");

    // تخزين الأحرف
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (!push(&b, input[i])) {
            break; // وقف إذا امتلأ
        }
    }

    printf("Output: ");

    // قراءة وطباعة
    while (!isEmpty(&b)) {
        char ch = pop(&b);
        printf("%c", ch);
    }

    printf("\n");

    // تأكيد
    if (isEmpty(&b)) {
        printf("Buffer empty now\n");
    }

    return 0;
}
