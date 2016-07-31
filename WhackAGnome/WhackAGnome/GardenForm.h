#pragma once

#include "GnomeFamily.h"

namespace WhackAGnome {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GardenForm
	/// </summary>
	public ref class GardenForm : public System::Windows::Forms::Form
	{
	public:
		GardenForm(void)
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
		~GardenForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		Random^ rGen;
		Graphics^ mainCanvas;
		GnomeFamily^ gnomeFamily;
		int gnomeIndex;
	private: System::Windows::Forms::Button^  btnStart;
	private: System::Windows::Forms::Label^  lblScore;
			 int hamsterCount;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->lblScore = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &GardenForm::timer1_Tick);
			// 
			// btnStart
			// 
			this->btnStart->Location = System::Drawing::Point(13, 13);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(75, 23);
			this->btnStart->TabIndex = 0;
			this->btnStart->Text = L"Start!";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &GardenForm::btnStart_Click);
			// 
			// lblScore
			// 
			this->lblScore->AutoSize = true;
			this->lblScore->Location = System::Drawing::Point(119, 18);
			this->lblScore->Name = L"lblScore";
			this->lblScore->Size = System::Drawing::Size(53, 17);
			this->lblScore->TabIndex = 1;
			this->lblScore->Text = L"Score: ";
			// 
			// GardenForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(732, 703);
			this->Controls->Add(this->lblScore);
			this->Controls->Add(this->btnStart);
			this->Name = L"GardenForm";
			this->Text = L"GardenForm";
			this->Load += gcnew System::EventHandler(this, &GardenForm::GardenForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void GardenForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
				 //set Window
				 Width = 750;
				 Height = 750;

				 //initialise variables
				 hamsterCount = 0;
				 gnomeIndex = 0;

				 rGen = gcnew Random;
				 mainCanvas = CreateGraphics();
				 gnomeFamily = gcnew GnomeFamily(rGen, mainCanvas, 10);
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
				 lblScore->Text = "Score: " + hamsterCount;

				 //hide previous gnome if not a hamster
				 if (!gnomeFamily->isHamster(gnomeIndex))
				 {
					 gnomeFamily->eraseOneGnome(gnomeIndex);
				 }				 

				 //draw hamsters
				 for (int i = 0; i < gnomeFamily->getNGnomes(); i++)
				 {
					 if (gnomeFamily->isHamster(i))
					 {
						 gnomeFamily->drawOneGnome(i);
					 }
				 }

				 //pick next gnome and draw
				 gnomeIndex = rGen->Next(gnomeFamily->getNGnomes());
				 gnomeFamily->drawOneGnome(gnomeIndex);

				 //test for game over
				 if (hamsterCount == gnomeFamily->getNGnomes())
				 {
					 timer1->Enabled = false;
					 MessageBox::Show("You win!");
				 }
	}
	
	private: System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e) 
	{
				 gnomeFamily->resetAllGnomes();
				 lblScore->Text += "Score: 0";
				 timer1->Enabled = true;
	}
	private: System::Void GardenForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
				 bool hitAGnome = gnomeFamily->hitGnome(gnomeIndex, e->X, e->Y);
				 if (hitAGnome)
				 {
					 gnomeFamily->changeGnomeImage(gnomeIndex, "images\\hamster.jpg");
					 gnomeFamily->setToHamster(gnomeIndex);
					 hamsterCount++;
				 }
	}
	};
}
