#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>

 void systemLogin( );
 void adminMainMenu();
 void customerMainMenu(char[]);
 void adminSavingAccounts();
 void adminFixedAccounts();
 void adminViewCustomers();
 void adminCustomersLoginAccounts();
 void addAdminNewSavingsAccount();
 void viewAdminSavingAccount();
 void updateAdminSavingsAccountDetails();
 void deleteAdminSavingsAccount();
 void viewAdminSavingsAccounts();
 void addAdminNewFixedAccount();
 void viewAdminFixedAccount();
 void updateAdminFixedAccountDetails();
 void deleteAdminFixedAccount();
 void viewAdminFixedAccounts();
 void viewAdminCustomerDetails();
 void viewAdminCustomersDetails();
 void addAdminNewLoginAccount();
 void viewAdminLoginAccount();
 void updateAdminLoginAccountDetails();
 void deleteAdminLoginAccount();
 void customerSavingsAccountView(char[]);
 void customerResetLoginPassword(char[]);
 void customerMoneyTransaction(char[]);
 void customerWithdrawMoney(char[]);
 void customerDepositMoney(char[]);
 void loading();
 int selectChoice(char[]);
 int okcancelSelection();
 void invalidmsg(char[]);
 void autoTime(int*,int*,int*);
 void  accountNumberValidate(char [],char[]);
 int yearValidation(char [] );
 int monthValidation(char []);
void dateValidation(int,int,char[]);
void nameValidation(char[],int);
void firstnameValidation(char[]);
void lastnameValidation(char[]);
void idNumberValidation(char[]);
void telephoneNumberValidation(char[]);
double amountValidation(char [],int,int,int);
void addressValidation(char[]);
void emailValidation(char[]);
void passwordValidation(char[]);
int monthsValidation(char[]);
double numbersGet(int *, int *, int *);
struct savingsAccount
{    char saccountNumber[30];
     char styear[15];
     char stmonth[15];
     char stdate[15];
     char sSname[30];
     char sFname[30];
     char sLname[30];
     char sbyear[15];
     char sbmonth[15];
     char sbdate[15];
     char saddress[50];
     char sidNumber[30];
     char sphoneNumber[30];
     char semail[60];
     double samount;
     int shours;
     int smin;
     int ssec;
};

struct fixedAccount
{    char faccountNumber[30];
     char ftyear[20];
     char ftmonth[20];
     char ftdate[20];
     char fSname[50];
     char fFname[50];
     char fLname[50];
     char fbyear[20];
     char fbmonth[20];
     char fbdate[20];
     char faddress[50];
     char fidNumber[20];
     char fphoneNumber[15];
     char femail[60];
     double famount;
     int fmonths;
     double fannualInterest;
};

struct customerLoginAccount
{
     char caccountNumber[30];
     char cpassword[30];
};

int main()
{
    //addAdminNewSavingsAccount();
    systemLogin();
    adminMainMenu();
   //adminSavingAccounts();
  //adminFixedAccounts();
  //adminViewCustomers();
  //adminCustomersLoginAccounts();
      return 0;
}
    // Login screen
void systemLogin()
{   struct customerLoginAccount log;
    struct savingsAccount sav1;
    const char ADMIN_USERNAME[20]= "admin";
    const char ADMIN_PASSWORD[20]="adm123";
    char msg[50];
    char username[20];
    char password[20];
    int isAccount=0;
    int isSavAccount=0;
    system("COLOR 3");
    printf("\n\n\n\t\t\t****************************************************\n");
    printf("\t\t\t*      Welcome to ABC Banking Management System    *\n");
    printf("\t\t\t*                                                  *\n");
    printf("\t\t\t*                  User Login                      *\n");
    printf("\t\t\t****************************************************\n\n");
    printf("\t\t\t   username: ");
    scanf(" %[^\n]",username);
    printf("\n\t\t\t   password: ");
    scanf(" %[^\n]",password);
    printf("\n\t\t\t****************************************************\n");

//user name password verification
  if((strcmp(ADMIN_USERNAME,username)==0) && (strcmp(ADMIN_PASSWORD,password)==0))
  { loading();
    adminMainMenu();
  }
  else
  {   FILE *fpointer;
      fpointer = fopen("CustomerLoginAccountsDetails.txt","r");
      while(!feof(fpointer))
      {
       fscanf(fpointer,"%s %s ",&log.caccountNumber,&log.cpassword);
       if((strcmp(username,log.caccountNumber)==0) && (strcmp(password,log.cpassword)==0))
       { isAccount++;}}
      fclose(fpointer);

      FILE *fptr = fopen("SavingsAccountsDetails.txt","r");
      while(!feof(fptr))
      {fscanf(fptr,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %d %d ",sav1.saccountNumber,sav1.styear,sav1.stmonth,sav1.stdate,sav1.sSname,sav1.sFname,sav1.sLname,sav1.sbyear,sav1.sbmonth,sav1.sbdate,sav1.saddress,sav1.sidNumber,sav1.sphoneNumber,sav1.semail,&sav1.samount,&sav1.shours,&sav1.smin,&sav1.ssec);
       if(strcmp(username,sav1.saccountNumber)==0)
       { isSavAccount++;}}
      fclose(fpointer);
      if((isAccount==1) && (isSavAccount==1))
      {
          loading();
        customerMainMenu(username);
      }
      if(isAccount!=1)
      {strcpy(msg,"Invalid Username or Password");
     invalidmsg(msg);}
      else
        {strcpy(msg,"This Account not exist!");
       invalidmsg(msg);}
      systemLogin();}}

           // Admin Main screen
void adminMainMenu()
{   system("COLOR 6");
    char choice[2];
    int value=0;
    char msg[50];
    printf("\n\n\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\t\t\t*                ABC Banking Management System              *\n");
    printf("\t\t\t*                                                           *\n");
    printf("\t\t\t*                         Main Menu                         *\n");
    printf("\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\t\t\t*                                                           *\n");
    printf("\t\t\t*  1. Savings Accounts                                      *\n");
    printf("\t\t\t*  2. Fixed Accounts                                        *\n");
    printf("\t\t\t*  3. View Customers                                        *\n");
    printf("\t\t\t*  4. Customers login accounts                              *\n") ;
    printf("\t\t\t*  5. Logout                                                *\n");
    printf("\t\t\t*                                                           *\n");
    printf("\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
    printf("\t\t\t      Enter your choice: ");
    scanf(" %[^\n]",choice);
    value=selectChoice(choice);
    switch(value)
   {case 1:
       loading();
       adminSavingAccounts();
       break;
   case 2:
       loading();
       adminFixedAccounts();
       break;
   case 3:
        loading();
        adminViewCustomers();
       break;
   case 4:
         loading();
         adminCustomersLoginAccounts();
       break;
   case 5:
       loading();
       systemLogin();
       break;
   default:
        strcpy(msg,"Invalid Choice");
        invalidmsg(msg);
        adminMainMenu();}}

            // Admin Savings Accounts Menu
  void adminSavingAccounts()
  {   system("COLOR 6");
      char choice[2];
      int value=0;
      char msg[30];
     printf("\n\n\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\t\t\t*                ABC Banking Management System              *\n");
    printf("\t\t\t*                                                           *\n");
    printf("\t\t\t*                     Saving Accounts Menu                  *\n");
    printf("\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\t\t\t*                                                           *\n");
    printf("\t\t\t*     1. Add New Account                                    *\n");
    printf("\t\t\t*     2. View Savings Account                               *\n");
    printf("\t\t\t*     3. Update Account details                             *\n");
    printf("\t\t\t*     4. Delete Account                                     *\n");
    printf("\t\t\t*     5. View All Savings Accounts                          *\n");
    printf("\t\t\t*     6. Go To Main Screen                                  *\n");
    printf("\t\t\t*                                                           *\n");
    printf("\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\n\t\t\t         Enter choice : ");
    scanf(" %[^\n]",choice);
    value=selectChoice(choice);
    switch(value)
    {case 1:
        loading();
        addAdminNewSavingsAccount();
        break;
    case 2:
        loading();
        viewAdminSavingAccount();
        break;
    case 3:
        loading();
        updateAdminSavingsAccountDetails();
        break;
    case 4:
        loading();
        deleteAdminSavingsAccount();
        break;
    case 5:
        loading();
        viewAdminSavingsAccounts();
    case 6:
        loading();
        adminMainMenu();
        break;
    default:
        strcpy(msg,"Invalid Choice");
        invalidmsg(msg);
        adminSavingAccounts();}}

   // Admin Savings Accounts Include function
 void addAdminNewSavingsAccount()
 {
      system("COLOR 6");
     struct savingsAccount sav1;
     struct savingsAccount sav2;
     char choice[2];
     int value=0;
     int ityear=0;
     int itmonth=0;
     int ibyear=0;
     int ibmonth=0;
     int moneyLimit= 500;
     int suggest=0;
     char accountNumber[20];
     char amount[50];
     char msg[30];
     int number=0;
     int namechoice=0;
     strcpy( sav1.saccountNumber,"SAV");

    printf("\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\t\t*                                    ABC Banking Management System                              *\n");
    printf("\t\t*                                                                                               *\n");
    printf("\t\t*                                       Add New Savings Account                                 *\n");
    printf("\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\n\t\t   1. Account Number                               : SAV");
    scanf(" %[^\n]",accountNumber);
    accountNumberValidate(accountNumber,sav1.saccountNumber);
    printf("\t\t   2. Today date   \n");
    printf("\t\t          Year                                     : ");
    scanf(" %[^\n]",sav1.styear);
    ityear = yearValidation(sav1.styear);
    printf("\t\t          Month                                    : ");
    scanf(" %[^\n]",sav1.stmonth);
    itmonth=monthValidation(sav1.stmonth);
    printf("\t\t          Date                                     : ");
    scanf(" %[^\n]",sav1.stdate);
    dateValidation(ityear,itmonth,sav1.stdate);
    printf("\t\t   3. Full Name \n");
    printf("\t\t          Surname                                  : ");
    scanf(" %[^\n]",sav1.sSname);
    namechoice=1;
    nameValidation(sav1.sSname,namechoice);
    printf("\t\t          First Name                               : ");
    scanf(" %[^\n]",sav1.sFname);
    namechoice=2;
    nameValidation(sav1.sFname,namechoice);
    printf("\t\t          Last Name                                : ");
    scanf(" %[^\n]",sav1.sLname);
    namechoice=3;
    nameValidation(sav1.sLname,namechoice);
    printf("\t\t   5. Birthday    \n ");
    printf("\t\t          Year                                     : ");
    scanf(" %[^\n]",sav1.sbyear);
    ibyear = yearValidation(sav1.sbyear);
    printf("\t\t          Month                                    : ");
    scanf(" %[^\n]",sav1.sbmonth);
    ibmonth=monthValidation(sav1.sbmonth);
    printf("\t\t          Date                                     : ");
    scanf(" %[^\n]",sav1.sbdate);
    dateValidation(ibyear,ibmonth,sav1.sbdate);
    printf("\n\t\t   6. Address                                      : ");
    scanf(" %[^\n]",sav1.saddress);
    addressValidation(sav1.saddress);
    printf("\n\t\t   7. Id Number                                    : ");
    scanf(" %[^\n]",sav1.sidNumber);
    idNumberValidation(sav1.sidNumber);
    printf("\n\t\t   8. Phone Number                                 : ");
    scanf(" %[^\n]",sav1.sphoneNumber);
    telephoneNumberValidation(sav1.sphoneNumber);
    printf("\n\t\t   9. Email                                        : ");
    scanf(" %[^\n]",sav1.semail);
    emailValidation(sav1.semail);
    printf("\n\t\t  10. Enter the amount of deposit  (Rs.)           : ");
    scanf(" %[^\n]",amount);
    moneyLimit=500;
    suggest=1;
    number =1;
    sav1.samount = amountValidation(amount,moneyLimit,suggest,number);
    printf("\n\n\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");

    value=okcancelSelection();
     switch (value)
     { FILE *fptr;
      case 1:
          strcat(sav1.saccountNumber,accountNumber);
          autoTime(&sav1.shours,&sav1.smin,&sav1.ssec);
         fptr = fopen("SavingsAccountsDetails.txt","r");
         while(!feof(fptr))
         { fscanf(fptr,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %d %d ",sav2.saccountNumber,sav2.styear,sav2.stmonth,sav2.stdate,sav2.sSname,sav2.sFname,sav2.sLname,sav2.sbyear,sav2.sbmonth,sav2.sbdate,sav2.saddress,sav2.sidNumber,sav2.sphoneNumber,sav2.semail,&sav2.samount,&sav2.shours,&sav2.smin,&sav2.ssec);
             if(strcmp(sav1.saccountNumber,sav2.saccountNumber)==0)
             {  strcpy(msg,"The Savings Account Already Exist");
                invalidmsg(msg);
                 addAdminNewSavingsAccount();
             }}
         fclose(fptr);

         fptr = fopen("SavingsAccountsDetails.txt","a");
         fprintf(fptr,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %d %d  \n",sav1.saccountNumber,sav1.styear,sav1.stmonth,sav1.stdate,sav1.sSname,sav1.sFname,sav1.sLname,sav1.sbyear,sav1.sbmonth,sav1.sbdate,sav1.saddress,sav1.sidNumber,sav1.sphoneNumber,sav1.semail,sav1.samount,sav1.shours,sav1.smin,sav1.ssec);
         fclose(fptr);
         printf("\n\n\t\t\t\t\t Savings Account Added Successfully !");
         sleep(3);
        loading();
         break;
     case 2:
        printf("\n\n\t\t\t\t\tCanceled !");
        sleep(2);
        loading();
        addAdminNewSavingsAccount();
        break;
     default:
        strcpy(msg,"Invalid Choice");
        invalidmsg(msg);
}
  do
  {  value=0;
    printf("\n\n\t\t\t------------------------------------------------------\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t| (1) add Savings another account                    |\n");
    printf("\t\t\t| (2) Go to savings accounts menu                    |\n");
    printf("\t\t\t| (3) Go to main menu                                |\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t------------------------------------------------------\n");
    printf("\t\t\t      Enter your choice : ");
    scanf(" %[^\n]",choice);
    value = selectChoice(choice);
    switch (value)
     {case 1:
            loading();
            addAdminNewSavingsAccount();
         break;
     case 2:
            loading();
            adminSavingAccounts();
        break;
     case 3:
            loading();
            adminMainMenu();
        break;
     default:
           strcpy(msg,"Invald Choice");
           invalidmsg(msg);
    }} while(!(value==1 || value==2 || value == 3));
}
           //View Savings Accounts
 void viewAdminSavingAccount()
 {   system("COLOR 1");
     struct savingsAccount sav1;
     char accountNo[30];
     int value=0;
     char choice[2];
     int isaccount=0;
     char msg[30];
     printf("\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\t\t\t*                ABC Banking Management System              *\n");
    printf("\t\t\t*                                                           *\n");
    printf("\t\t\t*                     View Saving Account                   *\n");
    printf("\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
    printf("\t\t\t    Enter Account no: ");
    scanf(" %[^\n]",accountNo);
    printf("\n\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
     value=okcancelSelection();
    switch(value)
    { FILE *fptr;
    case 1:
        fptr = fopen("SavingsAccountsDetails.txt","r");
        while(!feof(fptr))
        {fscanf(fptr,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %d %d ",sav1.saccountNumber,sav1.styear,sav1.stmonth,sav1.stdate,sav1.sSname,sav1.sFname,sav1.sLname,sav1.sbyear,sav1.sbmonth,sav1.sbdate,sav1.saddress,sav1.sidNumber,sav1.sphoneNumber,sav1.semail,&sav1.samount,&sav1.shours,&sav1.smin,&sav1.ssec);
        if(strcmp(accountNo,sav1.saccountNumber)==0)
        {   isaccount=1;
            loading();
            system("cls");
        printf("\t\t\t-----------------------------------------------------------\n");
        printf("\t\t\t|      Date          time              Total amount       |\n");
        printf("\t\t\t-----------------------------------------------------------\n");
        printf("\t\t\t|   %04s-%02s-%02s     %02d:%02d:%02d    %20.3lf       |\n",sav1.styear,sav1.stmonth,sav1.stdate,sav1.shours,sav1.smin,sav1.ssec,sav1.samount);
        printf("\t\t\t-----------------------------------------------------------\n");
        }}
       fclose(fptr);
       if(isaccount==0)
        { strcpy(msg,"Invalid Account Number");
          invalidmsg(msg);
        }
        break;
      case 2:
           printf("\n\n\t\t\t\t\tCanceled !");
            sleep(3);
           loading();
           viewAdminSavingAccount();
      default:
      strcpy(msg,"Invalid Choice");
      invalidmsg(msg);
}
do{  value=0;
    printf("\n\n\t\t\t------------------------------------------------------\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t| (1) Search another account                         |\n");
    printf("\t\t\t| (2) Go to savings accounts menu                    |\n");
    printf("\t\t\t| (3) Go to main menu                                |\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t------------------------------------------------------\n");
    printf("\t\t\t      Enter your choice : ");
    scanf(" %[^\n]",choice);
    value=selectChoice(choice);
 switch (value)
     {case 1:
          loading();
          viewAdminSavingAccount();
         break;
     case 2:
          loading();
          adminSavingAccounts();
        break;
     case 3:
          loading();
          adminMainMenu();
        break;
     default:
          strcpy(msg,"Invalid Choice");
          invalidmsg(msg);
}} while(!((value==1)|| (value==2)||(value==3)));}

    // update savings accounts details
 void updateAdminSavingsAccountDetails()
 {   system("COLOR 6");
     struct savingsAccount sav1;
     struct savingsAccount sav2;
     int value=0;
     int value1=0;
     char choice[2];
     char choice1[2];
     char select [2];
     char msg[20];
     int isAccount=0;
     char accountNumber[15];
     char address[40];
     char phonenumber[15];
     char idnumber[15];
     char email[30];
     strcpy(sav1.saccountNumber,"SAV");
    printf("\n\n\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\t\t\t*                ABC Banking  Management System             *\n");
    printf("\t\t\t*                                                           *\n");
    printf("\t\t\t*                    Delete  Savings  Account               *\n");
    printf("\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
    printf("\t\t\t   1. Account Number               : SAV");
    scanf(" %[^\n]",accountNumber);
    printf("\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
    value=okcancelSelection();
    switch(value)
    {
    case 1:
        strcat(sav1.saccountNumber,accountNumber);
        FILE *fptrOld, *fptrNew;
        fptrOld= fopen("SavingsAccountsDetails.txt","r");
        fptrNew= fopen("updateSavingsAccountsDetails.txt","a");
        while(!feof(fptrOld))
        {  fscanf(fptrOld," %s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %d %d ",sav2.saccountNumber,sav2.styear,sav2.stmonth,sav2.stdate,sav2.sSname,sav2.sFname,sav2.sLname,sav2.sbyear,sav2.sbmonth,sav2.sbdate,sav2.saddress,sav2.sidNumber,sav2.sphoneNumber,sav2.semail,&sav2.samount,&sav2.shours,&sav2.smin,&sav2.ssec);

            if(strcmp(sav1.saccountNumber,sav2.saccountNumber)!=0)
            {
            fprintf(fptrNew," %s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %d %d \n",sav2.saccountNumber,sav2.styear,sav2.stmonth,sav2.stdate,sav2.sSname,sav2.sFname,sav2.sLname,sav2.sbyear,sav2.sbmonth,sav2.sbdate,sav2.saddress,sav2.sidNumber,sav2.sphoneNumber,sav2.semail,sav2.samount,sav2.shours,sav2.smin,sav2.ssec);

            }
            else
            {   isAccount=1;
                strcpy(sav1.styear,sav2.styear);
                strcpy(sav1.stmonth,sav2.stmonth);
                strcpy(sav1.stdate,sav2.stdate);
                strcpy(sav1.sSname,sav2.sSname);
                strcpy(sav1.sFname,sav2.sFname);
                strcpy(sav1.sLname,sav2.sLname);
                strcpy(sav1.sbyear,sav2.sbyear);
                strcpy(sav1.sbmonth,sav2.sbmonth);
                strcpy(sav1.sbdate,sav2.sbdate);
                strcpy(sav1.saddress,sav2.saddress);
                strcpy(sav1.sidNumber,sav2.sidNumber);
                strcpy(sav1.sphoneNumber,sav2.sphoneNumber);
                strcpy(sav1.semail,sav2.semail);
                sav1.samount= sav2.samount;
                sav1.shours= sav2.shours;
                sav1.smin= sav2.smin;
                sav1.ssec= sav2.ssec;
}}
            if(isAccount !=0)
            {
              do { value =0;
               system("cls");
                printf("\n\n\n\t\t\t------------------------------------------------------------------\n");
                printf("\t\t\t| Enter the relevant number for the information needed to update |\n");
                printf("\t\t\t------------------------------------------------------------------\n");
                printf("\t\t\t|                                                                |\n");
                printf("\t\t\t|  1. Address                                                    |\n");
                printf("\t\t\t|  2. ID Number                                                  |\n");
                printf("\t\t\t|  3. Phone Number                                               |\n");
                printf("\t\t\t|  4. Email                                                      |\n");
                printf("\t\t\t|                                                                |\n");
                printf("\t\t\t------------------------------------------------------------------\n");
                printf("\t\t\t      Enter the Choice: ");
                scanf(" %[^\n]",choice);
                value1 = selectChoice(choice);
                switch(value1)
                {
                case 1:
                    printf("\n\t\t\t Enter the new address : ");
                    scanf(" %[^\n]",address);
                     addressValidation(address);
        fprintf(fptrNew," %s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %d %d \n",sav1.saccountNumber,sav1.styear,sav1.stmonth,sav1.stdate,sav1.sSname,sav1.sFname,sav1.sLname,sav1.sbyear,sav1.sbmonth,sav1.sbdate,address,sav1.sidNumber,sav1.sphoneNumber,sav1.semail,sav1.samount,sav1.shours,sav1.smin,sav1.ssec);
                   break;
                case 2:
                    printf("\n\t\t\t Enter the Id number : ");
                    scanf(" %[^\n]",idnumber);
                     idNumberValidation(idnumber);
        fprintf(fptrNew," %s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %d %d \n",sav1.saccountNumber,sav1.styear,sav1.stmonth,sav1.stdate,sav1.sSname,sav1.sFname,sav1.sLname,sav1.sbyear,sav1.sbmonth,sav1.sbdate,address,idnumber,sav1.sphoneNumber,sav1.semail,sav1.samount,sav1.shours,sav1.smin,sav1.ssec);
                    break;
                case 3:
                     printf("\n\t\t\t Enter the Phone number : ");
                    scanf(" %[^\n]",phonenumber);
                      telephoneNumberValidation(phonenumber);
        fprintf(fptrNew," %s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %d %d \n",sav1.saccountNumber,sav1.styear,sav1.stmonth,sav1.stdate,sav1.sSname,sav1.sFname,sav1.sLname,sav1.sbyear,sav1.sbmonth,sav1.sbdate,address,idnumber,phonenumber,sav1.semail,sav1.samount,sav1.shours,sav1.smin,sav1.ssec);
                    break;
                case 4:
                     printf("\n\t\t\t Enter the email : ");
                    scanf(" %[^\n]",email);
                    emailValidation(email);
        fprintf(fptrNew," %s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %d %d \n",sav1.saccountNumber,sav1.styear,sav1.stmonth,sav1.stdate,sav1.sSname,sav1.sFname,sav1.sLname,sav1.sbyear,sav1.sbmonth,sav1.sbdate,address,idnumber,sav1.sphoneNumber,email,sav1.samount,sav1.shours,sav1.smin,sav1.ssec);
                break;
                default:
                    strcpy(msg,"Invalid Choice!");
                    invalidmsg(msg);}
                     printf("\n\n\t\t\t\t\t Details Updated!");
                     sleep(3);
                    printf("\n\n\t\t\t Do you want to update another one(if want enter 'Y' or 'y')? : ");
                    scanf(" %[^\n]",select);
               }while(strcmp(select,"y")==0 || strcmp(select,"Y")==0);}

                  else
                    {
                        strcpy(msg,"Account not found!");
                        invalidmsg(msg);
                    }
                  fclose(fptrNew);
                  fclose(fptrOld);
                  remove("SavingsAccountsDetails.txt")  ;
                  rename("updateSavingsAccountsDetails.txt","SavingsAccountsDetails.txt");
                  break;
    case 2:
        printf("\n\n\t\t\t Canceled!");
        sleep(3);
        loading();
        updateAdminSavingsAccountDetails();
        break;

    default:
            strcpy(msg,"Invalid Choice!");
                invalidmsg(msg);
        }
   do { system("cls");
        value=0;
    printf("\n\n\n\t\t\t------------------------------------------------------\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t| (1) Update another Savings Account                 |\n");
    printf("\t\t\t| (2) Go to Savings Accounts menu                    |\n");
    printf("\t\t\t| (3) Go to main menu                                |\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t------------------------------------------------------\n");
    printf("\t\t\t      Enter your choice : ");
    scanf(" %[^\n]",&choice1);
    value=selectChoice(choice1);
 switch (value)
     {
     case 1:
               loading();
          updateAdminSavingsAccountDetails();
         break;
     case 2:
               loading();
           adminSavingAccounts();
        break;
     case 3:
            loading();
            adminMainMenu();
        break;
     default:
         strcpy(msg,"Invalid Choice");
         invalidmsg(msg);
        } }while(!((value==1)||(value==2)||(value==3)));
 }

   //Delete Savings Account
 void deleteAdminSavingsAccount()
 {
     system("COLOR 6");
     struct savingsAccount sav1;
     struct savingsAccount sav2;
     int value=0;
     char choice[2];
     char choice1[2];
     char msg[20];
     int isAccount=0;
     char accountNumber[15];
     strcpy(sav1.saccountNumber,"SAV");
    printf("\n\n\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\t\t\t*                ABC Banking  Management System             *\n");
    printf("\t\t\t*                                                           *\n");
    printf("\t\t\t*                    Delete  Savings  Account               *\n");
    printf("\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
    printf("\t\t\t   1. Account Number               : SAV");
    scanf(" %[^\n]",accountNumber);
    printf("\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
    value=okcancelSelection();
    switch(value)
    {  FILE *fptrOld ,*fptrNew;
    case 1:
         strcat(sav1.saccountNumber,accountNumber);
        fptrOld = fopen("SavingsAccountsDetails.txt","r");
        fptrNew = fopen("DeleteSavingsAccountsDetails.txt","a+");
        while(!feof(fptrOld))
        {
        fscanf(fptrOld,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %d %d ",sav2.saccountNumber,sav2.styear,sav2.stmonth,sav2.stdate,sav2.sSname,sav2.sFname,sav2.sLname,sav2.sbyear,sav2.sbmonth,sav2.sbdate,sav2.saddress,sav2.sidNumber,sav2.sphoneNumber,sav2.semail,&sav2.samount,&sav2.shours,&sav2.smin,&sav2.ssec);


             if(strcmp(sav1.saccountNumber,sav2.saccountNumber)!=0)
             {
         fprintf(fptrNew,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %d %d ",sav2.saccountNumber,sav2.styear,sav2.stmonth,sav2.stdate,sav2.sSname,sav2.sFname,sav2.sLname,sav2.sbyear,sav2.sbmonth,sav2.sbdate,sav2.saddress,sav2.sidNumber,sav2.sphoneNumber,sav2.semail,sav2.samount,sav2.shours,sav2.smin,sav2.ssec);
             }
             else
             {
               isAccount=1;
                system("cls");
                printf("\t\t\t-----------------------------------------------------------\n");
        printf("\t\t\t|      Date          time              Total amount       |\n");
        printf("\t\t\t-----------------------------------------------------------\n");
        printf("\t\t\t|   %04s-%02s-%02s     %02d:%02d:%02d    %20.3lf       |\n",sav2.styear,sav2.stmonth,sav2.stdate,sav2.shours,sav2.smin,sav2.ssec,sav2.samount);
        printf("\t\t\t-----------------------------------------------------------\n");
                strcpy(sav1.styear,sav2.styear);
                strcpy(sav1.stmonth,sav2.stmonth);
                strcpy(sav1.stdate,sav2.stdate);
                strcpy(sav1.sSname,sav2.sSname);
                strcpy(sav1.sFname,sav2.sFname);
                strcpy(sav1.sLname,sav2.sLname);
                strcpy(sav1.sbyear,sav2.sbyear);
                strcpy(sav1.sbmonth,sav2.sbmonth);
                strcpy(sav1.sbdate,sav2.sbdate);
                strcpy(sav1.saddress,sav2.saddress);
                strcpy(sav1.sidNumber,sav2.sidNumber);
                strcpy(sav1.sphoneNumber,sav2.sphoneNumber);
                strcpy(sav1.semail,sav2.semail);
                sav1.samount= sav2.samount;
                sav1.shours= sav2.shours;
                sav1.smin= sav2.smin;
                sav1.ssec= sav2.ssec;
}}
             if(isAccount!=0)
             {
                   value=0;
                   printf("\n\n\t\t\t-------------------------------------------------------------\n");
                   printf("\t\t\t| Are you sure you want to delete this account?             | \n");
                   printf("\t\t\t| 1. Yes                                                    |\n");
                   printf("\t\t\t| 2. No                                                     |\n");
                   printf("\t\t\t-------------------------------------------------------------\n");
                   printf("\t\t\t\   Enter the choice : ");
                   scanf(" %[^\n]",choice);
                   value= selectChoice(choice);
                   switch(value)
                   {
               case 1:
                   printf("\n\n\t\t\t\t\tDelete Account Successfully!");
                   sleep(3);
                   loading();
                   system("cls");
                   break;
               case 2:
         fprintf(fptrNew,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %d %d ",sav1.saccountNumber,sav1.styear,sav1.stmonth,sav1.stdate,sav1.sSname,sav1.sFname,sav1.sLname,sav1.sbyear,sav1.sbmonth,sav1.sbdate,sav1.saddress,sav1.sidNumber,sav1.sphoneNumber,sav1.semail,sav1.samount,sav1.shours,sav1.smin,sav1.ssec);
                printf("\n\n\t\t\t\t\tCanceled!");
                sleep(3);
                loading();
                deleteAdminLoginAccount();
                     break;
               default:
                   strcpy(msg,"Invalid Choice!");
                invalidmsg(msg);
                   }}
                  else
                    {
                        strcpy(msg,"Account not found!");
                        invalidmsg(msg);
                    }
                  fclose(fptrNew);
                  fclose(fptrOld);
                  remove("SavingsAccountsDetails.txt")  ;
                  rename("DeleteSavingsAccountsDetails.txt","SavingsAccountsDetails.txt");
                  break;

    case 2:
        printf("\n\n\t\t\t Canceled!");
        sleep(3);
        loading();
        deleteAdminLoginAccount();
        break;

    default:
            strcpy(msg,"Invalid Choice!");
                invalidmsg(msg);
        }
   do { value=0;
    printf("\n\n\n\t\t\t------------------------------------------------------\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t| (1) Delete another Savings Account                 |\n");
    printf("\t\t\t| (2) Go to Savings Accounts menu                    |\n");
    printf("\t\t\t| (3) Go to main menu                                |\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t------------------------------------------------------\n");
    printf("\t\t\t      Enter your choice : ");
    scanf(" %[^\n]",&choice1);
    value=selectChoice(choice1);
 switch (value)
     {
     case 1:
               loading();
          deleteAdminSavingsAccount();
         break;
     case 2:
               loading();
           adminSavingAccounts();
        break;
     case 3:
            loading();
            adminMainMenu();
        break;
     default:
         strcpy(msg,"Invalid Choice");
         invalidmsg(msg);
        } }while(!((value==1)||(value==2)||(value==3)));
 }
    // view all savings accounts details
 void viewAdminSavingsAccounts()
 {   struct savingsAccount sav1;
     char choice[2];
     int value=0;
     char msg[30];
    system("COLOR 6");
        FILE *fptr;
        fptr = fopen("SavingsAccountsDetails.txt","r");
        printf("\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
        printf("\t\t\t*                     ABC Banking Management System                     *\n");
        printf("\t\t\t*                                                                       *\n");
        printf("\t\t\t*                         View Saving Accounts                          *\n");
        printf("\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
        printf("\t\t\t--------------------------------------------------------------------------\n");
        printf("\t\t\t|     Account No         Date          time              Total amount    |\n");
        printf("\t\t\t--------------------------------------------------------------------------\n");
        printf("\t\t\t|                                                                        |\n");
      while(!feof(fptr))
        {
        fscanf(fptr,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %d %d ",sav1.saccountNumber,sav1.styear,sav1.stmonth,sav1.stdate,sav1.sSname,sav1.sFname,sav1.sLname,sav1.sbyear,sav1.sbmonth,sav1.sbdate,sav1.saddress,sav1.sidNumber,sav1.sphoneNumber,sav1.semail,&sav1.samount,&sav1.shours,&sav1.smin,&sav1.ssec);
        printf("\t\t\t|   %13s     %04s-%02s-%02s     %02d:%02d:%02d    %20.3lf    |\n",sav1.saccountNumber,sav1.styear,sav1.stmonth,sav1.stdate,sav1.shours,sav1.smin,sav1.ssec,sav1.samount);

        }
        printf("\t\t\t|                                                                        |\n");
        printf("\t\t\t--------------------------------------------------------------------------\n");
        fclose(fptr);
    printf("\n\n\n\n\t\t\t---------------------------------------------------------------------------------\n");
    printf("\t\t\t|                                                                                |\n");
    printf("\t\t\t| (1) Go to savings accounts menu                                                |\n");
    printf("\t\t\t| (2) Go to main menu                                                            |\n");
    printf("\t\t\t|                                                                                |\n");
    printf("\t\t\t----------------------------------------------------------------------------------\n");
    printf("\t\t\t      Enter your choice : ");
    scanf(" %[^\n]",choice);
    value = selectChoice(choice);
switch (value)
     {case 1:
           loading();
           adminSavingAccounts();
         break;
     case 2:
           loading();
          adminMainMenu();
        break;
     default:
        strcpy(msg,"Invalid Choice");
        invalidmsg(msg);
        viewAdminSavingsAccounts();
       }}

  // Admin Fixed Accounts  Menu
 void adminFixedAccounts()
 {   system("COLOR 6");
     char choice[2];
      int value =0;
      char msg[30];
    printf("\n\n\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\t\t\t*                ABC Banking Management System              *\n");
    printf("\t\t\t*                                                           *\n");
    printf("\t\t\t*                     Fixed Accounts Menu                   *\n");
    printf("\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\t\t\t*                                                           *\n");
    printf("\t\t\t*   1. Add New Account                                      *\n");
    printf("\t\t\t*   2. View Fixed Account                                   *\n");
    printf("\t\t\t*   3. Update Account details                               *\n");
    printf("\t\t\t*   4. Delete Account                                       *\n");
    printf("\t\t\t*   5. View All Fixed Accounts                              *\n");
    printf("\t\t\t*   6. Go To Main Screen                                    *\n");
    printf("\t\t\t*                                                           *\n");
    printf("\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
    printf("\t\t\t       Enter choice : ");
    scanf(" %[^\n]",choice);
    value=selectChoice(choice);
    switch(value)
    {
    case 1:
        loading();
        addAdminNewFixedAccount();
        break;
    case 2:
        loading();
        viewAdminFixedAccount();
        break;
    case 3:
        loading();
        updateAdminFixedAccountDetails();
        break;
    case 4:
        loading();
        deleteAdminFixedAccount();
        break;
    case 5:
        loading();
        viewAdminFixedAccounts();
        break;
    case 6:
        loading();
        adminMainMenu();
        break;
    default:
        strcpy(msg,"Invalid Choice");
        invalidmsg(msg);
        adminFixedAccounts();
    }}

  // Admin Fixed Accounts Include Functions
 void addAdminNewFixedAccount()
  { system("COLOR 6");
 struct fixedAccount fix1;
 struct fixedAccount fix2;
     int value=0;
     char choice2[2];
     int ityear=0;
     int itmonth=0;
     int ibyear=0;
     int ibmonth=0;
     char imonths[30];
     int moneyLimit=0;
     int suggest =0;
     char amount[50];
     char interest[50];
     int number=1;
     int nameplace=0;
     strcpy(fix1.faccountNumber,"FIX");
     char accountnumber[30];
     char msg[30];
    printf("\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\t\t*                                    ABC BankING Management System                              *\n");
    printf("\t\t*                                                                                               *\n");
    printf("\t\t*                                         Add New Fixed Account                                 *\n");
    printf("\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\t\t    1. Account Number                               : FIX");
    scanf(" %[^\n]",accountnumber);
    accountNumberValidate(accountnumber,fix1.faccountNumber);
    printf("\t\t    2. Today date   \n");
    printf("\t\t            Year                                    : ");
    scanf(" %[^\n]",fix1.ftyear);
    ityear = yearValidation(fix1.ftyear);
    printf("\t\t            Month                                   : ");
    scanf(" %[^\n]",fix1.ftmonth);
    itmonth=monthValidation(fix1.ftmonth);
    printf("\t\t            Date                                    : ");
    scanf(" %[^\n]",fix1.ftdate);
    dateValidation(ityear,itmonth,fix1.ftdate);
    printf("\t\t    3. Full Name \n");
    printf("\t\t            Surname                                 : ");
    scanf(" %[^\n]",fix1.fSname);
    nameplace=1;
    nameValidation(fix1.fSname,nameplace);
    printf("\t\t            First Name                              : ");
    scanf(" %[^\n]",fix1.fFname);
    nameplace=2;
    nameValidation(fix1.fFname,nameplace);
    printf("\t\t            Last Name                               : ");
    scanf(" %[^\n]",fix1.fLname);
    nameplace=3;
    nameValidation(fix1.fLname,nameplace);
    printf("\t\t    5. Birthday    \n ");
    printf("\t\t            Year                                    : ");
    scanf(" %[^\n]",fix1.fbyear);
    ibyear = yearValidation(fix1.fbyear);
    printf("\t\t            Month                                   : ");
    scanf(" %[^\n]",fix1.fbmonth);
    ibmonth=monthValidation(fix1.fbmonth);
    printf("\t\t            Date                                    : ");
    scanf(" %[^\n]",fix1.fbdate);
    dateValidation(ibyear,ibmonth,fix1.fbdate);
    printf("\n\t\t    6. Address                                      : ");
    scanf(" %[^\n]",fix1.faddress);
    addressValidation(fix1.faddress);
    printf("\n\t\t    7. Id Number                                    : ");
    scanf(" %[^\n]",fix1.fidNumber);
    idNumberValidation(fix1.fidNumber);
    printf("\n\t\t    8. Phone Number                                 : ");
    scanf(" %[^\n]",fix1.fphoneNumber);
    telephoneNumberValidation(fix1.fphoneNumber);
    printf("\n\t\t    9. Email                                        : ");
    scanf(" %[^\n]",fix1.femail);
    emailValidation(fix1.femail);
    printf("\n\t\t   10. Enter the amount of deposit  (Rs.)           : ");
    scanf(" %[^\n]",amount);
    moneyLimit=10000;
    suggest=1;
    number=1;
    fix1.famount = amountValidation(amount,moneyLimit,suggest,number);
    printf("\n\t\t   11. Number of months for deposit                 : ");
    scanf(" %[^\n]",imonths);
    fix1.fmonths= monthsValidation(imonths);
    printf("\n\t\t   12. Enter annual interest                        : ");
    scanf(" %[^\n]",interest);
    moneyLimit=100;
    suggest=2;
    fix1.fannualInterest= amountValidation( interest,moneyLimit,suggest,number);
    printf("\n\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    value=okcancelSelection();
     switch (value)
     {
           FILE *fptr;
       case 1:
           strcat(fix1.faccountNumber,accountnumber);
         fptr = fopen("FixedAccountsDetails.txt","r");
         while(!feof(fptr))
         {
             fscanf(fptr,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %lf",fix2.faccountNumber,fix2.ftyear,fix2.ftmonth,fix2.ftdate,fix2.fSname,fix2.fFname,fix2.fLname,fix2.fbyear,fix2.fbmonth,fix2.fbdate,fix2.faddress,fix2.fidNumber,fix2.fphoneNumber,fix2.femail,&fix2.famount,&fix2.fmonths,&fix2.fannualInterest);
             if(strcmp(fix1.faccountNumber,fix2.faccountNumber)==0)
             {
                 strcpy(msg,"The Deposit Account Already Exist");
                 invalidmsg(msg);
                 addAdminNewFixedAccount();
             }}
         fclose(fptr);

        fptr = fopen("FixedAccountsDetails.txt","a");
        fprintf(fptr,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %lf \n",fix1.faccountNumber,fix1.ftyear,fix1.ftmonth,fix1.ftdate,fix1.fSname,fix1.fFname,fix1.fLname,fix1.fbyear,fix1.fbmonth,fix1.fbdate,fix1.faddress,fix1.fidNumber,fix1.fphoneNumber,fix1.femail,fix1.famount,fix1.fmonths,fix1.fannualInterest);
        fclose(fptr);
         printf("\n\n\t\t\t\t\t Fixed Account Added Successfully !");
         sleep(3);
        loading();
         break;
     case 2:
        printf("\n\n\t\tCanceled !");
        sleep(2);
        loading();
        addAdminNewFixedAccount();
        break;
     default:
        strcpy(msg,"Invalid Choice");
        invalidmsg(msg);
     }
  do
  {  value=0;
    printf("\n\n\t\t\t------------------------------------------------------\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t| (1) add Fixed another account                      |\n");
    printf("\t\t\t| (2) Go to Fixed accounts menu                      |\n");
    printf("\t\t\t| (3) Go to main menu                                |\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t------------------------------------------------------\n");
    printf("\t\t\t      Enter your choice : ");
    scanf(" %[^\n]", choice2);
    value=selectChoice(choice2);
    switch (value)
     {
     case 1:
            loading();
            addAdminNewFixedAccount();
         break;
     case 2:
            loading();
            adminFixedAccounts();
        break;
     case 3:
            loading();
              adminMainMenu();
        break;
     default:
        strcpy(msg,"Invalid Choice");
        invalidmsg(msg);}
        } while(!(choice2==1 || choice2==2 || choice2 == 3));
 }
            //View Fixed Accounts Details
 void viewAdminFixedAccount()
 {
  system("COLOR 6");
     struct fixedAccount fix1;
     char accountNo[30];
     int value=0;
     char choice[2];
     int c=0;
     char msg[20];
    printf("\n\n\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\t\t\t*                ABC Banking Management System              *\n");
    printf("\t\t\t*                                                           *\n");
    printf("\t\t\t*                    View  Fixed  Account                   *\n");
    printf("\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
    printf("\t\t\t    Enter Account no: ");
    scanf(" %[^\n]",accountNo);
    printf("\n\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
    value = okcancelSelection();
    switch(value)
    {
        FILE *fptr;
    case 1:
        fptr = fopen("FixedAccountsDetails.txt","r");
        while(!feof(fptr))
        {
        fscanf(fptr,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %lf",fix1.faccountNumber,fix1.ftyear,fix1.ftmonth,fix1.ftdate,fix1.fSname,fix1.fFname,fix1.fLname,fix1.fbyear,fix1.fbmonth,fix1.fbdate,fix1.faddress,fix1.fidNumber,fix1.fphoneNumber,fix1.femail,&fix1.famount,&fix1.fmonths,&fix1.fannualInterest);
        if(strcmp(accountNo,fix1.faccountNumber)==0)
        {   c=1;
            loading();
            system("cls");
            double interest=0.0;
            double fullamount=0.0;
            interest= ((fix1.fannualInterest/100)/12)*fix1.fmonths*fix1.famount;
            fullamount= fix1.famount+interest;
        printf("\n\n\n\t\t\t--------------------------------------------------------------------------------------------------------\n");
        printf("\t\t\t|     Date      Annual Interest   Deposit Months        Deposit Amount                     Total amount|\n");
        printf("\t\t\t--------------------------------------------------------------------------------------------------------\n");
        printf("\t\t\t|  %04s-%02s-%02s        %5.3lf            %3d         %20.3lf   %30.3f|\n",fix1.ftyear,fix1.ftmonth,fix1.ftdate,fix1.fannualInterest,fix1.fmonths,fix1.famount,fullamount);
        printf("\t\t\t--------------------------------------------------------------------------------------------------------\n");
        }}
       fclose(fptr);
       if(c==0)
        {
         strcpy(msg,"Account Not Found");
         invalidmsg(msg);
        }
        break;
      case 2:
           printf("\n\n\t\t\t\t\tCanceled !");
            sleep(3);
           loading();
           viewAdminFixedAccount();
      default:
        strcpy(msg,"Invalid Choice");
         invalidmsg(msg);}
do{
    printf("\n\n\t\t\t------------------------------------------------------\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t| (1) Search another account                         |\n");
    printf("\t\t\t| (2) Go to Fixed accounts menu                      |\n");
    printf("\t\t\t| (3) Go to main menu                                |\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t------------------------------------------------------\n");
    printf("\t\t\t      Enter your choice : ");
    scanf(" %[^\n]",&choice);
    value= selectChoice(choice);
 switch (value)
     {
     case 1:
          loading();
          viewAdminFixedAccount();
         break;
     case 2:
          loading();
          adminFixedAccounts();
        break;
     case 3:
          loading();
          adminMainMenu();
        break;
     default:
          strcpy(msg,"Invalid Choice");
          invalidmsg(msg);
}} while(!((value==1)|| (value==2)||(value==3)));
}
 // Update Fixed Account details
 void updateAdminFixedAccountDetails()
 {system("COLOR 6");
     struct fixedAccount fix1;
     struct fixedAccount fix2;
     int value=0;
     int value1=0;
     char choice[2];
     char choice1[2];
     char select [2];
     char msg[20];
     int isAccount=0;
     char accountNumber[15];
     char address[40];
     char phonenumber[15];
     char idnumber[15];
     char email[30];
     char amount[20];
     char months[15];
     char annualInterest[20];
     int moneyLimit = 0;
     int  suggest=0;
     int number=0;
     strcpy(fix1.faccountNumber,"FIX");
    printf("\n\n\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\t\t\t*                ABC Banking  Management System             *\n");
    printf("\t\t\t*                                                           *\n");
    printf("\t\t\t*                     Update  Fixed  Account                *\n");
    printf("\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
    printf("\t\t\t   1. Account Number               : FIX");
    scanf(" %[^\n]",accountNumber);
    printf("\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
    value=okcancelSelection();
    switch(value)
    {
    case 1:
        strcat(fix1.faccountNumber,accountNumber);
        FILE *fptrOld, *fptrNew;
        fptrOld= fopen("FixedAccountsDetails.txt","r");
        fptrNew= fopen("updateFixedAccountsDetails.txt","a");
        while(!feof(fptrOld))
        {
        fscanf(fptrOld," %s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %lf ",fix2.faccountNumber,fix2.ftyear,fix2.ftmonth,fix2.ftdate,fix2.fSname,fix2.fFname,fix2.fLname,fix2.fbyear,fix2.fbmonth,fix2.fbdate,fix2.faddress,fix2.fidNumber,fix2.fphoneNumber,fix2.femail,&fix2.famount,&fix2.fmonths,&fix2.fannualInterest);

            if(strcmp(fix1.faccountNumber,fix2.faccountNumber)!=0)
            {
        fprintf(fptrNew," %s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %lf \n",fix2.faccountNumber,fix2.ftyear,fix2.ftmonth,fix2.ftdate,fix2.fSname,fix2.fFname,fix2.fLname,fix2.fbyear,fix2.fbmonth,fix2.fbdate,fix2.faddress,fix2.fidNumber,fix2.fphoneNumber,fix2.femail,fix2.famount,fix2.fmonths,fix2.fannualInterest);
            }
            else
            {   isAccount=1;
                strcpy(fix1.ftyear,fix2.ftyear);
                strcpy(fix1.ftmonth,fix2.ftmonth);
                strcpy(fix1.ftdate,fix2.ftdate);
                strcpy(fix1.fSname,fix2.fSname);
                strcpy(fix1.fFname,fix2.fFname);
                strcpy(fix1.fLname,fix2.fLname);
                strcpy(fix1.fbyear,fix2.fbyear);
                strcpy(fix1.fbmonth,fix2.fbmonth);
                strcpy(fix1.fbdate,fix2.fbdate);
                strcpy(fix1.faddress,fix2.faddress);
                strcpy(fix1.fidNumber,fix2.fidNumber);
                strcpy(fix1.fphoneNumber,fix2.fphoneNumber);
                strcpy(fix1.femail,fix2.femail);
                fix1.famount= fix2.famount;
                fix1.fmonths=fix2.fmonths;
                fix1.fannualInterest= fix2.fannualInterest;
               }}
            if(isAccount !=0)
            {
              do { value =0;
               system("cls");
                printf("\n\n\n\t\t\t------------------------------------------------------------------\n");
                printf("\t\t\t| Enter the relevant number for the information needed to update |\n");
                printf("\t\t\t------------------------------------------------------------------\n");
                printf("\t\t\t|                                                                |\n");
                printf("\t\t\t|  1. Address                                                    |\n");
                printf("\t\t\t|  2. ID Number                                                  |\n");
                printf("\t\t\t|  3. Phone Number                                               |\n");
                printf("\t\t\t|  4. Email                                                      |\n");
                printf("\t\t\t|  5. Amount                                                     |\n");
                printf("\t\t\t|  6. Number of months for deposit                               |\n");
                printf("\t\t\t|  7. Annual Interest                                            |\n");
                printf("\t\t\t|                                                                |\n");
                printf("\t\t\t------------------------------------------------------------------\n");
                printf("\t\t\t      Enter the Choice: ");
                scanf(" %[^\n]",choice);
                value1 = selectChoice(choice);
                switch(value1)
                {
                case 1:
                    printf("\n\t\t\t Enter the new address : ");
                    scanf(" %[^\n]",address);
                    addressValidation(address);
       fprintf(fptrNew," %s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %lf \n",fix1.faccountNumber,fix1.ftyear,fix1.ftmonth,fix1.ftdate,fix1.fSname,fix1.fFname,fix1.fLname,fix1.fbyear,fix1.fbmonth,fix1.fbdate,address,fix1.fidNumber,fix1.fphoneNumber,fix1.femail,fix1.famount,fix1.fmonths,fix1.fannualInterest);
                   break;
                case 2:
                    printf("\n\t\t\t Enter the Id number : ");
                    scanf(" %[^\n]",idnumber);
                     idNumberValidation(idnumber);
        fprintf(fptrNew," %s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %lf \n",fix1.faccountNumber,fix1.ftyear,fix1.ftmonth,fix1.ftdate,fix1.fSname,fix1.fFname,fix1.fLname,fix1.fbyear,fix1.fbmonth,fix1.fbdate,fix1.faddress,idnumber,fix1.fphoneNumber,fix1.femail,fix1.famount,fix1.fmonths,fix1.fannualInterest);
                     break;
                case 3:
                     printf("\n\t\t\t Enter the Phone number : ");
                    scanf(" %[^\n]",phonenumber);
                    telephoneNumberValidation(phonenumber);
       fprintf(fptrNew," %s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %lf \n",fix1.faccountNumber,fix1.ftyear,fix1.ftmonth,fix1.ftdate,fix1.fSname,fix1.fFname,fix1.fLname,fix1.fbyear,fix1.fbmonth,fix1.fbdate,address,fix1.fidNumber,phonenumber,fix1.femail,fix1.famount,fix1.fmonths,fix1.fannualInterest);
                    break;
                case 4:
                     printf("\n\t\t\t Enter the email : ");
                    scanf(" %[^\n]",email);
                     emailValidation(fix1.femail);
        fprintf(fptrNew," %s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %lf \n",fix1.faccountNumber,fix1.ftyear,fix1.ftmonth,fix1.ftdate,fix1.fSname,fix1.fFname,fix1.fLname,fix1.fbyear,fix1.fbmonth,fix1.fbdate,address,fix1.fidNumber,fix1.fphoneNumber,email,fix1.famount,fix1.fmonths,fix1.fannualInterest);
                break;
                case 5:
                    printf("\n\t\t\t Enter the amount : ");
                    scanf(" %[^\n]",amount);
                    moneyLimit=10000;
                    suggest=1;
                    number=1;
                    fix1.famount = amountValidation(amount,moneyLimit,suggest,number);
        fprintf(fptrNew," %s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %lf \n",fix1.faccountNumber,fix1.ftyear,fix1.ftmonth,fix1.ftdate,fix1.fSname,fix1.fFname,fix1.fLname,fix1.fbyear,fix1.fbmonth,fix1.fbdate,address,fix1.fidNumber,fix1.fphoneNumber,fix1.femail,fix1.famount,fix1.fmonths,fix1.fannualInterest);
                    break;
                case 6:
                    printf("\n\t\t\t Number of months for deposit : ");
                    scanf(" %[^\n]",months);
                    fix1.fmonths =  monthsValidation(months);
        fprintf(fptrNew," %s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %lf \n",fix1.faccountNumber,fix1.ftyear,fix1.ftmonth,fix1.ftdate,fix1.fSname,fix1.fFname,fix1.fLname,fix1.fbyear,fix1.fbmonth,fix1.fbdate,address,fix1.fidNumber,fix1.fphoneNumber,fix1.femail,fix1.famount,fix1.fmonths,fix1.fannualInterest);
                     break;
                case 7:
                    printf("\n\t\t\t Annual Interest : ");
                    scanf(" %[^\n]",annualInterest);
                    moneyLimit=100;
                    suggest=2;
                    fix1.fannualInterest= amountValidation( annualInterest,moneyLimit,suggest,number);

        fprintf(fptrNew," %s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %lf \n",fix1.faccountNumber,fix1.ftyear,fix1.ftmonth,fix1.ftdate,fix1.fSname,fix1.fFname,fix1.fLname,fix1.fbyear,fix1.fbmonth,fix1.fbdate,address,fix1.fidNumber,fix1.fphoneNumber,fix1.femail,fix1.famount,fix1.fmonths,fix1.fannualInterest);

                default:
                    strcpy(msg,"Invalid Choice!");
                    invalidmsg(msg);}
                     printf("\n\n\t\t\t\t\t Details Updated!");
                     sleep(3);
                    printf("\n\n\t\t\t Do you want to update another one(if want enter 'Y' or 'y')? : ");
                    scanf(" %[^\n]",select);
               }while(strcmp(select,"y")==0 || strcmp(select,"Y")==0);}

                  else
                    {
                        strcpy(msg,"Account not found!");
                        invalidmsg(msg);
                    }
                  fclose(fptrNew);
                  fclose(fptrOld);
                  remove("FixedAccountsDetails.txt")  ;
                  rename("updateFixedAccountsDetails.txt","FixedAccountsDetails.txt");
                  break;
    case 2:
        printf("\n\n\t\t\t Canceled!");
        sleep(3);
        loading();
        updateAdminSavingsAccountDetails();
        break;

    default:
            strcpy(msg,"Invalid Choice!");
                invalidmsg(msg);
        }
   do { system("cls");
        value=0;
    printf("\n\n\n\t\t\t------------------------------------------------------\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t| (1) Update another Fixed Account                   |\n");
    printf("\t\t\t| (2) Go to Fixed Accounts menu                      |\n");
    printf("\t\t\t| (3) Go to main menu                                |\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t------------------------------------------------------\n");
    printf("\t\t\t      Enter your choice : ");
    scanf(" %[^\n]",&choice1);
    value=selectChoice(choice1);
 switch (value)
     {
     case 1:
               loading();
          updateAdminFixedAccountDetails();
         break;
     case 2:
               loading();
           adminFixedAccounts();
        break;
     case 3:
            loading();
            adminMainMenu();
        break;
     default:
         strcpy(msg,"Invalid Choice");
         invalidmsg(msg);
        } }while(!((value==1)||(value==2)||(value==3)));
  }

 // Delete Fixed Account
  void deleteAdminFixedAccount()
  {system("COLOR 6");
 struct fixedAccount fix1;
     struct fixedAccount fix2;
     int value=0;
     char choice[2];
     char choice1[2];
     char msg[20];
     int isAccount=0;
     char accountNumber[15];
     strcpy(fix1.faccountNumber,"FIX");
    printf("\n\n\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\t\t\t*                ABC Banking  Management System             *\n");
    printf("\t\t\t*                                                           *\n");
    printf("\t\t\t*                     Delete  Fixed  Account                *\n");
    printf("\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
    printf("\t\t\t   1. Account Number               : FIX");
    scanf(" %[^\n]",accountNumber);
    printf("\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
    value=okcancelSelection();
    switch(value)
    {  FILE *fptrOld ,*fptrNew;
    case 1:
         strcat(fix1.faccountNumber,accountNumber);
        fptrOld = fopen("FixedAccountsDetails.txt","r");
        fptrNew = fopen("DeleteFixedAccountsDetails.txt","a+");
        while(!feof(fptrOld))
        {
        fscanf(fptrOld,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %lf",fix2.faccountNumber,fix2.ftyear,fix2.ftmonth,fix2.ftdate,fix2.fSname,fix2.fFname,fix2.fLname,fix2.fbyear,fix2.fbmonth,fix2.fbdate,fix2.faddress,fix2.fidNumber,fix2.fphoneNumber,fix2.femail,&fix2.famount,&fix2.fmonths,&fix2.fannualInterest);


             if(strcmp(fix1.faccountNumber,fix2.faccountNumber)!=0)
             {
        fprintf(fptrNew,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %lf",fix2.faccountNumber,fix2.ftyear,fix2.ftmonth,fix2.ftdate,fix2.fSname,fix2.fFname,fix2.fLname,fix2.fbyear,fix2.fbmonth,fix2.fbdate,fix2.faddress,fix2.fidNumber,fix2.fphoneNumber,fix2.femail,fix2.famount,fix2.fmonths,fix2.fannualInterest);
             }
             else
             {
               isAccount=1;
                system("cls");
            double interest=0.0;
            double fullamount=0.0;
            interest= ((fix2.fannualInterest/100)/12)*fix2.fmonths*fix2.famount;
            fullamount= fix2.famount+interest;
       printf("\n\n\n\t\t\t-------------------------------------------------------------------------------------------------------------\n");
        printf("\t\t\t|     Date      Annual Interest   Deposit Months        Deposit Amount                     Total amount     |\n");
        printf("\t\t\t-------------------------------------------------------------------------------------------------------------\n");
        printf("\t\t\t|  %04s-%02s-%02s        %5.3lf            %3d         %20.3lf  %30.3f  |\n",fix2.ftyear,fix2.ftmonth,fix2.ftdate,fix2.fannualInterest,fix2.fmonths,fix2.famount,fullamount);
        printf("\t\t\t-------------------------------------------------------------------------------------------------------------\n");
                strcpy(fix1.ftyear,fix2.ftyear);
                strcpy(fix1.ftmonth,fix2.ftmonth);
                strcpy(fix1.ftdate,fix2.ftdate);
                strcpy(fix1.fSname,fix2.fSname);
                strcpy(fix1.fFname,fix2.fFname);
                strcpy(fix1.fLname,fix2.fLname);
                strcpy(fix1.fbyear,fix2.fbyear);
                strcpy(fix1.fbmonth,fix2.fbmonth);
                strcpy(fix1.fbdate,fix2.fbdate);
                strcpy(fix1.faddress,fix2.faddress);
                strcpy(fix1.fidNumber,fix2.fidNumber);
                strcpy(fix1.fphoneNumber,fix2.fphoneNumber);
                strcpy(fix1.femail,fix2.femail);
                fix1.famount= fix2.famount;
                fix1.fmonths = fix2.fmonths;
                fix1.fannualInterest= fix2.fannualInterest;
}}
             if(isAccount!=0)
             {
                   value=0;
                   printf("\n\n\t\t\t-------------------------------------------------------------\n");
                   printf("\t\t\t| Are you sure you want to delete this account?             | \n");
                   printf("\t\t\t| 1. Yes                                                    |\n");
                   printf("\t\t\t| 2. No                                                     |\n");
                   printf("\t\t\t-------------------------------------------------------------\n");
                   printf("\t\t\t\   Enter the choice : ");
                   scanf(" %[^\n]",choice);
                   value= selectChoice(choice);
                   switch(value)
                   {
               case 1:
                   printf("\n\n\t\t\t\t\tDelete Account Successfully!");
                   sleep(3);
                   loading();
                   system("cls");
                   break;
               case 2:
        fprintf(fptrNew,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %lf",fix1.faccountNumber,fix1.ftyear,fix1.ftmonth,fix1.ftdate,fix1.fSname,fix1.fFname,fix1.fLname,fix1.fbyear,fix1.fbmonth,fix1.fbdate,fix1.faddress,fix1.fidNumber,fix1.fphoneNumber,fix1.femail,fix1.famount,fix1.fmonths,fix1.fannualInterest);
                printf("\n\n\t\t\t\t\tCanceled!");
                sleep(3);
                loading();
                deleteAdminLoginAccount();
                     break;
               default:
                   strcpy(msg,"Invalid Choice!");
                invalidmsg(msg);
                   }}
                  else
                    {
                        strcpy(msg,"Account not found!");
                        invalidmsg(msg);
                    }
                  fclose(fptrNew);
                  fclose(fptrOld);
                  remove("FixedAccountsDetails.txt")  ;
                  rename("DeleteFixedAccountsDetails.txt","FixedAccountsDetails.txt");
                  break;

    case 2:
        printf("\n\n\t\t\t Canceled!");
        sleep(3);
        loading();
        deleteAdminLoginAccount();
        break;

    default:
            strcpy(msg,"Invalid Choice!");
                invalidmsg(msg);
        }
   do { value=0;
    printf("\n\n\n\t\t\t------------------------------------------------------\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t| (1) Delete another Fixed Account                   |\n");
    printf("\t\t\t| (2) Go to Fixed Accounts menu                      |\n");
    printf("\t\t\t| (3) Go to main menu                                |\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t------------------------------------------------------\n");
    printf("\t\t\t      Enter your choice : ");
    scanf(" %[^\n]",&choice1);
    value=selectChoice(choice1);
 switch (value)
     {
     case 1:
               loading();
          deleteAdminFixedAccount();
         break;
     case 2:
               loading();
           adminFixedAccounts();
        break;
     case 3:
            loading();
            adminMainMenu();
        break;
     default:
         strcpy(msg,"Invalid Choice");
         invalidmsg(msg);
        } }while(!((value==1)||(value==2)||(value==3)));
  }
  // View All Fixed Accounts
 void viewAdminFixedAccounts()
 {
     struct fixedAccount fix1;
     system("COLOR 6");
      char choice[2];
      int value=0;
      char msg[20];
        FILE *fptr;
        fptr = fopen("FixedAccountsDetails.txt","r");
         printf("\n\n\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
         printf("\t\t\t*                                               ABC Banking Management System                                           *\n");
         printf("\t\t\t*                                                                                                                       *\n");
         printf("\t\t\t*                                                View Fixed Accounts Details                                            *\n");
         printf("\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
         printf("\n\n\n\t\t\t-------------------------------------------------------------------------------------------------------------------------\n");
         printf("\t\t\t|    Account No       Date      Annual Interest   Deposit Months        Deposit Amount                     Total amount |\n");
         printf("\t\t\t-------------------------------------------------------------------------------------------------------------------------\n");

        while(!feof(fptr))
        {
        fscanf(fptr,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %lf",fix1.faccountNumber,fix1.ftyear,fix1.ftmonth,fix1.ftdate,fix1.fSname,fix1.fFname,fix1.fLname,fix1.fbyear,fix1.fbmonth,fix1.fbdate,fix1.faddress,fix1.fidNumber,fix1.fphoneNumber,fix1.femail,&fix1.famount,&fix1.fmonths,&fix1.fannualInterest);
            double interest=0.0;
            double fullamount=0.0;
            interest= ((fix1.fannualInterest/100)/12)*fix1.fmonths*fix1.famount;
            fullamount= fix1.famount+interest;
        printf("\t\t\t|  %10s   %04s-%02s-%02s        %5.3lf            %3d         %20.3lf   %30.3f |\n",fix1.faccountNumber,fix1.ftyear,fix1.ftmonth,fix1.ftdate,fix1.fannualInterest,fix1.fmonths,fix1.famount,fullamount);
        }
        printf("\t\t\t-------------------------------------------------------------------------------------------------------------------------\n");
     fclose(fptr);

    printf("\n\n\n\n\t\t\t---------------------------------------------------------------------------------\n");
    printf("\t\t\t|                                                                                |\n");
    printf("\t\t\t| (1) Go to fixed accounts menu                                                  |\n");
    printf("\t\t\t| (2) Go to main menu                                                            |\n");
    printf("\t\t\t|                                                                                |\n");
    printf("\t\t\t----------------------------------------------------------------------------------\n");
    printf("\t\t\t      Enter your choice : ");
    scanf(" %[^\n]",&choice);
    value= selectChoice(choice);
  switch (value)
     {
     case 1:
            loading();
           adminFixedAccounts();
         break;
     case 2:
            loading();
          adminMainMenu();
        break;
     default:
         strcpy(msg,"Invalid Choice");
         invalidmsg(msg);
        viewAdminFixedAccounts();
        break;
        }}
   // Admin View Customers Menu
 void adminViewCustomers()
 {    system("COLOR 6");
      char msg[20];
     int value=0;
     char choice[2];
    printf("\n\n\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\t\t\t*                ABC Banking Management System              *\n");
    printf("\t\t\t*                                                           *\n");
    printf("\t\t\t*                    Customers Details Menu                 *\n");
    printf("\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\t\t\t*                                                           *\n");
    printf("\t\t\t*  1. Customer Details View                                 *\n");
    printf("\t\t\t*  2. Customers Details View                                *\n");
    printf("\t\t\t*  3. Go to Main Menu                                       *\n");
    printf("\t\t\t*                                                           *\n");
    printf("\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\n\n\t\t\t      Enter choice : ");
    scanf(" %[^\n]",&choice);
    value=selectChoice(choice);
    switch(value)
    {
    case 1:
        system("cls");
        viewAdminCustomerDetails();
     break;
    case 2:
       system("cls");
       viewAdminCustomersDetails();
        break;
    case 3:
        system("cls");
        adminMainMenu();
    default:
         strcpy(msg,"Invalid Choice");
         invalidmsg(msg);
        adminViewCustomers();
    } }

     //View Search Customer Details()
void viewAdminCustomerDetails()
{  system("COLOR 6");
      char msg[20];
    struct savingsAccount sav1;
    struct fixedAccount fix1;
     char accountNo[15];
     int value=0;
     char choice2[2];
     int c=0;
    printf("\n\n\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\t\t\t*                ABC Banking Management System              *\n");
    printf("\t\t\t*                                                           *\n");
    printf("\t\t\t*                    View Customer Details                  *\n");
    printf("\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
    printf("\t\t\t    Enter Account no: ");
    scanf(" %[^\n]",accountNo);
    printf("\n\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
    value= okcancelSelection();

   switch(value)
    {FILE *fptr;
    case 1:
        fptr = fopen("SavingsAccountsDetails.txt","r");
        while (!feof(fptr))
         {fscanf(fptr," %s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %d %d",sav1.saccountNumber,sav1.styear,sav1.stmonth,sav1.stdate,sav1.sSname,sav1.sFname,sav1.sLname,sav1.sbyear,sav1.sbmonth,sav1.sbdate,sav1.saddress,sav1.sidNumber,sav1.sphoneNumber,sav1.semail,&sav1.samount,&sav1.shours,&sav1.smin,&sav1.ssec);

        if(strcmp(accountNo,sav1.saccountNumber)==0)
        {   c=1;
            system("cls");
        printf("\n\n\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("|                                    Name               Birthday                     Address                      Id Number    PhoneNumber                 Email      |\n");
        printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("|   %25s %10s %10s    %04s-%02s-%02s    %40s   %10s   %10s    %25s|\n",sav1.sSname,sav1.sFname,sav1.sLname,sav1.sbyear,sav1.sbmonth,sav1.sbdate,sav1.saddress,sav1.sidNumber,sav1.sphoneNumber,sav1.semail);
        printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        }}
        fclose(fptr);
        FILE *fpointer = fopen("FixedAccountsDetails.txt","r");
        while (!feof(fptr))
        {fscanf(fptr,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %lf",fix1.faccountNumber,fix1.ftyear,fix1.ftmonth,fix1.ftdate,fix1.fSname,fix1.fFname,fix1.fLname,fix1.fbyear,fix1.fbmonth,fix1.fbdate,fix1.faddress,fix1.fidNumber,fix1.fphoneNumber,fix1.femail,&fix1.famount,&fix1.fmonths,&fix1.fannualInterest);
            if(strcmp(accountNo,fix1.faccountNumber)==0)
            {  c=1;
                system("cls");
        printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("|                                    Name               Birthday                     Address                      Id Number    PhoneNumber                 Email      |\n");
        printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("|   %25s %10s %10s    %04s-%02s-%02s    %40s   %10s   %10s    %25s|\n",fix1.fSname,fix1.fFname,fix1.fLname,fix1.fbyear,fix1.fbmonth,fix1.fbdate,fix1.faddress,fix1.fidNumber,fix1.fphoneNumber,fix1.femail);
        printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
            }}
        if(c==0)
        {    strcpy(msg,"Customer not found");
             invalidmsg(msg);
        }
        break;
      case 2:
           printf("\n\n\t\t\t\t\tCanceled !");
            sleep(3);
            system("cls");
            adminViewCustomers();
    default:
         strcpy(msg,"Invalid Choice");
         invalidmsg(msg);
}
   do { value=0;
    printf("\n\n\t\t\t------------------------------------------------------\n");
    printf("\t\t\t|                                                      |\n");
    printf("\t\t\t| (1) Search another Customer                          |\n");
    printf("\t\t\t| (2) Go to Customers Details  menu                    |\n");
    printf("\t\t\t| (3) Go to main menu                                  |\n");
    printf("\t\t\t|                                                      |\n");
    printf("\t\t\t--------------------------------------------------------\n");
    printf("\t\t\t      Enter your choice : ");
    scanf(" %[^\n]",&choice2);
    value=selectChoice(choice2);
    switch (value)
     {
     case 1:
               system("cls");
          viewAdminCustomerDetails();
         break;
     case 2:
               system("cls");
           adminViewCustomers();
        break;
     case 3:
               system("cls");
            adminMainMenu();
        break;
     default:
         strcpy(msg,"Invalid Choice");
         invalidmsg(msg);
        break;
   }}while(!((value==1)|| (value==2)||(value==3)));
      }
    //View All Customers Details
      void viewAdminCustomersDetails()
      { system("COLOR 6");
          struct savingsAccount sav1;
        struct fixedAccount fix1;
            int value=0;
            char choice[2];
            char msg[20];
         printf("\n\n\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
         printf("\t\t\t*                                               ABC Banking Management System                                           *\n");
         printf("\t\t\t*                                                                                                                       *\n");
         printf("\t\t\t*                                                   View Customers Details                                              *\n");
         printf("\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
        printf("\n\n\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("|   Account No                           Name                Birthday                      Address                   Id Number    PhoneNumber           Email         |\n");
        printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

        FILE *fptr= fopen("SavingsAccountsDetails.txt","r");
       while(!feof(fptr))
       {
        fscanf(fptr,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %d %d ",sav1.saccountNumber,sav1.styear,sav1.stmonth,sav1.stdate,sav1.sSname,sav1.sFname,sav1.sLname,sav1.sbyear,sav1.sbmonth,sav1.sbdate,sav1.saddress,sav1.sidNumber,sav1.sphoneNumber,sav1.semail,&sav1.samount,&sav1.shours,&sav1.smin,&sav1.ssec);
        printf("|%13s  %20s %10s %10s  %04s-%02s-%02s   %40s  %10s  %10s  %25s|\n",sav1.saccountNumber,sav1.sSname,sav1.sFname,sav1.sLname,sav1.sbyear,sav1.sbmonth,sav1.sbdate,sav1.saddress,sav1.sidNumber,sav1.sphoneNumber,sav1.semail);
       }
       fclose(fptr);
        printf("|                                                                                                                                                                     |\n");
        printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("|                                                                                                                                                                     |\n");
        FILE *fpointer = fopen("FixedAccountsDetails.txt","r");
       while(!feof(fpointer))
             {
         fscanf(fptr,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %lf",fix1.faccountNumber,fix1.ftyear,fix1.ftmonth,fix1.ftdate,fix1.fSname,fix1.fFname,fix1.fLname,fix1.fbyear,fix1.fbmonth,fix1.fbdate,fix1.faddress,fix1.fidNumber,fix1.fphoneNumber,fix1.femail,&fix1.famount,&fix1.fmonths,&fix1.fannualInterest);
         printf("|%13s  %20s %10s %10s  %04s-%02s-%02s   %40s  %10s  %10s  %25s|\n",fix1.faccountNumber,fix1.fSname,fix1.fFname,fix1.fLname,fix1.fbyear,fix1.fbmonth,fix1.fbdate,fix1.faddress,fix1.fidNumber,fix1.fphoneNumber,fix1.femail);
             }
             fclose(fpointer);
        printf("|                                                                                                                                                                     |\n");
        printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    printf("\n\n\n\n\t\t\t----------------------------------------------------------------------------------\n");
    printf("\t\t\t|                                                                                |\n");
    printf("\t\t\t| (1) Go to customers details menu                                               |\n");
    printf("\t\t\t| (2) Go to main menu                                                            |\n");
    printf("\t\t\t|                                                                                |\n");
    printf("\t\t\t----------------------------------------------------------------------------------\n");
    printf("\t\t\t      Enter your choice : ");
    scanf(" %[^\n]",&choice);
    value= selectChoice(choice);

    switch (value)
       {
     case 1:
          loading();
          adminViewCustomers();
         break;
     case 2:
           loading();
          adminMainMenu();
        break;
     default:
         strcpy(msg,"Invalid Choice");
         invalidmsg(msg);
        viewAdminCustomersDetails();
        break;
      }}
   // Admin Customers Login Account Menu
   void adminCustomersLoginAccounts()
 {
  system("COLOR 6");
  int value=0;
  char choice[2];
  char msg[20];
     printf("\n\n\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\t\t\t*                ABC Banking Management System              *\n");
    printf("\t\t\t*                                                           *\n");
    printf("\t\t\t*                 Customers Login Account Menu              *\n");
    printf("\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\t\t\t*                                                           *\n");
    printf("\t\t\t*  1. Add new login account                                 *\n");
    printf("\t\t\t*  2. View  login account                                   *\n");
    printf("\t\t\t*  3. Reset  password                                       *\n");
    printf("\t\t\t*  4. Delete account                                        *\n");
    printf("\t\t\t*  5. Go to Main Menu                                       *\n");
    printf("\t\t\t*                                                           *\n");
    printf("\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\n\n\t\t\t    Enter your choice: ");
    scanf(" %[^\n]",&choice);
    value=selectChoice(choice);
    switch(value)
    {
    case 1:
        loading();
        addAdminNewLoginAccount();
        break;
    case 2:
        loading();
        viewAdminLoginAccount();
        break;
    case 3:
        loading();
        updateAdminLoginAccountDetails();
        break;
    case 4:
        loading();
        deleteAdminLoginAccount();
    case 5:
        loading();
        adminMainMenu();
             break;
    default:
         strcpy(msg,"Invalid Choice");
         invalidmsg(msg);
         adminCustomersLoginAccounts();
    }}

    // Add Customer New Login Account
 void addAdminNewLoginAccount()
 {  system("COLOR 6");
     struct savingsAccount sav1;
     struct customerLoginAccount log1;
     struct customerLoginAccount log2;
     int value=0;
     char choice[2];
     char msg[20];
     int isAccountexist=0;
     int issavingAccountexist=0;
     char accountnumber[15];
     strcpy(log1.caccountNumber,"SAV");
    printf("\n\n\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\t\t\t*                ABC Banking Management System              *\n");
    printf("\t\t\t*                                                           *\n");
    printf("\t\t\t*               Add New Customers Login Account             *\n");
    printf("\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
    printf("\t\t\t    1. Account Number                 : SAV");
    scanf(" %[^\n]",accountnumber);
    accountNumberValidate(accountnumber,log1.caccountNumber);
    printf("\t\t\t    2. Password                       : ");
    scanf(" %[^\n]",log1.cpassword);
    passwordValidation(log1.cpassword);
    printf("\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
    value= okcancelSelection();

     switch (value)
     {
    FILE *fptr;
    case 1:
        strcat(log1.caccountNumber,accountnumber);
     fptr= fopen("CustomerLoginAccountsDetails.txt","r");
    while(!feof(fptr))
    { fscanf(fptr,"%s %s \n",log2.caccountNumber,log2.cpassword);
        if(strcmp(log1.caccountNumber,log2.caccountNumber)==0)
     {
      isAccountexist=1;
     }}
     fclose(fptr);
     FILE *fpointer = fopen("SavingsAccountsDetails.txt","r");
     while(!feof(fpointer))
     {fscanf(fptr,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %d %d ",sav1.saccountNumber,sav1.styear,sav1.stmonth,sav1.stdate,sav1.sSname,sav1.sFname,sav1.sLname,sav1.sbyear,sav1.sbmonth,sav1.sbdate,sav1.saddress,sav1.sidNumber,sav1.sphoneNumber,sav1.semail,&sav1.samount,&sav1.shours,&sav1.smin,&sav1.ssec);
       if(strcmp(log1.caccountNumber,sav1.saccountNumber)==0)
       {
           issavingAccountexist=1;
       }}
       fclose(fpointer);
    if(isAccountexist!=0 || issavingAccountexist!=1)
    {  if(isAccountexist!=0)
        {strcpy(msg,"Account is already exist");}
        else
        {strcpy(msg,"Savings Account Number not found");}
         invalidmsg(msg);
    }
    else
    { fptr= fopen("CustomerLoginAccountsDetails.txt","a");
    fprintf(fptr,"%s %s\n",log1.caccountNumber,log1.cpassword);
     fclose(fptr);
     printf("\n\n\t\t\t\t\t Customer Login Account Create Successfully !");
     sleep(3);
     loading();
    }
      break;
    case 2:
        printf("\n\n\t\t\t\t\tCanceled !");
        sleep(3);
        loading();
        addAdminNewLoginAccount();
        break;
    default:
        strcpy(msg,"Invalid Choice");
        invalidmsg(msg);
     }
     do { value=0;
    printf("\n\n\t\t\t------------------------------------------------------\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t| (1) Add another Login account                      |\n");
    printf("\t\t\t| (2) Go to Customer Login accounts menu             |\n");
    printf("\t\t\t| (3) Go to main menu                                |\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t------------------------------------------------------\n");
    printf("\t\t\t      Enter your choice : ");
    scanf(" %[^\n]",&choice);
    value=selectChoice(choice);
 switch (value)
     {
     case 1:
        loading();
        addAdminNewLoginAccount();
         break;
     case 2:
        loading();
        adminCustomersLoginAccounts();
         break;
     case 3:
        loading();
        adminMainMenu();
        break;
    default:
        strcpy(msg,"Invalid Choice");
        invalidmsg(msg);
     }}while(!((value ==1)|| (value==2)|| (value==3)));
 }
   // View Customer Login Account Password
 void viewAdminLoginAccount()
 {  system("COLOR 6");
     char msg[20];
struct customerLoginAccount log1;
  char accountNo[10];
  char accountNumber[20];
     int value=0;
     char choice[2];
     int isaccountexist=0;
    printf("\n\n\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\t\t\t*                ABC Banking  Management System             *\n");
    printf("\t\t\t*                                                           *\n");
    printf("\t\t\t*                 View  Customers Login Account             *\n");
    printf("\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
    printf("\t\t\t   1. Account Number               : SAV");
    scanf(" %[^\n]",&accountNo);
    printf("\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
    value=okcancelSelection();
    switch(value)
    { FILE *fptr;
    case 1:
        strcpy(accountNumber,"SAV");
        strcat(accountNumber,accountNo);
        fptr=fopen("CustomerLoginAccountsDetails.txt","r");
        while(!feof(fptr))
        {
        fscanf(fptr,"%s %s",&log1.caccountNumber,&log1.cpassword);
        if(strcmp(accountNumber,log1.caccountNumber)==0)
        { isaccountexist=1;
         system("cls");
        printf("\n\n\n\t\t\t------------------------------------------------------------");
        printf("\n\t\t\t| Password : %s                                      |",log1.cpassword);
        printf("\n\t\t\t------------------------------------------------------------\n");}}

      if(isaccountexist==0)
        {
         strcpy(msg,"Account not found");
         invalidmsg(msg);
        }
      case 2:
           printf("\n\n\t\t\t\t\tCanceled !");
            loading();
            viewAdminLoginAccount();
     default:
           strcpy(msg,"Invalid Choice");
           invalidmsg(msg);
}
  do { value=0;
    printf("\n\n\t\t\t------------------------------------------------------\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t| (1) Search another Login Account                   |\n");
    printf("\t\t\t| (2) Go to Customers Login Accounts menu            |\n");
    printf("\t\t\t| (3) Go to main menu                                |\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t------------------------------------------------------\n");
    printf("\t\t\t      Enter your choice : ");
    scanf(" %[^\n]",&choice);
    value=selectChoice(choice);
 switch (value)
     {
     case 1:
               loading();
          viewAdminLoginAccount();
         break;
     case 2:
               loading();
           adminCustomersLoginAccounts();
        break;
     case 3:
            loading();
            adminMainMenu();
        break;
     default:
         strcpy(msg,"Invalid Choice");
         invalidmsg(msg);
        } }while(!((value==1)||(value==2)||(value==3))); }

   // Update Login Account Password
 void updateAdminLoginAccountDetails()
 {system("COLOR 6");
   struct customerLoginAccount log1;
     struct customerLoginAccount log2;
     int value=0;
     char choice[2];
     char choice1[2];
     char msg[20];
     char accountNumber[15];
     int isAccount =0;
     strcpy(log1.caccountNumber,"SAV");
    printf("\n\n\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\t\t\t*                ABC Banking  Management System             *\n");
    printf("\t\t\t*                                                           *\n");
    printf("\t\t\t*           Reset  Customers Login Account Password            *\n");
    printf("\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
    printf("\t\t\t   1. Account Number               : SAV");
    scanf(" %[^\n]",accountNumber);
    printf("\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
    value=okcancelSelection();
    switch(value)
    {FILE *fptrOld,*fptrNew;
    case 1:
           strcat(log1.caccountNumber,accountNumber);
        fptrOld = fopen("CustomerLoginAccountsDetails.txt","r");
        fptrNew = fopen("UpdateCustomerLoginAccountsDetails.txt","a+");
        while(!feof(fptrOld))
        {
             fscanf(fptrOld," %s %s ",log2.caccountNumber,log2.cpassword);

             if(strcmp(log1.caccountNumber,log2.caccountNumber)!=0)
             {
               fprintf(fptrNew," %s %s \n",log2.caccountNumber,log2.cpassword);
             }
             else
                {
                    isAccount ++;
                 strcpy(log1.cpassword,log2.cpassword);
                }}
             if(isAccount==1)
             {
               printf("\n\n\t\t\t        Password                       : ");
               scanf(" %[^\n]",log1.cpassword);
               passwordValidation(log1.cpassword);
               fprintf(fptrNew," %s %s \n",log1.caccountNumber,log1.cpassword);
               printf("\n\n\t\t\t\t\tPassword reset successfull!");
             }
             else
             {
                strcpy(msg,"Account not found!");
                        invalidmsg(msg);
             }
                  fclose(fptrNew);
                  fclose(fptrOld);
                  remove("CustomerLoginAccountsDetails.txt")  ;
                  rename("UpdateCustomerLoginAccountsDetails.txt","CustomerLoginAccountsDetails.txt");
                  break;
     case 2:
        printf("\n\n\t\t\t Canceled!");
        sleep(3);
        loading();
        updateAdminLoginAccountDetails();
        break;
     default:
          strcpy(msg,"Invalid Choice!");
                invalidmsg(msg);}

                 do {  system("cls");
                        value=0;
    printf("\n\n\n\t\t\t------------------------------------------------------\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t| (1) Update another Login Account                   |\n");
    printf("\t\t\t| (2) Go to Customers Login Accounts menu            |\n");
    printf("\t\t\t| (3) Go to main menu                                |\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t------------------------------------------------------\n");
    printf("\t\t\t      Enter your choice : ");
    scanf(" %[^\n]",&choice1);
    value=selectChoice(choice1);
 switch (value)
     {
     case 1:
               loading();
          updateAdminLoginAccountDetails();
         break;
     case 2:
               loading();
           adminCustomersLoginAccounts();
        break;
     case 3:
            loading();
            adminMainMenu();
        break;
     default:
         strcpy(msg,"Invalid Choice");
         invalidmsg(msg);
        } }while(!((value==1)||(value==2)||(value==3)));


 }
   // Delete Login Account
 void deleteAdminLoginAccount()
 {system("COLOR 6");
     struct customerLoginAccount log1;
     struct customerLoginAccount log2;
     int value=0;
     char choice[2];
     char choice1[2];
     char msg[20];
     int isAccount=0;
     char accountNumber[15];
     strcpy(log1.caccountNumber,"SAV");
    printf("\n\n\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\t\t\t*                ABC Banking  Management System             *\n");
    printf("\t\t\t*                                                           *\n");
    printf("\t\t\t*                Delete  Customers Login Account            *\n");
    printf("\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
    printf("\t\t\t   1. Account Number               : SAV");
    scanf(" %[^\n]",accountNumber);
    printf("\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
    value=okcancelSelection();
    switch(value)
    {  FILE *fptrOld ,*fptrNew;
    case 1:
         strcat(log1.caccountNumber,accountNumber);
        fptrOld = fopen("CustomerLoginAccountsDetails.txt","r+");
        fptrNew = fopen("DeleteCustomerLoginAccountsDetails.txt","a+");
        while(!feof(fptrOld))
        {
             fscanf(fptrOld," %s %s ",log2.caccountNumber,log2.cpassword);

             if(strcmp(log1.caccountNumber,log2.caccountNumber)!=0)
             {
               fprintf(fptrNew," %s %s \n",log2.caccountNumber,log2.cpassword);
             }
             else
             {
               isAccount=1;
                system("cls");
                printf("\n\n\n\t\t\t-----------------------------------------------------------------\n");
                printf("\t\t\t|    Account No                                Password         |\n");
                printf("\t\t\t-----------------------------------------------------------------\n");
                printf("\t\t\t|    %10s                 %20s         |\n",log2.caccountNumber,log2.cpassword);
                printf("\t\t\t-----------------------------------------------------------------\n\n\n");
                strcpy(log1.cpassword,log2.cpassword);
            }}
             if(isAccount!=0)
             {
                   value=0;



                   printf("\n\n\t\t\t-------------------------------------------------------------\n");
                   printf("\t\t\t| Are you sure you want to delete this account?             | \n");
                   printf("\t\t\t| 1. Yes                                                    |\n");
                   printf("\t\t\t| 2. No                                                     |\n");
                   printf("\t\t\t-------------------------------------------------------------\n");
                   printf("\t\t\t\   Enter the choice : \n");
                   scanf(" %[^\n]",choice);
                   value= selectChoice(choice);
                   switch(value)
                   {
               case 1:
                   printf("\n\n\t\t\t\t\tDelete Account Successfully!");
                   sleep(3);
                   loading();
                   system("cls");
                   break;
               case 2:
               fprintf(fptrNew,"%s %s \n",log1.caccountNumber,log1.cpassword);
                printf("\n\n\t\t\t\t\tCanceled!");
                sleep(3);
                loading();
                deleteAdminLoginAccount();
                     break;
               default:
                   strcpy(msg,"Invalid Choice!");
                invalidmsg(msg);
                    }}
                else
                    {
                        strcpy(msg,"Account not found!");
                        invalidmsg(msg);
                    }
                  fclose(fptrNew);
                  fclose(fptrOld);
                  remove("CustomerLoginAccountsDetails.txt")  ;
                  rename("DeleteCustomerLoginAccountsDetails.txt","CustomerLoginAccountsDetails.txt");
                  break;

    case 2:
        printf("\n\n\t\t\t Canceled!");
        sleep(3);
        loading();
        deleteAdminLoginAccount();
        break;

    default:
            strcpy(msg,"Invalid Choice!");
                invalidmsg(msg);
        }
   do {   systemLogin("cls");
            value=0;
    printf("\n\n\n\t\t\t------------------------------------------------------\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t| (1) Delete another Login Account                   |\n");
    printf("\t\t\t| (2) Go to Customers Login Accounts menu            |\n");
    printf("\t\t\t| (3) Go to main menu                                |\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t------------------------------------------------------\n");
    printf("\t\t\t      Enter your choice : ");
    scanf(" %[^\n]",&choice1);
    value=selectChoice(choice1);
 switch (value)
     {
     case 1:
               loading();
          deleteAdminLoginAccount();
         break;
     case 2:
               loading();
           adminCustomersLoginAccounts();
        break;
     case 3:
            loading();
            adminMainMenu();
        break;
     default:
         strcpy(msg,"Invalid Choice");
         invalidmsg(msg);
        } }while(!((value==1)||(value==2)||(value==3))); }



                  // Customers screen
  void customerMainMenu(char username[])
 { system("COLOR 2");
     char msg[20];
     char choice[2];
      int value=0;
    printf("\n\n\n\t\t\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n");
    printf("\t\t\t=                ABC Banking Management System                =\n");
    printf("\t\t\t=                                                             =\n");
    printf("\t\t\t=                     Customers   Menu                        =\n");
    printf("\t\t\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n");
    printf("\t\t\t=                                                             =\n");
    printf("\t\t\t=  1. Savings Account View                                    =\n");
    printf("\t\t\t=  2. Reset login account password                            =\n");
    printf("\t\t\t=  3. Money Transaction                                       =\n");
    printf("\t\t\t=  4. Logout                                                  =\n");
    printf("\t\t\t=                                                             =\n");
    printf("\t\t\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n");
    printf("\n\n\t\t\t      Enter choice : ");
    scanf(" %[^\n]",&choice);
    value= selectChoice(choice);
    switch(value)
    {case 1:
        loading();
        customerSavingsAccountView(username);
        break;
    case 2:
        loading();
       customerResetLoginPassword(username);
        break;
    case 3:
        loading();
        customerMoneyTransaction(username);
        break;
    case 4:
        loading();
        systemLogin();
        break;
    default:
        strcpy(msg,"Invalid Choice");
         invalidmsg(msg);
        customerMainMenu(username);}}

    // Customers Saving Account Details view
  void customerSavingsAccountView(char username[])
  { struct savingsAccount sav1;
     system("COLOR 2");
      int value=0;
      char choice[2];
      char msg[20];
      FILE *fptr= fopen("SavingsAccountsDetails.txt","r");
      while(!feof(fptr))
      {
       fscanf(fptr,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %d %d ",sav1.saccountNumber,sav1.styear,sav1.stmonth,sav1.stdate,sav1.sSname,sav1.sFname,sav1.sLname,sav1.sbyear,sav1.sbmonth,sav1.sbdate,sav1.saddress,sav1.sidNumber,sav1.sphoneNumber,sav1.semail,&sav1.samount,&sav1.shours,&sav1.smin,&sav1.ssec);
       if(strcmp(username,sav1.saccountNumber)==0)
       {printf("\n\n\n\t\t\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n");
        printf("\t\t\t=                ABC Banking Management System                =\n");
        printf("\t\t\t=                                                             =\n");
        printf("\t\t\t=                    Savings Account View                     =\n");
        printf("\t\t\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n");
        printf("\t\t\t---------------------------------------------------------------\n");
        printf("\t\t\t|      Date          time              Total amount           |\n");
        printf("\t\t\t---------------------------------------------------------------\n");
        printf("\t\t\t|   %04s-%02s-%02s     %02d:%02d:%02d    %20.3lf           |\n",sav1.styear,sav1.stmonth,sav1.stdate,sav1.shours,sav1.smin,sav1.ssec,sav1.samount);
        printf("\t\t\t---------------------------------------------------------------\n");
       }}
        fclose(fptr);
    printf("\n\n\n\t\t\t------------------------------------------------------\n");
    printf("\t\t\t| (1)  Go to main menu                               |\n");
    printf("\t\t\t------------------------------------------------------\n");
    printf("\t\t\t       Enter your choice : ");
    scanf(" %[^\n]",&choice);
    value=selectChoice(choice);
 switch (value)
     {case 1:
            loading();
            customerMainMenu(username);
         break;
     default:
         strcpy(msg,"Invalid Choice");
         invalidmsg(msg);
        customerSavingsAccountView(username);
 }}
   // Customer Login Password Reset
 void customerResetLoginPassword(char username[])
 {
     system("COLOR 2");
     struct  customerLoginAccount  log1;
     char oldpassword[20];
     char newpassword[20];
     char confirmpassword[20];
     char oldCheckpassword[20];
     char msg[40];
     int isAccount =0;
     int value =0;
     char choice[2];
     printf("\n\n\n\t\t\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n");
     printf("\t\t\t=                ABC Banking Management System                =\n");
     printf("\t\t\t=                                                             =\n");
     printf("\t\t\t=                 Reset Login Account Password                =\n");
     printf("\t\t\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n");
     printf("\n\n\t\t\t 1. Old   Password                       : ");
     scanf(" %[^\n]",oldCheckpassword);
     printf("\t\t\t 2. New   Password                       : ");
     scanf(" %[^\n]",newpassword);
     passwordValidation(newpassword);
     printf("\t\t\t 3. Confirm Password                     : ");
     scanf(" %[^\n]",confirmpassword);
     value = okcancelSelection();
    switch(value)
    { FILE *fptrOld,*fptrNew;
     case 1:
         if(strcmp(newpassword,confirmpassword)!=0)
         {
            strcpy(msg,"Password and Confirm password do not match!");
            invalidmsg(msg);
         }
        else {fptrOld = fopen("CustomerLoginAccountsDetails.txt","r");
             fptrNew = fopen("UpdateCustomerLoginAccountsDetails.txt","a+");
             while(!feof(fptrOld))
            {
             fscanf(fptrOld," %s %s ",log1.caccountNumber,log1.cpassword);

             if(strcmp(username,log1.caccountNumber)!=0)
             {
               fprintf(fptrNew," %s %s \n",log1.caccountNumber,log1.cpassword);
             }
             else
                {
                    isAccount ++;
                 strcpy(oldpassword,log1.cpassword);
                }}
             if(isAccount==1)
             {
                      if(strcmp(oldCheckpassword,oldpassword)==0)
                 { if(strcmp(oldpassword,newpassword)!=0)
                  {fprintf(fptrNew," %s %s \n",username,newpassword);
                  printf("\n\n\t\t\t\t\tPassword reset successfull!");
                  loading();
                  fclose(fptrNew);
                  fclose(fptrOld);
                  remove("CustomerLoginAccountsDetails.txt")  ;
                  rename("UpdateCustomerLoginAccountsDetails.txt","CustomerLoginAccountsDetails.txt");}
                  else
                  {
                    strcpy(msg,"Don't Enter Old Password as New Password!");
                    invalidmsg(msg);
                     fclose(fptrNew);
                  fclose(fptrOld);
                  remove("UpdateCustomerLoginAccountsDetails.txt");
                  }}
                    else
                  {
                  strcpy(msg,"Incorrect Old Password!");
                  invalidmsg(msg);
                  fclose(fptrNew);
                  fclose(fptrOld);
                  remove("UpdateCustomerLoginAccountsDetails.txt");
                  }}}
                break;
               case 2:
                    printf("\n\n\t\t\t\t\tCanceled!");
                    loading();
                    customerResetLoginPassword(username);
                    break;
               default:
                    strcpy(msg,"Invalid Choice");
                    invalidmsg(msg);
                    }
            do{
                    value=0;
                printf("\n\n\n\t\t\t------------------------------------------------------\n");
                printf("\t\t\t|                                                    |\n");
                printf("\t\t\t| (1)  Reset Customer login Account                  |\n");
                printf("\t\t\t| (2)  Go to main menu                               |\n");
                printf("\t\t\t|                                                    |\n");
                printf("\t\t\t------------------------------------------------------\n");
                printf("\t\t\t       Enter your choice : ");
                scanf(" %[^\n]",choice);
                value=selectChoice(choice);
               switch (value)
              {
              case 1:
                loading();
                customerResetLoginPassword(username);
                break;
              case 2:
              loading();
              customerMainMenu(username);
              break;
             default:
             strcpy(msg,"Invalid Choice");
             invalidmsg(msg);
               }}while(!(value ==1 || value==2 ));
 }
   // Customer Money Transaction
 void customerMoneyTransaction(char username[])
 { system("COLOR 2");
     char msg[20];
  int value=0;
  char choice[2];
     printf("\n\n\n\t\t\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n");
    printf("\t\t\t=                ABC Banking Management System                =\n");
    printf("\t\t\t=                                                             =\n");
    printf("\t\t\t=                      Money  Transaction                     =\n");
    printf("\t\t\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n");
    printf("\t\t\t=                                                             =\n");
    printf("\t\t\t=  1. Withdraw Money                                          =\n");
    printf("\t\t\t=  2. Deposit Money                                           =\n");
    printf("\t\t\t=  3. Go to Main Menu                                         =\n");
    printf("\t\t\t=                                                             =\n");
    printf("\t\t\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n");
    printf("\n\n\t\t\t      Enter choice : ");
    scanf(" %[^\n]",&choice);
    value=selectChoice(choice);
    switch(value)
    {case 1:
        loading();
        customerWithdrawMoney(username);
        break;
    case 2:
        loading();
        customerDepositMoney(username);
        break;
    case 3:
        loading();
        customerMainMenu(username);
        break;
    default:
        strcpy(msg,"Invalid Choice");
         invalidmsg(msg);
        customerMoneyTransaction(username);
    }}
   // Withdraw Money Transaction
void customerWithdrawMoney(char username[])
{ struct savingsAccount sav1;
  struct savingsAccount sav2;
  system("COLOR 2");
    char accountNumber[15];
    char amount[50];
    int limit =0;
   int value=0;
   char choice[2];
   int suggest=0;
   int iyear=0;
   int imonth=0;
   char msg[20];
   int isAccount=0;
   int number=0;
   double fullamount=0.0;
   strcpy(sav1.saccountNumber,"SAV");
     printf("\n\n\n\t\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n");
    printf("\t\t=                ABC Banking Management System                    =\n");
    printf("\t\t=                                                                 =\n");
    printf("\t\t=                        Withdraw Money                           =\n");
    printf("\t\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n\n");
    printf("\t\t   1.Today Date                  \n");
    printf("\t\t          Year                                    : ");
     scanf(" %[^\n]",sav1.styear);
    iyear=yearValidation(sav1.styear);
    printf("\t\t          Month                                   : ");
    scanf(" %[^\n]",sav1.stmonth);
    imonth=monthValidation(sav1.stmonth);
    printf("\t\t          Date                                    : ");
    scanf(" %[^\n]",sav1.stdate);
    dateValidation(iyear,imonth,sav1.stdate);
    printf("\t\t  2. Enter the Amount of Withdraw                 : ");
    scanf(" %[^\n]",amount );
    suggest=1;
    number=2;
     sav1.samount =amountValidation(amount,limit,suggest,number);

    printf("\t\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n\n");
    value=okcancelSelection();

    switch(value)
    {FILE *oldfpointer,*newfpointer;
    case 1:
        oldfpointer=fopen("SavingsAccountsDetails.txt","r");
        newfpointer= fopen("UpdateSavingsAccountsDetails.txt","a");
        while(!feof(oldfpointer))
        { fscanf(oldfpointer," %s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %d %d ",sav2.saccountNumber,sav2.styear,sav2.stmonth,sav2.stdate,sav2.sSname,sav2.sFname,sav2.sLname,sav2.sbyear,sav2.sbmonth,sav2.sbdate,sav2.saddress,sav2.sidNumber,sav2.sphoneNumber,sav2.semail,&sav2.samount,&sav2.shours,&sav2.smin,&sav2.ssec);
          if(strcmp(username,sav2.saccountNumber)==0)
         {    autoTime(&sav1.shours,&sav1.smin,&sav1.ssec);
          fullamount= sav2.samount-sav1.samount;
             if(fullamount>=500)
           {
            fprintf(newfpointer," %s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %d %d \n",sav2.saccountNumber,sav1.styear,sav1.stmonth,sav1.stdate,sav2.sSname,sav2.sFname,sav2.sLname,sav2.sbyear,sav2.sbmonth,sav2.sbdate,sav2.saddress,sav2.sidNumber,sav2.sphoneNumber,sav2.semail,fullamount,sav1.shours,sav1.smin,sav1.ssec);
            isAccount=1;
           }}
         else
         {
           fprintf(newfpointer," %s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %d %d \n",sav2.saccountNumber,sav2.styear,sav2.stmonth,sav2.stdate,sav2.sSname,sav2.sFname,sav2.sLname,sav2.sbyear,sav2.sbmonth,sav2.sbdate,sav2.saddress,sav2.sidNumber,sav2.sphoneNumber,sav2.semail,sav2.samount,sav2.shours,sav2.smin,sav2.ssec);
         }}
        if(isAccount==1)
        {fclose(oldfpointer);
        fclose(newfpointer);
        remove("SavingsAccountsDetails.txt");
        rename("UpdateSavingsAccountsDetails.txt","SavingsAccountsDetails.txt");
            printf("\n\n\t\t\t\t\tMoney Withdraw Successfully!");
            loading();}
            else
            {
                 strcpy(msg,"Money Withdraw Unsuccessfully!");
               invalidmsg(msg);
               remove("UpdateSavingsAccountsDetails.txt");
            }
        break;
    case 2:
        printf("\n\n\t\t\t\t\tCanceled!");
        loading();
        customerWithdrawMoney(username);
        break;
    default:
        strcpy(msg,"Invalid Choice");
         invalidmsg(msg);
    }
   do { value=0;
    printf("\n\n\t\t\t------------------------------------------------------\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t| (1) Money Withdraw Again                           |\n");
    printf("\t\t\t| (2) Go to Transaction menu                         |\n");
    printf("\t\t\t| (3) Go to main menu                                |\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t------------------------------------------------------\n");
    printf("\t\t\t      Enter your choice : ");
    scanf(" %[^\n]",&choice);
    value= selectChoice(choice);
    switch (value)
     {case 1:
           loading();
           customerWithdrawMoney(username);
         break;
     case 2:
           loading();
           customerMoneyTransaction(username);
        break;
     case 3:
           loading();
           customerMainMenu(username);
        break;
     default:
         strcpy(msg,"Invalid Choice");
         invalidmsg(msg);
}}while(!((value==1)||(value==2)||(value==3)));}

  // Deposit Money Transaction
 void customerDepositMoney(char username[])
 {   struct savingsAccount sav1;
     struct savingsAccount sav2;
     system("COLOR 2");
 char amount[50];
 double fullamount=0.0;
    int limit=0;
   int value=0;
   char choice[2];
   int iyear=0;
   int imonth=0;
   int suggest=0;
   char msg[20];
   int number=0;
   int isAccount=0;
    printf("\n\n\n\t\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n");
    printf("\t\t=                ABC Banking Management System                    =\n");
    printf("\t\t=                                                                 =\n");
    printf("\t\t=                        Deposit Money                            =\n");
    printf("\t\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n\n");
    printf("\t\t    1. Today Date                  \n");
    printf("\t\t          Year                                    : ");
     scanf(" %[^\n]",sav1.styear);
    iyear=yearValidation(sav1.styear);
    printf("\t\t          Month                                   : ");
    scanf(" %[^\n]",sav1.stmonth);
    imonth=monthValidation(sav1.stmonth);
    printf("\t\t          Date                                    : ");
    scanf(" %[^\n]",sav1.stdate);
    dateValidation(iyear,imonth,sav1.stdate);
    printf("\t\t  2. Enter the Amount of Withdraw                 :");
    scanf(" %[^\n]",amount );
    suggest=1;
    number=2;
     sav1.samount =amountValidation(amount,limit,suggest,number);
    printf("\t\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n\n");
    value=okcancelSelection();

    switch(value)
    {FILE *oldfpointer,*newfpointer;
    case 1:
        oldfpointer=fopen("SavingsAccountsDetails.txt","r");
        newfpointer= fopen("UpdateSavingsAccountsDetails.txt","a");
        while(!feof(oldfpointer))
        { fscanf(oldfpointer," %s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %d %d ",sav2.saccountNumber,sav2.styear,sav2.stmonth,sav2.stdate,sav2.sSname,sav2.sFname,sav2.sLname,sav2.sbyear,sav2.sbmonth,sav2.sbdate,sav2.saddress,sav2.sidNumber,sav2.sphoneNumber,sav2.semail,&sav2.samount,&sav2.shours,&sav2.smin,&sav2.ssec);
          if(strcmp(username,sav2.saccountNumber)==0)
         {    autoTime(&sav1.shours,&sav1.smin,&sav1.ssec);
            fullamount= sav1.samount+sav2.samount;
           fprintf(newfpointer," %s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %d %d \n",sav2.saccountNumber,sav1.styear,sav1.stmonth,sav1.stdate,sav2.sSname,sav2.sFname,sav2.sLname,sav2.sbyear,sav2.sbmonth,sav2.sbdate,sav2.saddress,sav2.sidNumber,sav2.sphoneNumber,sav2.semail,fullamount,sav1.shours,sav1.smin,sav1.ssec);
            isAccount++;
          }
         else
         {
           fprintf(newfpointer," %s %s %s %s %s %s %s %s %s %s %s %s %s %s %lf %d %d %d \n",sav2.saccountNumber,sav2.styear,sav2.stmonth,sav2.stdate,sav2.sSname,sav2.sFname,sav2.sLname,sav2.sbyear,sav2.sbmonth,sav2.sbdate,sav2.saddress,sav2.sidNumber,sav2.sphoneNumber,sav2.semail,sav2.samount,sav2.shours,sav2.smin,sav2.ssec);
         }
        }
        fclose(oldfpointer);
        fclose(newfpointer);
        remove("SavingsAccountsDetails.txt");
        rename("UpdateSavingsAccountsDetails.txt","SavingsAccountsDetails.txt");
        printf("\n\n\t\t\t\t\tMoney  Successfully!");
        loading();
        break;
    case 2:
        printf("\n\n\t\t\t\t\tCanceled!");
        loading();
        customerDepositMoney (username);
        break;
    default:
        strcpy(msg,"Invalid Choice");
         invalidmsg(msg);
    }
    do{int value=0;
    printf("\n\n\t\t\t------------------------------------------------------\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t| (1) Money Deposit Again                            |\n");
    printf("\t\t\t| (2) Go to Transaction menu                         |\n");
    printf("\t\t\t| (3) Go to main menu                                |\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t------------------------------------------------------\n");
    printf("\t\t\t      Enter your choice : ");
    scanf(" %[^\n]",&choice);
    value=selectChoice(choice);

 switch (value)
     {case 1:
               loading();
           customerDepositMoney(username);
         break;
     case 2:
               loading();
           customerMoneyTransaction(username);
        break;
     case 3:
               loading();
             customerMainMenu(username);
        break;
     default:
         strcpy(msg,"Invalid Choice");
         invalidmsg(msg);
   }} while(!((value==1)|| (value==2)||(value==3)));}
   //loading Function
 void loading()
 {   int i=0;
     printf("\n\n\t\t\t\t \t Loading");
     for(i=0;i<4;i++)
     {printf(".");
      Sleep(300);}
     system("cls");
 }

   //Select Choice
int selectChoice(char choice[])
{   int value=0;
    int convertchar=0;
    convertchar=(int)choice[0];
    if(strlen(choice)== 1)
    {  switch(convertchar)
        {case 49:
                value=1;
                break;
              case 50:
                value=2;
                 break;
              case 51:
                value=3;
                 break;
              case 52:
                value=4;
                 break;
              case 53:
                value=5;
                 break;
              case 54:
                value=6;
                 break;}}
return value;}

   //Invalid Message
void invalidmsg(char msg[])
{       system("COLOR 4");
         printf("\a\n\n\t\t\t\t\t%s!\n\n",msg);
         sleep(3);
         system("cls");
         system("COLOR 1");}

void autoTime(int *hours,int *min, int *sec)
{   time_t cTime;
    time(&cTime);
    struct tm *currentTime = localtime(&cTime);
    *hours = currentTime->tm_hour;
    *min=currentTime->tm_min;
    *sec =currentTime->tm_sec;
}
    // Account Number validation
void  accountNumberValidate(char accountNumber[],char msg[])
{
    int convertchar=0;
    int checkError =0;
    int length=0;
    int i=0;
    int incomplete=0;
    do
    {
        incomplete=0;
        checkError =0;
        length= strlen(accountNumber);
        if(length <10)
        {
            incomplete ++;
        }
        else if(length>10)
        {
            checkError++;
        }
        else{
             for(i=0;i<10;i++)
            {
                convertchar=0;
                convertchar = (int)accountNumber[i];
              if(convertchar<48 || convertchar>57 )
              {
                  checkError++;
              }}}
            if(checkError !=0 || incomplete!=0)
           {
               system("COLOR 4");
               if(incomplete!=0)
               {
                printf("\a\t\t\t\t\t Incomplete Account Number !\n");
               }
               else
               {
                  printf("\a\t\t\t\t\t %s Invalid Account Number Format!\n");
               }
              sleep(2);
              system("COLOR 1");
              printf("\t\t   1. Account Number                               : %s",msg);
               scanf(" %[^\n]",accountNumber);
           }}while(checkError !=0 || incomplete!=0);
}
               // Year Validate
int yearValidation(char year[] )
{
    int checkError=0;
    int i=0;
    int convertchar =0;
    int iyear=0;
    int length= 0;
    int limitYear=0;
  do{
        limitYear=0;
        checkError=0;
        iyear=0;
        length = strlen(year);
        for(i=0;i<length;i++)
       {   convertchar=0;
           convertchar = (int)year[i];
        if (convertchar<48 || convertchar>57)
            {checkError++;}
              else
              {iyear += numbersGet(&convertchar, &length, &i);  }}

           if(checkError ==0)
           {if(iyear<1900)
             {limitYear++;
            } }
            printf("%d",iyear);
             if(checkError!=0 || limitYear!=0)
                {   system("COLOR 4");
                    if(checkError!=0)
                    {
                    printf("\a\t\t\t\t\t Invalid Year Format!\n");
                    }
                    else
                    {
                    printf("\a\t\t\t\t\t Invalid Year!\n");
                    }
                     sleep(3);
                     system("COLOR 1");
                     printf("\t\t          Year                                     : ");
                     scanf(" %[^\n]",year);}
             }while(checkError!=0 || limitYear!=0);
             return iyear;}

 int monthValidation(char month[])
 {
    int checkError=0;
    int i=0;
    int convertchar =0;
    int imonth=0;
    int length=0;
    int limitMonth=0;
  do {
        checkError =0;
        limitMonth=0;
        imonth=0;
        length= strlen(month);
        for(i=0;i<length;i++)
         {
            convertchar=0;
            convertchar = (int)month[i];
            if (convertchar<48 || convertchar>57)
            {
              checkError++;
              }
               else
              {imonth += numbersGet(&convertchar, &length, &i);}}
              if(checkError ==0)
              {
               if(imonth<1 || imonth>12)
               {limitMonth++;}}
                if(checkError!=0 || limitMonth!=0)
                {   system("COLOR 4");
                    if(checkError!=0)
                    {
                    printf("\a\t\t\t\t\t Invalid Month Format!\n");
                    }
                    else
                    {
                    printf("\a\t\t\t\t\t Invalid Month!\n");
                    }
                     sleep(3);
                     system("COLOR 1");
                     printf("\t\t          Month                                   : ");
                     scanf(" %[^\n]",month);
                }}while(checkError!=0 || limitMonth!=0);
                return imonth;}
 // Date Validation
void dateValidation(int year,int month,char date[])
{
    int checkError=0;
    int limitDays=0;
    int i=0;
    int convertchar =0;
    int iday=0;
    int length=0;

    do{     limitDays=0;
            checkError=0;
            iday=0;
            length= strlen(date);
        for(i=0;i<length;i++)
       {
            convertchar=0;
            convertchar = (int)date[i];
            if (convertchar<48 || convertchar>57)
            {checkError++;}
               else
              {iday += numbersGet(&convertchar, &length, &i);} }
          if(checkError==0)
              {
                 if(((year%4)==0)&& (year%100 !=0)|| (year%400 ==0))
               {
                 switch(month)
                 {
                 case 1:
                 case 3:
                 case 5:
                 case 7:
                 case 8:
                 case 10:
                 case 12:

                     if(iday<1 || iday>31)
                     {limitDays++;}
                     break;
                case 2:
                    if(iday<1 || iday>29 )
                    {limitDays++;}
                    break;
                default:
                    if(iday<1 || iday>30 )
                    {limitDays++;}}}
           else
               {
                  switch(month)
                 {
              case 1:
              case 3:
              case 5:
              case 7:
              case 8:
              case 10:
              case 12:

                     if(iday<1 || iday>31)
                     {limitDays++;}
                     break;
                  case 2:
                    if(iday<1 || iday>28 )
                    {limitDays++;}
                    break;
                  default:
                       if(iday<1 || iday>30 )
                    {limitDays++;}}}}
                    if(checkError!=0 || limitDays!=0)
                {   system("COLOR 4");
                    if(checkError!=0)
                    {printf("\a\t\t\t\t\t Invalid Date Format!\n");}
                    else
                    {printf("\a\t\t\t\t\t Invalid Date!\n");}
                     sleep(3);
                     system("COLOR 1");
                     printf("\t\t          Date                                     : ");
                     scanf(" %[^\n]",date);
                     }}while(checkError!=0||limitDays!=0);
}
                //Name validation
void nameValidation(char name[],int namepoint)
{   int i=0;
    int convertInt=0;
    int checkError=0;
    int checkCapitals=0;
  do{
     checkError=0;
     checkCapitals=0;
    for(i=0;i<strlen(name);i++)
   {convertInt=0;
      convertInt = (int)name[i];
    if( convertInt <65 || (convertInt>90 && convertInt<97)|| convertInt>122)
      {checkError++;}
    if(convertInt>96 && convertInt<123)
      {checkCapitals++;}
   }
   if(checkError!=0 || checkCapitals!=0)
   {
        system("COLOR 4");
       if(checkError!=0)
       {printf("\a\t\t\t\t\t Invalid format! \n");}
       else
       {printf("\a\t\t\t\t\t Enter CAPITAL letters only ! \n");}
            sleep(3);
            system("COLOR 1");
            if(namepoint==1)
            {   printf("\t\t          SurName                                  : ");}
            else if(namepoint==2)
            {   printf("\t\t          FirstName                                : ");}
            else
            {   printf("\t\t          LastName                                 : ");}
             scanf(" %[^\n]",name);
            }}while(checkError!=0 || checkCapitals!=0);
}
       // ID Number Validation
    void idNumberValidation(char idNumber[])
    {   int i=0;
        int length=0;
        int checkError=0;
        int checkIncomplete=0;
        int convertchar=0;
        do {
        checkError =0;
        checkIncomplete=0;
        convertchar=0;
        length= strlen(idNumber);

        if(length == 10 || length ==12)
        {  if(length ==10)
                {for(i=0;i<9;i++)
                {     convertchar=0;
                  convertchar = (int)idNumber[i];
                  if (convertchar<48 || convertchar>57)
                  {checkError++;}}
                 if( idNumber[9]!= 'V')
                 {  checkError++;}}
                else
                {for(i=0;i<12;i++)
                 {      convertchar=0;
                    convertchar = (int)idNumber[i];
                    if (convertchar<48 || convertchar>57)
                  {checkError++;}}
                    convertchar=(int)idNumber[0];
                    if(convertchar==48)
                    {checkError++;}}}
        else
            {if(length<12)
               {checkIncomplete++;}
               else
                {checkError++;}}
         if(checkError!=0 || checkIncomplete!=0)
            {if(checkError!=0)
                {system("COLOR 4");
                   printf("\a\t\t\t\t\t Invalid ID Number  Format!\n");
                   sleep(3);
                   system("COLOR 1");
                }
                else
                {
                   system("COLOR 4");
                   printf("\a\t\t\t\t\t Incomplete Id Number!\n");
                   sleep(3);
                   system("COLOR 1");
                }
                 printf("\t\t   7. Id Number                                    : ");
                 scanf(" %[^\n]",idNumber);
            }}while(checkError!=0 || checkIncomplete!=0);
}

void telephoneNumberValidation(char number[])
{
        int i=0;
        int length=0;
        int checkError=0;
        int checkIncomplete=0;
        int convertchar=0;
        do {
        checkError =0;
        checkIncomplete=0;
        length= strlen(number);
        if(length == 10)
        { for(i=0;i<10;i++)
                { convertchar=0;
                  convertchar = (int)number[i];
                  if (convertchar<48 || convertchar>57)
                  {checkError++;}}
                if( number[0]!= '0'|| number[1]=='0')
                 {  checkError++;}}
          else
            {    if(length>9)
             {checkError++;}
             else
             {checkIncomplete++;}}
            if(checkError!=0 || checkIncomplete!=0)
            {
                if(checkError!=0)
                {system("COLOR 4");
                    printf("\a\t\t\t\t\t Invalid Phone Number Format!\n");
                    sleep(3);
                    system("COLOR 1");
                }
                else
                {  system("COLOR 4");
                   printf("\a\t\t\t\t\t Incomplete Phone Number!\n");
                   sleep(3);
                   system("COLOR 1");
                }
                 printf("\t\t   8. Phone Number                                 : ");
                 scanf(" %[^\n]",number);
            }}while(checkError!=0 || checkIncomplete!=0);
}

          //email Validation

void emailValidation(char email[])
{
    int i=0;
    int check=0;
        int length=0;
        int checkError=0;
        int convertchar=0;
        do{
            checkError=0;
            length= strlen(email);
            convertchar= (int)email[0];

             if(convertchar<48 || (convertchar>57 && convertchar<65) || (convertchar>90 && convertchar<97)|| convertchar>122 )
            {checkError++;}
             convertchar= (int)email[length-1];
             if(convertchar<48 || (convertchar>57 && convertchar<65) || (convertchar>90 && convertchar<97)|| convertchar>122 )
           {checkError++;}
             for (i=0;i<length;i++)
              { convertchar=0;
                convertchar=(int)email[i];

             if(convertchar<33 || convertchar>126)
             {checkError++;}
               if((convertchar>32 && convertchar<48)|| (convertchar>57 && convertchar<65) || (convertchar>90 && convertchar<97)||(convertchar>122 && convertchar<127))
               {
                if( check == convertchar)
                 {  checkError++;}
                 check= convertchar;}}
                if(checkError!=0)
                {
                   system("COLOR 4");
                   printf("\a\t\t\t\t\t Invalid Email!\n");
                   sleep(3);
                   system("COLOR 1");
                   printf("\t\t   9. Email                                        : ");
                   scanf(" %[^\n]",email);
                }

}while(checkError!=0);
}

        //Amount Validation
 double amountValidation(char money[], int moneyLimit ,int suggest,int number)
{
    int i=0;
    int position=0;
    int position1=0;
    int length=0;
    int  checkFloat=0;
    int checkError=0;
    int convertchar=0;
    double icount=0.0;
    int limit=0;
       do {
           checkError =0;
           checkFloat=0;
           limit=0;
           icount=0.0;
           length= strlen(money);
           position=0;
           position1=0;
           for(i=0;i<length;i++)
                { convertchar=0;
                  convertchar = (int)money[i];
                 if (convertchar == 46)
                  {checkFloat++;
                  position = i;
                  position1 = i+1;
                  }
                if((convertchar<48 || convertchar>57) && convertchar!=46 )
                    {checkError++;}}
                                              printf("int before%lf\n",icount);

                 if(checkFloat<2 && checkError ==0 )
                 { if(checkFloat==0)
                   {
                     for(i=0;i<length;i++)
                    {   convertchar=0;
                    convertchar= (int)money[i];
                       icount += numbersGet(&convertchar, &length, &i);}
                     printf("int after %lf\n",icount);}


                   else
                   { printf("float before %lf\n",icount);
                      for(i=0;i<length;i++)
                        { convertchar=0;
                         convertchar = (int)money[i];
                           if(i<=position)
                       { icount += numbersGet(&convertchar,&position, &i);}
                       else
                       { icount += numbersGet(&convertchar, &position1 ,&i);}}
                      printf("float after %lf\n",icount);  }}

                if(checkFloat>1)
                {checkError++;}
                if(suggest==1)
                {  if(icount<moneyLimit)
                  {limit++;}
                  if(checkError!=0 || limit!=0)
                   { system("COLOR 4");
                       if(checkError!=0)
                       {printf("\a\t\t\t\t\t Invalid amount!\n");}
                      else
                       {printf("\a\t\t\t\t\t Less amount!\n");}
                       sleep(3);
                       system("COLOR 1");
                       if(number==1)
                       {printf("\n\t\t  10. Enter the amount of deposit  (Rs.)           : ");  }
                       else
                       {printf("\t\t   2. Enter the Amount of Withdraw                 : ");}
                        scanf(" %[^\n]",money);}}

                if(suggest==2)
                {
                       if(icount>moneyLimit)
                  {
                      checkError++;
                  }
                  if(checkError!=0)
                  {
                      system("COLOR 4");
                      printf("\a\t\t\t\t\t Invalid  Annual Interest!\n");
                       sleep(3);
                   system("COLOR 1");
                  printf("\n\t\t   12. Enter annual interest                        : ");
                  scanf(" %[^\n]",money);
                  }
                }
                   }while( checkFloat>1 || checkError !=0 || limit!=0);
  printf("final %lf\n",icount);
      return icount;
}

   //Address Validation
   void addressValidation(char address[])
   {
        int i=0;
        int length=0;
        int checkError=0;
        int convertchar=0;
        int checkCapital=0;
        int checkSpace=0;
        double icount=0.0;
        do{
            checkError=0;
            checkCapital=0;
            checkSpace=0;
            icount=0;
            length= strlen(address);
            for(i=0;i<length;i++)
            {
                convertchar=0;
                convertchar=(int)address[i];
                if((convertchar>33 && convertchar<97))
                {}
                else
                { if(convertchar>96 && convertchar<123)
                    {checkCapital++;}
                    else if(convertchar==32)
                    {checkSpace++;}
                     else
                     {checkError++;}}}
            if(checkError!=0 || checkCapital!=0 || checkSpace !=0)
            {  system("COLOR 4");
                if(checkError!=0)
                 {printf("\a\t\t\t\t\t Invalid Address Format!\n");}
                  else if(checkCapital!=0)
                  {printf("\a\t\t\t\t\t Type CAPITAL Letters only !\n");}
                  else
                  {printf("\a\t\t\t\t\t Don't Leave Spaces!\n");}
                   sleep(3);
                   system("COLOR 1");
                   printf("\t\t   6. Address                                      : ");
                   scanf(" %[^\n]",address);
            }

        }while(checkError!=0 || checkCapital!=0 || checkSpace!=0);
   }

   //password Validate
   void passwordValidation(char password[])
   {int checkError=0;
       int length =0;
     do  {checkError=0;
            length=strlen(password);
       if(length<8)
       { checkError++;
          system("COLOR 4");
          printf("\a\t\tAtleast 8 Characters needed!\n");
          sleep(3);
          system("COLOR 1");
       printf("  2. Password                                     : ");
      scanf(" %[^\n]",password);
       }}while(checkError!=0);
   }

  //Months Validation
  int monthsValidation(char months[] )
{
    int checkError=0;
    int i=0;
    int convertchar =0;
    double icount=0;
    int length= 0;
  do{
        checkError=0;
        icount=0;
        length = strlen(months);
        for(i=0;i<length;i++)
       {   convertchar=0;
           convertchar = (int)months[i];
        if (convertchar<48 || convertchar>57)
            {checkError++;}
              else {
                  icount+=  numbersGet( &convertchar,  &length ,&i);
              }}
             if(icount==0)
                  {
                      checkError++;
                  }
             if(checkError!=0 )
                {   system("COLOR 4");
                    printf("\a\t\t\t\t\t Invalid Months Format!\n");
                    sleep(3);
                     system("COLOR 1");
                     printf("\t\t 11. Number of months for deposit                 : ");
                     scanf(" %[^\n]",months);
               }}while(checkError!=0 );
             return icount;
}

  int okcancelSelection()
  {
     char choice[2];
     int value=0;
    printf("\n\n\t\t\t------------------------------------------------------\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t| (1) Ok                                             |\n");
    printf("\t\t\t| (2) Cancel                                         |\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t------------------------------------------------------\n");
    printf("\t\t\t      Enter your choice : ");
    scanf(" %[^\n]",choice);
    value =selectChoice(choice);
    return value;
  }

double numbersGet(int *convertchar, int *length, int *i)
  { double icount =0;
        switch(*convertchar)
                  {
                  case 46:
                    icount+= 0;
                    break;
                  case 48 :
                      icount += pow(10,(*length-1-*i))*0;
                      break;
                  case 49:
                       icount += pow(10,(*length-1-*i))*1;
                      break ;
                  case 50:
                       icount += pow(10,(*length-1-*i))*2;
                      break;
                  case 51:
                      icount += pow(10,(*length-1-*i))*3;
                      break;
                  case 52:
                      icount += pow(10,(*length-1-*i))*4;
                      break;
                  case 53:
                      icount += pow(10,(*length-1-*i))*5;
                      break;
                  case 54:
                      icount += pow(10,(*length-1-*i))*6;
                      break;
                  case 55:
                       icount += pow(10,(*length-1-*i))*7;
                      break;
                  case 56:
                       icount += pow(10,(*length-1-*i))*8;
                      break;
                  default:
                      icount += pow(10,(*length-1-*i))*9;
}return icount;}

