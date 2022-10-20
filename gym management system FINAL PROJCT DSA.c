#include<stdlib.h>
#include<string.h>
#include<stdio.h>

struct member
{
    int id;
    char name[100];
    char phone[100];
    float membershipperiod;
    struct member *next;
}* head;

void insert(int id, char* name, char* phone, float membershipperiod)
{

    struct member * member = (struct member *) malloc(sizeof(struct member));
    member->id = id;
    strcpy(member->name, name);
    strcpy(member->phone, phone);
    member->membershipperiod = membershipperiod;
    member->next = NULL;

    if(head==NULL){
        // if head is NULL
        // set member as the new head
        head = member;
    }
    else{
        // if list is not empty
        // insert member in beginning of head
        member->next = head;
        head = member;
    }

}
void search(int id)
{
    struct member * temp = head;
    while(temp!=NULL){
        if(temp->id==id){
            printf("\n\t\t \t \t \t \t\t \t \t \t \t    Id: %d\n", temp->id);
            printf("\n\t\t \t \t \t \t\t \t \t \t \t    Name: %s\n", temp->name);
            printf("\n\t\t \t \t \t \t\t \t \t \t \t    Phone: %s\n", temp->phone);
            printf("\n\t\t \t \t \t \t\t \t \t \t \t    Membership Period: %0.4f\n", temp->membershipperiod);
            return;
        }
        temp = temp->next;
    }
    printf("\n\t\t \t \t \t \t\t \t \t \t \t    Member with id %d is not found !!!\n", id);
}
void update(int id)
{

    struct member * temp = head;
    while(temp!=NULL){

        if(temp->id==id){
            printf("\n\t\t \t \t \t \t\t \t \t \t \t    Record with id %d Found !!!\n", id);
            printf("\n\t\t \t \t \t \t\t \t \t \t \t    Enter new name: ");
            scanf("%s", temp->name);
            printf("\n\t\t \t \t \t \t\t \t \t \t \t    Enter new phone number: ");
            scanf("%s", temp->phone);
            printf("\n\t\t \t \t \t \t\t \t \t \t \t    Enter new membershipperiod: ");
            scanf("%f",&temp->membershipperiod);
            printf("\n\t\t \t \t \t \t\t \t \t \t \t    Updation Successful!!!\n");
            return;
        }
        temp = temp->next;

    }
    printf("\n\t\t \t \t \t \t\t \t \t \t \t    Member with id %d is not found !!!\n", id);

}
void Delete(int id)
{
    struct member * temp1 = head;
    struct member * temp2 = head;
    while(temp1!=NULL){

        if(temp1->id==id){

            printf("\n\t\t \t \t \t \t\t \t \t \t \t    Record with id %d Found !!!\n", id);

            if(temp1==temp2){
                // this condition will run if
                // the record that we need to delete is the first node
                // of the linked list
                head = head->next;
                free(temp1);
            }
            else{
                // temp1 is the node we need to delete
                // temp2 is the node previous to temp1
                temp2->next = temp1->next;
                free(temp1);
            }

            printf("\n\t\t \t \t \t \t\t \t \t \t \t    Record Successfully Deleted !!!\n");
            return;

        }
        temp2 = temp1;
        temp1 = temp1->next;

    }
    printf("\n\t\t \t \t \t \t\t \t \t \t \t    Member with id %d is not found !!!\n", id);

}
void display()
{
    struct member * temp = head;
    while(temp!=NULL){

        printf("\n\t\t \t \t \t \t\t \t \t \t \t    ID: %d\n", temp->id);
        printf("\n\t\t \t \t \t \t\t \t \t \t \t    Name: %s\n", temp->name);
        printf("\n\t\t \t \t \t \t\t \t \t \t \t    Phone: %s\n", temp->phone);
        printf("\n\t\t \t \t \t \t\t \t \t \t \t    Membership Period: %0.1f\n\n", temp->membershipperiod);
        temp = temp->next;

    }
}


int main()
{
    head = NULL;
    int choice;
    char name[100];
    char phone[100];
    int id;
    float membershipperiod;


    printf("\n \n \t \t \t \t \t \t \t \t  **********************************************************************************\n");
    printf("\n\t\t\t\t\t\t \t \t \t \t \t        GYM  MANAGEMENT SYSTEM\n");
    printf("\n \t \t\t \t \t \t \t \t  **********************************************************************************\n");

    printf("\n\n\t\t \t \t \t \t\t \t \t \t \t    1] To Insert Member Details\n\n\t\t \t \t \t \t\t\t \t \t\t    2] To Search for Member Details\n\n \t \t \t\t \t \t \t \t \t \t\t    3] To Delete Member Details\n\n\t\t \t\t \t \t \t \t \t \t\t    4] To Update Member Details\n\n\t\t \t \t \t \t \t \t\t \t\t    5] To Display all Member Details\n\n\t\t \t \t \t \t \t \t\t \t\t    6] Exit\n\n");
    do
    {
        printf("\n\n\t\t\t \t \t \t \t \t    Enter Choice : --> ");
        scanf("%d", &choice);
        switch (choice)
        {

            case 1:
    printf("\n \n \t \t \t \t \t \t \t \t  **********************************************************************************\n");
    printf("\n\t\t\t\t\t\t \t \t \t \t \t \t   INSERT DETAILS\n");
    printf("\n \t \t\t \t \t \t \t \t  **********************************************************************************\n");
                printf("\n\t\t \t \t \t \t\t \t \t \t \t    Enter Id : - ");
                scanf("%d", &id);
                printf("\n\t\t \t \t \t \t\t \t \t \t \t    Enter Name : - ");
                scanf("%s", name);
                printf("\n\t\t \t \t \t \t\t \t \t \t \t    Enter Phone Number : - ");
                scanf("%s", phone);
                printf("\n\t\t \t \t \t \t\t \t \t \t \t    Enter Membership Period In Years : - ");
                scanf("%f", &membershipperiod);
                insert(id, name, phone, membershipperiod);
                break;


            case 2:
    printf("\n \n \t \t \t \t \t \t \t \t  **********************************************************************************\n");
    printf("\n\t\t\t\t\t\t \t \t \t \t \t \t   SEARCH DETAILS\n");
    printf("\n \t \t\t \t \t \t \t \t  **********************************************************************************\n");
                printf("\n\t\t \t \t \t \t\t \t \t \t \t    Enter Id To Search : - ");
                scanf("%d", &id);
                search(id);
                break;


            case 3:
    printf("\n \n \t \t \t \t \t \t \t \t  **********************************************************************************\n");
    printf("\n\t\t\t\t\t\t \t \t \t \t \t \t   DELETE DETAILS\n");
    printf("\n \t \t\t \t \t \t \t \t  **********************************************************************************\n");
                printf("\n\t\t \t \t \t \t\t \t \t \t \t    Enter Id  To Delete : - ");
                scanf("%d", &id);
                Delete(id);
                break;


            case 4:
    printf("\n \n \t \t \t \t \t \t \t \t  **********************************************************************************\n");
    printf("\n\t\t\t\t\t\t \t \t \t \t \t \t   UPDATE DETAILS\n");
    printf("\n \t \t\t \t \t \t \t \t  **********************************************************************************\n");
                printf("\n\t\t \t \t \t \t\t \t \t \t \t    Enter Id To Update : - ");
                scanf("%d", &id);
                update(id);
                break;


            case 5:
    printf("\n \n \t \t \t \t \t \t \t \t  **********************************************************************************\n");
    printf("\n\t\t\t\t\t\t \t \t \t \t \t \t   DISPLAY DETAILS : - \n");
    printf("\n \t \t\t \t \t \t \t \t  **********************************************************************************\n");
                display();
                break;


            case 6:
                exit(0);
                break;
        }

    } while (choice != 0);
}
