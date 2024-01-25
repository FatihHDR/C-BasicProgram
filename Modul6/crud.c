#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_CHAR 100

struct Book {
    int id;
    char title[MAX_CHAR];
    char author[MAX_CHAR];
    int pages;
    char genre[MAX_CHAR];
};

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Create New Book\n");
    printf("2. Display List of Books\n");
    printf("3. Update Book Information\n");
    printf("4. Delete Book\n");
    printf("5. Exit\n");
}

void createNewBook(struct Book books[], int *bookCount) {
    printf("\nEnter Book Details:\n");

    struct Book newBook;
    printf("ID: ");
    scanf("%d", &newBook.id);

    for (int i = 0; i < *bookCount; i++) {
        if (books[i].id == newBook.id) {
            printf("ID SUDAH TERDAFTAR\n");
            return;
        }
    }

    printf("Title: ");
    scanf(" %[^\n]s", newBook.title);

    printf("Author: ");
    scanf(" %[^\n]s", newBook.author);

    printf("Pages: ");
    scanf("%d", &newBook.pages);

    printf("Genre: ");
    scanf(" %[^\n]s", newBook.genre);

    books[*bookCount] = newBook;
    (*bookCount)++;
}

void displayListOfBooks(struct Book books[], int bookCount) {
    printf("\nList of Books:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("ID: %d, Title: %s, Author: %s, Pages: %d, Genre: %s\n",
               books[i].id, books[i].title, books[i].author, books[i].pages, books[i].genre);
    }
}

void updateBookInformation(struct Book books[], int bookCount) {
    int updateID, found = 0;
    printf("\nEnter the ID of the book to update: ");
    scanf("%d", &updateID);

    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == updateID) {
            printf("Enter new ID: ");
            scanf("%d", &books[i].id);

            printf("Enter new Title: ");
            scanf(" %[^\n]s", books[i].title);

            printf("Enter new Author: ");
            scanf(" %[^\n]s", books[i].author);

            printf("Enter new Pages: ");
            scanf("%d", &books[i].pages);

            printf("Enter new Genre: ");
            scanf(" %[^\n]s", books[i].genre);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

void deleteBook(struct Book books[], int *bookCount) {
    int deleteID, found = 0;
    printf("\nEnter the ID of the book to delete: ");
    scanf("%d", &deleteID);

    for (int i = 0; i < *bookCount; i++) {
        if (books[i].id == deleteID) {
            for (int j = i; j < *bookCount - 1; j++) {
                books[j] = books[j + 1];
            }
            (*bookCount)--;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

int main() {
    struct Book books[MAX_BOOKS];
    int bookCount = 0;
    FILE *file = fopen("library_books.txt", "a+");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_SET);
    while (fread(&books[bookCount], sizeof(struct Book), 1, file) == 1) {
        bookCount++;
    }

    printf("Selamat Datang di Sistem Perpustakaan\n");
    printf("Program ini dapat melakukan Create, Read, Update, dan Delete data buku.\n");

    int choice;
    do {
        displayMenu();
        printf("Pilihan Anda: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createNewBook(books, &bookCount);
                break;
            case 2:
                displayListOfBooks(books, bookCount);
                break;
            case 3:
                updateBookInformation(books, bookCount);
                break;
            case 4:
                deleteBook(books, &bookCount);
                break;
            case 5:
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }

        fseek(file, 0, SEEK_SET);
        for (int i = 0; i < bookCount; i++) {
            fwrite(&books[i], sizeof(struct Book), 1, file);
        }
    } while (choice != 5);

    fclose(file);
    return 0;
}
