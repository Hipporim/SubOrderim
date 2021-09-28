#include <my_global.h>	 //DB관련
#include <mysql.h>
#pragma comment(lib, "libmySQL.lib")

#include <iostream>
#include <windows.h>
#include <conio.h>	//_getch() 때문에
#define UP 3
#define DOWN 4
#define CHOOSE 5
#define GREEN 10
#define YELLOW 14
#define WHITE 15
using namespace std;

void gotoxy(int x, int y) {		//커서 위치 움직이는 함수
	HANDLE consoleArrow = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleArrow, pos);
}

int arrowControl() {
	char arrow = _getch(); //움직이는것 입력받기 위해

	if (arrow == '2') return DOWN;	//화살표 아래로
	else if (arrow == '5') return UP; //화살표 위로
	else if (arrow == ' ') return CHOOSE; //스페이스바
}
void textColor(int text) {	//글자 색 바꾸기
	int color = text;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int selectMenu() {		//메뉴 선택함수
	int x = 50, y = 15;
	gotoxy(x - 2, y);	//화살표 움직이기 위해서 -2
	cout << "> 메뉴보기";
	gotoxy(x, y + 1);
	cout << "주문방법보기";
	gotoxy(x, y + 2);
	cout << "주문하기";
	gotoxy(x, y + 3);
	cout << "로그인" << endl;
	for (;;) {
		int n = arrowControl();
		switch (n) {
		case 3: {
			if (y > 15) {
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, --y);
				cout << ">";
			}break;
		}
		case 4: {
			if (y < 18) {
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, ++y);
				cout << ">";
			}break;
		}
		case 5: return y - 14;
		}

	}
}

void titlePrint() {
	int x = 17, y = 5;
	cout << endl << endl << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	gotoxy(x, y);
	textColor(GREEN);
	cout << "     _______. __    __  .______   "; textColor(YELLOW); cout <<" _______          _             _       " << endl;
	gotoxy(x, y+1);
	textColor(GREEN);
	cout << "    /       ||  |  |  | |   _  \\  "; textColor(YELLOW); cout << "(_______)        | |           (_)      " << endl;
	gotoxy(x, y + 2);
	textColor(GREEN);
	cout << "   |   (----`|  |  |  | |  |_)  | "; textColor(YELLOW); cout << " _     _  ____ __| |_____  ____ _ ____  " << endl;
	gotoxy(x, y + 3);
	textColor(GREEN);
	cout << "    \\   \\    |  |  |  | |   _  <  "; textColor(YELLOW); cout << "| |   | |/ ___) _  | ___ |/ ___) |    \\ " << endl;
	gotoxy(x, y + 4);
	textColor(GREEN);
	cout << ".----)   |   |  `--'  | |  |_)  | "; textColor(YELLOW); cout << "| |___| | |  ( (_| | ____| |   | | | | |" << endl;
	gotoxy(x, y + 5);
	textColor(GREEN);
	cout << "|_______/     \\______/  |______/  "; textColor(YELLOW); cout << " \\_____/|_|   \\____|_____)_|   |_|_|_|_|" << endl;
	textColor(WHITE);
	cout << endl << endl << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
}

void Order() {
	system("cls");
	int x = 50, y = 15;
	gotoxy(x - 2, y);
	cout << "> 매장 주문" << endl;
	gotoxy(x, y + 1);
	cout << "픽업 주문" << endl;
}

void Login() {
	//포인트 적립률 3.6%
}

void showMenu() {
	int CMenu;
	system("cls");
	cout << endl << "======================================================메뉴===========================================================" << endl;
	cout << "1. 에그마요 \t\t 6. 이탈리안 비엠티 \t\t 11. 로스트 치킨 \t\t 16. 스테이크&치즈" << endl;
	cout << "2. 햄 \t\t\t 7. 베지 \t\t\t 12. 치킨 데리야키 \t\t 17. 터키 베이컨 아보카도" << endl;
	cout << "3. 참치  \t\t 8. 터키 \t\t\t 13. 스파이시 이탈리안 \t\t 18. 터키 베이컨" << endl;
	cout << "4. 미트볼 \t\t 9. 서브웨이 클럽 \t\t 14. 서브웨이 멜트 \t\t 19. 치킨 베이컨 랜치" << endl;
	cout << "5. 비엘티 \t\t10. 로티세리 바비큐 치킨 \t 15. 폴트포크 바비큐 \t\t 20. 로스트 비프 " << endl;
	cout << "=====================================================================================================================" << endl;
	cout << "궁금하신 메뉴를 선택해 주세요: ";
	cin >> CMenu;

	cout << "추천소스 >> ";
	switch (CMenu) {
	case 1: cout << "허니 머스타드, 스위트 칠리" << endl << "재료 >> " << "에그마요 2스쿱, 치즈 2장, 각종 야채"; break;
	case 2: cout << "마요네즈, 사우전 아일랜드" << endl << "재료 >> " << "햄 4장, 치즈 2장, 각종 야채"; break;
	case 3: cout << "허니 머스타드, 스모크 바비큐" << endl << "재료 >> " << "참치 2스쿱, 치즈 2장, 각종 야채"; break;
	case 4: cout << "마요네즈 , 핫 칠리" << endl << "재료 >> " << "미트볼 4개, 치즈 2장"; break;
	case 5: cout << "마요네즈, 스위트 칠리" << endl << "재료 >> " << "베이컨 4장, 치즈 2장, 각종 야채"; break;
	case 6: cout << "마요네즈, 홀스 래디쉬, 사우스 웨스트" << endl << "재료 >> " << "페퍼로니 3장, 살라미 3장, 햄2장, 치즈 2장, 각종 야채"; break;
	case 7: cout << "이탈리안 드레싱, 레드와인 식초, 올리브 오일" << endl << "재료 >> " << "치즈 2장, 각종 야채"; break;
	case 8: cout << "허니 머스타드, 사우스 웨스트, 랜치" << endl << "재료 >> " << "터키 4장, 치즈 2장, 각종 야채"; break;
	case 9: cout << "허니 머스타드, 사우스 웨스트, 랜치" << endl << "재료 >> " << "터키 4장, 로스트 비프 1장, 치즈 2장, 각종 야채"; break;
	case 10: cout << "스위트 어니언, 홀스 래디쉬" << endl << "재료 >> " << "로티세리 치킨 1스쿱, 치즈 2장, 각종 야채"; break;
	case 11: cout << "소금&후추, 허니머스타드" << endl << "재료 >> " << "치킨 브레스트 1개, 치즈 2장, 각종 야채"; break;
	case 12: cout << "스위트 어니언, 랜치, 스모크 바비큐" << endl << "치킨 데리야끼 1스쿱, 치즈 2장, 각종 야채"; break;
	case 13: cout << "마요네즈, 랜치, 핫 칠리" << endl << "페퍼로니 5장, 살라미 5장, 치즈 2장, 각종 야채"; break;
	case 14: cout << "허니 머스타드, 스위트 칠리" << endl << "터키 2장, 햄 2장, 베이컨 2장, 치즈 2장, 각종 야채"; break;
	case 15: cout << "랜치, 스위트 어니언, 스모크 바비큐" << endl << "스테이크 1스쿱, 치즈 2장, 각종 야채"; break;
	case 16: cout << "스모크 바비큐, 머스터드" << endl << "치킨 브레스트 1개, 치즈 2장, 각종 야채"; break;
	case 17: cout << "소금&후추, 올리브오일" << endl << "터키 3장, 베이컨 2장, 치즈 2장, 아보카도 1스쿱, 각종 야채"; break;
	case 18: cout << "스위트 어니언, 사우스 웨스트" << endl << "터키 3장, 베이컨 2장, 치즈 2장, 각종 야채"; break;
	case 19: cout << "후추, 홀스 래디쉬, 랜치" << endl << "치킨 스트립 1스쿱, 베이컨 2장, 치즈 2장, 각종 야채"; break;
	case 20: cout << "소금&후추,레드와인 식초, 올리브오일" << endl << "로스트 비프 3장, 치즈 2장, 각종 야채"; break;
	}
}

void showOrder() {
	system("cls");
	cout << endl << "======================================================주문방법==========================================================" << endl;
	cout << "1. 원하는 메뉴를 고른다. " << endl;
	cout << "2. 빵의 종류(허니오트, 하티, 위트, 파마산 오레가노, 화이트, 플랫브래드)와 빵의 길이(15cm or 30cm)를 선택한다." << endl;
	cout << "3. 치즈를 선택한다.(아메리칸 or 슈레드)" << endl;
	cout << "4. 빼고 싶은 채소나 더 넣고 싶은 채소들을 직원분께 얘기한다." << endl;
	cout << "5. 추가하고 싶은 토핑을 추가한다. " << endl;
	cout << "6. 소스를 고른다.(랜치, 마요네즈, 스위트 어니언, 허니 머스타드, 바비큐, 핫칠리, 사우스 웨스트, 레드와인 식초 등 " << endl;
}

int main() {
	titlePrint();
	for (;;) {
		textColor(WHITE);
		int menuNum = selectMenu();
		if (menuNum == 1) {
			showMenu();
		}
		else if (menuNum == 2) {
			showOrder();
		}
		else if (menuNum == 3) {
			//appOrder();
		}
		else if (menuNum == 4) {
			appLogin();
		}
	}
	return 0;

}
