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
	String^ connectoinString = "provider=Microsoft.Ace.OLEDB.12.0;Data Source=�������.accdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectoinString);
	dbConnection->Open(); 
	String^ query = "SELECT * FROM [table_1]";
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection); 
	OleDbDataReader^ dbReader = dbComand->ExecuteReader(); 

	if (dbReader->HasRows == false)
	{
		MessageBox::Show("������ ���������� ������!", "������!"); 
	}
	else
	{
		while (dbReader->Read())
		{
			dataGridView1->Rows->Add(dbReader["���������"], dbReader["�����"], dbReader["�����������"]);
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
		MessageBox::Show("�������� ���� ������ ��� ����������!", "��������!");
		return;
	}
	int index = dataGridView1->SelectedRows[0]->Index;
	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[2]->Value == nullptr)
	{
		MessageBox::Show("������� �� ��� ������!", "��������!");
		return;
	}
	String^ category = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ summa = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ comment = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ connectoinString = "provider=Microsoft.Ace.OLEDB.12.0;Data Source=�������.accdb"; 
	OleDbConnection^ db_connection = gcnew OleDbConnection(connectoinString);

	db_connection->Open(); 
	String^ query = "INSERT INTO [table_1] VALUES ('" + category + "', " + summa + " ,' " + comment + "')"; 
	OleDbCommand^ db_comand = gcnew OleDbCommand(query, db_connection); 

	if (db_comand->ExecuteNonQuery() != 1)
	{
		MessageBox::Show("������ ���������� �������!", "������!");
	}
	else
	{
		MessageBox::Show("������ ���������!", "������!");
	}
	db_connection->Close();

	return System::Void();
}

System::Void xakatonn::MyForm::btn_delete_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGridView1->SelectedRows->Count != 1)
	{
		MessageBox::Show("�������� ���� ������ ��� ����������!", "��������!");
		return;
	}
	int index = dataGridView1->SelectedRows[0]->Index;

	String^ category = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ summa = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ comment = dataGridView1->Rows[index]->Cells[2]->Value->ToString();

	String^ connectoinString = "provider=Microsoft.Ace.OLEDB.12.0;Data Source=�������.accdb"; 
	OleDbConnection^ db_connection = gcnew OleDbConnection(connectoinString);

	db_connection->Open(); 
	String^ query = "DELETE FROM [table_1] WHERE [���������] = '" + category + "' AND ����� = " + summa + " AND [�����������] = '" + comment + "'";

	OleDbCommand^ db_comand = gcnew OleDbCommand(query, db_connection);
	if (db_comand->ExecuteNonQuery() != 1)
	{
		MessageBox::Show("������ ���������� �������!", "������!");
	}
	else
	{
		MessageBox::Show("������ �������!", "������!");
	}
	db_connection->Close();
	return System::Void();
}

System::Void xakatonn::MyForm::btn_obshiy_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ connectionString = "provider=Microsoft.Ace.OLEDB.12.0;Data Source=�������.accdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	dbConnection->Open();

	String^ query = "SELECT SUM([�����]) FROM [table_1]";

	OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
	OleDbDataReader^ dbReader = dbCommand->ExecuteReader();

	if (dbReader->Read()) {
		double totalSum = dbReader[0] == DBNull::Value ? 0 : Convert::ToDouble(dbReader[0]);
		MessageBox::Show("����� �����: " + totalSum.ToString(), "���������");
	}else{
		MessageBox::Show("������ ��� ���������� ����� �����!", "������!");
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
		MessageBox::Show("����������, ������� ��������� ��� ������!", "������!");
		return;
	}
	String^ connectionString = "provider=Microsoft.Ace.OLEDB.12.0;Data Source=�������.accdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	dbConnection->Open();

	String^ query = "SELECT * FROM [table_1] WHERE [���������] = '" + categoryToSearch + "'";
	
	OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
	OleDbDataReader^ dbReader = dbCommand->ExecuteReader();

	if (dbReader->HasRows == false)
	{
		MessageBox::Show("������ � ��������� ���������� �� �������!", "����� ��������");
	}
	else
	{
		dataGridView1->Rows->Clear();

		while (dbReader->Read())
		{
			dataGridView1->Rows->Add(dbReader["���������"], dbReader["�����"], dbReader["�����������"]);
		}
	}
	dbReader->Close();
	dbConnection->Close();
}


