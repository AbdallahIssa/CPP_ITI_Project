#include <iostream>
#include <string>
using namespace std;

enum class cTransactionStatus{
    M_SUCCESS_OPERATION = 1,
    M_FAIL_NOT_SUFFICIENT_MONEY,
    M_FAIL_NOT_AN_ACTIVE_USER
};

enum class cAccountStatus
{
    ACTIVE = 1,
    RESTRICTED,
    CLOSED
};



class cAccountInfo
{
private:
    string m_fullName;
    string m_fullAddress;
    int m_age;
    double m_national_ID;
    double m_BankAccount_ID;
    int m_guardian;
    double m_guardianNational_ID;
    double m_balance;
    int m_accountStatus;
    int m_password;//Auto generated
public:
    /*cAccountInfo();:m_fullName(""), m_fullAddress(""), m_age(0), m_national_ID(0), m_BankAccount_ID(0),
    m_guardian(0), m_guardianNational_ID(0), m_balance(0), m_accountStatus.setStatus("ACTIVE"),
    m_password(){}*/
    string getFullName();
    void setFullName(string fullName);
    string getFullAddress();
    void setFullAddress(string fullAddress);
    int getAge();
    void setAge(int age);
    double getNational_ID();
    void setNational_ID(double national_ID);
    double getBankAccount_ID();
    void setBankAccount_ID(double bankAccount_ID);
    int getGuardian();
    void setGuardian(int guardian);
    double getGuardianNational_ID();
    void setGuardianNational_ID(double guardianNational_ID);
    double getBalance();
    void setBalance(double balance);
    int getAccountStatus();
    void setAccountStatus(int accountStatus);
    int getPassword();
    void setPassword(int password);

};



class cSystem
{
public:
    void initTheSystem();
    void startTheSystem();
    void exitTheSystem();
};

class cAdmin
{
private:
    string m_username;
    int m_password;
public:

    //Admin functions
    void adminMode();   
    void createNewAccount();
    void openExistingAccount();
    int doesBankAccountIDExist(double bankAccountID);
    int Admin_MakeTransaction(double senderID, double receiverID, double money);
    void Admin_changeAccountStatus(double userID, int bankAccountStatus);
    int Admin_getCash(double userID, double cash);
    void Admin_depositInAccount(double userID,double depositCash);
    void Admin_returnToMainMenu();
};

class cClient
{
public:
    //Client functions
    void clientMode(void);
    int Client_MakeTransaction(double senderID, double receiverID, double money);
    void Client_changeAccountPassword(double userID, int newPassword);
    int Client_getCash(double userID, double cash);
    void Client_depositInAccount(double userID,double depositCash);
    void Client_returnToMainMenu(void);
};

class cAuxiliaryFunctions
{
public:
    int random_(int minVal, int maxVal);
    void delay(int milli_seconds);
    int doubleCompare(double num1, double num2);
    void TestPrintResults(void);
};



