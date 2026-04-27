#include <stdio.h>
#include <string.h>

#define MAX 5   

typedef struct {
    char data[MAX];
    int front;
    int rear;
    int used;
} Buffer;

void setup(Buffer *b) {
    b->front = 0;
    b->rear = 0;
    b->used = 0;
}

int isEmpty(Buffer *b) {
    return b->used == 0;
}

int isFull(Buffer *b) {
    return b->used == MAX;
}

int push(Buffer *b, char c) {
    if (isFull(b)) {
        printf("Overflow!\n");
        return 0;
    }

    b->data[b->rear] = c;
    b->rear = (b->rear + 1) % MAX; 
    b->used++;

    return 1;
}

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

    strcat(input, "CE-ESY");

    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (!push(&b, input[i])) {
            break;
        }
    }

    printf("Output: ");

    while (!isEmpty(&b)) {
        char ch = pop(&b);
        printf("%c", ch);
    }

    printf("\n");

    if (isEmpty(&b)) {
        printf("Buffer empty now\n");
    }

    return 0;
}
