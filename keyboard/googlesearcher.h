#ifndef GOOGLESEARCHER_H
#define GOOGLESEARCHER_H

#include <QtWidgets>
#include <QtNetwork>
#include <QObject>
#include <QDesktopServices>
#include <QUrl>
#include"buttonoperator.h"

class QNetworkReply;

using namespace std;
class GoogleSearcher: public QObject
{
    Q_OBJECT

public:
    GoogleSearcher(QWidget *parent = 0);
  //  ~GoogleSearcher();

    void search(QString searchText);
    void openLink(int index);
    void setHintButtonList( vector<ButtonOperator*> sHintButtonList);
    void setTextEdit(QTextEdit *sEdit);
    bool checkNetworkConnection();
public slots:
    void handleNetworkData(QNetworkReply *networkReply);
private:
     QJsonObject searchResults;
     QNetworkAccessManager networkManager;
     void setHintButtons();
     vector<ButtonOperator*> hintButtonList;
     QTextEdit *textEdit;
     void setHintText(QString text,ButtonOperator *button);
     QString setDisplayListElement( int index);

};

#endif // GOOGLESEARCHER_H
