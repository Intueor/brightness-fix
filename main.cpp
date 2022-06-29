//== ВКЛЮЧЕНИЯ.
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

//== ПРОСТРАНСТВА ИМЁН.
using namespace std;

//== ФУНКЦИИ.
// Точка входа.
int main(int iArgc, char* p_mArgv[])
{
	if(iArgc != 4) // Требуется три аргумента.
	{
		cout << "Error. Wrong args number!" << endl;
		return -1;
	}
	//
	ifstream ifsRFile(p_mArgv[1]); // Путь файла для чтения (напр. '/sys/class/backlight/acpi_video1/brightness').
	ofstream ofsWFile(p_mArgv[2]); // Путь файла для записи (напр. '/sys/class/backlight/amdgpu_bl0/brightness').
	double dbMult = stod(p_mArgv[3]); // Множитель значения яркости - напр., при диапазоне входного значения 0-50 и выходного 0-255 - множитель 5.1.
	//
	if(ifsRFile.is_open() && ofsWFile.is_open()) // Проверка доступа к файлам.
	{
		string strText;
		ifsRFile >> strText;
		int iResult = round(stod(strText) * dbMult); // К диапазону выходного.
		ofsWFile << to_string(iResult); // Запись.
		ifsRFile.close();
		ofsWFile.close();
		return 0;
	}
	cout << "Error. Can`t open files!" << endl;
	return -1;
}
