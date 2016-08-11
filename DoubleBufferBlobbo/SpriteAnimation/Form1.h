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
	private: System::Windows::Forms::Button^  btnStart;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		SpriteList^ spriteList;
		Graphics^ formCanvas;
		const int NUM_FRAMES = 8;
		int additionCount;
		Bitmap^ offScreenBitmap;
		Graphics^ offScreenCanvas;
		Image^ backgroundImage;

			 Random^ rGen;

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
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 500;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// btnStart
			// 
			this->btnStart->Location = System::Drawing::Point(13, 13);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(75, 23);
			this->btnStart->TabIndex = 0;
			this->btnStart->Text = L"Start!";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &Form1::btnStart_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(710, 505);
			this->Controls->Add(this->btnStart);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
	{
				 formCanvas = CreateGraphics();
				 rGen = gcnew Random();
				 spriteList = gcnew SpriteList();
				 additionCount = 0;
				 backgroundImage = Image::FromFile("images\\outerSpace.jpg");

				 offScreenBitmap = gcnew Bitmap(1024, 768);
				 offScreenCanvas = Graphics::FromImage(offScreenBitmap);
				 offScreenCanvas->DrawImage(backgroundImage, 0, 0);

				 formCanvas->DrawImage(offScreenBitmap, Rectangle(0, 0, 1024, 768));
				 
				 this->Location = Point(50, 50);
				 this->Width = 1600;
				 this->Height = 768;
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
				 additionCount++;
				 if ((additionCount % 5) == 0)
				 {
					 Sprite^ newSprite = gcnew Sprite(offScreenCanvas, "images\\BlobboMulti.bmp", rGen, NUM_FRAMES);
					 spriteList->addSprite(newSprite);
				 }
				 offScreenCanvas->DrawImage(backgroundImage, Rectangle(0, 0, 1024, 768));
	
				 spriteList->wanderSprites();
				 spriteList->moveSprites();
				 spriteList->updateSprites();
				 spriteList->drawSprites();

				 formCanvas->DrawImage(offScreenBitmap, 0, 0);
	}
	private: System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e) 
	{
				 Sprite^ newSprite = gcnew Sprite(formCanvas, "images\\BlobboMulti.bmp", rGen, NUM_FRAMES);
				 spriteList->addSprite(newSprite);
				 timer1->Enabled = true;
	}
	};
}
