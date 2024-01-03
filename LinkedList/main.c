#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Визначаємо структуру для зберігання інформації про книгу
typedef struct Book {
    char title[100];
    float price;
    int pages;
    char language[20];
    float weight;
    int year;
    struct Book *next;
} Book;

// Функція для створення нової книги
Book* createBook(char *title, float price, int pages, char *language, float weight, int year) {
    Book *newBook = (Book*)malloc(sizeof(Book));
    if (newBook == NULL) {
        printf("Error allocating memory!\n");
        exit(1);
    }
    strcpy(newBook->title, title);
    newBook->price = price;
    newBook->pages = pages;
    strcpy(newBook->language, language);
    newBook->weight = weight;
    newBook->year = year;
    newBook->next = NULL;
    return newBook;
}

// Функція для додавання книги до зв'язаного списку
void addBook(Book **head, Book *newBook) {
    newBook->next = *head;
    *head = newBook;
}

// Функція для виводу інформації про книги
void printBooks(Book *head) {
    Book *current = head;
    while (current != NULL) {
        printf("Book: %s\n", current->title);
        printf("Price: %.2f\n", current->price);
        printf("Pages: %d\n", current->pages);
        printf("Language: %s\n", current->language);
        printf("Weight: %.2f kg\n", current->weight);
        printf("Year of Publication: %d\n", current->year);
        printf("-----------------------------\n");
        current = current->next;
    }
}

// Функція для очищення пам'яті
void freeBooks(Book *head) {
    Book *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    Book *head = NULL;

    // Додавання книг до списку
    addBook(&head, createBook("Harry Potter and the Philosopher's Stone", 10.99, 223, "English", 0.27, 1997));
    addBook(&head, createBook("Harry Potter and the Chamber of Secrets", 11.99, 251, "English", 0.29, 1998));
    addBook(&head, createBook("Harry Potter and the Prisoner of Azkaban", 12.99, 317, "English", 0.35, 1999));
    addBook(&head, createBook("Harry Potter and the Goblet of Fire", 15.99, 636, "English", 0.45, 2000));
    addBook(&head, createBook("Harry Potter and the Order of the Phoenix", 18.99, 766, "English", 0.55, 2003));
    addBook(&head, createBook("Harry Potter and the Half-Blood Prince", 20.99, 607, "English", 0.50, 2005));
    addBook(&head, createBook("Harry Potter and the Deathly Hallows", 22.99, 607, "English", 0.60, 2007));

    // Виводимо інформацію про книги
    printBooks(head);

    // Очищуємо пам'ять
    freeBooks(head);

    return 0;
}

