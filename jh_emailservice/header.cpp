#include "header.h";

void AccountController::LoginAccount()
{
	while (true)
	{
		system("cls");
		std::cout << "<< 로그인 >>" << std::endl << std::endl;
		std::cout << "아이디: ";
		std::cin >> id;
		std::cout << "비밀번호: ";
		std::cin >> password;
		std::cout << std::endl << std::endl;
		if (account_map.find(id) == account_map.end())
		{
			system("cls");
			std::cout << "아이디가 존재하지 않습니다." << std::endl;
			Sleep(1000);
			while (true)
			{
				system("cls");
				std::cout << "로그인을 재시도하시겠습니까?(y / n) ";
				std::cin >> answer;
				if (answer == "y")
				{
					break;
				}
				else if (answer == "n")
					return;
				else
				{
					std::cout << "잘못 입력하셨습니다. 다시 입력해 주세요." << std::endl;
					Sleep(1000);
				}
			}
		}
		else if (account_map[id] != password) {
			system("cls");
			std::cout << "비밀번호가 틀렸습니다.";
			Sleep(1000);
			while (true)
			{
				system("cls");
				std::cout << "로그인을 재시도하시겠습니까?(y/n) ";
				std::cin >> answer;
				if (answer == "y")
				{
					break;
				}
				else if (answer == "n")
					return;
				else {
					std::cout << "잘못 입력하셨습니다. 다시 입력해 주세요." << std::endl;
					Sleep(1000);
				}
			}
		}
		else
		{
			std::cout << "로그인 되었습니다.";
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
		std::cout << "<< 회원가입 >>" << std::endl << std::endl;
		std::cout << "아이디: ";
		std::cin >> id;
		std::cout << "비밀번호: ";
		std::cin >> password;
		std::cout << std::endl << std::endl;
		auto iter = account_map.find(id);
		if (iter != account_map.end())
		{
			system("cls");
			std::cout << "중복된 아이디입니다." << std::endl;
			Sleep(1000);
			while (true)
			{
				system("cls");
				std::cout << "회원가입을 재시도 하시겠습니까 ? (y / n) ";
				std::cin >> answer;
				if (answer == "y")
				{
					break;
				}
				else if (answer == "n")
					return;
				else
				{
					std::cout << "잘못 입력하셨습니다. 다시 입력해 주세요.";
					Sleep(1000);
				}
			}
		}
		else
		{
			account_map[id] = password;
			std::cout << "회원가입이 완료되었습니다." << std::endl;
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
		std::cout << "<< (" << id << ")마이룸 >> " << std::endl << std::endl;
		std::cout << "1. 이메일쓰기" << std::endl;
		std::cout << "2. 보낸이메일함" << std::endl;
		std::cout << "3. 받은이메일함" << std::endl;
		std::cout << "4. 로그아웃" << std::endl << std::endl;
		std::cout << "원하시는 번호를 입력해주세요. ";
		std::cin >> answer;

		if (!std::cin)
		{
			std::cout << "숫자를 입력하세요.";
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
			std::cout << "잘못 입력하셨습니다. 다시 입력해 주세요. ";
			Sleep(1000);
		}
	}
}
void EmailController::WriteEmail(const std::string& id)
{
	while (true)
	{
		system("cls");
		std::cout << "<< 메일 보내기 >>" << std::endl << std::endl;
		mail.from = id;
		std::cout << "To: ";
		std::cin >> mail.to;
		if (account_map.find(mail.to) == account_map.end())
		{
			system("cls");
			std::cout << "아이디가 존재하지 않습니다." << std::endl;
			Sleep(1000);
			while (true)
			{
				system("cls");
				std::cout << "계속해서 메일을 쓰시겠습니까?(y/n) " << std::endl;
				std::cin >> answer;
				if (answer == "y")
				{
					break;
				}
				else if (answer == "n")
					return;
				else {
					std::cout << "잘못 입력하셨습니다. 다시 입력해 주세요." << std::endl;
					Sleep(1000);
				}
			}
		}
		else
		{
			std::cin.ignore();
			std::cout << "제목: ";
			getline(std::cin, mail.title);
			std::cout << "내용: ";
			getline(std::cin, mail.contents);
			email.push_back(mail);
			std::cout << "전송 완료" << std::endl << std::endl;
			Sleep(1000);
			while (true)
			{
				system("cls");
				std::cout << "계속해서 메일을 쓰겠습니까?(y / n) ";
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
					std::cout << "잘못 입력하셨습니다. 다시 입력해 주세요.";
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
	std::cout << "<< 보낸 메일 >>" << std::endl << std::endl;
	for (int i = 0; i < email.size(); i++) {
		if (email[i].from == id) {
			std::cout << "-------------------" << std::endl;
			std::cout << "받는 사람: " << email[i].to << std::endl;
			std::cout << "제목: " << email[i].title << std::endl;
			std::cout << "내용: " << email[i].contents << std::endl << std::endl;
			++check;
		}
	}
	if (check == 0)
	{
		std::cout << "보낸 메일이 없습니다." << std::endl << std::endl;
	}
	system("pause");
	return;
}
void EmailController::ReceivedEmail(const std::string& id)
{
	system("cls");
	check = 0;
	std::cout << "<< 받은 메일 >>" << std::endl << std::endl;
	for (int i = 0; i < email.size(); i++) {
		if (email[i].to == id) {
			std::cout << "-------------------" << std::endl;
			std::cout << "보낸 사람: " << email[i].from << std::endl;
			std::cout << "제목: " << email[i].title << std::endl;
			std::cout << "내용: " << email[i].contents << std::endl << std::endl;
			++check;
		}
	}
	if (check == 0)
	{
		std::cout << "받은 메일이 없습니다." << std::endl << std::endl;
	}
	system("pause");
	return;
}
void MainController::start()
{
	while (true)
	{
		system("cls");
		std::cout << "<< 이메일 서비스입니다 >>" << std::endl << std::endl;
		std::cout << "1. 로그인" << std::endl;
		std::cout << "2. 회원가입" << std::endl;
		std::cout << "3. 종료" << std::endl << std::endl;
		std::cout << "원하시는 번호를 입력해 주세요. ";
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
			std::cout << "잘못 입력하셨습니다.";
			Sleep(1000);
		}
	}
}

