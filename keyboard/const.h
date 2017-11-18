#include <QString>
#ifndef CONST_H
#define CONST_H
const int TIMER_TICK=200;
const int TICK_COUNTER=8;
const int BUTTON_COUNT=3;
const int CAPS_ID=20;
const int SHIFT_ID=30;
const int PL_ID=42;
const int SPECIAL_ID=40;
//if no ctrl and alt added - else BACK_ID = 46 and anything after ID +2
const int BACK_ID=44;
const int SEND_ID=45;
const int END_ID=46;
const int CLEAR_ID=47;
const int HOME_ID=48;
const int LEFT_ID=49;
const int UP_ID=50;
const int RIGHT_ID=51;
const int DOWN_ID=52;
const int TXT2SPEACH_ID=53;
const int MENU_ID=54;
const int HINT1_ID=55;
const int HINT2_ID=56;
const int HINT3_ID=57;
const int HINT4_ID=58;
const int LEAVE_ID=59;
const int STOP_ID=60;


const int MIN_HINT_SIZE=1;
const int ALPHABETS= 35;

const int MAX_WORD_SIZE= 25;
const int MAX_CHAR_EDITTEXT_LINE=100;
const QString GOOGLE_URL= "https://www.googleapis.com/customsearch/v1?key=AIzaSyCYJXxtbDUUUGUVH1feRH2K9R8LjAVLu2g&cx=003632838831069368478:eoxvklfvqlu&q=%1";
#endif // CONST_H
