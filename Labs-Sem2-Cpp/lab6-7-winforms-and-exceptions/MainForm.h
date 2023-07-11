#pragma once

#include <Windows.h>
#include <string>
#include "Function.h"
#include "Program.h"
namespace Lab67 {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;

    public ref class MainForm : public System::Windows::Forms::Form {
    private:
        

        System::Windows::Forms::Label^ resultLabel;
        System::Windows::Forms::ListBox^ answersListBox;

    private: System::Windows::Forms::PictureBox^ functionPictureBox;
    private: System::Windows::Forms::Label^ headerLabel;
    private: System::Windows::Forms::Label^ intervalLabel;
    private: System::Windows::Forms::TextBox^ intervalBeginTextBox;

    private: System::Windows::Forms::TextBox^ intervalEndTextBox;
    private: System::Windows::Forms::Label^ IntervalXLabel;

    private: System::Windows::Forms::Label^ xStepLabel;
    private: System::Windows::Forms::TextBox^ xStepTextBox;

    private: System::Windows::Forms::Button^ calculateButton;

    public:
        MainForm() {
            
            InitializeComponent();
          
        }

    private:
        void InitializeComponent() {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
            this->resultLabel = (gcnew System::Windows::Forms::Label());
            this->answersListBox = (gcnew System::Windows::Forms::ListBox());
            this->functionPictureBox = (gcnew System::Windows::Forms::PictureBox());
            this->headerLabel = (gcnew System::Windows::Forms::Label());
            this->intervalLabel = (gcnew System::Windows::Forms::Label());
            this->intervalBeginTextBox = (gcnew System::Windows::Forms::TextBox());
            this->intervalEndTextBox = (gcnew System::Windows::Forms::TextBox());
            this->IntervalXLabel = (gcnew System::Windows::Forms::Label());
            this->calculateButton = (gcnew System::Windows::Forms::Button());
            this->xStepLabel = (gcnew System::Windows::Forms::Label());
            this->xStepTextBox = (gcnew System::Windows::Forms::TextBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->functionPictureBox))->BeginInit();
            this->SuspendLayout();
            // 
            // resultLabel
            // 
            this->resultLabel->AutoSize = true;
            this->resultLabel->Location = System::Drawing::Point(8, 8);
            this->resultLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->resultLabel->Name = L"resultLabel";
            this->resultLabel->Size = System::Drawing::Size(0, 13);
            this->resultLabel->TabIndex = 0;
            // 
            // answersListBox
            // 
            this->answersListBox->FormattingEnabled = true;
            this->answersListBox->Location = System::Drawing::Point(252, 36);
            this->answersListBox->Name = L"answersListBox";
            this->answersListBox->Size = System::Drawing::Size(273, 160);
            this->answersListBox->TabIndex = 10;
            // 
            // functionPictureBox
            // 
            this->functionPictureBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->functionPictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"functionPictureBox.Image")));
            this->functionPictureBox->ImageLocation = L"";
            this->functionPictureBox->Location = System::Drawing::Point(37, 51);
            this->functionPictureBox->Name = L"functionPictureBox";
            this->functionPictureBox->Size = System::Drawing::Size(147, 45);
            this->functionPictureBox->TabIndex = 3;
            this->functionPictureBox->TabStop = false;
            // 
            // headerLabel
            // 
            this->headerLabel->AutoSize = true;
            this->headerLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->headerLabel->Location = System::Drawing::Point(6, 9);
            this->headerLabel->Name = L"headerLabel";
            this->headerLabel->Size = System::Drawing::Size(477, 24);
            this->headerLabel->TabIndex = 4;
            this->headerLabel->Text = L"Обчислення значень функцій на заданому проміжку";
            // 
            // intervalLabel
            // 
            this->intervalLabel->AutoSize = true;
            this->intervalLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->intervalLabel->Location = System::Drawing::Point(34, 109);
            this->intervalLabel->Name = L"intervalLabel";
            this->intervalLabel->Size = System::Drawing::Size(156, 17);
            this->intervalLabel->TabIndex = 5;
            this->intervalLabel->Text = L"Введіть інтервал для x";
            // 
            // intervalBeginTextBox
            // 
            this->intervalBeginTextBox->Location = System::Drawing::Point(10, 131);
            this->intervalBeginTextBox->Name = L"intervalBeginTextBox";
            this->intervalBeginTextBox->Size = System::Drawing::Size(72, 20);
            this->intervalBeginTextBox->TabIndex = 6;
            // 
            // intervalEndTextBox
            // 
            this->intervalEndTextBox->Location = System::Drawing::Point(148, 129);
            this->intervalEndTextBox->Name = L"intervalEndTextBox";
            this->intervalEndTextBox->Size = System::Drawing::Size(72, 20);
            this->intervalEndTextBox->TabIndex = 7;
            // 
            // IntervalXLabel
            // 
            this->IntervalXLabel->AutoSize = true;
            this->IntervalXLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->IntervalXLabel->Location = System::Drawing::Point(88, 129);
            this->IntervalXLabel->Name = L"IntervalXLabel";
            this->IntervalXLabel->Size = System::Drawing::Size(54, 20);
            this->IntervalXLabel->TabIndex = 8;
            this->IntervalXLabel->Text = L"≤  X  ≤";
            // 
            // calculateButton
            // 
            this->calculateButton->Location = System::Drawing::Point(148, 166);
            this->calculateButton->Name = L"calculateButton";
            this->calculateButton->Size = System::Drawing::Size(75, 23);
            this->calculateButton->TabIndex = 9;
            this->calculateButton->Text = L"Обчислити";
            this->calculateButton->UseVisualStyleBackColor = true;
            this->calculateButton->Click += gcnew System::EventHandler(this, &MainForm::calculateButton_Click);
            // 
            // xStepLabel
            // 
            this->xStepLabel->AutoSize = true;
            this->xStepLabel->Location = System::Drawing::Point(12, 171);
            this->xStepLabel->Name = L"xStepLabel";
            this->xStepLabel->Size = System::Drawing::Size(45, 13);
            this->xStepLabel->TabIndex = 12;
            this->xStepLabel->Text = L"Крок X:";
            // 
            // xStepTextBox
            // 
            this->xStepTextBox->Location = System::Drawing::Point(63, 168);
            this->xStepTextBox->Name = L"xStepTextBox";
            this->xStepTextBox->Size = System::Drawing::Size(72, 20);
            this->xStepTextBox->TabIndex = 13;
            // 
            // MainForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(537, 207);
            this->Controls->Add(this->xStepTextBox);
            this->Controls->Add(this->xStepLabel);
            this->Controls->Add(this->answersListBox);
            this->Controls->Add(this->calculateButton);
            this->Controls->Add(this->IntervalXLabel);
            this->Controls->Add(this->intervalEndTextBox);
            this->Controls->Add(this->intervalBeginTextBox);
            this->Controls->Add(this->intervalLabel);
            this->Controls->Add(this->headerLabel);
            this->Controls->Add(this->functionPictureBox);
            this->Controls->Add(this->resultLabel);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->Margin = System::Windows::Forms::Padding(2);
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"MainForm";
            this->Text = L"Function Calculator";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->functionPictureBox))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
        // InitializeComponent END

        // calculate button handler
        System::Void calculateButton_Click(System::Object^ sender, System::EventArgs^ e) {
            try {
                double intervalBegin = System::Convert::ToDouble(intervalBeginTextBox->Text);
                double intervalEnd = System::Convert::ToDouble(intervalEndTextBox->Text);
                double xStep = System::Convert::ToDouble(xStepTextBox->Text);

                answersListBox->Items->Clear();

                Function^ function = gcnew Function();

                Program::Calculate(intervalBegin, intervalEnd, xStep, function, answersListBox);
            }
            catch (System::ArgumentException^ ex) {
                MessageBox::Show(ex->Message, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
            catch (System::FormatException^) {
                MessageBox::Show("Введено некоректні значення", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
            catch (...) {
                MessageBox::Show("Виникла помилка", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }


      
};
}
