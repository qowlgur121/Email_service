#ifndef AccountController_h
#define AccountController_h
#include <iostream>
#include < windows.h >
#include <string>
#include <vector>
#include <map>
#include "MailData.h"

class AccountController
{
protected:
    int check;
    std::string answer;
    Mail mail;
    std::string id, password;
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

#endif