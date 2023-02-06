#include "header.h";

void AccountController::LoginAccount()
{
	while (true)
	{
		system("cls");
		std::cout << "<< 로그인 >>" << "\n\n";
		std::cout << "아이디: ";
		std::cin >> id;
		std::cout << "비밀번호: ";
		std::cin >> password;
		std::cout << "\n\n";
		if (account_map.find(id) == account_map.end())
		{
			system("cls");
			std::cout << "아이디가 존재하지 않습니다." << "\n";
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
					std::cout << "잘못 입력하셨습니다. 다시 입력해 주세요." << "\n";
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
					std::cout << "잘못 입력하셨습니다. 다시 입력해 주세요." << "\n";
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
void AccountController::ChangeAcPage()
{
	while (true)
	{
		system("cls");
		std::cout << "<< 회원정보변경 >>" << "\n\n";
		std::cout << "1. 아이디변경" << "\n";
		std::cout << "2. 비밀번호변경" << "\n";
		std::cout << "3. 이전 페이지" << "\n\n";
		std::cout << "원하시는 번호를 입력해주세요. ";
		std::cin >> answer;

		if (!std::cin)
		{
			std::cout << "숫자를 입력하세요.";
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			Sleep(1000);
		}
		else if (answer == "1") 
		{
			ChangeId();
		}
		else if (answer == "2") 
		{
			ChangePw();
		}
		else if (answer == "3")
		{
			return;
		}
		else
		{
			std::cout << "잘못 입력하셨습니다. 다시 입력해 주세요. ";
			Sleep(1000);
		}
	}
}
void AccountController::ChangeId()
{
	while (true)
	{
		system("cls");
		std::cout << "<< 아이디 변경 >>" << "\n\n";
		std::cout << "변경할 아이디: ";
		std::cin >> id_;
		std::cout << "\n\n";
		if (account_map.find(id_) != account_map.end())
		{
			system("cls");
			std::cout << "중복된 아이디입니다." << "\n";
			Sleep(1000);
			while (true)
			{
				system("cls");
				std::cout << "아이디 변경을 재시도 하시겠습니까 ? (y / n) ";
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
			auto password = account_map[id];
			account_map.erase(id);
			account_map[id_] = password;
			for (int i = 0; i < email.size(); i++) 
			{
				if (email[i].from == id) 
				{
					email[i].from = id_;
				}
				if (email[i].to == id)
				{
					email[i].to = id_;
				}
			}
			id = id_;
			std::cout << "아이디 변경이 완료되었습니다." << "\n";
			Sleep(1000);
			return;
		}
	}
}

void AccountController::ChangePw()
{
	system("cls");
	std::cout << "<< 비밀번호 변경 >>" << "\n\n";
	std::cout << "변경할 비밀번호: ";
	std::cin >> password_;
	std::cout << "\n\n";
	account_map[id] = password_;
	std::cout << "비밀번호 변경이 완료되었습니다." << "\n";
	Sleep(1000);
	return;
}

void AccountController::SignupAccount()
{
	while (true)
	{
		system("cls");
		std::cout << "<< 회원가입 >>" << "\n\n";
		std::cout << "아이디: ";
		std::cin >> id;
		std::cout << "비밀번호: ";
		std::cin >> password;
		std::cout << "\n\n";
		if (account_map.find(id) != account_map.end())
		{
			system("cls");
			std::cout << "중복된 아이디입니다." << "\n";
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
			std::cout << "회원가입이 완료되었습니다." << "\n";
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
		std::cout << "<< (" << id << ")마이룸 >> " << "\n\n";
		std::cout << "1. 이메일쓰기" << "\n";
		std::cout << "2. 보낸이메일함" << "\n";
		std::cout << "3. 받은이메일함" << "\n";
		std::cout << "4. 회원정보변경" << "\n";
		std::cout << "5. 로그아웃" << "\n\n";
		std::cout << "원하시는 번호를 입력해주세요. ";
		std::cin >> answer;

		if (!std::cin)
		{
			std::cout << "숫자를 입력하세요.";
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			Sleep(1000);
		}
		else if (answer == "1") 
		{
			WriteEmail(id);
		}
		else if (answer == "2") 
		{
			SentEmail(id);
		}
		else if (answer == "3") 
		{
			ReceivedEmail(id);
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
		std::cout << "<< 메일 보내기 >>" << "\n\n";
		mail.from = id;
		std::cout << "To: ";
		std::cin >> mail.to;
		if (account_map.find(mail.to) == account_map.end())
		{
			system("cls");
			std::cout << "아이디가 존재하지 않습니다." << "\n";
			Sleep(1000);
			while (true)
			{
				system("cls");
				std::cout << "계속해서 메일을 쓰시겠습니까?(y/n) " << "\n";
				std::cin >> answer;
				if (answer == "y")
				{
					break;
				}
				else if (answer == "n")
					return;
				else {
					std::cout << "잘못 입력하셨습니다. 다시 입력해 주세요." << "\n";
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
			std::cout << "전송 완료" << "\n\n";
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
	std::cout << "<< 보낸 메일 >>" << "\n\n";
	for (int i = 0; i < email.size(); i++) 
	{
		if (email[i].from == id) {
			std::cout << "-------------------" << "\n";
			std::cout << "("<<check<<")" << "\n";
			std::cout << "받는 사람: " << email[i].to << "\n";
			std::cout << "제목: " << email[i].title << "\n";
			std::cout << "내용: " << email[i].contents << "\n\n";
			++check;
		}
	}
	if (check == 0)
	{
		std::cout << "보낸 메일이 없습니다." << "\n\n";
	}
	system("pause");
	return;
}
void EmailController::ReceivedEmail(const std::string& id)
{
	system("cls");
	check = 0;
	std::cout << "<< 받은 메일 >>" << "\n\n";
	for (int i = 0; i < email.size(); i++) {
		if (email[i].to == id) {
			std::cout << "-------------------" << "\n";
			std::cout << "(" << check << ")" << "\n";
			std::cout << "(1)" << "\n";
			std::cout << "보낸 사람: " << email[i].from << "\n";
			std::cout << "제목: " << email[i].title << "\n";
			std::cout << "내용: " << email[i].contents << "\n\n";
			++check;
		}
	}
	if (check == 0)
	{
		std::cout << "받은 메일이 없습니다." << "\n\n";
	}
	system("pause");
	return;
}
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

