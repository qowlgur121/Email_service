#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include < windows.h >
#include <string>
#include <vector>
#include <map>
#include "stdlib.h"

struct Mail 
{
    std::string from;
    std::string to;
    std::string title;
    std::string contents;
};
class AccountController
{
protected:
    int check;
    std::string answer;
    Mail mail;
    std::string id , password;
    std::string id_, password_;
    std::map<std::string, std::string> account_map;
    std::vector<Mail> email;
public:
    void LoginAccount();
    void ChangeAcPage();
    void ChangeId();
    void ChangePw();
    void SignupAccount();
    virtual void AccountPage() = 0;
};
class EmailController : public AccountController
{
public:
    void AccountPage() override;
    void WriteEmail();
    void SentEmail();
    void ReceivedEmail();
};
class MainController : public EmailController
{
public:
    void start();
};
#endif


