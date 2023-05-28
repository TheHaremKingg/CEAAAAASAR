#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct Node {
    char data;
    struct Node* next;
} Node;
void push(Node** head, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
char pop(Node** head) {
    if (*head == NULL) {
        return '\0';
    }
    Node* temp = *head;
    char data = temp->data;
    *head = (*head)->next;
    free(temp);
    return data;
}
void chiffrementCesar(char message[], int decalage) {
    Node* stack = NULL;
    int i = 0;
    while (message[i] != '\0') {
        if (isalpha(message[i])) {
            char base = (isupper(message[i])) ? 'A' : 'a';
            char encryptedChar = ((message[i] - base + decalage) % 26) + base;
            push(&stack, encryptedChar);
        }
        i++;
    }
    i = 0;
    while (stack != NULL) {
        message[i] = pop(&stack);
        i++;
    }
    message[i] = '\0';  
     int len = i;
    for (int j = 0; j < len / 2; j++) {
        char temp = message[j];
        message[j] = message[len - 1 - j];
        message[len - 1 - j] = temp;}
}
int main() {
    int choice;
    char message[100];
    int decalage;
    printf("Menu:\n");
    printf("1. Chiffrement \n");
    printf("2. Dechiffrement\n");
    printf("pick an option : ");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Entrer un message :");
        scanf("%99s", message);
        printf("Entrer un decalage : ");
        scanf("%d", &decalage);
        chiffrementCesar(message, decalage);
        printf("Message chiffre : %s\n", message);
    } else if (choice == 2) {
        printf("Entrer le message a dechiffrer : ");
        scanf(" %99s", message);
        printf("Entrer le decalage utilise : ");
        scanf("%d", &decalage);
        chiffrementCesar(message, 26 - decalage);
        printf("Message dechiffre : %s\n", message);
    } else {
        printf("invalid option \n");
    }
    return 0;
}

