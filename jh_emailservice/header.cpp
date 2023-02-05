#include "header.h";

void AccountController::LoginAccount()
{
	while (true)
	{
		system("cls");
		std::cout << "<< �α��� >>" << "\n\n";
		std::cout << "���̵�: ";
		std::cin >> id;
		std::cout << "��й�ȣ: ";
		std::cin >> password;
		std::cout << std::endl << std::endl;
		if (account_map.find(id) == account_map.end())
		{
			system("cls");
			std::cout << "���̵� �������� �ʽ��ϴ�." << "\n";
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
					std::cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��� �ּ���." << "\n";
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
					std::cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��� �ּ���." << "\n";
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
		std::cout << "<< ȸ������ >>" << "\n\n";
		std::cout << "���̵�: ";
		std::cin >> id;
		std::cout << "��й�ȣ: ";
		std::cin >> password;
		std::cout << "\n\n";
		auto iter = account_map.find(id);
		if (iter != account_map.end())
		{
			system("cls");
			std::cout << "�ߺ��� ���̵��Դϴ�." << "\n";
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
			std::cout << "ȸ�������� �Ϸ�Ǿ����ϴ�." << "\n";
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
		std::cout << "<< (" << id << ")���̷� >> " << "\n\n";
		std::cout << "1. �̸��Ͼ���" << "\n";
		std::cout << "2. �����̸�����" << "\n";
		std::cout << "3. �����̸�����" << "\n";
		std::cout << "4. �α׾ƿ�" << "\n\n";
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
			std::cout << "\n\n";
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
void EmailController::SentEmail(const std::string& id)
{
	system("cls");
	check = 0;
	std::cout << "<< ���� ���� >>" << "\n\n";
	for (int i = 0; i < email.size(); i++) {
		if (email[i].from == id) {
			std::cout << "-------------------" << "\n";
			std::cout << "�޴� ���: " << email[i].to << "\n";
			std::cout << "����: " << email[i].title << "\n";
			std::cout << "����: " << email[i].contents << "\n\n";
			++check;
		}
	}
	if (check == 0)
	{
		std::cout << "���� ������ �����ϴ�." << "\n\n";
	}
	system("pause");
	return;
}
void EmailController::ReceivedEmail(const std::string& id)
{
	system("cls");
	check = 0;
	std::cout << "<< ���� ���� >>" << "\n\n";
	for (int i = 0; i < email.size(); i++) {
		if (email[i].to == id) {
			std::cout << "-------------------" << "\n";
			std::cout << "���� ���: " << email[i].from << "\n";
			std::cout << "����: " << email[i].title << "\n";
			std::cout << "����: " << email[i].contents << "\n\n";
			++check;
		}
	}
	if (check == 0)
	{
		std::cout << "���� ������ �����ϴ�." << "\n\n";
	}
	system("pause");
	return;
}
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

