#pragma once

#include "TileMap.h"
#include "TileList.h"
#include "Tile.h"

#define DIFF_TILES 13

namespace TileCollisionMaze {

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


	private:
		Graphics^ canvas;
		TileMap^ tileMap;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Timer^  timer1;
			 TileList^ tileList;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(13, 13);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1559, 980);
			this->panel1->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1584, 1005);
			this->Controls->Add(this->panel1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
	{
				 canvas = panel1->CreateGraphics();
				 tileList = gcnew TileList();

				 Bitmap^ bookBitmap = gcnew Bitmap("images/Book Tile.bmp");
				 Bitmap^ grassBitmap = gcnew Bitmap("images/Grass Tile.jpg");
				 Bitmap^ candyBitmap = gcnew Bitmap("images/Candy Tile.bmp");
				 Bitmap^ gloomBitmap = gcnew Bitmap("images/Gloom Tile.bmp");
				 Bitmap^ squirtleBitmap = gcnew Bitmap("images/Squirtle Tile.bmp");
				 Bitmap^ pikachuBitmap = gcnew Bitmap("images/Pikachu Tile.bmp");
				 Bitmap^ tangelaBitmap = gcnew Bitmap("images/Tangela Tile.bmp");
				 Bitmap^ starmieBitmap = gcnew Bitmap("images/Starmie Tile.bmp");
				 Bitmap^ flower3Bitmap = gcnew Bitmap("images/Flower3 Tile.bmp");
				 Bitmap^ flower2Bitmap = gcnew Bitmap("images/Flower2 Tile.bmp");
				 Bitmap^ flower1Bitmap = gcnew Bitmap("images/Flower1 Tile.bmp");
				 Bitmap^ pumpkinBitmap = gcnew Bitmap("images/Pumpkin Tile.bmp");
				 Bitmap^ potionBitmap = gcnew Bitmap("images/Potion Tile.bmp");


				 Tile^ bookTile = gcnew Tile(bookBitmap);
				 Tile^ grassTile = gcnew Tile(grassBitmap);
				 Tile^ candyTile = gcnew Tile(candyBitmap);
				 Tile^ gloomTile = gcnew Tile(gloomBitmap);
				 Tile^ squirtleTile = gcnew Tile(squirtleBitmap);
				 Tile^ pikachuTile = gcnew Tile(pikachuBitmap);
				 Tile^ tangelaTile = gcnew Tile(tangelaBitmap);
				 Tile^ starmieTile = gcnew Tile(starmieBitmap);
				 Tile^ flower3Tile = gcnew Tile(flower3Bitmap);
				 Tile^ flower2Tile = gcnew Tile(flower2Bitmap);
				 Tile^ flower1Tile = gcnew Tile(flower1Bitmap);
				 Tile^ pumpkinTile = gcnew Tile(pumpkinBitmap);
				 Tile^ potionTile = gcnew Tile(potionBitmap);

				 tileList->SetTileArrayEntry(2, bookTile);
				 tileList->SetTileArrayEntry(12, grassTile);
				 tileList->SetTileArrayEntry(1, candyTile);
				 tileList->SetTileArrayEntry(3, gloomTile);
				 tileList->SetTileArrayEntry(5, squirtleTile);
				 tileList->SetTileArrayEntry(4, pikachuTile);
				 tileList->SetTileArrayEntry(8, tangelaTile);
				 tileList->SetTileArrayEntry(5, starmieTile);
				 tileList->SetTileArrayEntry(2, flower3Tile);
				 tileList->SetTileArrayEntry(0, flower2Tile);
				 tileList->SetTileArrayEntry(9, flower1Tile);
				 tileList->SetTileArrayEntry(10, pumpkinTile);
				 tileList->SetTileArrayEntry(11, potionTile);

				 tileMap = gcnew TileMap(tileList, canvas);

				 timer1->Enabled = true;

				 tileMap->LoadMapFromFile("newChickenMap16x12.csv");
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
				 tileMap->DrawMap();
	}
	};
}
