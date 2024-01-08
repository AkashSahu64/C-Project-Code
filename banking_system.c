#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20
typedef struct
{
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;
Contact contacts[MAX_CONTACTS];
int numContacts = 0;
void addContact();
void deleteContact();
void updateContact();
void displayContacts();
int main()
{
    int choice;
    while (1)
    {
        printf("\n--- Contact Manager ---\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Update Contact\n");
        printf("4. Display Contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addContact();
            break;
        case 2:
            deleteContact();
            break;
        case 3:
            updateContact();
            break;
        case 4:
            displayContacts();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
void addContact()
{
    if (numContacts >= MAX_CONTACTS)
    {
        printf("Maximum contacts reached.\n");
        return;
    }
    Contact newContact;
    printf("Enter name: ");
    scanf("%s", newContact.name);
    printf("Enter phone number: ");
    scanf("%s", newContact.phone);
    contacts[numContacts++] = newContact;
    printf("Contact added successfully.\n");
}
void deleteContact()
{
    if (numContacts == 0)
    {
        printf("No contacts to delete.\n");
        return;
    }
    int i, index;
    char name[MAX_NAME_LENGTH];
    printf("Enter name to delete: ");
    scanf("%s", name);
    for (i = 0; i < numContacts; i++)
    {
        if (strcmp(contacts[i].name, name) == 0)
        {
            index = i;
            break;
        }
    }
    if (i == numContacts)
    {
        printf("Contact not found.\n");
        return;
    }
    for (i = index; i < numContacts - 1; i++)
    {
        contacts[i] = contacts[i + 1];
    }
    numContacts--;
    printf("Contact deleted successfully.\n");
}
void updateContact()
{
    if (numContacts == 0)
    {
        printf("No contacts to update.\n");
        return;
    }
    int i, index;
    char name[MAX_NAME_LENGTH];
    printf("Enter name to update: ");
    scanf("%s", name);
    for (i = 0; i < numContacts; i++)
    {
        if (strcmp(contacts[i].name, name) == 0)
        {
            index = i;
            break;
        }
    }
    if (i == numContacts)
    {
        printf("Contact not found.\n");
        return;
    }
    Contact updatedContact;
    printf("Enter new name: ");
    scanf("%s", updatedContact.name);
    printf("Enter new phone number: ");
    scanf("%s", updatedContact.phone);
    contacts[index] = updatedContact;
    printf("Contact updated successfully.\n");
}
void displayContacts()
{
    if (numContacts == 0)
    {
        printf("No contacts to display.\n");
        return;
    }
    printf("--- Contact List ---\n");
    for (int i = 0; i < numContacts; i++)
    {
        printf("Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
    }
}