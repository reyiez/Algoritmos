#include "MyForm.h"
using namespace System::Windows::Forms;

void main() {

	Application::EnableVisualStyles();
	Application::Run(gcnew gamejam::MyForm());

}
