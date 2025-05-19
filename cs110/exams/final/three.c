#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _letter {
        char info;
        struct _letter *next;
} Letter;

// Build a linked list to represent the specified word.
// Return the head of the linked list built.
Letter *buildList(char word[]);

// Print the linked list.
void printList(char prefix[], Letter *head);

// Mirror a non-empty linked list.
// Note every node except the last node will be mirrored
// If the input linked list is A-->B-->C,
// the mirred linked list will be  A-->B-->C-->B-->A
Letter *mirrorList(Letter *head);

int main(void)
{
        char word[100];
        printf("Enter a word: ");
        scanf("%s", word);

        Letter *head=buildList(word);
        printList("List before mirroring: ", head);

        head=mirrorList(head);
        printList("List after mirroring: ", head);

        return 0;
}

void printList(char prefix[], Letter *head)
{
    printf("%s", prefix);
    for (Letter *ptr=head; ptr!=NULL; ptr=ptr->next) {
        if (ptr==head)
            printf("%c", ptr->info);
        else
            printf("->%c", ptr->info);
    }
    printf("\n");
}

Letter *buildList(char str[])
{
    Letter *head=NULL;
    for (int i=strlen(str)-1; i>=0; i--) {
        Letter *ptr=malloc(sizeof(Letter));
        ptr->info=str[i];
        ptr->next=head;
        head=ptr;
    }
    return head;
}

// do not change anything above this line
Letter *mirrorList(Letter *head)
{
    if (head->next == NULL) return head;        //case 1: list only contains one node. return as is.

    char word[100];                             //case 2: more than one node. Start off by going through list and recording the word except its last letter/node
    int i=0;
    for (Letter *ptr=head; ptr!=NULL; ptr=ptr->next) {
        word[i] = ptr->info;
        i++;
    }
    word[i] = '\0';

    char wordReversed[100];
    int j=0;
    for (int n=i-1-1; n>=0; n--) {
        wordReversed[j++]=word[n];
    }
    wordReversed[j] = '\0';

    strcat(word, wordReversed);

    Letter *head1 = buildList(word);
    return head1;
}