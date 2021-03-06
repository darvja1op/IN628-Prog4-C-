#pragma once

#include "SpriteList.h"
#include "Sprite.h"

namespace CollisionDetection {

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
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		Graphics^ formCanvas;
		const int NUM_FRAMES = 8;
		int additionCount;
		Bitmap^ offScreenBitmap;
		Graphics^ offScreenCanvas;
		SpriteList^ chickenList;
		Random^ rGen;
		Sprite^ knight;
		int HEIGHT;
	private: System::Windows::Forms::Timer^  timer1;
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
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(1223, 726);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
	{
				 formCanvas = CreateGraphics();
				 rGen = gcnew Random();

				 WIDTH = this->Width;
				 HEIGHT = this->Height;

				 offScreenBitmap = gcnew Bitmap(WIDTH, HEIGHT);
				 offScreenCanvas = Graphics::FromImage(offScreenBitmap);

				 formCanvas->DrawImage(offScreenBitmap, 0, 0);

				 generateChickenSprites();
				 knight = generateKnightSprite();
				 timer1->Enabled = true;
	}
	private: Sprite^ generateKnightSprite(){
				 int framesInKnightSheet = 8;
				 int directions = 4;

				 array<String^>^ knightImages = gcnew array<String^>(directions);
				 knightImages[EAST] = "images/Knight Walk East 8.bmp";
				 knightImages[NORTH] = "images/Knight Walk North 8.bmp";
				 knightImages[SOUTH] = "images/Knight Walk South 8.bmp";
				 knightImages[WEST] = "images/Knight Walk West 8.bmp";

				 return gcnew Sprite(offScreenCanvas, knightImages, rGen, framesInKnightSheet, Rectangle(0, 0, Width, Height),0.1);
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
					 Sprite^ newChicken = gcnew Sprite(offScreenCanvas, chickenImages, rGen, framesInChickenSheet, chickenBounds, 0.3);
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
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
{
			 Sprite^ victim = chickenList->checkCollisions(knight);

			 if (victim != nullptr)
			 {
				 victim->XVel = 0;
				 victim->YVel = 0;
			 }

			 chickenList->eraseSprites();
			 chickenList->moveSprites();
			 chickenList->updateSprites();
			 chickenList->drawSprites();

			 knight->erase(Color::Black);
			 knight->move();
			 knight->updateFrame();
			 knight->draw();

			 formCanvas->DrawImage(offScreenBitmap, 0, 0);
}
};
}
