#include "Program.h"

void Program::Calculate(double intervalBegin, double intervalEnd, double xStep, Function^ function, ListBox^ answersListBox) {
    if (intervalBegin > intervalEnd) {
        throw gcnew System::ArgumentException("������� ��������� ������� ���� ������ �� ����� ���������.");
    }
    if (xStep == 0) {
        throw gcnew System::ArgumentException("���� �� ���� ���������� 0.");
    }

    double y = 0;

    if (xStep > 0) {

        for (double x = intervalBegin; x <= intervalEnd; x += xStep) {
            function->SetX(x);
            try {
                y = function->Calculate();
            }
            catch (std::invalid_argument) {
                answersListBox->Items->Add("f(" + x + ") - �� ����");
                continue;
            }
            answersListBox->Items->Add("f(" + x + ") = " + y);
        }
    }
    else if (xStep < 0) {
        for (double x = intervalEnd; x >= intervalBegin; x += xStep) {
            function->SetX(x);
            try {
                y = function->Calculate();
            }
            catch (std::invalid_argument) {
                answersListBox->Items->Add("f(" + x + ") - �� ����");
                continue;
            }
            answersListBox->Items->Add("f(" + x + ") = " + y);
        }
    }
}