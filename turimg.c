#include <stdio.h>
#include <string.h>

#define TAPE_LENGTH 1000

void turingMirror(char* tape) {
    int head = 0;
    int end = strlen(tape) - 1;

    while (head < end) {
        char temp = tape[head];
        tape[head] = tape[end];
        tape[end] = temp;
        head++;
        end--;
    }
}

int main() {
    char tape[TAPE_LENGTH]; // Лента машины Тьюринга
    printf("Введите двоичный код: ");
    scanf("%s", tape);

    printf("Исходный двоичный код: %s\n", tape);

    turingMirror(tape);

    printf("Зеркальное отображение: %s\n", tape);

    return 0;
}
