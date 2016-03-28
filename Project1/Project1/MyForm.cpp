#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]//leave this as is
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project1::MyForm form;
	Application::Run(%form);
}

void generateButton_Click(Object^ sender ,System::EventArgs^ e) {
	this->progressBar1->
}

