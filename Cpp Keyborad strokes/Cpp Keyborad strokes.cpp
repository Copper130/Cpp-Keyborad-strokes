#include <Windows.h>
#include <string>
#include <iostream>
#include <map>


void PressKey(WORD key) {
    INPUT input = { 0 };
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = key;
    SendInput(1, &input, sizeof(INPUT));
}

void ReleaseKey(WORD key) {
    INPUT input = { 0 };
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = key;
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));
}

void TypeString(const std::string& text) {
    for (char c : text) {
        SHORT vk = VkKeyScan(c);  // Get the virtual key for the character
        PressKey(vk); 
        ReleaseKey(vk);
    }
}
// Map of each letter and the Hexadecimal code for them
std::map<char, int> keyMap = {
    {'A', 0x41}, {'B', 0x42}, {'C', 0x43}, {'D', 0x44},
    {'E', 0x45}, {'F', 0x46}, {'G', 0x47}, {'H', 0x48},
    {'I', 0x49}, {'J', 0x4A}, {'K', 0x4B}, {'L', 0x4C},
    {'M', 0x4D}, {'N', 0x4E}, {'O', 0x4F}, {'P', 0x50},
    {'Q', 0x51}, {'R', 0x52}, {'S', 0x53}, {'T', 0x54},
    {'U', 0x55}, {'V', 0x56}, {'W', 0x57}, {'X', 0x58},
    {'Y', 0x59}, {'Z', 0x5A}, {' ', 0x20}
};

// Open the notepad
void Windows_Run(std::string run) {
    // Simulate Win + R to open the Run dialog
    PressKey(VK_RWIN); // Press Windows key
    PressKey(keyMap['R']); // Press 'R'
    ReleaseKey(keyMap['R']); // Release 'R'
    ReleaseKey(VK_RWIN); // Release Windows key

    Sleep(300); // Wait for the Run dialog to open

    // Type "notepad" and press Enter
    TypeString(run);
    PressKey(VK_RETURN); // Press Enter
    ReleaseKey(VK_RETURN); // Release Enter
    Sleep(300);// Wait for the Notepad to open
}

// Function to open a URL in the default web browser
void OpenURL(const std::string& url) {
    ShellExecuteA(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

int main() {
    int Seconds{};
    std::cout << "Please enter your wait time in seconds:";
    std::cin >> Seconds;
    int WaitTime_ms = Seconds * 1000;//converts seconds to ms for the wait time
    std::cout << "\nwaiting for " << Seconds << " Seconds" << std::endl;
    Sleep(WaitTime_ms);// Wait for 'WaitTime_ms' which is equal to the entered time by the user
    
    Windows_Run("notepad");
    
    TypeString("This code has just opened the Notepad on your device...");
    PressKey(VK_RETURN);
    ReleaseKey(VK_RETURN);
    Sleep(2000);
    TypeString("I will now type out the whole bee movie script in 2 in a half seconds");
    Sleep(2500);
    PressKey(VK_RETURN);
    ReleaseKey(VK_RETURN);
    TypeString("According to all known laws of aviation,\n");
    Sleep(1000);
    TypeString("there is no way a bee should be able to fly.\n");
    Sleep(1000);
    TypeString("Its wings are too small to get its fat little body off the ground.\n");
    Sleep(1000);
    TypeString("The bee, of course, flies anyway...\n");
    Sleep(1000);
    TypeString("Bees don’t care what humans think is impossible.\n");
    Sleep(1000);
    TypeString("Yellow, black. Yellow, black. Yellow, black. Yellow, black.\n");
    Sleep(1000);
    TypeString("Ooh, black and yellow Let's shake it up a little.\n");
    Sleep(1000);
    TypeString("Barry Breakfast is ready\n");
    Sleep(1000);
    TypeString("Coming Hang on a second. Hello.\n");
    Sleep(1000);
    TypeString("Barry. Adam. Can you believe this is happening. I can't. I'll pick you up.\n");
    Sleep(1000);
    TypeString("Looking sharp. Use the stairs. Your father paid good money for those.\n");
    Sleep(1000);
    TypeString("Sorry. I'm excited.\n");
    Sleep(1000);
    TypeString("Here's the graduate. We're very proud of you, Barry.\n");
    Sleep(2000);
    PressKey(VK_CONTROL);
    PressKey(keyMap['A']);
    ReleaseKey(VK_CONTROL);
    ReleaseKey(keyMap['A']);
    PressKey(VK_BACK);
    ReleaseKey(VK_BACK);
    TypeString("Nah I'm fucking with you");
    Sleep(2000);
    OpenURL("https://www.digitalmzx.com/play/2753/");
    Sleep(1000);
    PressKey(VK_F11);
    ReleaseKey(VK_F11);


    return 0;
}
