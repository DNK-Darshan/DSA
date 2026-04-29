#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Create multiple nodes
void create_nodes(int n)
{
    struct node *newnode, *temp;

    for(int i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        if(newnode == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }

        printf("Enter data %d: ", i + 1);
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
}

// Insert at position
void insert_at_pos()
{
    struct node *newnode, *temp;
    int pos, count = 0;

    temp = head;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos <= 0 || pos > count + 1)
    {
        printf("Invalid position\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if(pos == 1)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        temp = head;

        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }
}

// Delete at position
void delete_pos()
{
    struct node *temp, *nextnode;
    int pos, count = 0;

    temp = head;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    if(count == 0)
    {
        printf("List is empty\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos <= 0 || pos > count)
    {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    else
    {
        temp = head;

        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        nextnode = temp->next;
        temp->next = nextnode->next;
        free(nextnode);
    }
}

// Display list
void display()
{
    struct node *temp = head;

    if(temp == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("List: ");
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice, n;

    while(1)
    {
        printf("\n===== MENU =====\n");
        printf("1. Create Nodes\n");
        printf("2. Insert at Position\n");
        printf("3. Delete at Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("How many nodes? ");
                scanf("%d", &n);
                create_nodes(n);
                break;

            case 2:
                insert_at_pos();
                break;

            case 3:
                delete_pos();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}