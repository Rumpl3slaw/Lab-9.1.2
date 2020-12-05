#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Special { ПЗ, КН, ІТ, СА };

string s_special[] = {
	"Інженерія програмного забезпечення",
	"Комп'ютерні науки",
	"Інформаційні системи та технології",
	"Системний Аналіз" };

struct student
{
	string prizv;
	int kurs;
	Special spec;
	int math;
	int informatic;
	int physics;
	union 
	{
		int programing;
		int history;
		int discmath;
	};
};

void Create(student* s, const int kilkist);
void Print(student* s, const int kilkist);
double Percent(student* s, const int kilkist);
int Students(student* s, const int kilkist);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int klkst_student;
	cout << "Введіть кількість студентів:";cin >> klkst_student;
	cout << endl;
	student* s = new student[klkst_student];

	Create(s, klkst_student);
	cout << endl;
	Print(s, klkst_student);
	cout << endl;

	cout << "Відсоток студентів,які вчаться на відмінно:" << setprecision(2) << Percent(s, klkst_student) << "%" << endl;

	if (Students(s, klkst_student))
		cout << "Прізвища студентів, які отримали з фізики оцінку '5':" << endl;
	else
		cout << "Прізвища студентів, які отримали з фізики оцінку '5' не знайшлося: " << endl;
	delete[]s;
}
void Create(student* s, const int kilkist)
{
	int kurs, special;
	for (int i = 0;i < kilkist;i++)
	{
		cout << endl;
		cout << "студент №" << i + 1 << endl;

		cin.get();
		cin.sync();

		cout << "прізвище:";getline(cin, s[i].prizv);
		cout << "курс:";cin >> s[i].kurs;
		cout << "спеціальність(0 -Інженерія програмного забезпечення, 1 - Комп'ютерні науки, 2 - Інформаційні системи та технології, 3 -Системний Аналіз):";cin >> special;
		s[i].spec = (Special)special;
		cout << "оцінка з математики:";cin >> s[i].math;
		cout << "оцінка з інформатики:";cin >> s[i].informatic;
		cout << "оцінка з фізики:";cin >> s[i].physics;
		switch (special)
		{
		case 0:
			cout << "  оцінка з програмування: "; cin >> s[i].programing;
			break;
		case 1:
			cout << "  оцінка з історії: "; cin >> s[i].history;
			break;
		case 2:
		case 3:
		case 4:
			cout << "  оцінка з дискретної математики: "; cin >> s[i].discmath;
			break;
		default:
			cout << "Ви ввели помилкове значення! " << endl;
		}
		cout << endl;
	}
}
void Print(student* s, const int kilkist)
{
	cout << "======================================================================================================"
		<< endl;
	cout << "|  № |  Прізвище    | Курс | Спеціальність                      | Фізика | Математика  | Інформатика |Програмування|Історія|Дискретна|"
		<< endl;
	cout << "------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < kilkist; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " "
			<< "| " << setw(13) << left << s[i].prizv
			<< "| " << setw(3) << right << s[i].kurs << "  "
			<< "| " << setw(35) << left << s_special[s[i].spec] << ""
			<< "| " << setw(4) << right << s[i].math << "   "
			<< "| " << setw(6) << right << s[i].informatic << "      "
			<< "| " << setw(6) << right << s[i].physics << "      |" ;
		switch(s[i].spec)
		{
		case 0:
			cout  << setw(7)  << s[i].programing << "       |" << setw(18) << "|" << setw(13) << "|" ;
		case 1:
			cout << "| " << setw(15) << "|" << setw(10) << right << s[i].history << "       |" << setw(13) << "|" ;
		case 2:
			cout << "| " << setw(15) << "|" << setw(18) << "|" << right << setw(7) << s[i].discmath << "     |";
			break;
		}
	}
	cout << "======================================================================================================" << endl;
}
double Percent(student* s, const int kilkist)
{
	int k = 0;
	for (int i = 0;i < kilkist;i++)
		if (s[i].math == 5 && s[i].informatic == 5 && s[i].physics == 5)
			k++;
	return 100.0 * k / kilkist;
}
int Students(student* s, const int kilkist)
{
	int l = 0;
	for (int i = 0; i < kilkist;i++)
		if (s[i].physics == 5)
		{
			cout << s[i].prizv << endl;
			l = 1;
		}
	return l;
}