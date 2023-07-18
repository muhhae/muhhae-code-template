#ifndef _APP_HPP
#define _APP_HPP

#include <wx/wx.h>

#include "MainFrame.hpp"

class App : public wxApp
{
    public:
        bool OnInit();
};

#endif