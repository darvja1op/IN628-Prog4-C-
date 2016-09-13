#pragma once

#include "Creature.h"
#include "Thing.h"

namespace FiniteStateMachineCreatures {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		array<Thing^>^ foodArray;
		array<Thing^>^ obstacleArray;
		array<Creature^>^ creatureArray;
		Graphics^ offScreenCanvas;
	private: System::Windows::Forms::Panel^  panel1;
			 Graphics^ mainCanvas;
			 Random^ rGen;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(13, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(13, 43);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(976, 562);
			this->panel1->TabIndex = 1;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1001, 617);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
				 //enable timer
				 timer1->Enabled = true;
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) 
	{
				 //double buffer
				 mainCanvas = panel1->CreateGraphics();

				 rGen = gcnew Random();
				 int startWorldWidth = panel1->Width;
				 int startWorldHeight = panel1->Height;

				 //create creatures and things
				 foodArray = gcnew array<Thing^>(20);
				 for (int i = 0; i < foodArray->Length; i++)
				 {
					 Thing^ newFood = gcnew Thing(offScreenCanvas, rGen, startWorldWidth, startWorldHeight, "images/cookie.jpg");
					 foodArray[i] = newFood;
				 }

				 obstacleArray = gcnew array<Thing^>(20);
				 for (int i = 0; i < obstacleArray->Length; i++)
				 {
					 Thing^ newObstacle = gcnew Thing(offScreenCanvas, rGen, startWorldWidth, startWorldHeight, "images/gemstone.jpg");
					 obstacleArray[i] = newObstacle;
				 }
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
				 //update creature state
				 for each (Thing^ creature in creatureArray)
				 {
					 creature->
				 }
				 //make creatures perform their actions
	}
	};
}
