#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode; 
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
    printf("%d eklendi.\n", data);
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Liste boş.\n");
        return;
    }
    struct Node* temp = head;
    printf("Liste: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("Liste boş.\n");
        return;
    }
    struct Node* current = *head;
    struct Node* prev = NULL;

    if (current->data == key) {
        struct Node* last = *head;
        while (last->next != *head)
            last = last->next;
        if (*head == last) {
            free(*head);
            *head = NULL;
        } else {
            last->next = (*head)->next;
            free(*head);
            *head = last->next;
        }
        printf("%d silindi.\n", key);
        return;
    }

    do {
        if (current->data == key) {
            prev->next = current->next;
            free(current);
            printf("%d silindi.\n", key);
            return;
        }
        prev = current;
        current = current->next;
    } while (current != *head);

    printf("%d bulunamadı.\n", key);
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    do {
        printf("\n1. Eleman ekle\n");
        printf("2. Liste görüntüle\n");
        printf("3. Eleman sil\n");
        printf("4. Çıkış\n");
        printf("Seçiminizi yapın: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Eklenecek elemanı girin: ");
                scanf("%d", &data);
                insertNode(&head, data);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                printf("Silinecek elemanı girin: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 4:
                printf("Program sonlandırılıyor.\n");
                break;
            default:
                printf("Geçersiz seçim.\n");
        }
    } while (choice != 4);

    struct Node* current = head;
    if (head != NULL) {
        do {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        } while (current != head);
    }

    return 0;
}