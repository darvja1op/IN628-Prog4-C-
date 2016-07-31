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
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 750;
			this->timer1->Tick += gcnew System::EventHandler(this, &GardenForm::timer1_Tick);
			// 
			// GardenForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(794, 517);
			this->Name = L"GardenForm";
			this->Text = L"GardenForm";
			this->Load += gcnew System::EventHandler(this, &GardenForm::GardenForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void GardenForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
				 //initialise variables
				 hamsterCount = 0;
				 gnomeIndex = 10;

				 rGen = gcnew Random;
				 gnomeFamily = gcnew GnomeFamily(rGen, mainCanvas, gnomeIndex);
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
	}
	
	};
}
