#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb;

[STAThread]
int main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	xakatonn::MyForm form;
	Application::Run(% form);
}

System::Void xakatonn::MyForm::btn_download_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ connectoinString = "provider=Microsoft.Ace.OLEDB.12.0;Data Source=хакатон.accdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectoinString);
	dbConnection->Open(); 
	String^ query = "SELECT * FROM [table_1]";
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection); 
	OleDbDataReader^ dbReader = dbComand->ExecuteReader(); 

	if (dbReader->HasRows == false)
	{
		MessageBox::Show("Ошибка считывания данных!", "Ошибка!"); 
	}
	else
	{
		while (dbReader->Read())
		{
			dataGridView1->Rows->Add(dbReader["Категория"], dbReader["Сумма"], dbReader["Комментарий"]);
		}
	}
	dbReader->Close();
	dbConnection->Close();
	return System::Void();
}

System::Void xakatonn::MyForm::btn_add_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGridView1->SelectedRows->Count != 1)
	{
		MessageBox::Show("Выберите одну строку для добавления!", "Внимение!");
		return;
	}
	int index = dataGridView1->SelectedRows[0]->Index;
	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[2]->Value == nullptr)
	{
		MessageBox::Show("Введены не все данные!", "Внимание!");
		return;
	}
	String^ category = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ summa = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ comment = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ connectoinString = "provider=Microsoft.Ace.OLEDB.12.0;Data Source=хакатон.accdb"; 
	OleDbConnection^ db_connection = gcnew OleDbConnection(connectoinString);

	db_connection->Open(); 
	String^ query = "INSERT INTO [table_1] VALUES ('" + category + "', " + summa + " ,' " + comment + "')"; 
	OleDbCommand^ db_comand = gcnew OleDbCommand(query, db_connection); 

	if (db_comand->ExecuteNonQuery() != 1)
	{
		MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
	}
	else
	{
		MessageBox::Show("Данные добавлены!", "Готово!");
	}
	db_connection->Close();

	return System::Void();
}

System::Void xakatonn::MyForm::btn_delete_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGridView1->SelectedRows->Count != 1)
	{
		MessageBox::Show("Выберите одну строку для добавления!", "Внимение!");
		return;
	}
	int index = dataGridView1->SelectedRows[0]->Index;

	String^ category = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ summa = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ comment = dataGridView1->Rows[index]->Cells[2]->Value->ToString();

	String^ connectoinString = "provider=Microsoft.Ace.OLEDB.12.0;Data Source=хакатон.accdb"; 
	OleDbConnection^ db_connection = gcnew OleDbConnection(connectoinString);

	db_connection->Open(); 
	String^ query = "DELETE FROM [table_1] WHERE [Категория] = '" + category + "' AND Сумма = " + summa + " AND [Комментарий] = '" + comment + "'";

	OleDbCommand^ db_comand = gcnew OleDbCommand(query, db_connection);
	if (db_comand->ExecuteNonQuery() != 1)
	{
		MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
	}
	else
	{
		MessageBox::Show("Данные удалены!", "Готово!");
	}
	db_connection->Close();
	return System::Void();
}

System::Void xakatonn::MyForm::btn_obshiy_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ connectionString = "provider=Microsoft.Ace.OLEDB.12.0;Data Source=хакатон.accdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	dbConnection->Open();

	String^ query = "SELECT SUM([Сумма]) FROM [table_1]";

	OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
	OleDbDataReader^ dbReader = dbCommand->ExecuteReader();

	if (dbReader->Read()) {
		double totalSum = dbReader[0] == DBNull::Value ? 0 : Convert::ToDouble(dbReader[0]);
		MessageBox::Show("Общая сумма: " + totalSum.ToString(), "Результат");
	}else{
		MessageBox::Show("Ошибка при вычислении общей суммы!", "Ошибка!");
	}

	dbReader->Close();
	dbConnection->Close();
	return System::Void();
}


System::Void xakatonn::MyForm::btn_search_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ categoryToSearch = dataGridView1->Rows[0]->Cells[0]->Value->ToString();
	if (categoryToSearch == "")
	{
		MessageBox::Show("Пожалуйста, введите категорию для поиска!", "Ошибка!");
		return;
	}
	String^ connectionString = "provider=Microsoft.Ace.OLEDB.12.0;Data Source=хакатон.accdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	dbConnection->Open();

	String^ query = "SELECT * FROM [table_1] WHERE [Категория] = '" + categoryToSearch + "'";
	
	OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
	OleDbDataReader^ dbReader = dbCommand->ExecuteReader();

	if (dbReader->HasRows == false)
	{
		MessageBox::Show("Записи с указанной категорией не найдены!", "Поиск завершен");
	}
	else
	{
		dataGridView1->Rows->Clear();

		while (dbReader->Read())
		{
			dataGridView1->Rows->Add(dbReader["Категория"], dbReader["Сумма"], dbReader["Комментарий"]);
		}
	}
	dbReader->Close();
	dbConnection->Close();
}


