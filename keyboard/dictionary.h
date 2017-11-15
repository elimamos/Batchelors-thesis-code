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
    Dictionary(QTextEdit *sTextEdit,std::vector<ButtonOperator*> sHintButtonList);
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
    void update(QString chosenLetter);
     void backSpace();

private:
    QString currentWord;
    QString wholeTxt;
    //   int cursorsPosition;
    QTextEdit *textEdit;
    std::vector<ButtonOperator*> hintButtonList;
    map<QString, int> alfabet;
    map<int,QString> reverseAlfabet;
    void setHintText(QString text,ButtonOperator *button);
    struct node * trieTree;
    vector<QChar> printUtil;
    void readDictionaryFile();
    void updateHints();
};

#endif // DICTIONARY_H
