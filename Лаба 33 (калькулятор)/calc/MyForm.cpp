#include "MyForm.h"
using namespace calc; // по умолчанию используется навзание проекта, но можно поменять
int main()
{
	//здесь текст только для отображения формы
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}