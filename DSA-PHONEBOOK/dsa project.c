#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    char firstname[20];
    char lastname[20];
    long double number;
    struct node *next;
};


struct node *start=NULL;

struct node *getnode()
{
    return((struct node *)malloc(sizeof(struct node)));
} 


void display(struct node *start)
{
    struct node *temp;
    temp=start;
    while(temp!=NULL)
    {
        printf("%s\n",temp->firstname);
        printf("%s\n",temp->lastname);
        printf("%ld\n",temp->number);
        temp=temp->next;
    }
}
/*void sort()
{
    struct node *temp,*pretemp;
    char *p;
    temp=start;
    pretemp=start->next;
    while(pretemp!=NULL)
    {
    if(strcmp(temp->lastname,pretemp->lastname)>0)
    {
        if(temp->lastname==pretemp->lastname)
        {
            if(strcmp(temp->firstname,pretemp->firstname)>0)
            {
                p=temp->firstname;
                temp->firstname=pretemp->firstname;
                pretemp->firstname=p;   
            }
        }
        else
        {
                p=temp->lastname;
                temp->lastname=pretemp->firstname;
                pretemp->firstname=p;
        }
    }
    }
}
*/
void insert()
{
    struct node *temp,*new;
    new=getnode();
    temp=start;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        
    }
    printf("Enter First name:\n");
    scanf("%s",&new->firstname);
    printf("Enter Last name:\n");
    scanf("%s",&new->lastname);
    printf("Enter number:\n");
    scanf("%ld",&new->number);
    temp->next=new;
    new->next=NULL;
    display(start);
}

struct node *create()
{
    struct node *temp,*new;
    if(start!=NULL)
        insert();
    else
    {
    new=getnode();
    start=new;
    temp=start;
    printf("Enter First name:\n");
    scanf("%s",&new->firstname);
    printf("Enter Last name:\n");
    scanf("%s",&new->lastname);
    printf("Enter number:\n");
    scanf("%ld",&new->number);
    new->next=NULL;
    display(start);
    }
}
void search()
{
    struct node *temp;
    char *f,*l;
    temp=start;
    printf("Enter name to be searched:\n");
    scanf("%s",&f);
    scanf("%s",&l);
    while((temp->firstname==f)&&(temp->lastname==l))
    {
        temp=temp->next;
    }
    printf("%s\n",temp->firstname);
    printf("%s\n",temp->lastname);
    printf("%ld\n",temp->number);
}

void del()
{
    struct node *pretemp,*temp;
    char *f,*l;
    temp=start;
    pretemp=start->next;
    printf("Enter name :");
    scanf("%s",&f);
    scanf("%s",&l);
    while(temp!=NULL)
    {
        if((pretemp->firstname==f)&&(pretemp->lastname==l))
        {
            printf("%s ",temp->firstname);
            printf("%s ",temp->lastname);
            printf("%ld ",temp->number);
            temp->next=pretemp->next;
            free(pretemp);
            printf("contact deleted");
            break;
        }
        else 
        {
            temp=temp->next;
            pretemp=pretemp->next;
        }
        
        
    }
}

int main()
{
    int option,choice;
    do{
        printf("\n-------PHONEBOOK--------\n\n ");
        printf("1.Create contact\n2.Insert contact\n3.Display all contacts\n4.Delete contact\n5.Search contact\n");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: create();
            break;
            case 2: insert();
            break;	
            case 3: display(start);
            break;
            case 4: del();
            break;
            case 5:search();
            break;
            /*case 6:sort();
            break;*/
        }
        printf("\n\nDo you want to quit ? 1 for continue / 0 for quit:\n\n");
        scanf("%d",&option);
    }while(option!=0);
return 0;
}

