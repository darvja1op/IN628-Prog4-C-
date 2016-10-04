#pragma once

#include "GameManager.h"

namespace darvja1_RogueLike {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
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
		GameManager^ gameManager;
		Graphics^ mainCanvas;
	private: System::Windows::Forms::Panel^  panel1;
			 Graphics^ offScreenCanvas;
			 Bitmap^ offScreenBitmap;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(13, 13);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1254, 766);
			this->panel1->TabIndex = 0;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1279, 791);
			this->Controls->Add(this->panel1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
	{
				 mainCanvas = panel1->CreateGraphics();
				 offScreenBitmap = gcnew Bitmap(Width, Height);
				 offScreenCanvas = Graphics::FromImage(offScreenBitmap);
				 rGen = gcnew Random();

				 gameManager = gcnew GameManager(rGen, offScreenCanvas, mainCanvas);

				 gameManager->loadDungeon();
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
				 gameManager->runGame();
	}
	};
}
