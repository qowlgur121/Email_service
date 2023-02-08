#ifndef EmailController_h
#define EmailController_h
#include <iostream>
#include < windows.h >
#include <string>
#include <vector>
#include <map>
#include "AccountController.h"

class EmailController : public AccountController
{
public:
    void AccountPage() override;
    void WriteEmail();
    void SentEmail();
    void ReceivedEmail();
};

#endif