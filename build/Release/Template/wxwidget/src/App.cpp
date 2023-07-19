#include "include/App.hpp"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
    MainFrame* mainFrame = new MainFrame("Segitiga GUI");
    mainFrame->SetClientSize(640, 480);
    mainFrame->Center();
    mainFrame->Show();
    return true;
}