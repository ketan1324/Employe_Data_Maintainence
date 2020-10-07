#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct employee
{
    int Employee_id;
     char Name[35];
     char Project_Working[50] ;
     long int Salary;
    struct employee *next;
    struct employee *prev;
};

typedef struct employee EMP;
typedef struct employee* PEMP;
typedef struct employee** PPEMP;
///***********************************************************************************************
void InsertFirst(PPEMP head,PPEMP tail,int id,char *name,char *project_work,long int salary)
{
        PEMP newn=NULL;
        newn=(PEMP)malloc(sizeof(EMP));
        newn->Employee_id=id;
        strcpy(newn->Name,name);
        strcpy(newn->Project_Working,project_work);
        newn->Salary=salary;

        if((*head==NULL)&&(*head==NULL))
        {
            *head=newn;
            *tail=newn;
        }

        else
            {
                newn->next=*head;
                (*head)->prev=newn;
                *head=newn;
            }
            (*tail)->next=*head;
            (*head)->prev=*tail;
}

///***********************************************************************************************
void InsertLast(PPEMP head,PPEMP tail,int id,char *name,char *project_work,long int salary)
{
      PEMP newn=NULL;
        newn=(PEMP)malloc(sizeof(EMP));
        newn->Employee_id=id;
        strcpy(newn->Name,name);
        strcpy(newn->Project_Working,project_work);
        newn->Salary=salary;

        if((*head==NULL)&&(*head==NULL))
        {
            *head=newn;
            *tail=newn;
        }
        else
        {
            (*tail)->next=newn;
            newn->prev=*tail;
            *tail=newn;
        }
            (*tail)->next=*head;
            (*head)->prev=*tail;


}

///***********************************************************************************************

void InsertAtPos(PPEMP head,PPEMP tail,int id,char *name,char *project_work,long int salary,int pos)
{
    int i=0;
    PEMP temp=*head;
    PEMP temp2;
         PEMP newn=NULL;
        newn=(PEMP)malloc(sizeof(EMP));
        newn->Employee_id=id;
       strcpy(newn->Name,name);
        strcpy(newn->Project_Working,project_work);
        newn->Salary=salary;

        if((*head==NULL)&&(*head==NULL))
        {
            *head=newn;
            *tail=newn;
        }
        else
        {
            for(i=1;i<pos-1;i++)
            {
                temp=temp->next;
            }
            newn->next=temp->next;
            temp->next->prev=newn;
            temp->next=newn;
            newn->prev=temp;
        }

}

///***********************************************************************************************
void DeleteFirst(PPEMP head,PPEMP tail)
{
     if(*head == NULL && *tail == NULL)  // Empty linked list
    {
        return;
    }

    if(*head == *tail)  // Singl node
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
    }
    else

    {*head=(*head)->next;
    free((*head)->prev);}
    (*tail)->next=*head;
    (*head)->prev=*tail;
}
///***********************************************************************************************

void DeleteLast(PPEMP head,PPEMP tail)
{
       if(*head == NULL && *tail == NULL)  // Empty linked list
    {
        return;
    }
    *tail=(*tail)->prev;
    free((*tail)->next);
    (*tail)->next=*head;
    (*head)->prev=*tail;
}
///***********************************************************************************************


void DeleteAtPos(PPEMP head,PPEMP tail,int pos)
{
    int i=0;
    PEMP temp=*head;
    for(i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
    temp->next=temp->next->next;
    free(temp->next->prev);
    temp->next->prev=temp;

}
///***********************************************************************************************
void Display(PEMP head,PEMP tail)
{
   if((head == NULL) && (tail == NULL))
        {
            return;
        }
        do
        {
            printf("\n Employee id is = %d",head->Employee_id);
            printf("\n Name of the Employee is = %s",head->Name);
            printf("\nProject he is working in = %s",head->Project_Working);
            printf("\nSalary of the Employee is %d\n",head->Salary);
            head = head->next;
        }while(head != tail->next);

}

///***********************************************************************************************
int Count(PEMP head,PEMP tail)
{
   int iCnt = 0;

        if((head == NULL) && (tail == NULL))
        {
            return 0;
        }

        do
        {
            iCnt++;
            head = head->next;
        }while(head != tail->next);

    return iCnt;

}
int main()
{
    PEMP first=NULL;
    PEMP last=NULL;
    int employee_id=0,choice=1;
    long int salary=0;
    char Name[35];
    char Project_Working[50];
    int iPos=0,iRet=0;

    printf("\t\tWelcome to ketans application");


    while(choice!=0)
    {

        printf("\n---------------------------------\n");

        printf("\n1:InsertFirst\n2:InsertLast\n3.InsertAtPos\n4:DeleteFirst\n5:DeleteLast6:DeleteAtPos\n7:Dispalay\n8:Count");

        printf("\n---------------------------------");
        printf("\n\nEnter the choice\n");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("Please Enter the Employee id-\n");
            scanf("%d",&employee_id);
            printf("Please Enter your Name : \n");
            scanf(" %[^\n]s",Name);
            printf("Please Enter the project you are currenty working in: \n ");
            scanf("  %[^\n]s",Project_Working);
            printf("Please Enter your salary");
            scanf(" %lu",&salary);
            InsertFirst(&first,&last,employee_id,Name,Project_Working,salary);
            break;

        case 2:
            printf("Please Enter the Employee id-\n");
            scanf("%d",&employee_id);
            printf("Please Enter your Name : \n");
            scanf("   %[^\n]s",Name);
            printf("Please Enter the project you are currenty working in: \n ");
            scanf(" %[^\n]s",Project_Working);
            printf("Please Enter your salary");
            scanf(" %lu",&salary);
            InsertLast(&first,&last,employee_id,Name,Project_Working,salary);
            break;

        case 3:
            printf("Please Enter the Employee id-\n");
            scanf("%d",&employee_id);
            printf("Please Enter your Name : \n");
            scanf(" %[^\n]s",Name);
            printf("Please Enter the project you are currenty working in: \n ");
            scanf(" %[^\n]s",Project_Working);
            printf("Please Enter your salary");
            scanf(" %lu",&salary);
            printf("Enter the position you wish to insert Employee information: \n ");
            scanf(" %d",&iPos);
            InsertAtPos(&first,&last,employee_id,Name,Project_Working,salary,iPos);
            break;


        case 4:
            DeleteFirst(&first,&last);
            break;

        case 5:
            DeleteLast(&first,&last);
            break;

        case 6:
            printf("Enter the POSITION you wish to delete Employee information :\n");
            scanf("%d",iPos);
            DeleteAtPos(&first,&last,iPos);
            break;

        case 7:
            Display(first,last);
            break;

        case 8:
            iRet=Count(first,last);
            printf("The Number Of available Employee information is : %d",iRet);
            break;

        case 0:
            printf("Thankyou for using the application\n ");




        }
    }


}
