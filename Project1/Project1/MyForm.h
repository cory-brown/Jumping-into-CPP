#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  generateButton;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->generateButton = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->SuspendLayout();
			// 
			// generateButton
			// 
			this->generateButton->Location = System::Drawing::Point(99, 226);
			this->generateButton->Name = L"generateButton";
			this->generateButton->Size = System::Drawing::Size(75, 23);
			this->generateButton->TabIndex = 0;
			this->generateButton->Text = L"Generate";
			this->generateButton->UseVisualStyleBackColor = true;
			this->generateButton->Click += gcnew System::EventHandler(this, &MyForm::generateButton_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(63, 170);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(154, 23);
			this->progressBar1->TabIndex = 1;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->generateButton);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void generateButton_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	};
}
