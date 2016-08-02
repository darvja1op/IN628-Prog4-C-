#pragma once

#include "Pellet.h"
#include "PelletList.h"

namespace RainbowChickenLinkedList {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for DanceFloor
	/// </summary>
	public ref class DanceFloor : public System::Windows::Forms::Form
	{
	public:
		DanceFloor(void)
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
		~DanceFloor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lblScore;
	protected:
	private: System::Windows::Forms::PictureBox^  picChicken;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->lblScore = (gcnew System::Windows::Forms::Label());
			this->picChicken = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picChicken))->BeginInit();
			this->SuspendLayout();
			// 
			// lblScore
			// 
			this->lblScore->AutoSize = true;
			this->lblScore->Location = System::Drawing::Point(13, 13);
			this->lblScore->Name = L"lblScore";
			this->lblScore->Size = System::Drawing::Size(16, 17);
			this->lblScore->TabIndex = 0;
			this->lblScore->Text = L"0";
			// 
			// picChicken
			// 
			this->picChicken->Location = System::Drawing::Point(302, 458);
			this->picChicken->Name = L"picChicken";
			this->picChicken->Size = System::Drawing::Size(69, 50);
			this->picChicken->TabIndex = 1;
			this->picChicken->TabStop = false;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &DanceFloor::timer1_Tick);
			// 
			// DanceFloor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(638, 531);
			this->Controls->Add(this->picChicken);
			this->Controls->Add(this->lblScore);
			this->Name = L"DanceFloor";
			this->Text = L"DanceFloor";
			this->Load += gcnew System::EventHandler(this, &DanceFloor::DanceFloor_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &DanceFloor::DanceFloor_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picChicken))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void DanceFloor_Load(System::Object^  sender, System::EventArgs^  e) 
	{
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
	}
	private: System::Void DanceFloor_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
	{
	}
	};
}
