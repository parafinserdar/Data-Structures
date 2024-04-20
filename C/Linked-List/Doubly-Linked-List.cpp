#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    printf("%d basıldı, eleman eklendi.\n", data);
}

void insertAtIndex(struct Node** head, int data, int index) {
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    int i = 0;

    if (index == 0) {
        insertAtBeginning(head, data);
        return;
    }

    while (current != NULL && i < index - 1) {
        current = current->next;
        i++;
    }

    if (current == NULL) {
        printf("Belirtilen indeks mevcut değil.\n");
        return;
    }

    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    printf("%d basıldı, belirtilen indekse eleman eklendi.\n", data);
}

void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        printf("Bağlı liste boş, silinecek eleman yok.\n");
        return;
    }

    struct Node* current = *head;
    while (current != NULL) {
        if (current->data == data) {
            if (current->prev == NULL) {
                *head = current->next;
            } else {
                current->prev->next = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            printf("%d basıldı, eleman silindi.\n", data);
            free(current);
            return;
        }
        current = current->next;
    }

    printf("%d bulunamadı, silme işlemi yapılamadı.\n", data);
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Bağlı liste boş.\n");
        return;
    }

    printf("Bağlı Liste: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, index;

    while (1) {
        printf("\n1: Eleman ekle\n2: Eleman sil\n3: Listeyi göster\n4: Belirli bir index'e eleman ekle\n5: Programı sonlandır\n");
        printf("Seçiminiz: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Eklemek istediğiniz elemanı girin: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Silmek istediğiniz elemanı girin: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Eklemek istediğiniz elemanı ve index'i girin (index 0'dan başlar): ");
                scanf("%d %d", &data, &index);
                insertAtIndex(&head, data, index);
                break;
            case 5:
                printf("Program sonlandırılıyor...\n");
                exit(0);
            default:
                printf("Geçersiz seçim. Lütfen tekrar deneyin.\n");
        }
    }

    return 0;
}