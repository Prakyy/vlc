#ifndef DARKMODE_HPP
#define DARKMODE_HPP

#include <windows.h>
#include <dwmapi.h>

#ifndef DWMWA_USE_IMMERSIVE_DARK_MODE
#define DWMWA_USE_IMMERSIVE_DARK_MODE 20
#endif

#include "qt.hpp"
#include <QSettings>

// Declare the global theme variable
extern QString theme;  // Declare the variable as extern

void setDarkTitlebar(HWND hwnd);
void checkAndSetDarkMode(HWND hwnd, intf_thread_t *p_intf);

#endif
