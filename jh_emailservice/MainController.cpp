#include "MainController.h"

void MainController::start()
{
	while (true)
	{
		system("cls");
		std::cout << "<< �̸��� �����Դϴ� >>" << "\n\n";
		std::cout << "1. �α���" << "\n";
		std::cout << "2. ȸ������" << "\n";
		std::cout << "3. ����" << "\n\n";
		std::cout << "���Ͻô� ��ȣ�� �Է��� �ּ���. ";
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
			std::cout << "�߸� �Է��ϼ̽��ϴ�.";
			Sleep(1000);
		}
	}
}
