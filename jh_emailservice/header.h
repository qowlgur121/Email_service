#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include < windows.h >
#include <string>
#include <vector>
#include <map>
#include "stdlib.h"

struct Mail {
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
    std::string id, password;
    std::map<std::string, std::string> account_map;
    std::vector<Mail> email;
public:
    void LoginAccount();
    void SignupAccount();
    virtual void AccountPage(const std::string& id) = 0;
};
class EmailController : public AccountController
{
public:
    void AccountPage(const std::string& id) override;
    void WriteEmail(const std::string& id);
    void SentEmail(const std::string& id);
    void ReceivedEmail(const std::string& id);
};
class MainController : public EmailController
{
public:
    void start();
};
#endif


