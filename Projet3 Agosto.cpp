#include <iostream>
#include "Header.h"
using namespace std;
const std::string file = "CS210_Project_Three_Input_File.txt";
/*
nicholas agosto
12/14/2024
*/
int main()
{// program first counts the words then writes to the outfile and finally opens the menu
	WordProcessor wp;
	wp.wordCounter(file);
	wp.dataBackup("frequency.dat");
	wp.menuOptions();
	return 0;
}