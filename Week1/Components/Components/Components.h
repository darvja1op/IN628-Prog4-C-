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
	private: System::Windows::Forms::Button^  btnMoveBox;
	private: System::Windows::Forms::TextBox^  txtMoveBox;
	private: System::Windows::Forms::PictureBox^  picBox;
	private: System::Windows::Forms::PictureBox^  picDragon;

	private: System::Windows::Forms::Button^  btnAnimate;



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
				 this->btnMoveBox = (gcnew System::Windows::Forms::Button());
				 this->txtMoveBox = (gcnew System::Windows::Forms::TextBox());
				 this->picBox = (gcnew System::Windows::Forms::PictureBox());
				 this->picDragon = (gcnew System::Windows::Forms::PictureBox());
				 this->btnAnimate = (gcnew System::Windows::Forms::Button());
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBox))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picDragon))->BeginInit();
				 this->SuspendLayout();
				 // 
				 // btnGrow
				 // 
				 this->btnGrow->Location = System::Drawing::Point(169, 15);
				 this->btnGrow->Margin = System::Windows::Forms::Padding(4);
				 this->btnGrow->Name = L"btnGrow";
				 this->btnGrow->Size = System::Drawing::Size(100, 28);
				 this->btnGrow->TabIndex = 0;
				 this->btnGrow->Text = L"Grow!";
				 this->btnGrow->UseVisualStyleBackColor = true;
				 this->btnGrow->Click += gcnew System::EventHandler(this, &Components::btnGrow_Click);
				 // 
				 // txtChange
				 // 
				 this->txtChange->Location = System::Drawing::Point(16, 76);
				 this->txtChange->Margin = System::Windows::Forms::Padding(4);
				 this->txtChange->Name = L"txtChange";
				 this->txtChange->Size = System::Drawing::Size(180, 22);
				 this->txtChange->TabIndex = 1;
				 // 
				 // btnChange
				 // 
				 this->btnChange->Location = System::Drawing::Point(240, 76);
				 this->btnChange->Margin = System::Windows::Forms::Padding(4);
				 this->btnChange->Name = L"btnChange";
				 this->btnChange->Size = System::Drawing::Size(193, 28);
				 this->btnChange->TabIndex = 2;
				 this->btnChange->Text = L"Change!";
				 this->btnChange->UseVisualStyleBackColor = true;
				 this->btnChange->Click += gcnew System::EventHandler(this, &Components::btnChange_Click);
				 // 
				 // listBox1
				 // 
				 this->listBox1->FormattingEnabled = true;
				 this->listBox1->ItemHeight = 16;
				 this->listBox1->Location = System::Drawing::Point(240, 138);
				 this->listBox1->Margin = System::Windows::Forms::Padding(4);
				 this->listBox1->Name = L"listBox1";
				 this->listBox1->Size = System::Drawing::Size(159, 116);
				 this->listBox1->TabIndex = 3;
				 // 
				 // btnAdd
				 // 
				 this->btnAdd->Location = System::Drawing::Point(97, 138);
				 this->btnAdd->Margin = System::Windows::Forms::Padding(4);
				 this->btnAdd->Name = L"btnAdd";
				 this->btnAdd->Size = System::Drawing::Size(100, 28);
				 this->btnAdd->TabIndex = 4;
				 this->btnAdd->Text = L"Add Line";
				 this->btnAdd->UseVisualStyleBackColor = true;
				 this->btnAdd->Click += gcnew System::EventHandler(this, &Components::btnAdd_Click);
				 // 
				 // btnToggle
				 // 
				 this->btnToggle->Location = System::Drawing::Point(97, 225);
				 this->btnToggle->Margin = System::Windows::Forms::Padding(4);
				 this->btnToggle->Name = L"btnToggle";
				 this->btnToggle->Size = System::Drawing::Size(100, 28);
				 this->btnToggle->TabIndex = 5;
				 this->btnToggle->Text = L"On";
				 this->btnToggle->UseVisualStyleBackColor = true;
				 this->btnToggle->Click += gcnew System::EventHandler(this, &Components::btnToggle_Click);
				 // 
				 // btnMoveBox
				 // 
				 this->btnMoveBox->Location = System::Drawing::Point(16, 325);
				 this->btnMoveBox->Name = L"btnMoveBox";
				 this->btnMoveBox->Size = System::Drawing::Size(132, 23);
				 this->btnMoveBox->TabIndex = 6;
				 this->btnMoveBox->Text = L"Move Box";
				 this->btnMoveBox->UseVisualStyleBackColor = true;
				 this->btnMoveBox->Click += gcnew System::EventHandler(this, &Components::btnMoveBox_Click);
				 // 
				 // txtMoveBox
				 // 
				 this->txtMoveBox->Location = System::Drawing::Point(16, 297);
				 this->txtMoveBox->Name = L"txtMoveBox";
				 this->txtMoveBox->Size = System::Drawing::Size(132, 22);
				 this->txtMoveBox->TabIndex = 7;
				 // 
				 // picBox
				 // 
				 this->picBox->BackColor = System::Drawing::SystemColors::HotTrack;
				 this->picBox->Location = System::Drawing::Point(185, 297);
				 this->picBox->Name = L"picBox";
				 this->picBox->Size = System::Drawing::Size(59, 51);
				 this->picBox->TabIndex = 8;
				 this->picBox->TabStop = false;
				 // 
				 // picDragon
				 // 
				 this->picDragon->Location = System::Drawing::Point(169, 371);
				 this->picDragon->Name = L"picDragon";
				 this->picDragon->Size = System::Drawing::Size(202, 163);
				 this->picDragon->TabIndex = 9;
				 this->picDragon->TabStop = false;
				 // 
				 // btnAnimate
				 // 
				 this->btnAnimate->Location = System::Drawing::Point(29, 380);
				 this->btnAnimate->Name = L"btnAnimate";
				 this->btnAnimate->Size = System::Drawing::Size(75, 23);
				 this->btnAnimate->TabIndex = 10;
				 this->btnAnimate->Text = L"Animate!";
				 this->btnAnimate->UseVisualStyleBackColor = true;
				 this->btnAnimate->Click += gcnew System::EventHandler(this, &Components::btnAnimate_Click);
				 // 
				 // Components
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(449, 779);
				 this->Controls->Add(this->btnAnimate);
				 this->Controls->Add(this->picDragon);
				 this->Controls->Add(this->picBox);
				 this->Controls->Add(this->txtMoveBox);
				 this->Controls->Add(this->btnMoveBox);
				 this->Controls->Add(this->btnToggle);
				 this->Controls->Add(this->btnAdd);
				 this->Controls->Add(this->listBox1);
				 this->Controls->Add(this->btnChange);
				 this->Controls->Add(this->txtChange);
				 this->Controls->Add(this->btnGrow);
				 this->Margin = System::Windows::Forms::Padding(4);
				 this->Name = L"Components";
				 this->Text = L"Components";
				 this->Load += gcnew System::EventHandler(this, &Components::Components_Load);
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBox))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picDragon))->EndInit();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private: System::Void Components_Load(System::Object^  sender, System::EventArgs^  e)
	{
				 count = 0;
				 isOn = false;
				 picDragon->Image = Image::FromFile("C:\\Users\\Jared\\Desktop\\dragons\\Dragon1.bmp");
	}
			 //Task 1
	private: System::Void btnGrow_Click(System::Object^  sender, System::EventArgs^  e)
	{
				 btnGrow->Width += 10;
				 if ((btnGrow->Left < 0) || (btnGrow->Right > this->Width))
				 {
					 btnGrow->Text = "Too Big!";
				 }
	}
			 //Task 2
	private: System::Void btnChange_Click(System::Object^  sender, System::EventArgs^  e)
	{
				 btnChange->Text = txtChange->Text;
	}
			 //Task 3
	private: System::Void btnAdd_Click(System::Object^  sender, System::EventArgs^  e)
	{
				 count++;
				 listBox1->Items->Add("This is line " + count);
	}
			 //Task 4
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
			 //Task 5
	private: System::Void btnMoveBox_Click(System::Object^  sender, System::EventArgs^  e)
	{
				 int steps = 0;
				 if (txtMoveBox->Text->Length > 0)
				 {
					 steps = System::Int32::Parse(txtMoveBox->Text);
					 for (int i = 0; i < steps; i++)
					 {
						 picBox->Left += 10;
						 System::Threading::Thread::Sleep(100);
					 }
				 }
	}
			 //Task 6
	private: System::Void btnAnimate_Click(System::Object^  sender, System::EventArgs^  e)
	{
				 for (int i = 1; i < 10; i++)
				 {
					 System::Threading::Thread::Sleep(100);
					 Application::DoEvents();
					 picDragon->Image = Image::FromFile("C:\\Users\\Jared\\Desktop\\dragons\\Dragon" + i + ".bmp");
				 }
	}
	};
}
