[33mcommit 8ec1ab8515cde374444be55aa3297a7e4f63e62e[m[33m ([m[1;36mHEAD -> [m[1;32mmain[m[33m)[m
Author: abdallah.issa <abdallah.issa@gmail.com>
Date:   Thu Sep 15 00:27:24 2022 +0200

    First commit

[1mdiff --git a/C++.cpp b/C++.cpp[m
[1mnew file mode 100644[m
[1mindex 0000000..b286401[m
[1m--- /dev/null[m
[1m+++ b/C++.cpp[m
[36m@@ -0,0 +1,103 @@[m
[32m+[m[32m#include <iostream>[m
[32m+[m[32m#include <string>[m
[32m+[m[32m#include "C++_interface.h"[m
[32m+[m
[32m+[m[32musing namespace std;[m
[32m+[m
[32m+[m
[32m+[m[32mcAccountStatus::cAccountStatus()[m
[32m+[m[32m{[m
[32m+[m[32m    setAccountStatus("ACTIVE");[m
[32m+[m[32m}[m
[32m+[m[32mvoid cAccountStatus::setAccountStatus(string status)[m
[32m+[m[32m{[m
[32m+[m[32m    this->m_status = status;[m
[32m+[m[32m}[m
[32m+[m[32mstring cAccountStatus::getAccountStatus()[m
[32m+[m[32m{[m
[32m+[m[32m    return m_status;[m
[32m+[m[32m}[m
[32m+[m
[32m+[m
[32m+[m
[32m+[m[32mstring cAccountInfo::getFullName() {[m
[32m+[m[32m    return m_fullName;[m
[32m+[m[32m}[m
[32m+[m
[32m+[m[32mvoid cAccountInfo::setFullName(string fullName) {[m
[32m+[m[32m    this->m_fullName = fullName;[m
[32m+[m[32m}[m
[32m+[m
[32m+[m[32mstring cAccountInfo::getFullAddress() {[m
[32m+[m[32m    return m_fullAddress;[m
[32m+[m[32m}[m
[32m+[m
[32m+[m[32mvoid cAccountInfo::setFullAddress(string fullAddress) {[m
[32m+[m[32m    this->m_fullAddress = fullAddress;[m
[32m+[m[32m}[m
[32m+[m
[32m+[m[32mint cAccountInfo::getAge() {[m
[32m+[m[32m    return m_age;[m
[32m+[m[32m}[m
[32m+[m
[32m+[m[32mvoid cAccountInfo::setAge(int age) {[m
[32m+[m[32m    this->m_age = age;[m
[32m+[m[32m}[m
[32m+[m
[32m+[m[32mdouble cAccountInfo::getNational_ID() {[m
[32m+[m[32m    return m_national_ID;[m
[32m+[m[32m}[m
[32m+[m
[32m+[m[32mvoid cAccountInfo::setNational_ID(double national_ID) {[m
[32m+[m[32m    this->m_national_ID = national_ID;[m
[32m+[m[32m}[m
[32m+[m
[32m+[m[32mdouble cAccountInfo::getBankAccount_ID() {[m
[32m+[m[32m    return m_BankAccount_ID;[m
[32m+[m[32m}[m
[32m+[m
[32m+[m[32mvoid cAccountInfo::setBankAccount_ID(double bankAccount_ID) {[m
[32m+[m[32m    this->m_BankAccount_ID = bankAccount_ID;[m
[32m+[m[32m}[m
[32m+[m
[32m+[m[32mint cAccountInfo::getGuardian() {[m
[32m+[m[32m    return m_guardian;[m
[32m+[m[32m}[m
[32m+[m
[32m+[m[32mvoid cAccountInfo::setGuardian(int guardian) {[m
[32m+[m[32m    this->m_guardian = guardian;[m
[32m+[m[32m}[m
[32m+[m
[32m+[m[32mdouble cAccountInfo::getGuardianNational_ID() {[m
[32m+[m[32m    return m_guardianNational_ID;[m
[32m+[m[32m}[m
[32m+[m
[32m+[m[32mvoid cAccountInfo::setGuardianNational_ID(double guardianNational_ID) {[m
[32m+[m[32m    this->m_guardianNational_ID = guardianNational_ID;[m
[32m+[m[32m}[m
[32m+[m
[32m+[m[32mdouble cAccountInfo::getBalance() {[m
[32m+[m[32m    return m_balance;[m
[32m+[m[32m}[m
[32m+[m
[32m+[m[32mvoid cAccountInfo::setBalance(double balance) {[m
[32m+[m[32m    this->m_balance = balance;[m
[32m+[m[32m}[m
[32m+[m
[32m+[m[32mstring cAccountInfo::getPassword() {[m
[32m+[m[32m    return m_password;[m
[32m+[m[32m}[m
[32m+[m
[32m+[m[32mvoid cAccountInfo::setPassword(string password) {[m
[32m+[m[32m    this->m_password = password;[m
[32m+[m[32m}[m
[32m+[m
[32m+[m
[32m+[m
[32m+[m[32mint main()[m
[32m+[m[32m{[m
[32m+[m[32m    cAccountStatus s;[m
[32m+[m[32m    s.setAccountStatus("ACTIVE");[m
[32m+[m[32m    cout<<s.getAccountStatus()<<endl;[m
[32m+[m[32m    return 0;[m
[32m+[m[32m}[m
\ No newline at end of file[m
[1mdiff --git a/C++.exe b/C++.exe[m
[1mnew file mode 100644[m
[1mindex 0000000..877f6fd[m
Binary files /dev/null and b/C++.exe differ
[1mdiff --git a/C++_interface.h b/C++_interface.h[m
[1mnew file mode 100644[m
[1mindex 0000000..623b2b2[m
[1m--- /dev/null[m
[1m+++ b/C++_interface.h[m
[36m@@ -0,0 +1,95 @@[m
[32m+[m[32m#include <iostream>[m
[32m+[m[32m#include <string>[m
[32m+[m[32musing namespace std;[m
[32m+[m
[32m+[m[32mclass cAuxiliaryFunctions[m
[32m+[m[32m{[m
[32m+[m[32mpublic:[m
[32m+[m[32m    int random_(int minVal, int maxVal);[m
[32m+[m[32m    void delay(int milli_seconds);[m
[32m+[m[32m    int doubleCompare(double num1, double num2);[m
[32m+[m[32m    void TestPrintResults(void);[m
[32m+[m[32m};[m
[32m+[m
[32m+[m[32mclass cTransactionStatus[m
[32m+[m[32m{[m
[32m+[m[32m private:[m
[32m+[m[32m    /*[m
[32m+[m[32m    "M_SUCCESS_OPERATION";[m
[32m+[m[32m    "M_FAIL_NOT_SUFFICIENT_MONEY"[m
[32m+[m[32m    "M_FAIL_NOT_AN_ACTIVE_USER"[m
[32m+[m[32m    */[m
[32m+[m[32m    string m_status;[m
[32m+[m[32m public:[m
[32m+[m[32m    void setTransactionStatus(string status);[m
[32m+[m[32m    string getTransactionStatus();[m
[32m+[m[32m};[m
[32m+[m
[32m+[m[32mclass cAccountStatus[m
[32m+[m[32m{[m
[32m+[m[32mprivate:[m
[32m+[m[32m    string m_status;[m
[32m+[m[32mpublic:[m
[32m+[m[32m    cAccountStatus();[m
[32m+[m[32m    void setAccountStatus(string status);[m
[32m+[m[32m    string getAccountStatus();[m
[32m+[m[32m};[m
[32m+[m
[32m+[m
[32m+[m
[32m+[m[32mclass cAccountInfo[m
[32m+[m[32m{[m
[32m+[m[32mprivate:[m
[32m+[m[32m    string m_fullName;[m
[32m+[m[32m    string m_fullAddress;[m
[32m+[m[32m    int m_age;[m
[32m+[m[32m    double m_national_ID;[m
[32m+[m[32m    double m_BankAccount_ID;[m
[32m+[m[32m    int m_guardian;[m
[32m+[m[32m    double m_guardianNational_ID;[m
[32m+[m[32m    double m_balance;[m
[32m+[m[32m    cAccountStatus m_accountStatus;[m
[32m+[m[32m    string m_password;//Auto generated[m
[32m+[m[32mpublic:[m
[32m+[m[32m    /*cAccountInfo();:m_fullName(""), m_fullAddress(""), m_age(0), m_national_ID(0), m_BankAccount_ID(0),[m
[32m+[m[32m    m_guardian(0), m_guardianNational_ID(0), m_balance(0), m_accountStatus.setStatus("ACTIVE"),[m
[32m+[m[32m    m_password(){}*/[m
[32m+[m
[32m+[m[32m    string getFullName();[m
[32m+[m
[32m+[m[32m    void setFullName(string fullName);[m
[32m+[m
[32m+[m[32m    string getFullAddress();[m
[32m+[m
[32m+[m[32m    void setFullAddress(string fullAddress);[m
[32m+[m
[32m+[m[32m    int getAge();[m
[32m+[m
[32m+[m[32m    void setAge(int age);[m
[32m+[m
[32m+[m[32m    double getNational_ID();[m
[32m+[m
[32m+[m[32m    void setNational_ID(double national_ID);[m
[32m+[m
[32m+[m[32m    double getBankAccount_ID();[m
[32m+[m
[32m+[m[32m    void setBankAccount_ID(double bankAccount_ID);[m
[32m+[m
[32m+[m[32m    int getGuardian();[m
[32m+[m
[32m+[m[32m    void setGuardian(int guardian);[m
[32m+[m
[32m+[m[32m    double getGuardianNational_ID();[m
[32m+[m
[32m+[m[32m    void setGuardianNational_ID(double guardianNational_ID);[m
[32m+[m
[32m+[m[32m    double getBalance();[m
[32m+[m
[32m+[m[32m    void setBalance(double balance);[m
[32m+[m
[32m+[m[32m    string getPassword();[m
[32m+[m
[32m+[m[32m    void setPassword(string password);[m
[32m+[m
[32m+[m[32m};[m
[32m+[m
