#pragma once

namespace Components {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Components
	/// </summary>
	public ref class Components : public System::Windows::Forms::Form
	{
	public:
		Components(void)
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
		~Components()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnGrow;
	private: System::Windows::Forms::TextBox^  txtChange;

	private: System::Windows::Forms::Button^  btnChange;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Button^  btnAdd;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Button^  btnToggle;
			 int count;
			 bool isOn;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnGrow = (gcnew System::Windows::Forms::Button());
			this->txtChange = (gcnew System::Windows::Forms::TextBox());
			this->btnChange = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->btnToggle = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnGrow
			// 
			this->btnGrow->Location = System::Drawing::Point(127, 12);
			this->btnGrow->Name = L"btnGrow";
			this->btnGrow->Size = System::Drawing::Size(75, 23);
			this->btnGrow->TabIndex = 0;
			this->btnGrow->Text = L"Grow!";
			this->btnGrow->UseVisualStyleBackColor = true;
			this->btnGrow->Click += gcnew System::EventHandler(this, &Components::btnGrow_Click);
			// 
			// txtChange
			// 
			this->txtChange->Location = System::Drawing::Point(12, 62);
			this->txtChange->Name = L"txtChange";
			this->txtChange->Size = System::Drawing::Size(136, 20);
			this->txtChange->TabIndex = 1;
			// 
			// btnChange
			// 
			this->btnChange->Location = System::Drawing::Point(180, 62);
			this->btnChange->Name = L"btnChange";
			this->btnChange->Size = System::Drawing::Size(145, 23);
			this->btnChange->TabIndex = 2;
			this->btnChange->Text = L"Change!";
			this->btnChange->UseVisualStyleBackColor = true;
			this->btnChange->Click += gcnew System::EventHandler(this, &Components::btnChange_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(180, 112);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(120, 95);
			this->listBox1->TabIndex = 3;
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(73, 112);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(75, 23);
			this->btnAdd->TabIndex = 4;
			this->btnAdd->Text = L"Add Line";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &Components::btnAdd_Click);
			// 
			// btnToggle
			// 
			this->btnToggle->Location = System::Drawing::Point(73, 183);
			this->btnToggle->Name = L"btnToggle";
			this->btnToggle->Size = System::Drawing::Size(75, 23);
			this->btnToggle->TabIndex = 5;
			this->btnToggle->Text = L"On";
			this->btnToggle->UseVisualStyleBackColor = true;
			this->btnToggle->Click += gcnew System::EventHandler(this, &Components::btnToggle_Click);
			// 
			// Components
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(337, 633);
			this->Controls->Add(this->btnToggle);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->btnChange);
			this->Controls->Add(this->txtChange);
			this->Controls->Add(this->btnGrow);
			this->Name = L"Components";
			this->Text = L"Components";
			this->Load += gcnew System::EventHandler(this, &Components::Components_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Components_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		count = 0;
		isOn = false;
	}
	private: System::Void btnGrow_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		btnGrow->Width += 10;
		if ((btnGrow->Left < 0)||(btnGrow->Right > this->Width))
		{
			btnGrow->Text = "Too Big!";
		}
	}
	private: System::Void btnChange_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		btnChange->Text = txtChange->Text;
	}
	private: System::Void btnAdd_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		count++;
		listBox1->Items->Add("This is line " + count);
	}
	private: System::Void btnToggle_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (isOn)
		{
			btnToggle->Text = "On";
		}
		else
		{
			btnToggle->Text = "Off";
		}
		isOn = !isOn;
	}
};
}
