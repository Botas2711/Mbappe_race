#include "MyForm.h"
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;
using namespace Mbapperace;

int main() {
	srand(time(NULL));
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm());
}
