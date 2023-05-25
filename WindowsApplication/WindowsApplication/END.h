#pragma once
#include <string>
#include <msclr/marshal_cppstd.h>
#include "CaesarCipher.h"
#include "VigenereCipher.h"
#include <regex>

using namespace std;

namespace WindowsApplication {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class END : public System::Windows::Forms::Form
	{
	public:
		END(void)
		{
			InitializeComponent();
			comboBox1->Items->Add("Шифр Виженера");
			comboBox1->Items->Add("Шифр Цезаря");
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~END()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ InputBox;
	private: System::Windows::Forms::TextBox^ OutputBox;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ Encryptbtn;
	private: System::Windows::Forms::Button^ Decryptbtn;


	private: System::Windows::Forms::TextBox^ KeyBox;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ Clearbtn;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(END::typeid));
			this->InputBox = (gcnew System::Windows::Forms::TextBox());
			this->OutputBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->Encryptbtn = (gcnew System::Windows::Forms::Button());
			this->Decryptbtn = (gcnew System::Windows::Forms::Button());
			this->KeyBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Clearbtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// InputBox
			// 
			this->InputBox->BackColor = System::Drawing::Color::White;
			this->InputBox->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->InputBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->InputBox->ForeColor = System::Drawing::SystemColors::MenuText;
			this->InputBox->Location = System::Drawing::Point(12, 159);
			this->InputBox->Multiline = true;
			this->InputBox->Name = L"InputBox";
			this->InputBox->Size = System::Drawing::Size(445, 281);
			this->InputBox->TabIndex = 2;
			// 
			// OutputBox
			// 
			this->OutputBox->BackColor = System::Drawing::Color::White;
			this->OutputBox->Cursor = System::Windows::Forms::Cursors::Default;
			this->OutputBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->OutputBox->ForeColor = System::Drawing::SystemColors::MenuText;
			this->OutputBox->Location = System::Drawing::Point(577, 159);
			this->OutputBox->Multiline = true;
			this->OutputBox->Name = L"OutputBox";
			this->OutputBox->ReadOnly = true;
			this->OutputBox->Size = System::Drawing::Size(445, 281);
			this->OutputBox->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(172, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(243, 29);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Метод шифрования";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(8, 132);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(155, 24);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Входящий текст";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(573, 132);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(200, 24);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Обработанный текст";
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(411, 18);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(267, 32);
			this->comboBox1->TabIndex = 7;
			// 
			// Encryptbtn
			// 
			this->Encryptbtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Encryptbtn->Location = System::Drawing::Point(13, 475);
			this->Encryptbtn->Name = L"Encryptbtn";
			this->Encryptbtn->Size = System::Drawing::Size(176, 36);
			this->Encryptbtn->TabIndex = 8;
			this->Encryptbtn->Text = L"Зашифровать";
			this->Encryptbtn->UseVisualStyleBackColor = true;
			this->Encryptbtn->Click += gcnew System::EventHandler(this, &END::Encryptbtn_Click);
			// 
			// Decryptbtn
			// 
			this->Decryptbtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Decryptbtn->Location = System::Drawing::Point(280, 475);
			this->Decryptbtn->Name = L"Decryptbtn";
			this->Decryptbtn->Size = System::Drawing::Size(176, 36);
			this->Decryptbtn->TabIndex = 9;
			this->Decryptbtn->Text = L"Расшифровать";
			this->Decryptbtn->UseVisualStyleBackColor = true;
			this->Decryptbtn->Click += gcnew System::EventHandler(this, &END::Decryptbtn_Click);
			// 
			// KeyBox
			// 
			this->KeyBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->KeyBox->Location = System::Drawing::Point(802, 24);
			this->KeyBox->Multiline = true;
			this->KeyBox->Name = L"KeyBox";
			this->KeyBox->Size = System::Drawing::Size(82, 29);
			this->KeyBox->TabIndex = 10;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(728, 24);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(68, 26);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Ключ";
			// 
			// Clearbtn
			// 
			this->Clearbtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Clearbtn->Location = System::Drawing::Point(338, 114);
			this->Clearbtn->Name = L"Clearbtn";
			this->Clearbtn->Size = System::Drawing::Size(118, 39);
			this->Clearbtn->TabIndex = 12;
			this->Clearbtn->Text = L"Очистить";
			this->Clearbtn->UseVisualStyleBackColor = true;
			this->Clearbtn->Click += gcnew System::EventHandler(this, &END::Clearbtn_Click);
			// 
			// END
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1034, 548);
			this->Controls->Add(this->Clearbtn);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->KeyBox);
			this->Controls->Add(this->Decryptbtn);
			this->Controls->Add(this->Encryptbtn);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->OutputBox);
			this->Controls->Add(this->InputBox);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"END";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"END";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void Clearbtn_Click(System::Object^ sender, System::EventArgs^ e) {
		InputBox->Text = "";
		OutputBox->Text = "";
	}

	private: System::Void Encryptbtn_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (comboBox1->SelectedItem == nullptr) {
				throw gcnew System::Exception("Не выбран метод шифрования.");
			}
			System::String^ selectedCipher = comboBox1->SelectedItem->ToString();
			if (KeyBox->Text->Trim() == "") {
				throw gcnew System::Exception("Не выбран ключ.");
			}
			if (selectedCipher == "Шифр Цезаря") {
				System::String^ inputText = InputBox->Text;
				string textCiphered = msclr::interop::marshal_as<string>(inputText);
				System::String^ keyText = KeyBox->Text;
				for each (char c in keyText) {
					if (!Char::IsDigit(c) && c != '-') {
						throw gcnew System::Exception("Введены недопустимые символы в ключе.");
					}
				}
				int key = System::Convert::ToInt32(keyText);
				std::regex russianLetters("[а-яА-Я]");
				if (std::regex_search(textCiphered, russianLetters)) {
					throw gcnew System::Exception("Введены буквы русского алфавита.");
				}
				string encryptedText = CaesarCipher::Encrypt(textCiphered, key);
				System::String^ outputText = msclr::interop::marshal_as<System::String^>(encryptedText);
				OutputBox->Text = outputText;
			}
			else if (selectedCipher == "Шифр Виженера") {
				System::String^ inputText = InputBox->Text;
				string textCiphered = msclr::interop::marshal_as<string>(inputText);
				System::String^ keyText = KeyBox->Text;
				string key = msclr::interop::marshal_as<std::string>(keyText);
				std::regex nonLetters("[^a-zA-Z]");
				if (std::regex_search(key, nonLetters)) {
					throw gcnew System::Exception("Введены недопустимые символы в ключе.");
				}
				std::regex russianLetters("[а-яА-Я]");
				if (std::regex_search(textCiphered, russianLetters)) {
					throw gcnew System::Exception("Введены буквы русского алфавита.");
				}
				string encryptedText = VigenereCipher::Encrypt(textCiphered, key);
				System::String^ outputText = msclr::interop::marshal_as<System::String^>(encryptedText);
				OutputBox->Text = outputText;
			}
		}
		catch (System::Exception^ ex) {
			System::Windows::Forms::MessageBox::Show(ex->Message, "Ошибка", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
		}
	}
	private: System::Void Decryptbtn_Click(System::Object^ sender, System::EventArgs^ e) {
		try{
			if (comboBox1->SelectedItem == nullptr) {
				throw gcnew System::Exception("Не выбран метод шифрования.");
			}
			System::String^ selectedCipher = comboBox1->SelectedItem->ToString();
			if (KeyBox->Text->Trim() == "") {
				throw gcnew System::Exception("Не выбран ключ.");
			}
			if (selectedCipher == "Шифр Цезаря") {
				System::String^ inputText = InputBox->Text;
				string textDeciphered = msclr::interop::marshal_as<string>(inputText);
				System::String^ keyText = KeyBox->Text;
				for each (char c in keyText){
					if (!Char::IsDigit(c) && c != '-'){
						throw gcnew System::Exception("Введены недопустимые символы в ключе.");
					}
				}
				int key = System::Convert::ToInt32(keyText);
				std::regex russianLetters("[а-яА-Я]");
				if (std::regex_search(textDeciphered, russianLetters)) {
					throw gcnew System::Exception("Введены буквы русского алфавита.");
				}
				string decryptedText = CaesarCipher::Decrypt(textDeciphered, key);
				System::String^ outputText = msclr::interop::marshal_as<System::String^>(decryptedText);
				OutputBox->Text = outputText;
			}
			else if (selectedCipher == "Шифр Виженера") {
				System::String^ inputText = InputBox->Text;
				string textDeciphered = msclr::interop::marshal_as<string>(inputText);
				System::String^ keyText = KeyBox->Text;
				string key = msclr::interop::marshal_as<std::string>(keyText);
				std::regex nonLetters("[^a-zA-Z]");
				if (std::regex_search(key, nonLetters)) {
					throw gcnew System::Exception("Введены недопустимые символы в ключе.");
				}
				std::regex russianLetters("[а-яА-Я]");
				if (std::regex_search(textDeciphered, russianLetters)) {
					throw gcnew System::Exception("Введены буквы русского алфавита.");
				}
				string decryptedText = VigenereCipher::Decrypt(textDeciphered, key);
				System::String^ outputText = msclr::interop::marshal_as<System::String^>(decryptedText);
				OutputBox->Text = outputText;
			}
		}
		catch (System::Exception^ ex) {
			System::Windows::Forms::MessageBox::Show(ex->Message, "Ошибка", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
		}
	}

	};
}
