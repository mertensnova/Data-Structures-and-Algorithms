#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person_node
{
    int numbers;
    struct person_node *next;

} node;

node *create_node(int numbers);
node *find_node(node *head, int value);
node *insert_at_head(node *head, int value);
void *update_node(node *head, int value, int new_value);
void *delete_node(node **head, int numbers);
void *insert_at_tail(node *head, int value);
void *insert_after_node(node *head, int value);
void print_list(node *head);
void write_file(node *head);
void read_file(node *head);

int main(void)
{
    node *head = NULL;
    node *tmp;

    head = insert_at_head(head, 19);

    for (int i = 0; i < 25; i++)
    {
        insert_at_tail(head, i);
    }

    // write_file(head);
    // read_file(tmp);
    update_node(head, 19, 22);
    print_list(head);

    return 0;
}

node *insert_at_head(node *head, int value)
{
    node *new = malloc(sizeof(node));
    new->numbers = value;
    new->next = head;

    return new;
}

void *insert_after_node(node *head, int value)
{
    node *new = malloc(sizeof(node));
    new->numbers = value;
    new->next = head->next;
    head->next = new;

    return new;
}

void *insert_at_tail(node *head, int value)
{
    node *tmp = head;
    while (tmp->next != NULL)
        tmp = tmp->next;

    node *new = malloc(sizeof(node));
    new->numbers = value;
    new->next = NULL;
    tmp->next = new;
}

void *delete_node(node **head, int value)
{
    node *tmp = *head;
    node *prev = *head;
    node *curr = *head;

    while (tmp->numbers != value)
    {
        prev = curr;
        curr = curr->next;
        tmp = tmp->next;
    }
    prev->next = curr->next;
    free(curr);
    curr = NULL;
}

void *update_node(node *head, int value, int new_value)
{
    node *tmp = head;

    while (tmp->numbers != value)
        tmp = tmp->next;

    tmp->numbers = new_value;
}

node *create_node(int numbers)
{
    node *new = malloc(sizeof(node));
    new->numbers = numbers;
    new->next = NULL;

    return new;
}
node *find_node(node *head, int value)
{
    node *tmp = head;
    while (tmp->numbers != value)
        tmp = tmp->next;

    printf("Node %d found at address %p\n", tmp->numbers, *tmp);
}

void print_list(node *head)
{
    node *tmp = head;

    while (tmp != NULL)
    {
        printf("%d =>", tmp->numbers);
        tmp = tmp->next;
    }

    printf("\n");
}
void write_file(node *head)
{
    FILE *fp = fopen("Data.txt", "w");
    node *tmp = head;

    while (tmp != NULL)
    {
        fprintf(fp, "%d, ", tmp->numbers);
        tmp = tmp->next;
    }

    fclose(fp);
}
void read_file(node *head)
{
    FILE *fp = fopen("Data.txt", "r");
    node *tmp = malloc(sizeof(node));
    int value;

    while (fscanf(fp, "%d ,", &value) > 0)
        insert_at_tail(head, value);

    fclose(fp);
}