#include "EmailController.h"

void EmailController::AccountPage()
{
	while (true)
	{
		system("cls");
		std::cout << "<< (" << id << ")���̷� >> " << "\n\n";
		std::cout << "1. �̸��� ����" << "\n";
		std::cout << "2. ���� �̸�����" << "\n";
		std::cout << "3. ���� �̸�����" << "\n";
		std::cout << "4. ȸ������ ����" << "\n";
		std::cout << "5. �α׾ƿ�" << "\n\n";
		std::cout << "���Ͻô� ��ȣ�� �Է����ּ���. ";
		std::cin >> answer;

		if (!std::cin)
		{
			std::cout << "���ڸ� �Է��ϼ���.";
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			Sleep(1000);
		}
		else if (answer == "1") 
		{
			WriteEmail();
		}
		else if (answer == "2") 
		{
			SentEmail();
		}
		else if (answer == "3") 
		{
			ReceivedEmail();
		}
		else if (answer == "4")
		{
			ChangeAcPage();
		}
		else if (answer == "5") 
		{
			return;
		}
		else
		{
			std::cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��� �ּ���. ";
			Sleep(1000);
		}
	}
}
void EmailController::WriteEmail()
{
	while (true)
	{
		system("cls");
		std::cout << "<< ���� ������ >>" << "\n\n";
		mail.from = id;
		std::cout << "To: ";
		std::cin >> mail.to;
		if (account_map.find(mail.to) == account_map.end())
		{
			system("cls");
			std::cout << "���̵� �������� �ʽ��ϴ�." << "\n";
			Sleep(1000);
			while (true)
			{
				system("cls");
				std::cout << "����ؼ� ������ ���ðڽ��ϱ�?(y/n) " << "\n";
				std::cin >> answer;
				if (answer == "y")
				{
					break;
				}
				else if (answer == "n")
					return;
				else {
					std::cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��� �ּ���." << "\n";
					Sleep(1000);
				}
			}
		}
		else
		{
			std::cin.ignore();
			std::cout << "����: ";
			getline(std::cin, mail.title);
			std::cout << "����: ";
			getline(std::cin, mail.contents);
			email.push_back(mail);
			std::cout << "���� �Ϸ�" << "\n\n";
			Sleep(1000);
			while (true)
			{
				system("cls");
				std::cout << "����ؼ� ������ ���ڽ��ϱ�?(y / n) ";
				std::cin >> answer;
				if (answer == "y")
				{
					break;
				}
				else if (answer == "n")
				{
					return;
				}
				else
				{
					std::cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��� �ּ���.";
					Sleep(1000);
				}
			}
		}
	}
}
void EmailController::SentEmail()
{
	system("cls");
	check = 0;
	std::cout << "<< ���� ���� >>" << "\n\n";
	for (int i = 0; i < email.size(); i++) 
	{
		if (email[i].from == id) {
			++check;
			std::cout << "-------------------" << "\n";
			std::cout << "("<<check<<")" << "\n";
			std::cout << "�޴� ���: " << email[i].to << "\n";
			std::cout << "����: " << email[i].title << "\n";
			std::cout << "����: " << email[i].contents << "\n\n";
		}
	}
	if (check == 0)
	{
		std::cout << "���� ������ �����ϴ�." << "\n\n";
	}
	system("pause");
	return;
}
void EmailController::ReceivedEmail()
{
	system("cls");
	check = 0;
	std::cout << "<< ���� ���� >>" << "\n\n";
	for (int i = 0; i < email.size(); i++) {
		if (email[i].to == id) {
			++check;
			std::cout << "-------------------" << "\n";
			std::cout << "(" << check << ")" << "\n";
			std::cout << "���� ���: " << email[i].from << "\n";
			std::cout << "����: " << email[i].title << "\n";
			std::cout << "����: " << email[i].contents << "\n\n";
		}
	}
	if (check == 0)
	{
		std::cout << "���� ������ �����ϴ�." << "\n\n";
	}
	system("pause");
	return;
}