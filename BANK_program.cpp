#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include "BANK_interface.h"
#include "BANK_private.h"
#include "BANK_config.h"

using namespace std;

#define CLEAR_SCREEN()    system("cls")


/************************************************************************************/
/******************            Global object variables             ******************/
/************************************************************************************/


cAccountInfo accInfo[NUMBER_OF_CUSTOMERS];
cAuxiliaryFunctions auxFun;
cSystem sys;
cAdmin admin;
cClient client;






/************************************************************************************/
/******************                  System                        ******************/
/************************************************************************************/

void cSystem::initTheSystem()
{
    //To Initiate the BankAccount_ID for all customers with -1
    //to Avoid that doesBankAccountIDExist relys on default value 0
    for(int index = 0;index<NUMBER_OF_CUSTOMERS; index++)
    {
        
        accInfo[index].setBankAccount_ID(-1);
    }

    for(int i=0; i<3; i++)
    {
        cout << "                          *********************************************************************                          "<<endl;
        cout << "                          *                     Welcome to IMT Bank system                    *                          "<<endl;
        cout << "                          *********************************************************************                          "<<endl;
        auxFun.delay(500);
        CLEAR_SCREEN();
        auxFun.delay(500);
    }
}


void cSystem::startTheSystem()
{
    int sysChoice, choice;
    char adminUsername[50] = {0};

    cout << "Choose from these options:\n\n\
           1-for Administrator mode.\n\
           2-for Client mode.\n\n";
    cout << "Enter your choice: ";
    cin >> sysChoice;
    switch(sysChoice)
    {
    case 1:
    {
        CLEAR_SCREEN();
        cout << "Enter username please: ";
        cin >> adminUsername;
        CLEAR_SCREEN();
        cout << "Enter password please: ";

        //To make Password Invisible and predetermined with (ADMIN_PASSWORD_LENGTH) digits
        char adminPassword[5] = {0};
        for (int index=0; index<ADMIN_PASSWORD_LENGTH; index++) {
            adminPassword[index] = getch();
            cout << "*";
        }
        adminPassword[4] = '\0';
        if((!strcmp(adminUsername, ADMIN_USERNAME)) && (!strcmp(adminPassword, ADMIN_PASSWORD)))
        {
            CLEAR_SCREEN();
            admin.adminMode();
        }
        else
        {
            CLEAR_SCREEN();
            cout << "You Enter invalid username or password, please try again...\n\n";
            cout << "Do you want to continue?\n1-for Yes.\n2-for No.\n\nEnter your choice: ";
            cin >> choice;
            switch(choice)
            {
            case 1:
                CLEAR_SCREEN();
                sys.startTheSystem();
                break;
            case 2: default:
                CLEAR_SCREEN();
                sys.exitTheSystem();
                break;
            }
        }
        break;
    }
    case 2:
    {
        CLEAR_SCREEN();
        client.clientMode();
        break;
    }
    default:
    {
        CLEAR_SCREEN();
        cout << "You entered invalid option\n\n";
        cout << "Do you want to continue?\n1-for Yes.\n2-for No.\n\nEnter your choice: ";
        cin >> choice;
        switch(choice)
        {
        case 1:
            CLEAR_SCREEN();
            sys.startTheSystem();
            break;
        case 2: default:
            CLEAR_SCREEN();
            sys.exitTheSystem();
            break;
        }
        break;
    }
    }
}


/************************************************************************************/
/******************                  Admin                         ******************/
/************************************************************************************/



// cAdmin::cAdmin(string username, int password)
// {
//     this->m_username = username;
//     this->m_password = password;
// }

//Admin functions
void cAdmin::adminMode()
{
    int choice1, choice2;

    cout << "Choose from these options:\n\n\
           1-Create New Account.\n\
           2-Open Existing Account.\n\
           3-Exit the sys.\n\
           4-TestPrintResults.\n\n";
    cout << "Enter your choice: ";
    cin >> choice1;

    switch(choice1)
    {
    case 1:
        CLEAR_SCREEN();
        admin.createNewAccount();
        break;
    case 2:
        CLEAR_SCREEN();
        admin.openExistingAccount();
        break;
    case 3:
        CLEAR_SCREEN();
        sys.exitTheSystem();
        break;
    case 4:
        CLEAR_SCREEN();
        auxFun.TestPrintResults();
        break;
    default:
        CLEAR_SCREEN();
        cout << "You entered invalid option\n\n";
        cout << "Do you want to continue?\n1-for Yes.\n2-for No.\n\nEnter your choice: ";
        cin >> choice2;
        switch(choice2)
        {
        case 1:
            CLEAR_SCREEN();
            admin.Admin_returnToMainMenu();
            break;
        case 2: default:
            CLEAR_SCREEN();
            sys.exitTheSystem();
            break;
        }
        break;
    }
}





void cAdmin::createNewAccount()
{
    //cout << "Hi from create";
    string sInput;
    int iInput;
    double dInput;

    static int i = 0;
    cout << "Enter the full name please:  ";
    cin >> sInput;
    accInfo[i].setFullName(sInput);
    cout << "Enter the full address please:  ";
    cin >> sInput;
    accInfo[i].setFullAddress(sInput);
    cout << "Enter the national ID please:  ";
    cin >> dInput;
    accInfo[i].setNational_ID(dInput);
    cout << "Enter the age please:  ";
    cin >> iInput;
    accInfo[i].setAge(iInput);
    if(accInfo[i].getAge() < ALLOWED_AGE)
    {
        accInfo[i].setGuardian(1);
        cout << "Enter the guardian national ID please:  ";
        cin >> sInput;
        accInfo[i].setGuardianNational_ID(dInput);
    }
    else
    {
        accInfo[i].setGuardian(0);
    }
    cout << "Enter the balance please:  ";
    cin >> dInput;
    accInfo[i].setBalance(dInput);

    accInfo[i].setAccountStatus((int)cAccountStatus::ACTIVE);
    accInfo[i].setPassword(auxFun.random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    accInfo[i].setBankAccount_ID(i);

    i++;

    CLEAR_SCREEN();
    for(int index=0; index<3; index++)
    {
        cout << "             Registration process is Done Successfully!             ";
        auxFun.delay(500);
        CLEAR_SCREEN();
        auxFun.delay(300);
    }
    Admin_returnToMainMenu();
    
}


void cAdmin::openExistingAccount()
{
    double bankAccountID, Getcash, depositCash;
    int ID_exists1, ID_exists2, choice, bankAccountStatus, cashAvilablity;
    cout << "Enter client bank account ID please: ";
    cin >> bankAccountID;
    ID_exists1 = admin.doesBankAccountIDExist(bankAccountID);
    if(ID_exists1)
    {
        CLEAR_SCREEN();
        cout << "Choose from these options:\n\n\
               1- Make Transaction.\n\
               2- Change Account Status.\n\
               3- Get Cash.\n\
               4- Deposit in Account.\n\
               5- Return to main menu.\n\n";

        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
        case 1:
        {
            CLEAR_SCREEN();
            double receiverID, money;
            cout << "please Enter amount of money: ";
            cin >> money;

            cout << "please Enter the Bank Account ID you want to transfer the money to: ";
            cin >> receiverID;
            ID_exists2 = admin.doesBankAccountIDExist(receiverID);

            if(ID_exists2)
            {
                int tranactionResult = admin.Admin_MakeTransaction(bankAccountID, receiverID, money);
                if(tranactionResult == (int)cTransactionStatus::M_SUCCESS_OPERATION)
                {
                    CLEAR_SCREEN();
                    for(int index=0; index<3; index++)
                    {
                        cout << "             Transaction process is Done Successfully!             ";
                        auxFun.delay(500);
                        CLEAR_SCREEN();
                        auxFun.delay(500);
                    }
                    admin.Admin_returnToMainMenu();
                }
                else if(tranactionResult == (int)cTransactionStatus::M_FAIL_NOT_SUFFICIENT_MONEY)
                {
                    CLEAR_SCREEN();
                    cout << "Operation failed because there is no sufficient money!";
                    auxFun.delay(3000);
                    CLEAR_SCREEN();
                    admin.Admin_returnToMainMenu();
                }
                else
                {
                    CLEAR_SCREEN();
                    cout << "Operation failed because the user isn't an active user!";
                    auxFun.delay(3000);
                    CLEAR_SCREEN();
                    admin.Admin_returnToMainMenu();
                }
            }
            else
            {
                cout << "This ID doesn't exist";
                auxFun.delay(3000);
                CLEAR_SCREEN();
                admin.Admin_returnToMainMenu();
            }
            break;
        }

        case 2:
        {
            CLEAR_SCREEN();
            cout << "Choose from these options to enter the bank account status:\n\n\
            1- Set Account to Active State.\n\
            2- Set Account to Restricted State.\n\
            3- Set Account to Closed. \n\n";

            cout << "Enter your choice: ";
            cin >> bankAccountStatus;
            admin.Admin_changeAccountStatus(bankAccountID, bankAccountStatus);
            CLEAR_SCREEN();
            for(int index=0; index<3; index++)
            {
                cout << "             Changing the account status is Done Successfully!             ";
                auxFun.delay(500);
                CLEAR_SCREEN();
                auxFun.delay(300);
            }
            admin.Admin_returnToMainMenu();
            break;
        }

        case 3:
        {
            CLEAR_SCREEN();
            cout << "Please enter the cash amount you want from this account : ";
            cin >> Getcash;
            cashAvilablity = Admin_getCash(bankAccountID, Getcash);
            if(cashAvilablity)
            {
                CLEAR_SCREEN();
                for(int index=0; index<3; index++)
                {
                    cout << "             Getting the cash is Done Successfully!             ";
                    auxFun.delay(500);
                    CLEAR_SCREEN();
                    auxFun.delay(300);
                }
                admin.Admin_returnToMainMenu();
            }
            else
            {
                CLEAR_SCREEN();
                cout << "Operation failed because there is no sufficient money!";
                auxFun.delay(3000);
                CLEAR_SCREEN();
                admin.Admin_returnToMainMenu();
            }
            break;
        }

        case 4:
        {
            CLEAR_SCREEN();
            cout << "Please enter the cash amount you want to deposit to this account : ";
            cin >> depositCash;
            admin.Admin_depositInAccount(bankAccountID, depositCash);
            CLEAR_SCREEN();
            for(int index=0; index<3; index++)
            {
                cout << "             deposit In Account is Done Successfully!             ";
                auxFun.delay(500);
                CLEAR_SCREEN();
                auxFun.delay(300);
            }
            admin.Admin_returnToMainMenu();
            break;
        }

        case 5:
        {
            CLEAR_SCREEN();
            admin.Admin_returnToMainMenu();
            break;
        }
        default:
        {
            CLEAR_SCREEN();
            cout << "You entered invalid option\n\n";
            auxFun.delay(3000);
            CLEAR_SCREEN();
            admin.Admin_returnToMainMenu();
            break;
        }
        }
    }
    else
    {
        CLEAR_SCREEN();
        cout << "This ID doesn't exist";
        auxFun.delay(3000);
        CLEAR_SCREEN();
        admin.Admin_returnToMainMenu();
    }

}

int cAdmin::doesBankAccountIDExist(double bankAccountID)
{
    int exist = 0;
    for(int index=0; index<NUMBER_OF_CUSTOMERS; index++)
    {
        if(accInfo[index].getBankAccount_ID() == bankAccountID)
        {
            exist = 1;
            break;
        }
    }
    return exist;
}

int cAdmin::Admin_MakeTransaction(double senderID, double receiverID, double money)
{
    int transactionStatus;
    //make sure that the amount of money is less than the balance
    if(money < accInfo[(int)senderID].getBalance())
    {
        if((accInfo[(int)receiverID].getAccountStatus() == (int)cAccountStatus::ACTIVE) &&
            (accInfo[(int)senderID].getAccountStatus() == (int)cAccountStatus::ACTIVE))
        {
            accInfo[(int)senderID].setBalance(accInfo[(int)senderID].getBalance() - money);
            accInfo[(int)receiverID].setBalance(accInfo[(int)receiverID].getBalance() + money);
            transactionStatus = (int)cTransactionStatus::M_SUCCESS_OPERATION;
        }
        else
        {
            transactionStatus = (int)cTransactionStatus::M_FAIL_NOT_AN_ACTIVE_USER;
        }
    }
    else
    {
        transactionStatus = (int)cTransactionStatus::M_FAIL_NOT_SUFFICIENT_MONEY;
    }
    return transactionStatus;
}

void cAdmin::Admin_changeAccountStatus(double userID, int bankAccountStatus)
{
    int choice;
    switch(bankAccountStatus)
    {
    case 1:
        accInfo[(int)userID].setAccountStatus((int)cAccountStatus::ACTIVE);
        break;
    case 2:
        accInfo[(int)userID].setAccountStatus((int)cAccountStatus::RESTRICTED);
        break;
    case 3:
        accInfo[(int)userID].setAccountStatus((int)cAccountStatus::CLOSED);
        break;
    default:
        cout << "You entered invalid account status\n";
        cout << "Do you want to continue?\n1-for Yes\n2-for No\n\nEnter your choice: ";
        cin >> choice;
        switch(choice)
        {
        case 1:
            CLEAR_SCREEN();
            Admin_changeAccountStatus(userID, bankAccountStatus);
            break;
        case 2: default:
            CLEAR_SCREEN();
            Admin_returnToMainMenu();
            break;
        }
        break;
    }
}

int cAdmin::Admin_getCash(double userID, double cash)
{
    int cashAvilablity;
    if(accInfo[(int)userID].getBalance() > cash)
    {
        accInfo[(int)userID].setBalance(accInfo[(int)userID].getBalance() - cash);
        cashAvilablity = 1;
    }
    else
    {
        cashAvilablity = 0;
    }

    return cashAvilablity;
}

void cAdmin::Admin_depositInAccount(double userID,double depositCash)
{
    accInfo[(int)userID].setBalance(accInfo[(int)userID].getBalance() + depositCash);
}

void cAdmin::Admin_returnToMainMenu()
{
    admin.adminMode();
}
void cSystem::exitTheSystem()
{
    CLEAR_SCREEN();
    cout << "Thanks                                    \n";
    auxFun.delay(500);
    cout << "             For                          \n";
    auxFun.delay(500);
    cout << "                        Using             \n";
    auxFun.delay(500);
    cout << "                                       Our\n";
    auxFun.delay(500);
    cout << "                        IMT               \n";
    auxFun.delay(500);
    cout << "             Bank                         \n";
    auxFun.delay(500);
    cout << "system                                    \n";
    auxFun.delay(500);
    CLEAR_SCREEN();
    exit(0);
}





void cAuxiliaryFunctions::TestPrintResults(void)
{
   for(int index =0; index<NUMBER_OF_CUSTOMERS; index++)
   {
        cout << "Age             =     " << accInfo[index].getAge() << endl;
        cout << "BankAccount_ID  =     " << accInfo[index].getBankAccount_ID() << endl;
        cout << "accountStatus   =     " << accInfo[index].getAccountStatus() << endl;
        cout << "fullName        =     " << accInfo[index].getFullName() << endl;
        cout << "fullAddress     =     " << accInfo[index].getFullAddress() << endl;
        cout << "Balance         =     " << accInfo[index].getBalance() << endl;
        cout << "guardian        =     " << accInfo[index].getGuardian() << endl;
        cout << "Gnational_ID    =     " << accInfo[index].getGuardianNational_ID() << endl;
        cout << "national_ID     =     " << accInfo[index].getNational_ID() << endl;
        cout << "password        =     " << accInfo[index].getPassword() << endl;
        cout << "***************************************************" << endl;
        cout << "***************************************************" << endl;
   }

   

    int choice;
    cout << "\n\nDo you want to continue?\n1-for Yes\n2-for No\n\nEnter your choice: ";
    cin >> choice;
    switch(choice)
    {
    case 1:
        CLEAR_SCREEN();
        sys.startTheSystem();
        break;
    case 2: default:
        CLEAR_SCREEN();
        sys.exitTheSystem();
        break;
    }

}

/************************************************************************************/
/******************                  Client                        ******************/
/************************************************************************************/


void cClient::clientMode()
{
    double bankAccountID, Getcash, depositCash, receiverID, money;
    int Password, oldPass, newPass;
    int ID_exists1, passwordCorrect, ID_exists2, choice, bankAccountStatus, cashAvilablity, c;

    cout << "Welcome in client mode\n\n\
           Choose from these options:\n\
           1-Enter Client Mode.\n\
           2-Back To Main Menu.\n\n";
    cout << "Enter your choice: ";
    cin >> c;
    switch(c)
    {
    case 1:
        CLEAR_SCREEN();
        cout << "Enter client bank account ID please: ";
        cin >> bankAccountID;
        ID_exists1 = admin.doesBankAccountIDExist(bankAccountID);

        if(ID_exists1)
        {
            cout << "Enter your Password please: ";
            cin >> Password;

            passwordCorrect = ((Password == accInfo[(int)bankAccountID].getPassword())?1:0);
            if(passwordCorrect)
            {
                CLEAR_SCREEN();
                cout << "Choose from these options:\n\n\
                       1- Make Transaction.\n\
                       2- Change Account Password.\n\
                       3- Get Cash.\n\
                       4- Deposit in Account.\n\
                       5- Return to main menu.\n\n";

                cout << "Enter your choice: ";
                cin >> choice;
                switch(choice)
                {
                case 1:
                    CLEAR_SCREEN();
                    cout << "please Enter amount of money: ";
                    cin >> money;
                    cout << "please Enter the Bank Account ID you want to transfer the money to: ";
                    cin >> receiverID;
                    ID_exists2 = admin.doesBankAccountIDExist(receiverID);

                    if(ID_exists2)
                    {
                        int tranactionResult = client.Client_MakeTransaction(bankAccountID, receiverID, money);
                        if(tranactionResult == (int)cTransactionStatus::M_SUCCESS_OPERATION)
                        {
                            CLEAR_SCREEN();
                            for(int index=0; index<3; index++)
                            {
                                cout << "             Transaction process is Done Successfully!             ";
                                auxFun.delay(500);
                                CLEAR_SCREEN();
                                auxFun.delay(300);
                            }
                            client.Client_returnToMainMenu();
                        }
                        else if(tranactionResult == (int)cTransactionStatus::M_FAIL_NOT_SUFFICIENT_MONEY)
                        {
                            CLEAR_SCREEN();
                            cout << "Operation failed because there is no sufficient money!";
                            auxFun.delay(3000);
                            CLEAR_SCREEN();
                            client.Client_returnToMainMenu();
                        }
                        else
                        {
                            CLEAR_SCREEN();
                            cout << "Operation failed because the user isn't an active user!";
                            auxFun.delay(3000);
                            CLEAR_SCREEN();
                            client.Client_returnToMainMenu();
                        }
                    }
                    else
                    {
                        cout << "This ID doesn't exist";
                        auxFun.delay(3000);
                        CLEAR_SCREEN();
                        client.Client_returnToMainMenu();
                    }
                    break;



                case 2:
                    CLEAR_SCREEN();
                    cout << "Enter the old Password first: ";
                    cin >> oldPass;
                    if(accInfo[(int)bankAccountID].getPassword() == oldPass)
                    {
                        cout << "Now, enter the new Password: ";
                        cin >> newPass;
                        client.Client_changeAccountPassword(bankAccountID, newPass);
                        CLEAR_SCREEN();
                        for(int index=0; index<3; index++)
                        {
                            cout << "             Changing the Password is Done Successfully!             ";
                            auxFun.delay(500);
                            CLEAR_SCREEN();
                            auxFun.delay(300);
                        }
                        client.Client_returnToMainMenu();
                    }
                    else
                    {
                        CLEAR_SCREEN();
                        cout << "You entered the old password\n\n";
                        auxFun.delay(3000);
                        CLEAR_SCREEN();
                       client.Client_returnToMainMenu();
                    }

                    break;


                case 3:
                    CLEAR_SCREEN();
                    cout << "Please enter the cash amount you want from this account : ";
                    cin >> Getcash;
                    cashAvilablity = client.Client_getCash(bankAccountID, Getcash);
                    if(cashAvilablity)
                    {
                        CLEAR_SCREEN();
                        for(int index=0; index<3; index++)
                        {
                            cout << "             Getting the cash is Done Successfully!             ";
                            auxFun.delay(500);
                            CLEAR_SCREEN();
                            auxFun.delay(300);
                        }
                        client.Client_returnToMainMenu();
                    }
                    else
                    {
                        CLEAR_SCREEN();
                        cout << "Operation failed because there is no sufficient money!";
                        auxFun.delay(3000);
                        CLEAR_SCREEN();
                        client.Client_returnToMainMenu();
                    }

                    break;


                case 4:
                    CLEAR_SCREEN();
                    cout << "Please enter the cash amount you want to deposit to this account : ";
                    cin >> depositCash;
                    client.Client_depositInAccount(bankAccountID, depositCash);
                    CLEAR_SCREEN();
                    for(int index=0; index<3; index++)
                    {
                        cout << "             deposit In Account is Done Successfully!             ";
                        auxFun.delay(500);
                        CLEAR_SCREEN();
                        auxFun.delay(300);
                    }
                    client.Client_returnToMainMenu();
                    break;
                case 5:
                    CLEAR_SCREEN();
                    client.Client_returnToMainMenu();
                    break;
                default:
                    CLEAR_SCREEN();
                    cout << "You entered invalid option\n\n";
                    auxFun.delay(3000);
                    CLEAR_SCREEN();
                    client.Client_returnToMainMenu();
                    break;
                }
            }
            else
            {
                CLEAR_SCREEN();
                cout << "You entered invalid password\n\n";
                auxFun.delay(3000);
                CLEAR_SCREEN();
                client.Client_returnToMainMenu();
            }

        }
        else
        {
            CLEAR_SCREEN();
            cout << "This ID doesn't exist";
            auxFun.delay(3000);
            CLEAR_SCREEN();
            client.Client_returnToMainMenu();
        }
        break;
    case 2:
        CLEAR_SCREEN();
        sys.startTheSystem();
        break;
    default:
        CLEAR_SCREEN();
        cout << "You entered invalid option\n\n";
        auxFun.delay(3000);
        CLEAR_SCREEN();
        sys.startTheSystem();
        break;
    }
}


int cClient::Client_MakeTransaction(double senderID, double receiverID, double money)
{
   int transactionStatus;
    //make sure that the amount of money is less than the balance
    if(money < accInfo[(int)senderID].getBalance())
    {
        if((accInfo[(int)receiverID].getAccountStatus() == (int)cAccountStatus::ACTIVE) &&
            (accInfo[(int)senderID].getAccountStatus() == (int)cAccountStatus::ACTIVE))
        {
            accInfo[(int)senderID].setBalance(accInfo[(int)senderID].getBalance() - money);
            accInfo[(int)receiverID].setBalance(accInfo[(int)receiverID].getBalance() + money);
            transactionStatus = (int)cTransactionStatus::M_SUCCESS_OPERATION;
        }
        else
        {
            transactionStatus = (int)cTransactionStatus::M_FAIL_NOT_AN_ACTIVE_USER;
        }
    }
    else
    {
        transactionStatus = (int)cTransactionStatus::M_FAIL_NOT_SUFFICIENT_MONEY;
    }
    return transactionStatus;
}

void cClient::Client_changeAccountPassword(double userID, int newPassword)
{
    accInfo[(int)userID].setPassword(newPassword);
}

int cClient::Client_getCash(double userID, double cash)
{
    int cashAvilablity;
    if(accInfo[(int)userID].getBalance() > cash)
    {
        accInfo[(int)userID].setBalance(accInfo[(int)userID].getBalance() - cash);
        cashAvilablity = 1;
    }
    else
    {
        cashAvilablity = 0;
    }

    return cashAvilablity;
}

void cClient::Client_depositInAccount(double userID,double depositCash)
{
    accInfo[(int)userID].setBalance(accInfo[(int)userID].getBalance() + depositCash);
}

void cClient::Client_returnToMainMenu(void)
{
    cClient::clientMode();
}




/************************************************************************************/
/******************                Auxiliary                       ******************/
/************************************************************************************/

int cAuxiliaryFunctions::random_(int minVal, int maxVal)
{
    int count = 0;
    int result = ((rand()%(( maxVal + 1 - minVal) + minVal)));
    int temp = result;
    while(temp!=0)
    {
       temp/=10;
       count++;
    }
    if(count>RANDOM_PASSWORD_LENGTH)
    {
        result = random_(minVal, maxVal);
    }
    return result;
}

void cAuxiliaryFunctions::delay(int milli_seconds)
{
    // Storing start time
    clock_t start_time = clock();
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}
int cAuxiliaryFunctions::doubleCompare(double num1, double num2)
{
    return (fabs(num1 - num2) < EPSILON);
}



string cAccountInfo::getFullName() {
    return m_fullName;
}

void cAccountInfo::setFullName(string fullName) {
    this->m_fullName = fullName;
}

string cAccountInfo::getFullAddress() {
    return m_fullAddress;
}

void cAccountInfo::setFullAddress(string fullAddress) {
    this->m_fullAddress = fullAddress;
}

int cAccountInfo::getAge() {
    return m_age;
}

void cAccountInfo::setAge(int age) {
    this->m_age = age;
}

double cAccountInfo::getNational_ID() {
    return m_national_ID;
}

void cAccountInfo::setNational_ID(double national_ID) {
    this->m_national_ID = national_ID;
}

double cAccountInfo::getBankAccount_ID() {
    return m_BankAccount_ID;
}

void cAccountInfo::setBankAccount_ID(double bankAccount_ID) {
    this->m_BankAccount_ID = bankAccount_ID;
}

int cAccountInfo::getGuardian() {
    return m_guardian;
}

void cAccountInfo::setGuardian(int guardian) {
    this->m_guardian = guardian;
}

double cAccountInfo::getGuardianNational_ID() {
    return m_guardianNational_ID;
}

void cAccountInfo::setGuardianNational_ID(double guardianNational_ID) {
    this->m_guardianNational_ID = guardianNational_ID;
}

double cAccountInfo::getBalance() {
    return m_balance;
}

void cAccountInfo::setBalance(double balance) {
    this->m_balance = balance;
}

int cAccountInfo::getAccountStatus()
{
    return m_accountStatus;
}

void cAccountInfo::setAccountStatus(int accountStatus)
{
    this->m_accountStatus = accountStatus;
}

int cAccountInfo::getPassword() {
    return m_password;
}

void cAccountInfo::setPassword(int password) {
    this->m_password = password;
}
