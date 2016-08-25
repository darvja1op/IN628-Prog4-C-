#pragma once

#include "TileMap.h"
#include "TileList.h"
#include "Tile.h"

#define DIFF_TILES 3

namespace TileMapMaze {

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
	private: System::Windows::Forms::Button^  btnRandom;
	protected:
	private: System::Windows::Forms::Button^  btnLoadFile;
	private: System::Windows::Forms::Panel^  panel1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

	private:
		Graphics^ canvas;
		TileMap^ tileMap;
		TileList^ tileList;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnRandom = (gcnew System::Windows::Forms::Button());
			this->btnLoadFile = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// btnRandom
			// 
			this->btnRandom->Location = System::Drawing::Point(13, 13);
			this->btnRandom->Name = L"btnRandom";
			this->btnRandom->Size = System::Drawing::Size(75, 25);
			this->btnRandom->TabIndex = 0;
			this->btnRandom->Text = L"Random Map";
			this->btnRandom->UseVisualStyleBackColor = true;
			this->btnRandom->Click += gcnew System::EventHandler(this, &Form1::btnRandom_Click);
			// 
			// btnLoadFile
			// 
			this->btnLoadFile->Location = System::Drawing::Point(119, 13);
			this->btnLoadFile->Name = L"btnLoadFile";
			this->btnLoadFile->Size = System::Drawing::Size(128, 25);
			this->btnLoadFile->TabIndex = 1;
			this->btnLoadFile->Text = L"Map from File";
			this->btnLoadFile->UseVisualStyleBackColor = true;
			this->btnLoadFile->Click += gcnew System::EventHandler(this, &Form1::btnLoadFile_Click);
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(13, 58);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1182, 884);
			this->panel1->TabIndex = 2;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1207, 954);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->btnLoadFile);
			this->Controls->Add(this->btnRandom);
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
				 
				 Bitmap^ grassBitmap = gcnew Bitmap("images/Dry Grass Tile 32.bmp");
				 Bitmap^ cobblestoneBitmap = gcnew Bitmap("images/Cobblestones Tile 32.bmp");
				 Bitmap^ flowerBitmap = gcnew Bitmap("images/Flower Tile 32.bmp");

				 Tile^ grassTile = gcnew Tile(grassBitmap);
				 Tile^ cobblestoneTile = gcnew Tile(cobblestoneBitmap);
				 Tile^ flowerTile = gcnew Tile(flowerBitmap);

				 tileList->SetTileArrayEntry(0, grassTile);
				 tileList->SetTileArrayEntry(1, cobblestoneTile);
				 tileList->SetTileArrayEntry(2, flowerTile);

				 tileMap = gcnew TileMap(tileList, canvas);
	}
	private: System::Void btnRandom_Click(System::Object^  sender, System::EventArgs^  e) 
	{
				 tileMap->LoadRandomMap(DIFF_TILES);
				 tileMap->DrawMap();
	}
	private: System::Void btnLoadFile_Click(System::Object^  sender, System::EventArgs^  e) 
	{
				 tileMap->LoadMapFromFile("mazeMap_30_20.csv");
				 tileMap->DrawMap();
	}
	};
}
