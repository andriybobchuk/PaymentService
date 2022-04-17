#pragma once

#include "controller.h"
#include <msclr\marshal_cppstd.h>


namespace MoneyTransferApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pSignIn;
	protected:

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ tbEmail;

	private: System::Windows::Forms::Button^ btnSignIn;
	private: System::Windows::Forms::TextBox^ tbPassword;
	private: System::Windows::Forms::Panel^ pSignUp;



	private: System::Windows::Forms::Button^ btnSignUp;
	private: System::Windows::Forms::TextBox^ tbPassword1;


	private: System::Windows::Forms::TextBox^ tbEmail1;
	private: System::Windows::Forms::Label^ lInfo;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ tbName;
	private: System::Windows::Forms::Label^ lSuccess;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ tbAccessCode;
	private: System::Windows::Forms::TextBox^ tbPosition;


	private: System::Windows::Forms::Button^ btnSignUpStaff;
	private: System::Windows::Forms::Label^ lFail;

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
			this->pSignIn = (gcnew System::Windows::Forms::Panel());
			this->lFail = (gcnew System::Windows::Forms::Label());
			this->btnSignIn = (gcnew System::Windows::Forms::Button());
			this->tbPassword = (gcnew System::Windows::Forms::TextBox());
			this->tbEmail = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pSignUp = (gcnew System::Windows::Forms::Panel());
			this->btnSignUpStaff = (gcnew System::Windows::Forms::Button());
			this->tbAccessCode = (gcnew System::Windows::Forms::TextBox());
			this->tbPosition = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lSuccess = (gcnew System::Windows::Forms::Label());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->btnSignUp = (gcnew System::Windows::Forms::Button());
			this->tbPassword1 = (gcnew System::Windows::Forms::TextBox());
			this->tbEmail1 = (gcnew System::Windows::Forms::TextBox());
			this->lInfo = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pSignIn->SuspendLayout();
			this->pSignUp->SuspendLayout();
			this->SuspendLayout();
			// 
			// pSignIn
			// 
			this->pSignIn->BackColor = System::Drawing::Color::White;
			this->pSignIn->Controls->Add(this->lFail);
			this->pSignIn->Controls->Add(this->btnSignIn);
			this->pSignIn->Controls->Add(this->tbPassword);
			this->pSignIn->Controls->Add(this->tbEmail);
			this->pSignIn->Controls->Add(this->label2);
			this->pSignIn->Controls->Add(this->label1);
			this->pSignIn->Location = System::Drawing::Point(201, 61);
			this->pSignIn->Name = L"pSignIn";
			this->pSignIn->Size = System::Drawing::Size(296, 329);
			this->pSignIn->TabIndex = 0;
			// 
			// lFail
			// 
			this->lFail->AutoSize = true;
			this->lFail->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
			this->lFail->ForeColor = System::Drawing::Color::Red;
			this->lFail->Location = System::Drawing::Point(88, 271);
			this->lFail->Name = L"lFail";
			this->lFail->Size = System::Drawing::Size(120, 19);
			this->lFail->TabIndex = 11;
			this->lFail->Text = L"Wrong login data!";
			this->lFail->Visible = false;
			// 
			// btnSignIn
			// 
			this->btnSignIn->BackColor = System::Drawing::Color::Black;
			this->btnSignIn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold));
			this->btnSignIn->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnSignIn->Location = System::Drawing::Point(51, 219);
			this->btnSignIn->Name = L"btnSignIn";
			this->btnSignIn->Size = System::Drawing::Size(194, 30);
			this->btnSignIn->TabIndex = 4;
			this->btnSignIn->Text = L"Sign in";
			this->btnSignIn->UseVisualStyleBackColor = false;
			this->btnSignIn->Click += gcnew System::EventHandler(this, &MainForm::btnSignIn_Click);
			// 
			// tbPassword
			// 
			this->tbPassword->Location = System::Drawing::Point(51, 175);
			this->tbPassword->Name = L"tbPassword";
			this->tbPassword->Size = System::Drawing::Size(194, 22);
			this->tbPassword->TabIndex = 3;
			this->tbPassword->Text = L"Password";
			// 
			// tbEmail
			// 
			this->tbEmail->Location = System::Drawing::Point(51, 138);
			this->tbEmail->Name = L"tbEmail";
			this->tbEmail->Size = System::Drawing::Size(194, 22);
			this->tbEmail->TabIndex = 2;
			this->tbEmail->Text = L"Email";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
			this->label2->Location = System::Drawing::Point(47, 85);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(198, 19);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Log in to your existing account";
			this->label2->Click += gcnew System::EventHandler(this, &MainForm::label2_Click_1);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(46, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 30);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Sign In";
			// 
			// pSignUp
			// 
			this->pSignUp->BackColor = System::Drawing::Color::White;
			this->pSignUp->Controls->Add(this->btnSignUpStaff);
			this->pSignUp->Controls->Add(this->tbAccessCode);
			this->pSignUp->Controls->Add(this->tbPosition);
			this->pSignUp->Controls->Add(this->label5);
			this->pSignUp->Controls->Add(this->label3);
			this->pSignUp->Controls->Add(this->lSuccess);
			this->pSignUp->Controls->Add(this->tbName);
			this->pSignUp->Controls->Add(this->btnSignUp);
			this->pSignUp->Controls->Add(this->tbPassword1);
			this->pSignUp->Controls->Add(this->tbEmail1);
			this->pSignUp->Controls->Add(this->lInfo);
			this->pSignUp->Controls->Add(this->label4);
			this->pSignUp->Location = System::Drawing::Point(515, 61);
			this->pSignUp->Name = L"pSignUp";
			this->pSignUp->Size = System::Drawing::Size(296, 526);
			this->pSignUp->TabIndex = 1;
			// 
			// btnSignUpStaff
			// 
			this->btnSignUpStaff->BackColor = System::Drawing::Color::Black;
			this->btnSignUpStaff->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold));
			this->btnSignUpStaff->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnSignUpStaff->Location = System::Drawing::Point(52, 399);
			this->btnSignUpStaff->Name = L"btnSignUpStaff";
			this->btnSignUpStaff->Size = System::Drawing::Size(194, 30);
			this->btnSignUpStaff->TabIndex = 10;
			this->btnSignUpStaff->Text = L"Sign Up a staff";
			this->btnSignUpStaff->UseVisualStyleBackColor = false;
			this->btnSignUpStaff->Click += gcnew System::EventHandler(this, &MainForm::btnSignUpStaff_Click);
			// 
			// tbAccessCode
			// 
			this->tbAccessCode->Location = System::Drawing::Point(51, 324);
			this->tbAccessCode->Name = L"tbAccessCode";
			this->tbAccessCode->Size = System::Drawing::Size(194, 22);
			this->tbAccessCode->TabIndex = 9;
			this->tbAccessCode->Text = L"Access Code";
			// 
			// tbPosition
			// 
			this->tbPosition->Location = System::Drawing::Point(51, 285);
			this->tbPosition->Name = L"tbPosition";
			this->tbPosition->Size = System::Drawing::Size(194, 22);
			this->tbPosition->TabIndex = 8;
			this->tbPosition->Text = L"Position";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
			this->label5->Location = System::Drawing::Point(47, 253);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(123, 19);
			this->label5->TabIndex = 7;
			this->label5->Text = L"For staff members:";
			this->label5->Click += gcnew System::EventHandler(this, &MainForm::label5_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
			this->label3->Location = System::Drawing::Point(47, 85);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(141, 19);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Create a new account";
			this->label3->Click += gcnew System::EventHandler(this, &MainForm::label3_Click_1);
			// 
			// lSuccess
			// 
			this->lSuccess->AutoSize = true;
			this->lSuccess->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
			this->lSuccess->ForeColor = System::Drawing::Color::ForestGreen;
			this->lSuccess->Location = System::Drawing::Point(80, 477);
			this->lSuccess->Name = L"lSuccess";
			this->lSuccess->Size = System::Drawing::Size(150, 19);
			this->lSuccess->TabIndex = 6;
			this->lSuccess->Text = L"Signed Up successfully!";
			this->lSuccess->Visible = false;
			// 
			// tbName
			// 
			this->tbName->Location = System::Drawing::Point(51, 138);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(194, 22);
			this->tbName->TabIndex = 5;
			this->tbName->Text = L"Name";
			// 
			// btnSignUp
			// 
			this->btnSignUp->BackColor = System::Drawing::Color::Black;
			this->btnSignUp->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold));
			this->btnSignUp->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnSignUp->Location = System::Drawing::Point(51, 363);
			this->btnSignUp->Name = L"btnSignUp";
			this->btnSignUp->Size = System::Drawing::Size(194, 30);
			this->btnSignUp->TabIndex = 4;
			this->btnSignUp->Text = L"Sign Up a client";
			this->btnSignUp->UseVisualStyleBackColor = false;
			this->btnSignUp->Click += gcnew System::EventHandler(this, &MainForm::btnSignUp_Click);
			// 
			// tbPassword1
			// 
			this->tbPassword1->Location = System::Drawing::Point(51, 212);
			this->tbPassword1->Name = L"tbPassword1";
			this->tbPassword1->Size = System::Drawing::Size(194, 22);
			this->tbPassword1->TabIndex = 3;
			this->tbPassword1->Text = L"Password";
			// 
			// tbEmail1
			// 
			this->tbEmail1->Location = System::Drawing::Point(51, 175);
			this->tbEmail1->Name = L"tbEmail1";
			this->tbEmail1->Size = System::Drawing::Size(194, 22);
			this->tbEmail1->TabIndex = 2;
			this->tbEmail1->Text = L"Email";
			// 
			// lInfo
			// 
			this->lInfo->AutoSize = true;
			this->lInfo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
			this->lInfo->ForeColor = System::Drawing::Color::Red;
			this->lInfo->Location = System::Drawing::Point(48, 458);
			this->lInfo->Name = L"lInfo";
			this->lInfo->Size = System::Drawing::Size(218, 19);
			this->lInfo->TabIndex = 1;
			this->lInfo->Text = L"Weak password or incorrect email!";
			this->lInfo->Visible = false;
			this->lInfo->Click += gcnew System::EventHandler(this, &MainForm::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13, System::Drawing::FontStyle::Bold));
			this->label4->Location = System::Drawing::Point(46, 39);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(94, 30);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Sign Up";
			this->label4->Click += gcnew System::EventHandler(this, &MainForm::label4_Click);
			// 
			// MainForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(248)),
				static_cast<System::Int32>(static_cast<System::Byte>(248)));
			this->ClientSize = System::Drawing::Size(1060, 669);
			this->Controls->Add(this->pSignUp);
			this->Controls->Add(this->pSignIn);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->pSignIn->ResumeLayout(false);
			this->pSignIn->PerformLayout();
			this->pSignUp->ResumeLayout(false);
			this->pSignUp->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}

/// <summary>
/// Sign Up client
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
/// <returns></returns>
private: System::Void btnSignUp_Click(System::Object^ sender, System::EventArgs^ e) {
	
	msclr::interop::marshal_context context;
	std::string name = context.marshal_as<std::string>(tbName->Text);
	std::string password = context.marshal_as<std::string>(tbPassword1->Text);
	std::string email = context.marshal_as<std::string>(tbEmail1->Text);

	if (!signUp(name, password, email)) {
		lInfo->Text = "Weak password or wrong email!";
		lInfo->Visible = true;
		lSuccess->Visible = false;
	} else {
		lInfo->Visible = false;
		lSuccess->Visible = true;
	}
}

private: System::Void label3_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}

/// <summary>
/// Sign up staff
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
/// <returns></returns>
private: System::Void btnSignUpStaff_Click(System::Object^ sender, System::EventArgs^ e) {

	msclr::interop::marshal_context context;
	std::string name = context.marshal_as<std::string>(tbName->Text);
	std::string password = context.marshal_as<std::string>(tbPassword1->Text);
	std::string email = context.marshal_as<std::string>(tbEmail1->Text);
	std::string position = context.marshal_as<std::string>(tbPosition->Text);
	std::string accessCode = context.marshal_as<std::string>(tbAccessCode->Text);

	if (!signUp(name, password, email, position, accessCode)) {
		lInfo->Text = "Weak password or wrong email or wrong code!";
		lInfo->Visible = true;
		lSuccess->Visible = false;
	}
	else {
		lInfo->Visible = false;
		lSuccess->Visible = true;
	}


}
private: System::Void btnSignIn_Click(System::Object^ sender, System::EventArgs^ e) {

	msclr::interop::marshal_context context;
	std::string password = context.marshal_as<std::string>(tbPassword->Text);
	std::string email = context.marshal_as<std::string>(tbEmail->Text);

	if (!signIn(email, password)) {
		lFail->Visible = true;
	} else {
		lFail->Visible = false;
	}
}

	   void drawUi() {

	   }



};
}
