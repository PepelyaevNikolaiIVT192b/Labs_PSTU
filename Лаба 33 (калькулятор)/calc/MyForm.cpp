#include "MyForm.h"
using namespace calc; // �� ��������� ������������ �������� �������, �� ����� ��������
int main()
{
	//����� ����� ������ ��� ����������� �����
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}