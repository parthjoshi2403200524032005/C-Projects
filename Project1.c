#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a contact
struct Contact {
    char name[50];
    char phone[20];
    char email[50];
};

// Function prototypes
void addContact(struct Contact contacts[], int *numContacts);
void listContacts(struct Contact contacts[], int numContacts);
void searchContact(struct Contact contacts[], int numContacts, const char *name);
void deleteContact(struct Contact contacts[], int *numContacts, const char *name);

int main() {
    struct Contact contacts[100]; // Array to store contacts
    int numContacts = 0; // Number of contacts currently stored

    int choice;
    do {
        // Display menu
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. List Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &numContacts);
                break;
            case 2:
                listContacts(contacts, numContacts);
                break;
            case 3: {
                char searchName[50];
                printf("Enter name to search: ");
                scanf("%s", searchName);
                searchContact(contacts, numContacts, searchName);
                break;
            }
            case 4: {
                char deleteName[50];
                printf("Enter name to delete: ");
                scanf("%s", deleteName);
                deleteContact(contacts, &numContacts, deleteName);
                break;
            }
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to add a new contact
void addContact(struct Contact contacts[], int *numContacts) {
    if (*numContacts >= 100) {
        printf("Contact list is full. Cannot add more contacts.\n");
        return;
    }

    struct Contact newContact;
    printf("Enter name: ");
    scanf("%s", newContact.name);
    printf("Enter phone number: ");
    scanf("%s", newContact.phone);
    printf("Enter email address: ");
    scanf("%s", newContact.email);

    contacts[*numContacts] = newContact;
    (*numContacts)++;
    printf("Contact added successfully.\n");
}

// Function to list all contacts
void listContacts(struct Contact contacts[], int numContacts) {
    if (numContacts == 0) {
        printf("No contacts available.\n");
        return;
    }

    printf("List of Contacts:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("%d. Name: %s, Phone: %s, Email: %s\n", i + 1, contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

// Function to search for a contact by name
void searchContact(struct Contact contacts[], int numContacts, const char *name) {
    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Contact found:\n");
            printf("Name: %s, Phone: %s, Email: %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to delete a contact by name
void deleteContact(struct Contact contacts[], int *numContacts, const char *name) {
    int found = 0;
    for (int i = 0; i < *numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            found = 1;
            for (int j = i; j < *numContacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*numContacts)--;
            printf("Contact deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}
