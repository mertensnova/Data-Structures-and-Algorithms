#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 15
#define DELETED_NODE (person_t *)(0xFFFFFFFFFFFUL)

typedef struct person
{
    char name[MAX_NAME];
    char age;
} person_t;

person_t *hash_table[TABLE_SIZE];

unsigned int hash(char *name)
{
    int len = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;

    for (int i = 0; i < len; i++)
    {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }

    return hash_value;
}

void init_hash_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
}

void print_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i] == NULL)
            printf("\t%i\t---\n", i);
        else if (hash_table[i] == DELETED_NODE)
            printf("\t%i\t---<deleted node>\n", i);
        else
            printf("\t%i\t%s\n", i, hash_table[i]->name);
    }
}

bool hash_table_insert(person_t *p)
{
    if (p == NULL)
        return false;

    int index = hash(p->name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[try] == NULL || hash_table[try] == DELETED_NODE)
        {
            hash_table[try] = p;
            return true;
        }
    }

    return false;
}

person_t *hash_table_delete(char *name)
{
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (i + index) % TABLE_SIZE;

        if (hash_table[try] == NULL)
        {
            return NULL;
        }
        if (hash_table[try] == DELETED_NODE)
        {

            continue;
        }

        if (strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0)
        {
            person_t *tmp = hash_table[try];
            hash_table[try] = DELETED_NODE;
            return tmp;
        }
    }

    return NULL;
}

person_t *hash_table_find(char *name)
{
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[try] == NULL)
            return false;
        if (hash_table[try] == DELETED_NODE)
            continue;

        if (strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0)
            return hash_table[try];
    }

    return NULL;
}

int main(void)
{
    init_hash_table();

    person_t kate = {.name = "Kate", .age = 203};
    person_t amr = {.name = "Amr", .age = 20};
    person_t ron = {.name = "Ron", .age = 33};

    person_t cake = {.name = "Cake", .age = 23};
    person_t george = {.name = "George", .age = 2};
    person_t susan = {.name = "Susan", .age = 3};

    person_t carol = {.name = "Carol", .age = 23};
    person_t alex = {.name = "Alex", .age = 2};
    person_t josh = {.name = "Josh", .age = 3};

    hash_table_insert(&kate);
    hash_table_insert(&amr);
    hash_table_insert(&ron);

    hash_table_insert(&cake);
    hash_table_insert(&susan);
    hash_table_insert(&george);

    hash_table_insert(&alex);
    hash_table_insert(&josh);
    hash_table_insert(&carol);

    hash_table_delete("Amr");
    hash_table_delete("Josh");
    person_t adam = {.name = "Adam", .age = 2};
    person_t jack = {.name = "Jack", .age = 3};

    hash_table_insert(&adam);
    hash_table_insert(&jack);
    // print_table();

    hash_table_insert(&amr);

    print_table();

    // person_t *tmp = hash_table_find("Alex");

    // if (tmp == NULL)
    //     printf("NOT FOUND");
    // else
    //     printf("FOUND");

    return 0;
}