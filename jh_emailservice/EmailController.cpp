#include "EmailController.h"

void EmailController::AccountPage()
{
	while (true)
	{
		system("cls");
		std::cout << "<< (" << id << ")마이룸 >> " << "\n\n";
		std::cout << "1. 이메일 쓰기" << "\n";
		std::cout << "2. 보낸 이메일함" << "\n";
		std::cout << "3. 받은 이메일함" << "\n";
		std::cout << "4. 회원정보 변경" << "\n";
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
			std::cout << "잘못 입력하셨습니다. 다시 입력해 주세요. ";
			Sleep(1000);
		}
	}
}
void EmailController::WriteEmail()
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
void EmailController::SentEmail()
{
	system("cls");
	check = 0;
	std::cout << "<< 보낸 메일 >>" << "\n\n";
	for (int i = 0; i < email.size(); i++) 
	{
		if (email[i].from == id) {
			++check;
			std::cout << "-------------------" << "\n";
			std::cout << "("<<check<<")" << "\n";
			std::cout << "받는 사람: " << email[i].to << "\n";
			std::cout << "제목: " << email[i].title << "\n";
			std::cout << "내용: " << email[i].contents << "\n\n";
		}
	}
	if (check == 0)
	{
		std::cout << "보낸 메일이 없습니다." << "\n\n";
	}
	system("pause");
	return;
}
void EmailController::ReceivedEmail()
{
	system("cls");
	check = 0;
	std::cout << "<< 받은 메일 >>" << "\n\n";
	for (int i = 0; i < email.size(); i++) {
		if (email[i].to == id) {
			++check;
			std::cout << "-------------------" << "\n";
			std::cout << "(" << check << ")" << "\n";
			std::cout << "보낸 사람: " << email[i].from << "\n";
			std::cout << "제목: " << email[i].title << "\n";
			std::cout << "내용: " << email[i].contents << "\n\n";
		}
	}
	if (check == 0)
	{
		std::cout << "받은 메일이 없습니다." << "\n\n";
	}
	system("pause");
	return;
}