#include "header.h";

void AccountController::LoginAccount()
{
	while (true)
	{
		system("cls");
		std::cout << "<< �α��� >>" << std::endl << std::endl;
		std::cout << "���̵�: ";
		std::cin >> id;
		std::cout << "��й�ȣ: ";
		std::cin >> password;
		std::cout << std::endl << std::endl;
		if (account_map.find(id) == account_map.end())
		{
			system("cls");
			std::cout << "���̵� �������� �ʽ��ϴ�." << std::endl;
			Sleep(1000);
			while (true)
			{
				system("cls");
				std::cout << "�α����� ��õ��Ͻðڽ��ϱ�?(y / n) ";
				std::cin >> answer;
				if (answer == "y")
				{
					break;
				}
				else if (answer == "n")
					return;
				else
				{
					std::cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��� �ּ���." << std::endl;
					Sleep(1000);
				}
			}
		}
		else if (account_map[id] != password) {
			system("cls");
			std::cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�.";
			Sleep(1000);
			while (true)
			{
				system("cls");
				std::cout << "�α����� ��õ��Ͻðڽ��ϱ�?(y/n) ";
				std::cin >> answer;
				if (answer == "y")
				{
					break;
				}
				else if (answer == "n")
					return;
				else {
					std::cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��� �ּ���." << std::endl;
					Sleep(1000);
				}
			}
		}
		else
		{
			std::cout << "�α��� �Ǿ����ϴ�.";
			Sleep(1000);
			AccountPage(id);
			return;
		}
	}
}
void AccountController::SignupAccount()
{
	while (true)
	{
		system("cls");
		std::cout << "<< ȸ������ >>" << std::endl << std::endl;
		std::cout << "���̵�: ";
		std::cin >> id;
		std::cout << "��й�ȣ: ";
		std::cin >> password;
		std::cout << std::endl << std::endl;
		auto iter = account_map.find(id);
		if (iter != account_map.end())
		{
			system("cls");
			std::cout << "�ߺ��� ���̵��Դϴ�." << std::endl;
			Sleep(1000);
			while (true)
			{
				system("cls");
				std::cout << "ȸ�������� ��õ� �Ͻðڽ��ϱ� ? (y / n) ";
				std::cin >> answer;
				if (answer == "y")
				{
					break;
				}
				else if (answer == "n")
					return;
				else
				{
					std::cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��� �ּ���.";
					Sleep(1000);
				}
			}
		}
		else
		{
			account_map[id] = password;
			std::cout << "ȸ�������� �Ϸ�Ǿ����ϴ�." << std::endl;
			Sleep(1000);
			return;
		}
	}
}
void EmailController::AccountPage(const std::string& id)
{
	while (true)
	{
		system("cls");
		std::cout << "<< (" << id << ")���̷� >> " << std::endl << std::endl;
		std::cout << "1. �̸��Ͼ���" << std::endl;
		std::cout << "2. �����̸�����" << std::endl;
		std::cout << "3. �����̸�����" << std::endl;
		std::cout << "4. �α׾ƿ�" << std::endl << std::endl;
		std::cout << "���Ͻô� ��ȣ�� �Է����ּ���. ";
		std::cin >> answer;

		if (!std::cin)
		{
			std::cout << "���ڸ� �Է��ϼ���.";
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			Sleep(1000);
		}
		else if (answer == "1") {
			WriteEmail(id);
		}
		else if (answer == "2") {
			SentEmail(id);
		}
		else if (answer == "3") {
			std::cout << std::endl << std::endl;
			ReceivedEmail(id);
		}
		else if (answer == "4") {
			return;
		}
		else
		{
			std::cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��� �ּ���. ";
			Sleep(1000);
		}
	}
}
void EmailController::WriteEmail(const std::string& id)
{
	while (true)
	{
		system("cls");
		std::cout << "<< ���� ������ >>" << std::endl << std::endl;
		mail.from = id;
		std::cout << "To: ";
		std::cin >> mail.to;
		if (account_map.find(mail.to) == account_map.end())
		{
			system("cls");
			std::cout << "���̵� �������� �ʽ��ϴ�." << std::endl;
			Sleep(1000);
			while (true)
			{
				system("cls");
				std::cout << "����ؼ� ������ ���ðڽ��ϱ�?(y/n) " << std::endl;
				std::cin >> answer;
				if (answer == "y")
				{
					break;
				}
				else if (answer == "n")
					return;
				else {
					std::cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��� �ּ���." << std::endl;
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
			std::cout << "���� �Ϸ�" << std::endl << std::endl;
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
void EmailController::SentEmail(const std::string& id)
{
	system("cls");
	check = 0;
	std::cout << "<< ���� ���� >>" << std::endl << std::endl;
	for (int i = 0; i < email.size(); i++) {
		if (email[i].from == id) {
			std::cout << "-------------------" << std::endl;
			std::cout << "�޴� ���: " << email[i].to << std::endl;
			std::cout << "����: " << email[i].title << std::endl;
			std::cout << "����: " << email[i].contents << std::endl << std::endl;
			++check;
		}
	}
	if (check == 0)
	{
		std::cout << "���� ������ �����ϴ�." << std::endl << std::endl;
	}
	system("pause");
	return;
}
void EmailController::ReceivedEmail(const std::string& id)
{
	system("cls");
	check = 0;
	std::cout << "<< ���� ���� >>" << std::endl << std::endl;
	for (int i = 0; i < email.size(); i++) {
		if (email[i].to == id) {
			std::cout << "-------------------" << std::endl;
			std::cout << "���� ���: " << email[i].from << std::endl;
			std::cout << "����: " << email[i].title << std::endl;
			std::cout << "����: " << email[i].contents << std::endl << std::endl;
			++check;
		}
	}
	if (check == 0)
	{
		std::cout << "���� ������ �����ϴ�." << std::endl << std::endl;
	}
	system("pause");
	return;
}
void MainController::start()
{
	while (true)
	{
		system("cls");
		std::cout << "<< �̸��� �����Դϴ� >>" << std::endl << std::endl;
		std::cout << "1. �α���" << std::endl;
		std::cout << "2. ȸ������" << std::endl;
		std::cout << "3. ����" << std::endl << std::endl;
		std::cout << "���Ͻô� ��ȣ�� �Է��� �ּ���. ";
		std::cin >> answer;
		if (answer == "1")
		{
			LoginAccount();
			continue;
		}
		else if (answer == "2")
		{
			SignupAccount();
			continue;
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

