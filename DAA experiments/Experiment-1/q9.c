#include <stdio.h>

struct Book
{
    int id;
    char title[100];
    char author[100];
    int total;
    int available;
};

int main()
{
    struct Book books[100];
    int n = 0;
    int choice, id, i, found;

    while(1)
    {
        printf("\n\n===== LIBRARY MENU =====");
        printf("\n1. Add Book");
        printf("\n2. Search Book");
        printf("\n3. Issue Book");
        printf("\n4. Return Book");
        printf("\n5. Display Unavailable Books");
        printf("\n6. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("\nEnter Book ID: ");
            scanf("%d", &books[n].id);

            printf("Enter Title: ");
            scanf(" %[^\n]", books[n].title);

            printf("Enter Author: ");
            scanf(" %[^\n]", books[n].author);

            printf("Enter Total Copies: ");
            scanf("%d", &books[n].total);

            books[n].available = books[n].total;

            n++;

            printf("Book added successfully.");
        }

        else if(choice == 2)
        {
            printf("Enter Book ID: ");
            scanf("%d", &id);

            found = 0;

            for(i = 0; i < n; i++)
            {
                if(books[i].id == id)
                {
                    printf("\nTitle: %s", books[i].title);
                    printf("\nAuthor: %s", books[i].author);
                    printf("\nAvailable Copies: %d", books[i].available);
                    found = 1;
                    break;
                }
            }

            if(!found)
                printf("Book not found.");
        }

        else if(choice == 3)
        {
            printf("Enter Book ID: ");
            scanf("%d", &id);

            found = 0;

            for(i = 0; i < n; i++)
            {
                if(books[i].id == id)
                {
                    found = 1;

                    if(books[i].available > 0)
                    {
                        books[i].available--;
                        printf("Book issued successfully.");
                    }
                    else
                    {
                        printf("Book is unavailable.");
                    }

                    break;
                }
            }

            if(!found)
                printf("Book not found.");
        }

        else if(choice == 4)
        {
            printf("Enter Book ID: ");
            scanf("%d", &id);

            found = 0;

            for(i = 0; i < n; i++)
            {
                if(books[i].id == id)
                {
                    found = 1;

                    if(books[i].available < books[i].total)
                    {
                        books[i].available++;
                        printf("Book returned successfully.");
                    }
                    else
                    {
                        printf("All copies are already available.");
                    }

                    break;
                }
            }

            if(!found)
                printf("Book not found.");
        }

        else if(choice == 5)
        {
            printf("\nUnavailable Books:\n");

            for(i = 0; i < n; i++)
            {
                if(books[i].available == 0)
                {
                    printf("\nID: %d", books[i].id);
                    printf("\nTitle: %s", books[i].title);
                    printf("\nAuthor: %s\n", books[i].author);
                }
            }
        }

        else if(choice == 6)
        {
            printf("Exiting...");
            break;
        }

        else
        {
            printf("Invalid choice.");
        }
    }

    return 0;
}