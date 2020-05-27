#pragma once
#include <vector>
#include <string>
#include <map>
#include <ctime>
using namespace std;
vector < System::Char > vect;
int oper = 7, first = NULL, second = NULL; //переменнная операций, первого числа и второго числа
bool rem = false; //флаг наличия оставшегося числа 
namespace calc {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void) { InitializeComponent(); }
	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::TextBox^ textbox;
	private: System::Windows::Forms::Button^ rez;
	private: System::Windows::Forms::Button^ button_I;
	private: System::Windows::Forms::Button^ button_V;
	private: System::Windows::Forms::Button^ button_X;
	private: System::Windows::Forms::Button^ button_DEL;
	private: System::Windows::Forms::Button^ button_PLS;

	private: System::Windows::Forms::Button^ button_L;
	private: System::Windows::Forms::Button^ button_C;
	private: System::Windows::Forms::Button^ button_D;
	private: System::Windows::Forms::Button^ button_M;
	private: System::Windows::Forms::Button^ button_MIN;
	private: System::Windows::Forms::Button^ button_CLEAR;
	private: System::Windows::Forms::Button^ button_MOD;
	private: System::Windows::Forms::Button^ button_DIV;
	private: System::Windows::Forms::Button^ button_MUL;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel2;
	private: System::Windows::Forms::Button^ button;
	private: System::Windows::Forms::Label^ label;





	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->button_CLEAR = (gcnew System::Windows::Forms::Button());
			this->rez = (gcnew System::Windows::Forms::Button());
			this->button_MOD = (gcnew System::Windows::Forms::Button());
			this->button_MUL = (gcnew System::Windows::Forms::Button());
			this->button_PLS = (gcnew System::Windows::Forms::Button());
			this->button_DIV = (gcnew System::Windows::Forms::Button());
			this->button_MIN = (gcnew System::Windows::Forms::Button());
			this->button = (gcnew System::Windows::Forms::Button());
			this->textbox = (gcnew System::Windows::Forms::TextBox());
			this->button_DEL = (gcnew System::Windows::Forms::Button());
			this->button_X = (gcnew System::Windows::Forms::Button());
			this->button_V = (gcnew System::Windows::Forms::Button());
			this->button_I = (gcnew System::Windows::Forms::Button());
			this->button_M = (gcnew System::Windows::Forms::Button());
			this->button_D = (gcnew System::Windows::Forms::Button());
			this->button_C = (gcnew System::Windows::Forms::Button());
			this->button_L = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->BackColor = System::Drawing::Color::Transparent;
			this->flowLayoutPanel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->flowLayoutPanel1->Controls->Add(this->button_CLEAR);
			this->flowLayoutPanel1->Controls->Add(this->rez);
			this->flowLayoutPanel1->Controls->Add(this->button_MOD);
			this->flowLayoutPanel1->Controls->Add(this->button_MUL);
			this->flowLayoutPanel1->Controls->Add(this->button_PLS);
			this->flowLayoutPanel1->Controls->Add(this->button_DIV);
			this->flowLayoutPanel1->Controls->Add(this->button_MIN);
			this->flowLayoutPanel1->Controls->Add(this->button);
			this->flowLayoutPanel1->FlowDirection = System::Windows::Forms::FlowDirection::BottomUp;
			this->flowLayoutPanel1->Location = System::Drawing::Point(360, 98);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(341, 175);
			this->flowLayoutPanel1->TabIndex = 0;
			// 
			// button_CLEAR
			// 
			this->button_CLEAR->BackColor = System::Drawing::Color::Transparent;
			this->button_CLEAR->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_CLEAR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_CLEAR->Location = System::Drawing::Point(3, 93);
			this->button_CLEAR->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button_CLEAR->Name = L"button_CLEAR";
			this->button_CLEAR->Size = System::Drawing::Size(80, 80);
			this->button_CLEAR->TabIndex = 4;
			this->button_CLEAR->Text = L"c";
			this->button_CLEAR->UseVisualStyleBackColor = false;
			this->button_CLEAR->Click += gcnew System::EventHandler(this, &MyForm::button_CLEAR_click);
			// 
			// rez
			// 
			this->rez->BackColor = System::Drawing::Color::Transparent;
			this->rez->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->rez->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->rez->Location = System::Drawing::Point(3, 9);
			this->rez->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->rez->Name = L"rez";
			this->rez->Size = System::Drawing::Size(80, 80);
			this->rez->TabIndex = 0;
			this->rez->Text = L"=";
			this->rez->UseVisualStyleBackColor = false;
			this->rez->Click += gcnew System::EventHandler(this, &MyForm::button_rez_click);
			// 
			// button_MOD
			// 
			this->button_MOD->BackColor = System::Drawing::Color::Transparent;
			this->button_MOD->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_MOD->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_MOD->Location = System::Drawing::Point(89, 93);
			this->button_MOD->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button_MOD->Name = L"button_MOD";
			this->button_MOD->Size = System::Drawing::Size(80, 80);
			this->button_MOD->TabIndex = 4;
			this->button_MOD->Text = L"%";
			this->button_MOD->UseVisualStyleBackColor = false;
			this->button_MOD->Click += gcnew System::EventHandler(this, &MyForm::button_MOD_click);
			// 
			// button_MUL
			// 
			this->button_MUL->BackColor = System::Drawing::Color::Transparent;
			this->button_MUL->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_MUL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_MUL->Location = System::Drawing::Point(89, 9);
			this->button_MUL->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button_MUL->Name = L"button_MUL";
			this->button_MUL->Size = System::Drawing::Size(80, 80);
			this->button_MUL->TabIndex = 4;
			this->button_MUL->Text = L"*";
			this->button_MUL->UseVisualStyleBackColor = false;
			this->button_MUL->Click += gcnew System::EventHandler(this, &MyForm::button_MUL_click);
			// 
			// button_PLS
			// 
			this->button_PLS->BackColor = System::Drawing::Color::Transparent;
			this->button_PLS->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_PLS->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_PLS->Location = System::Drawing::Point(175, 93);
			this->button_PLS->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button_PLS->Name = L"button_PLS";
			this->button_PLS->Size = System::Drawing::Size(80, 80);
			this->button_PLS->TabIndex = 4;
			this->button_PLS->Text = L"+";
			this->button_PLS->UseVisualStyleBackColor = false;
			this->button_PLS->Click += gcnew System::EventHandler(this, &MyForm::button_PLS_click);
			// 
			// button_DIV
			// 
			this->button_DIV->BackColor = System::Drawing::Color::Transparent;
			this->button_DIV->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_DIV->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_DIV->Location = System::Drawing::Point(175, 9);
			this->button_DIV->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button_DIV->Name = L"button_DIV";
			this->button_DIV->Size = System::Drawing::Size(80, 80);
			this->button_DIV->TabIndex = 4;
			this->button_DIV->Text = L"/";
			this->button_DIV->UseVisualStyleBackColor = false;
			this->button_DIV->Click += gcnew System::EventHandler(this, &MyForm::button_DIV_click);
			// 
			// button_MIN
			// 
			this->button_MIN->BackColor = System::Drawing::Color::Transparent;
			this->button_MIN->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_MIN->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_MIN->Location = System::Drawing::Point(261, 93);
			this->button_MIN->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button_MIN->Name = L"button_MIN";
			this->button_MIN->Size = System::Drawing::Size(80, 80);
			this->button_MIN->TabIndex = 4;
			this->button_MIN->Text = L"-";
			this->button_MIN->UseVisualStyleBackColor = false;
			this->button_MIN->Click += gcnew System::EventHandler(this, &MyForm::button_MIN_click);
			// 
			// button
			// 
			this->button->BackColor = System::Drawing::Color::Transparent;
			this->button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button->Location = System::Drawing::Point(261, 9);
			this->button->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button->Name = L"button";
			this->button->Size = System::Drawing::Size(80, 80);
			this->button->TabIndex = 5;
			this->button->Text = L"\?";
			this->button->UseVisualStyleBackColor = false;
			this->button->Click += gcnew System::EventHandler(this, &MyForm::button_Click);
			// 
			// textbox
			// 
			this->textbox->BackColor = System::Drawing::Color::GhostWhite;
			this->textbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textbox->CharacterCasing = System::Windows::Forms::CharacterCasing::Upper;
			this->textbox->Cursor = System::Windows::Forms::Cursors::No;
			this->textbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 38, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textbox->Location = System::Drawing::Point(12, 9);
			this->textbox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textbox->MaxLength = 10;
			this->textbox->Name = L"textbox";
			this->textbox->ReadOnly = true;
			this->textbox->Size = System::Drawing::Size(686, 79);
			this->textbox->TabIndex = 3;
			this->textbox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// button_DEL
			// 
			this->button_DEL->BackColor = System::Drawing::Color::Transparent;
			this->button_DEL->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_DEL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_DEL->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_DEL->Location = System::Drawing::Point(261, 9);
			this->button_DEL->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button_DEL->Name = L"button_DEL";
			this->button_DEL->Size = System::Drawing::Size(80, 80);
			this->button_DEL->TabIndex = 4;
			this->button_DEL->Text = L"→";
			this->button_DEL->UseVisualStyleBackColor = false;
			this->button_DEL->Click += gcnew System::EventHandler(this, &MyForm::button_DEL_click);
			// 
			// button_X
			// 
			this->button_X->BackColor = System::Drawing::Color::Transparent;
			this->button_X->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_X->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_X->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_X->Location = System::Drawing::Point(175, 9);
			this->button_X->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button_X->Name = L"button_X";
			this->button_X->Size = System::Drawing::Size(80, 80);
			this->button_X->TabIndex = 4;
			this->button_X->Text = L"X";
			this->button_X->UseVisualStyleBackColor = false;
			this->button_X->Click += gcnew System::EventHandler(this, &MyForm::button_X_click);
			// 
			// button_V
			// 
			this->button_V->BackColor = System::Drawing::Color::Transparent;
			this->button_V->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_V->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_V->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_V->Location = System::Drawing::Point(89, 9);
			this->button_V->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button_V->Name = L"button_V";
			this->button_V->Size = System::Drawing::Size(80, 80);
			this->button_V->TabIndex = 4;
			this->button_V->Text = L"V";
			this->button_V->UseVisualStyleBackColor = false;
			this->button_V->Click += gcnew System::EventHandler(this, &MyForm::button_V_click);
			// 
			// button_I
			// 
			this->button_I->BackColor = System::Drawing::Color::Transparent;
			this->button_I->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button_I->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_I->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_I->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_I->ForeColor = System::Drawing::Color::Black;
			this->button_I->Location = System::Drawing::Point(3, 9);
			this->button_I->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button_I->Name = L"button_I";
			this->button_I->Size = System::Drawing::Size(80, 80);
			this->button_I->TabIndex = 1;
			this->button_I->Text = L"I";
			this->button_I->UseVisualStyleBackColor = false;
			this->button_I->Click += gcnew System::EventHandler(this, &MyForm::button_I_click);
			// 
			// button_M
			// 
			this->button_M->BackColor = System::Drawing::Color::Transparent;
			this->button_M->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_M->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_M->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_M->Location = System::Drawing::Point(261, 93);
			this->button_M->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button_M->Name = L"button_M";
			this->button_M->Size = System::Drawing::Size(80, 80);
			this->button_M->TabIndex = 4;
			this->button_M->Text = L"M";
			this->button_M->UseVisualStyleBackColor = false;
			this->button_M->Click += gcnew System::EventHandler(this, &MyForm::button_M_click);
			// 
			// button_D
			// 
			this->button_D->BackColor = System::Drawing::Color::Transparent;
			this->button_D->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_D->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_D->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_D->Location = System::Drawing::Point(175, 93);
			this->button_D->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button_D->Name = L"button_D";
			this->button_D->Size = System::Drawing::Size(80, 80);
			this->button_D->TabIndex = 4;
			this->button_D->Text = L"D";
			this->button_D->UseVisualStyleBackColor = false;
			this->button_D->Click += gcnew System::EventHandler(this, &MyForm::button_D_click);
			// 
			// button_C
			// 
			this->button_C->BackColor = System::Drawing::Color::Transparent;
			this->button_C->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_C->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_C->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_C->Location = System::Drawing::Point(89, 93);
			this->button_C->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button_C->Name = L"button_C";
			this->button_C->Size = System::Drawing::Size(80, 80);
			this->button_C->TabIndex = 4;
			this->button_C->Text = L"C";
			this->button_C->UseVisualStyleBackColor = false;
			this->button_C->Click += gcnew System::EventHandler(this, &MyForm::button_C_click);
			// 
			// button_L
			// 
			this->button_L->BackColor = System::Drawing::Color::Transparent;
			this->button_L->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_L->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_L->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_L->Location = System::Drawing::Point(3, 93);
			this->button_L->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button_L->Name = L"button_L";
			this->button_L->Size = System::Drawing::Size(80, 80);
			this->button_L->TabIndex = 4;
			this->button_L->Text = L"L";
			this->button_L->UseVisualStyleBackColor = false;
			this->button_L->Click += gcnew System::EventHandler(this, &MyForm::button_L_click);
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->BackColor = System::Drawing::Color::Transparent;
			this->flowLayoutPanel2->Controls->Add(this->button_L);
			this->flowLayoutPanel2->Controls->Add(this->button_I);
			this->flowLayoutPanel2->Controls->Add(this->button_C);
			this->flowLayoutPanel2->Controls->Add(this->button_V);
			this->flowLayoutPanel2->Controls->Add(this->button_D);
			this->flowLayoutPanel2->Controls->Add(this->button_X);
			this->flowLayoutPanel2->Controls->Add(this->button_M);
			this->flowLayoutPanel2->Controls->Add(this->button_DEL);
			this->flowLayoutPanel2->FlowDirection = System::Windows::Forms::FlowDirection::BottomUp;
			this->flowLayoutPanel2->Location = System::Drawing::Point(16, 98);
			this->flowLayoutPanel2->Margin = System::Windows::Forms::Padding(4);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(341, 175);
			this->flowLayoutPanel2->TabIndex = 5;
			// 
			// label
			// 
			this->label->AutoSize = true;
			this->label->BackColor = System::Drawing::Color::GhostWhite;
			this->label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label->Location = System::Drawing::Point(23, 22);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(0, 58);
			this->label->TabIndex = 6;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(716, 283);
			this->Controls->Add(this->label);
			this->Controls->Add(this->textbox);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->flowLayoutPanel2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MyForm";
			this->Text = L"Калькулятор";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {}
		   /*
		   буквы заносятся в вектор
		   после нажатия кнопки операции содержимое вектора преобразуется в число int, в глобальную переменную записывается номер опреации
		   при нажатии на кнопку вывода результата преобразуется второе число, через switch определяется операция
		   полученное цисло преобразуется обратно в римскую СС
		   при последующем нажатии на кнопку числа все содержимое блока вывода стирается
		   */

		   //изменение фона окна ввода
		   void cl() {//случайная генерация цвета
			   srand(time(NULL)); int n = rand() % 4;
			   int r = rand() % 50, g = rand() % 25 + 200, b = rand() % 50 + 200;
			   this->textbox->BackColor = System::Drawing::Color::FromArgb(r, g, b);
			   this->label->BackColor = System::Drawing::Color::FromArgb(r, g, b);
		   }
		   //функция для очистки окна для текста
		   void cls(bool f) {
			   textbox->Text = L" "; //удаление букв из textbox
			   vect.clear(); //очистка вектора
			   rem = false; //флаг того, что textbox пуст
			   first = NULL; //обнуление операндов
			   second = NULL;
			   if (f) { label->Text = " "; oper = 7; } //если необходимо очистить вместе с label и номером операции
		   }
		   //перевод из римской СС в десятичную
		   int dec() {
			   int count = 0;
			   for (unsigned int i = 0; i < vect.size(); i++) {
				   switch (vect[i]) {
				   case 'M':
					   count += 1000;
					   break;
				   case 'D':
					   count += 500;
					   break;
				   case 'C':
					   if (i + 1 < vect.size() && (vect[i + 1] == 'D' || vect[i + 1] == 'M'))
						   count -= 100;
					   else
						   count += 100;
					   break;
				   case 'L':
					   count += 50;
					   break;
				   case 'X':
					   if (i + 1 < vect.size() && (vect[i + 1] == 'L' || vect[i + 1] == 'C' || vect[i + 1] == 'M'))
						   count -= 10;
					   else
						   count += 10;
					   break;
				   case 'V':
					   count += 5;
					   break;
				   case 'I':
					   if (i + 1 < vect.size() && (vect[i + 1] == 'V' || vect[i + 1] == 'X' || vect[i + 1] == 'C'))
						   count -= 1;
					   else count += 1;

					   break;
				   }
			   }
			   return count;
		   }
		   //перевод из десятичной СС
		   System::String^ sw(int num, System::String^ hi, System::String^ re, System::String^ lo) {
			   switch (num) {
			   case 9: return lo + hi;
			   case 8: return re + lo + lo + lo;
			   case 7: return re + lo + lo;
			   case 6: return re + lo;
			   case 5: return re;
			   case 4: return lo + re;
			   case 3: return lo + lo + lo;
			   case 2: return lo + lo;
			   case 1: return lo;
			   case 0: return "";
			   }
		   }
		   System::String^ rim(int arabien_num) {
			   System::String^ rome_num;
			   rome_num += sw(arabien_num / 1000, "", "", "M");
			   arabien_num %= 1000;
			   rome_num += sw(arabien_num / 100, "M", "D", "C");
			   arabien_num %= 100;
			   rome_num += sw(arabien_num / 10, "C", "L", "X");
			   arabien_num %= 10;
			   rome_num += sw(arabien_num, "X", "V", "I");
			   return rome_num;
		   }
		   //кнопка для вывода результата
	private: System::Void button_rez_click(System::Object^ sender, System::EventArgs^ e) {
		cl();
		if (first != NULL || !vect.empty()) {
			second = dec(); //перевод второго числа
			int rez;
			//выполнение операции
			switch (oper)
			{
			case 1: rez = first + second; break;
			case 2: rez = first - second; break;
			case 3: rez = first * second; break;
			case 4: rez = first / second; break;
			case 5: rez = first % second; break;
			default: break;
			}
			if (abs(rez) < 4000 && rez != 0)
			{
				System::String^ s;
				if (rez < 0) //если число отрицательное - первым выведется минус
					s = "-";
				s += rim(abs(rez)); //добавление к строке переведенного числа
				//заполнение textbox
				textbox->Text = s;

				first = rez;
				//обнуление переменных
				second = NULL;
				oper = 7;
				rem = true;
				return;
			}
			System::String^ s = gcnew String(to_string(rez).c_str());
			if (rez == 0)
			{
				System::Windows::Forms::MessageBox::Show("В ответе " + s + " , но в римской Системе Счисления нет такого числа", "Ошибка");
				cls(true);
			}
			else
			{
				System::Windows::Forms::MessageBox::Show("Полученное (" + s + ") значение превышает пределы римской Системы Счисления", "Ошибка");
				cls(true);
			}
		}
		else //если первое число не введено или нет знаков в векторе - выводится уведомление
			System::Windows::Forms::MessageBox::Show("Вы не ввели числа", "Ошибка"); //формат [текст] [заголовок]
	}
		   //функция для ввода римских чисел
		   void input(System::Char c) {
			   if (rem) //очистка окна ввода для избежания слипания чисел
				   cls(false);
			   textbox->Text += c; //добавление символа в поле вывода
			   vect.push_back(c); //добавление символа в конец вектора
		   }
		   //кнопки для ввода чисел 
	private: System::Void button_I_click(System::Object^ sender, System::EventArgs^ e) { input(L'I'); }
	private: System::Void button_V_click(System::Object^ sender, System::EventArgs^ e) { input(L'V'); }
	private: System::Void button_X_click(System::Object^ sender, System::EventArgs^ e) { input(L'X'); }
	private: System::Void button_L_click(System::Object^ sender, System::EventArgs^ e) { input(L'L'); }
	private: System::Void button_C_click(System::Object^ sender, System::EventArgs^ e) { input(L'C'); }
	private: System::Void button_D_click(System::Object^ sender, System::EventArgs^ e) { input(L'D'); }
	private: System::Void button_M_click(System::Object^ sender, System::EventArgs^ e) { input(L'M'); }
		   //функция для ввода арифметических действий
		   void op(int n) {
			   System::String^ temp = label->Text, ^ s;
			   if (oper != 7) { //если в label уже стоит знак (то есть oper опеределен)
				   for (int i = 0; i < temp->Length - 2; i++)
					   s += temp[i];
			   }
			   else if (first != NULL) { //если первый операнд - результат предыдущих вычислений
				   s = textbox->Text;
				   textbox->Text = L" ";
				   rem = false;
			   }
			   else { //если первое число еще не заполнено
				   for (unsigned int i = 0; i < vect.size(); i++)
					   s += vect[i];
				   first = dec();//перевод в десятичный вид числа из вектора
			   }
			   switch (n) {//вставка символа операции
			   case 1: s += " +"; break;
			   case 2: s += " -"; break;
			   case 3: s += " *"; break;
			   case 4: s += " /"; break;
			   case 5: s += " %"; break;
			   }
			   label->Text = s;//вывод в доп окно
			   oper = n;//обозначение номера операции
			   cl();//смена цвета для обозначения реакции
			   textbox->Text = L" ";//очистка textbox
			   vect.clear(); //очистка вектора
		   }
		   //кнопки математических действий
	private: System::Void button_PLS_click(System::Object^ sender, System::EventArgs^ e) { op(1); }
	private: System::Void button_MIN_click(System::Object^ sender, System::EventArgs^ e) { op(2); }
	private: System::Void button_MUL_click(System::Object^ sender, System::EventArgs^ e) { op(3); }
	private: System::Void button_DIV_click(System::Object^ sender, System::EventArgs^ e) { op(4); }
	private: System::Void button_MOD_click(System::Object^ sender, System::EventArgs^ e) { op(5); }
		   //кнопки для работы с введенным текстом
	private: System::Void button_DEL_click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ s;
		if (!vect.empty()) {
			vect.pop_back();//удаление из вектора
			for (unsigned int i = 0; i < vect.size(); i++)
				s += vect[i];//вставляются все символы, кроме последнего
			textbox->Text = s;
		}
	}
	private: System::Void button_CLEAR_click(System::Object^ sender, System::EventArgs^ e) { cls(true); }
		   //кнопка со справкой
	private: System::Void button_Click(System::Object^ sender, System::EventArgs^ e) {
		cl();
		System::String^ s1 = "Необходимо вводить числа в римской Системе Счисления посредством кнопок.";
		System::String^ s2 = "\nДля взаимодействия доступны следующие кнопки:";
		System::String^ s3 = "\n- Кнопки с числами: I (1), V (5), X (10), L (50), C (100), D (500) и M (1000);";
		System::String^ s4 = "\n- Кнопки с арифметическими действиями: + (сложение),\n  - (вычитание), * (умножение), / (целочисленное деление),\n  а так же % (получение остатка от деления).";
		System::String^ s5 = "\nЦвет окна вывода меняется при нажатии на кнопки арифметических операций, кнопку вызова справки и кнопку вычисления результата ";
		System::Windows::Forms::MessageBox::Show((s1 + s2 + s3 + s4 + s5), "Справка");
		cls(true);
	}
	};
}
