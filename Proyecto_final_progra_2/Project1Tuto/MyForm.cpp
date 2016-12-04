#include "MyForm.h"
using namespace System; 
using namespace System::Windows::Forms; 
[STAThread] 
void main(array<String^>^ arg) 
{ 
Application::EnableVisualStyles(); Application::SetCompatibleTextRenderingDefault(false); 
Application::Run( gcnew Project1Tuto::MyForm()); //Project 1 es el nombre del proyecto 
}