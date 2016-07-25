#pragma once

namespace CanvasDrawing {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CanvasForm
	/// </summary>
	public ref class CanvasForm : public System::Windows::Forms::Form
	{
	public:
		CanvasForm(void)
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
		~CanvasForm()
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
		/// <summary>
		/// Required designer variable.
		/// </summary>
		Graphics^ mainCanvas;
		int randX = 0, randY = 0;
		Random^ rand;

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
			this->timer1->Tick += gcnew System::EventHandler(this, &CanvasForm::timer1_Tick);
			// 
			// CanvasForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(671, 538);
			this->Name = L"CanvasForm";
			this->Text = L"CanvasForm";
			this->Load += gcnew System::EventHandler(this, &CanvasForm::CanvasForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void CanvasForm_Load(System::Object^  sender, System::EventArgs^  e) 
	{
				 mainCanvas = CreateGraphics();
				 rand = gcnew Random();
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
				 randX = rand->Next(100);
				 randY = rand->Next(100);

				 Brush^ greenBrush = gcnew SolidBrush(Color::Green);
				 mainCanvas->FillEllipse(greenBrush, randX, randY, 10, 10);
	}
	};
}
