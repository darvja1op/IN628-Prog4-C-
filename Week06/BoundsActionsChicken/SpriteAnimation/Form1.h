#pragma once

#include "SpriteList.h"
#include "Sprite.h"

namespace SpriteAnimation {

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
		Graphics^ formCanvas;
		const int NUM_FRAMES = 8;
		int additionCount;
		Bitmap^ offScreenBitmap;
		Graphics^ offScreenCanvas;
		SpriteList^ chickenList;
		Random^ rGen;
		Sprite^ knight;
		int HEIGHT;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  rdoWrap;
	private: System::Windows::Forms::RadioButton^  rdoBounce;
	private: System::Windows::Forms::RadioButton^  rdoDie;
	private: System::Windows::Forms::RadioButton^  rdoStop;
			 int WIDTH;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->rdoStop = (gcnew System::Windows::Forms::RadioButton());
			this->rdoDie = (gcnew System::Windows::Forms::RadioButton());
			this->rdoBounce = (gcnew System::Windows::Forms::RadioButton());
			this->rdoWrap = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->rdoWrap);
			this->groupBox1->Controls->Add(this->rdoBounce);
			this->groupBox1->Controls->Add(this->rdoDie);
			this->groupBox1->Controls->Add(this->rdoStop);
			this->groupBox1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->groupBox1->Location = System::Drawing::Point(13, 13);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(138, 138);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Bounds Actions";
			// 
			// rdoStop
			// 
			this->rdoStop->AutoSize = true;
			this->rdoStop->Location = System::Drawing::Point(7, 22);
			this->rdoStop->Name = L"rdoStop";
			this->rdoStop->Size = System::Drawing::Size(58, 21);
			this->rdoStop->TabIndex = 0;
			this->rdoStop->TabStop = true;
			this->rdoStop->Text = L"Stop";
			this->rdoStop->UseVisualStyleBackColor = true;
			// 
			// rdoDie
			// 
			this->rdoDie->AutoSize = true;
			this->rdoDie->Location = System::Drawing::Point(7, 50);
			this->rdoDie->Name = L"rdoDie";
			this->rdoDie->Size = System::Drawing::Size(50, 21);
			this->rdoDie->TabIndex = 1;
			this->rdoDie->TabStop = true;
			this->rdoDie->Text = L"Die";
			this->rdoDie->UseVisualStyleBackColor = true;
			// 
			// rdoBounce
			// 
			this->rdoBounce->AutoSize = true;
			this->rdoBounce->Location = System::Drawing::Point(7, 78);
			this->rdoBounce->Name = L"rdoBounce";
			this->rdoBounce->Size = System::Drawing::Size(77, 21);
			this->rdoBounce->TabIndex = 2;
			this->rdoBounce->TabStop = true;
			this->rdoBounce->Text = L"Bounce";
			this->rdoBounce->UseVisualStyleBackColor = true;
			// 
			// rdoWrap
			// 
			this->rdoWrap->AutoSize = true;
			this->rdoWrap->Location = System::Drawing::Point(7, 106);
			this->rdoWrap->Name = L"rdoWrap";
			this->rdoWrap->Size = System::Drawing::Size(84, 21);
			this->rdoWrap->TabIndex = 3;
			this->rdoWrap->TabStop = true;
			this->rdoWrap->Text = L"rdoWrap";
			this->rdoWrap->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(818, 647);
			this->Controls->Add(this->groupBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)
	{
				 formCanvas = CreateGraphics();
				 rGen = gcnew Random();

				 this->Width = 800;
				 this->Height = 600;
				 WIDTH = this->Width;
				 HEIGHT = this->Height;

				 offScreenBitmap = gcnew Bitmap(WIDTH, HEIGHT);
				 offScreenCanvas = Graphics::FromImage(offScreenBitmap);

				 formCanvas->DrawImage(offScreenBitmap, 0,0);

				 generateChickenSprites();
				 //knight = generateKnightSprite();
				 timer1->Enabled = true;
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
				 chickenList->eraseSprites();
				 chickenList->moveSprites();
				 chickenList->updateSprites();
				 chickenList->drawSprites();

				 /*
				 knight->erase(Color::Black);
				 knight->move();
				 knight->updateFrame();
				 knight->draw();*/

				 formCanvas->DrawImage(offScreenBitmap, 0, 0);
	}
	private: Sprite^ generateKnightSprite(){
				 int framesInKnightSheet = 8;
				 int directions = 4;

				 array<String^>^ knightImages = gcnew array<String^>(directions);
				 knightImages[EAST] = "images/Knight Walk East 8.bmp";
				 knightImages[NORTH] = "images/Knight Walk North 8.bmp";
				 knightImages[SOUTH] = "images/Knight Walk South 8.bmp";
				 knightImages[WEST] = "images/Knight Walk West 8.bmp";

				 return gcnew Sprite(offScreenCanvas, knightImages, rGen, framesInKnightSheet, Rectangle(0,0,Width,Height));
	}
	private: void generateChickenSprites(){
				 int framesInChickenSheet = 8;
				 int directions = 4;
				 int nChickens = 12;

				 chickenList = gcnew SpriteList();

				 array<String^>^ chickenImages = gcnew array<String^>(directions);
				 chickenImages[EAST] = "images/Little Chicken Walk East 8.bmp";
				 chickenImages[NORTH] = "images/Little Chicken Walk North 8.bmp";
				 chickenImages[SOUTH] = "images/Little Chicken Walk South 8.bmp";
				 chickenImages[WEST] = "images/Little Chicken Walk West 8.bmp";

				 Rectangle chickenBounds = Rectangle(0, 0, Width, Height);

				 for (int i = 0; i < nChickens; i++)
				 {
					 Sprite^ newChicken = gcnew Sprite(offScreenCanvas, chickenImages, rGen, framesInChickenSheet, chickenBounds);
					 newChicken->SpriteDirection = rGen->Next(directions);
					 newChicken->XVel = rGen->Next(1, 7);
					 newChicken->YVel = rGen->Next(1, 7);
					 chickenList->addSprite(newChicken);
				 }
	}
	private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
	{
				 switch (e->KeyData)
				 {
				 case Keys::Left:
					 knight->SpriteDirection = WEST;
					 break;
				 case Keys::Right:
					 knight->SpriteDirection = EAST;
					 break;
				 case Keys::Up:
					 knight->SpriteDirection = NORTH;
					 break;
				 case Keys::Down:
					 knight->SpriteDirection = SOUTH;
					 break;
				 }
	}
};
}
