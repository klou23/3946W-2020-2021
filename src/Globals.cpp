#include "Globals.hpp"
#include "main.h"
#include "Constants.hpp"
#include "Initialize.hpp"
#include "LvglOps.hpp"
#include "LvglFuncs.hpp"

int autonColor = AUTON_RED;
int autonNum = 0;

void print(string s){
    logText += s + "\n";
    lv_label_set_text(logLabel, logText.c_str());
    lv_page_scroll_ver(logPage, -10000);
}

void printSpecial(string s, string color){
    logText += color + s + "#\n";
    lv_label_set_text(logLabel, logText.c_str());
    lv_page_scroll_ver(logPage, -10000);
}
