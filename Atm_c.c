#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define DataFile "AccountData.txt"
#define S_Size sizeof(detail_t)
struct details
{
    char username[30];
    int pass;
    int init_amt;
};

int i;
int balance;
int total_user=0;
typedef struct details detail_t;

int Person_check(detail_t*,int n);
void withdraw_cash(detail_t*);
void check_balance(detail_t*);
void change_pin(detail_t* e);
void deposit_cash(detail_t *e);
void details(detail_t *e);
void star_horizontal();
void gap();
void data_update(detail_t* e);

int main()
{
    // detail_t e[] = {{"Praneeth Nairy",2005,50000},{"Prajwal",2002,80000},{"R Rahul",4573,100000},{"Prithvi Palachandra",9628,200000},{"Girish",1758,300000},{"Vinay",2003,50000},{"Gautham",5000,90000},{"Suhas",3916,100000},{"Karthik",8623,500000},{"Arijit Singh",5664,7000000},{"Arman Malik",4990,4000000},{"Shreya Ghoshal",6987,3000000},{"Vikram Batra",4532,8000000},{"Narendra Modi",6785,300000000},{"Rahul Gandhi",7856,10000000},{"Siddaramayya",5674,6000000},{"Ram",6534,590000},{"Manpreet",4632,100000},{"Prateek",4570,300000},{"Rakesh",6711,500000},{"123",3000,456777}};
    // printf("%d",sizeof(e)/sizeof(e[0]));
    FILE *fp=fopen(DataFile,"r");
    // int u = 0;
    // while(strcmp(e[u].username,"123") != 0)
    // {
    //    fwrite(&e[u],sizeof(detail_t),1,fp); 
    //    u++;
    // }
    // fclose(fp);
    detail_t e[500];
    detail_t *p = e;
    int k = 0;
    while(fread(&e[k],S_Size,1,fp))
    {
        k++;
        total_user++;
    }
    // printf("%d",total_user);
    fclose(fp);
    int n = sizeof(e)/sizeof(e[0]);
    star_horizontal();
    int correct = Person_check(p,n);
    balance = ((e+i)->init_amt);
    // printf("%d",correct);
    star_horizontal();
    if(correct)
    {
        printf("Successfully logged in!!\n");
        star_horizontal();
        void gap();
    }
    system("cls");
    int count;
    while(correct)
    {
        // printf("%d",i);
        printf("Enter what kind of operation you want to perform.\n1. Press 1 to view your account details.\n2. Press 2 to withdraw Money.\n3. Press 3 to change your pin(password).\n4. Press 4 to deposit Money.\n5. Press 5 to exit the portal\n");
        int choice;
        scanf("%d",&choice);
        //star_horizontal();
        system("cls");
        switch (choice)
        {
        case 1:
            details(p);
            fflush(stdin);
            getchar();
            break;
        case 2:
            withdraw_cash(p);
            check_balance(p);
            char what;
            fflush(stdin);
            printf("Do you want to continue??\n");
            scanf("%c",&what);
            
            if(what == 'y' || what == 'Y')
            {
                break;
            }

            else if(what == 'n'|| what == 'N')
            {
                exit(0);
            }
            else
            {
                while(what != 'y'&&what != 'Y'&&what != 'n'&&what != 'N')
                {
                    printf("Enter correct option\n");
                    fflush(stdin);
                    printf("Do you want to continue??\n");
                    scanf("%c",&what);
                }
                if(what == 'y' || what == 'Y')
                {
                    break;
                }

                else if(what == 'n'|| what == 'N')
                {
                    exit(0);
                }
            }
        case 3:
            change_pin(p);
            star_horizontal();
            fflush(stdin);
            system("cls");
            correct = Person_check(p,n);
            void gap();
            break;
        case 4:
            //Deposit Money
            deposit_cash(p);
            check_balance(p);
            char what1;
            fflush(stdin);
            printf("Do you want to continue??\n");
            scanf("%c",&what1);
            
            if(what1 == 'y' || what1 == 'Y')
            {
                break;
            }

            else if(what1 == 'n'|| what1 == 'N')
            {
                exit(0);
            }
            else
            {
                while(what != 'y'&&what != 'Y'&&what != 'n'&&what != 'N')
                {
                    printf("Enter correct option\n");
                    fflush(stdin);
                    printf("Do you want to continue??\n");
                    scanf("%c",&what);
                }
                if(what == 'y' || what == 'Y')
                {
                    break;
                }

                else if(what == 'n'|| what == 'N')
                {
                    exit(0);
                }
            }
            // break;
        case 5:
            exit(0);
            break;
        default:
            printf("Warning!!\nYou have entered a wrong operation!!!\n");
            //star_horizontal();
            break;
        }
        system("cls");
        
    }
    
    return 0;
}

int Person_check(detail_t* e,int n)
{
    int value = 0;
    char name[50];
    int pin;
    printf("Enter the user name to login:\n");
    scanf("%[^\n]s",name);
    star_horizontal();
    printf("Enter the ATM Pin:\n");
    scanf("%d",&pin);
    // printf("%d",n);
    for(i = 0;i<n;i++)
    {
        if((!strcmp((e+i)->username,name))&&(((e+i)->pass) == pin))
        {
            // return 1;
            value = 1;
            break;
        }
    }
    return value;
}

void change_pin(detail_t* e)
{
    printf("Enter old ATM pin:\n");
    int old;
    scanf("%d",&old);
    star_horizontal();
    if(((e+i)->pass) == old)
    {
        void gap();
        printf("Enter new password:\n");
        int new;
        scanf("%d",&new);
        ((e+i)->pass)  = new;
    }
    data_update(e);
}

void star_horizontal()
{
    for(int i = 0;i<50;i++)
    {
        printf("*");
    }
    printf("\n");
}

void withdraw_cash(detail_t* e)
{
  int select;
  int withdraw;
  printf("ENTER THE AMOUNT TO BE WITHDRAWN:\n");
  printf("Press 1 for 500Rs\nPress 2 for 1000Rs\nPress 3 for 5000Rs\nPress 4 for 10000Rs\nPress 5 for Others\n");
  scanf("%d",&select);
  star_horizontal();
  switch (select)
  {
    case 1:
          withdraw = 500;
          if(withdraw <= balance)
          {
            balance = balance - withdraw;
            (e+i)->init_amt = balance;
            printf("You have withdrawn %d from your account\n",withdraw);
            void gap();
          }
          else
          {
              printf("Not enough balance in your account\n");
              void gap();
          }
          break;
    case 2:
          withdraw = 1000;
          if(withdraw <= balance)
          {
            balance = balance - withdraw;
            (e+i)->init_amt = balance;
            printf("You have withdrawn %d from your account\n",withdraw);
            void gap();
          }
          else
              printf("Not enough balance in your account\n");
          break;


    case 3:
          withdraw = 5000;
          if(withdraw <= balance)
          {
            balance = balance - withdraw;
            (e+i)->init_amt = balance;
            printf("You have withdrawn %d from your account\n",withdraw);
          }
          else
              printf("Not enough balance in your account\n");
          break;
    case 4:
          withdraw = 10000;
          if(withdraw <= balance)
          {
            balance = balance - withdraw;
            (e+i)->init_amt = balance;
            printf("You have withdrawn %d from your account\n",withdraw);
          }
          else
              printf("Not enough balance in your account\n");
        break;


    case 5:
          printf("Enter the amount you want to withdraw:\n");
          scanf("%d",&withdraw);
          star_horizontal();
          if(withdraw <= balance)
          {
            if(withdraw % 100 != 0)
            {
              printf("Please enter in multiples of 100\n");
            }
            else
            {
                balance = balance - withdraw;
                printf("You have withdrawn %d from your account\n",withdraw);
            }
          }
          else
          {
            printf("Not enough balance in your account\n");
          }
          (e+i)->init_amt = balance;
          break;

  }
  data_update(e);
}
void check_balance(detail_t* e)
{
  printf("The balance in your account:%d\n",(e+i)->init_amt);
}
void gap(){
    printf("\n");
    printf("\n");
}
void deposit_cash(detail_t *e){
    int x;
    printf("Enter the amount to deposit to your account: ");
    scanf("%d",&x);
    balance = balance + x;
    (e+i)->init_amt = balance;
    printf("Your account has been credited by %d amount\n",x);
    // printf("The balance in your account: %d\n",(e+i)->final_amt);
    data_update(e);
}
void details(detail_t *e){
    printf("Account details are as follows:\n");
    printf("The name of the account holder is: %s\n",(e+i)->username);
    printf("The balance amount is: %d\n",balance);
}

void data_update(detail_t* e)
{
    FILE *fp = fopen(DataFile,"w");
    if(fp == NULL)
    {
        perror("Error");
    }
    for(int j=0;j<total_user;j++)
    {
        if(j!=i)
        {
            fwrite(e+j,S_Size,1,fp);
        }
        else
        {
            fwrite(e+i,S_Size,1,fp);
        }
    }
    fclose(fp);
}