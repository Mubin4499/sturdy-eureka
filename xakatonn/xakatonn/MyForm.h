#pragma once

namespace xakatonn {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ btn_delete;
	private: System::Windows::Forms::Button^ btn_search;



	private: System::Windows::Forms::Button^ btn_add;

	private: System::Windows::Forms::Button^ btn_download;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ category;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ summa;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ comment;
	private: System::Windows::Forms::Button^ btn_obshiy;
	private: System::Windows::Forms::TextBox^ textBoxCategory;






	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->category = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->summa = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->comment = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btn_obshiy = (gcnew System::Windows::Forms::Button());
			this->btn_delete = (gcnew System::Windows::Forms::Button());
			this->btn_search = (gcnew System::Windows::Forms::Button());
			this->btn_add = (gcnew System::Windows::Forms::Button());
			this->btn_download = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->dataGridView1->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::Control;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->category,
					this->summa, this->comment
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(611, 452);
			this->dataGridView1->TabIndex = 0;
			// 
			// category
			// 
			this->category->HeaderText = L"Категория";
			this->category->MinimumWidth = 6;
			this->category->Name = L"category";
			this->category->Width = 125;
			// 
			// summa
			// 
			dataGridViewCellStyle2->Format = L"N2";
			dataGridViewCellStyle2->NullValue = nullptr;
			this->summa->DefaultCellStyle = dataGridViewCellStyle2;
			this->summa->HeaderText = L"Сумма";
			this->summa->MinimumWidth = 6;
			this->summa->Name = L"summa";
			this->summa->Width = 125;
			// 
			// comment
			// 
			this->comment->HeaderText = L"Комментарий";
			this->comment->MinimumWidth = 6;
			this->comment->Name = L"comment";
			this->comment->Width = 125;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->btn_obshiy);
			this->groupBox1->Controls->Add(this->btn_delete);
			this->groupBox1->Controls->Add(this->btn_search);
			this->groupBox1->Controls->Add(this->btn_add);
			this->groupBox1->Controls->Add(this->btn_download);
			this->groupBox1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->groupBox1->Location = System::Drawing::Point(630, 7);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(249, 457);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			// 
			// btn_obshiy
			// 
			this->btn_obshiy->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_obshiy->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_obshiy.Image")));
			this->btn_obshiy->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btn_obshiy->Location = System::Drawing::Point(7, 260);
			this->btn_obshiy->Name = L"btn_obshiy";
			this->btn_obshiy->Size = System::Drawing::Size(236, 70);
			this->btn_obshiy->TabIndex = 4;
			this->btn_obshiy->Text = L"Все расходы";
			this->btn_obshiy->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_obshiy->UseVisualStyleBackColor = true;
			this->btn_obshiy->Click += gcnew System::EventHandler(this, &MyForm::btn_obshiy_Click);
			// 
			// btn_delete
			// 
			this->btn_delete->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_delete->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_delete.Image")));
			this->btn_delete->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btn_delete->Location = System::Drawing::Point(7, 337);
			this->btn_delete->Name = L"btn_delete";
			this->btn_delete->Size = System::Drawing::Size(236, 70);
			this->btn_delete->TabIndex = 3;
			this->btn_delete->Text = L"Удалить";
			this->btn_delete->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_delete->UseVisualStyleBackColor = true;
			this->btn_delete->Click += gcnew System::EventHandler(this, &MyForm::btn_delete_Click);
			// 
			// btn_search
			// 
			this->btn_search->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_search->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_search.Image")));
			this->btn_search->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btn_search->Location = System::Drawing::Point(7, 183);
			this->btn_search->Name = L"btn_search";
			this->btn_search->Size = System::Drawing::Size(236, 70);
			this->btn_search->TabIndex = 2;
			this->btn_search->Text = L"Поиск";
			this->btn_search->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_search->UseVisualStyleBackColor = true;
			this->btn_search->Click += gcnew System::EventHandler(this, &MyForm::btn_search_Click);
			// 
			// btn_add
			// 
			this->btn_add->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_add->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_add.Image")));
			this->btn_add->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btn_add->Location = System::Drawing::Point(7, 106);
			this->btn_add->Name = L"btn_add";
			this->btn_add->Size = System::Drawing::Size(236, 70);
			this->btn_add->TabIndex = 1;
			this->btn_add->Text = L"Добавить";
			this->btn_add->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_add->UseVisualStyleBackColor = true;
			this->btn_add->Click += gcnew System::EventHandler(this, &MyForm::btn_add_Click);
			// 
			// btn_download
			// 
			this->btn_download->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btn_download->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_download->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_download.Image")));
			this->btn_download->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btn_download->Location = System::Drawing::Point(7, 29);
			this->btn_download->Name = L"btn_download";
			this->btn_download->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->btn_download->Size = System::Drawing::Size(236, 70);
			this->btn_download->TabIndex = 0;
			this->btn_download->Text = L"Загрузить";
			this->btn_download->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_download->UseVisualStyleBackColor = true;
			this->btn_download->Click += gcnew System::EventHandler(this, &MyForm::btn_download_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(891, 476);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Калькулятор расходов";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void btn_download_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btn_add_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btn_search_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btn_delete_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btn_obshiy_Click(System::Object^ sender, System::EventArgs^ e);
	  
};
}
