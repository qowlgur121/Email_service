#include "MainController.h"

void MainController::start()
{
	while (true)
	{
		system("cls");
		std::cout << "<< 이메일 서비스입니다 >>" << "\n\n";
		std::cout << "1. 로그인" << "\n";
		std::cout << "2. 회원가입" << "\n";
		std::cout << "3. 종료" << "\n\n";
		std::cout << "원하시는 번호를 입력해 주세요. ";
		std::cin >> answer;
		if (answer == "1")
		{
			LoginAccount();
		}
		else if (answer == "2")
		{
			SignupAccount();
		}
		else if (answer == "3")
		{
			exit(1);
		}
		else
		{
			std::cout << "잘못 입력하셨습니다.";
			Sleep(1000);
		}
	}
}
