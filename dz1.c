#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct locate{
    int loc;
    struct locate * next;
} locate_t;

int pop(locate_t **head) {
    locate_t * prev = NULL;
    int loc;

    if (head == NULL) {
        exit(-1);
     }  

     prev = (*head);
     loc = prev->loc;
     (*head) = (*head)->next;

     free(prev);
     return loc;#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct locate{
    int loc;
    struct locate * next;
} locate_t;

int pop(locate_t **head) {
    locate_t * prev = NULL;
    int loc;

    if (head == NULL) {
        exit(-1);
     }  

     prev = (*head);
     loc = prev->loc;
     (*head) = (*head)->next;

     free(prev);
     return loc;
}

void push(locate_t **head, int loc){
     locate_t *tmp = (locate_t*) malloc(sizeof(locate_t));
     tmp->loc = loc;
     tmp->next = (*head);
     (*head) = tmp;
}

void autofill(locate_t **head){
    
    int *arr; // указатель на массив
    int tmp_size, size;
    
    printf("Введите размер кол-во элементов:");
    scanf("%d", &size);

// Выделение памяти
    arr = (int*)malloc(size * sizeof(int));

// Ввод элементов массива
    for (tmp_size = 0; tmp_size<size; tmp_size++){
        
        printf("%d элемент = ", tmp_size + 1);
        scanf("%d", &arr[tmp_size]);
    } 

    size_t i = size - 1;

    if (arr == NULL || size == 0){
    return;
    }

    do {
    push(head, arr[i]);

    } while(i--!=0);
    
    free(arr);
}

void print(locate_t *head){
    while (head) {
        printf("%d  ", head->loc);
        head = head->next;
    }
printf("\n");

}

int main(void){

    //Добавление массива
    locate_t * head = NULL;
    autofill(&head);
    print(head);


    // Удаление элемента
    pop(&head);

    // Вывод на экран
    printf("Числа структуры:\n");
    print(head);

    return 0;
}
}

void push(locate_t **head, int data){
     locate_t *tmp = (locate_t*) malloc(sizeof(locate_t));
     tmp->loc = data;
     tmp->next = (*head);
     (*head) = tmp;
}

void autofill(locate_t **head){
    
    int *arr; // указатель на массив
    int tmp_size, size;
    
    printf("Введите размер кол-во элементов:");
    scanf("%d", &size);

// Выделение памяти
    arr = (int*)malloc(size * sizeof(int));

// Ввод элементов массива
    
    for (tmp_size = 0; tmp_size<size; tmp_size++){
        printf("%d элемент=", tmp_size + 1);
        scanf("%d", &arr[tmp_size]);
    } 

    size_t i = size - 1;

    if (arr == NULL || size == 0){
    return;
    }

    do {
    push(head, arr[i]);
    } while(i--!=0);
}

void print(locate_t *head){
    while (head) {
        printf("%d", head->loc);
        head = head->next;
    }
printf("\n");
}


int main(void){

    //Добавление массива
    locate_t * head = NULL;
    autofill(&head);


    // Удаление элемента
    pop(&head);

    // Вывод на экран
    printf("Числа структуры:\n");
    print(head);

    return 0;
}
