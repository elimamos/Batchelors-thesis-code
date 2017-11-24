#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <QCoreApplication>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include<QString>
#include"const.h"
#include<QTextEdit>
#include"buttonoperator.h"

using namespace std;

class Dictionary
{
public:
    Dictionary(QTextEdit *sTextEdit,std::vector<ButtonOperator*> sHintButtonList,std::vector<ButtonOperator*> sButtonList);
    struct node
    {
        struct node * parent;
        struct node * children[ALPHABETS];
        vector<int> occurrences;
    };
    void insertWord(struct node * trieTree, QString word, int index);
    struct node * searchWord(struct node * treeNode, QString word);
    void removeWord(struct node * trieTree, QString word);
    void getSimilarEndings(struct node * trieTree, vector<QChar> word,vector<QString>*endings);
    int getLetterIndex(char alfabet[], char currentLetter);
    int update(QString chosenLetter,int keyboardState);
    void backSpace();
    void useHint(int hintID);
    void moveCursor(QString direction);
    void moveCursorEnd(QString direction);
    void clearTextbox();
    void resetAll();

private:
    QString currentWord;
    int currentWordSart;
    int currentPosition;
    QString wholeTxt;
    QTextEdit *textEdit;
    std::vector<ButtonOperator*> hintButtonList;
    map<QString, int> alfabet;
    map<int,QString> reverseAlfabet;
    struct node * trieTree;
    vector<QChar> printUtil;
    std::vector<ButtonOperator*> buttonList;
    bool isLower;
    void readDictionaryFile();
    void updateHints();
    void clearHints();
    void getCurrentWordStart();
    void getCurrentWord();
    void moveCursor(QString direction, int distance );
    void setHintText(QString text,ButtonOperator *button);
    int switchBetweenKeyboards(QString letter, bool isLower);
    void clearFiftKeyboard();
};

#endif // DICTIONARY_H
