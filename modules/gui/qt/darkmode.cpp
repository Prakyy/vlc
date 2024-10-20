#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "darkmode.hpp"

typedef HRESULT (WINAPI *DwmSetWindowAttributeFunc)(HWND, DWORD, LPCVOID, DWORD);

// Define the global theme variable
QString theme = "None";  // Initilaize the theme variable as "None"

void setDarkTitlebar(HWND hwnd) {
    // If the theme is "QtDark", set the dark mode for the title bar
    if (theme == "QtDark") {
        // Load dwmapi.dll
        HMODULE hDwmapi = LoadLibrary(L"dwmapi.dll");
        if (hDwmapi) {
            // Get the address of the DwmSetWindowAttribute function
            DwmSetWindowAttributeFunc pDwmSetWindowAttribute = 
                (DwmSetWindowAttributeFunc)GetProcAddress(hDwmapi, "DwmSetWindowAttribute");

            if (pDwmSetWindowAttribute) {
                // Enable dark mode for the title bar
                BOOL darkMode = TRUE;
                HRESULT hr = pDwmSetWindowAttribute(hwnd, DWMWA_USE_IMMERSIVE_DARK_MODE, &darkMode, sizeof(darkMode));
                // Handle HRESULT hr if needed
            }
            FreeLibrary(hDwmapi);
        }
    }
}
void checkAndSetDarkMode(HWND hwnd, intf_thread_t *p_intf) {
    // If theme is empty, fetch it from the settings
    if (theme == "None") {
        theme = getSettings()->value("MainWindow/QtStyle", "").toString();
    }
    setDarkTitlebar(hwnd);
}
