#ifndef MainController_h
#define MainController_h

#include <iostream>
#include < windows.h >
#include <string>
#include <vector>
#include <map>
#include "EmailController.h"


class MainController : public EmailController
{
public:
    void start();
};

#endif