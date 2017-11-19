#include "googlesearcher.h"
#include "const.h"
GoogleSearcher::GoogleSearcher(QWidget *parent): QObject(parent)
{
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(handleNetworkData(QNetworkReply*)));
}

void GoogleSearcher::search(QString searchText){
    QString url = QString(GOOGLE_URL).arg(searchText);
    networkManager.get(QNetworkRequest(QString(url)));
}

void GoogleSearcher::handleNetworkData(QNetworkReply *networkReply)
{
    QUrl url = networkReply->url();

    if (!networkReply->error()) {


        QByteArray response(networkReply->readAll());
        QString string = QString(response);
        //qDebug()<<string;
        //QJsonDocument json=QJsonDocument(response);
        QJsonDocument jsonDoc = QJsonDocument::fromJson(string.toUtf8());

        searchResults = jsonDoc.object();
     //   QJsonValue value = searchResults.value(QString("items")).toArray();
       // QJsonValue value = jo.value(QString("items")).toArray()[0].toObject().value("link");
      //  qDebug()<<value;

       // QDesktopServices::openUrl(QUrl(value.toString()));

        setHintButtons();
        textEdit->clear();

        textEdit->append(setDisplayListElement(0));
        textEdit->append(setDisplayListElement(1));
        textEdit->append(setDisplayListElement(2));
        textEdit->append(setDisplayListElement(3));
    }
    networkReply->deleteLater();
}
QString GoogleSearcher::setDisplayListElement( int index){
    return QString::number(index+1)+". "+ searchResults.value(QString("items")).toArray()[index].toObject().value("title").toString()+"\n"+
            searchResults.value(QString("items")).toArray()[index].toObject().value("link").toString()+"\n";
}

void GoogleSearcher::setHintButtonList( vector<ButtonOperator*> sHintButtonList){
        hintButtonList=sHintButtonList;
}
void GoogleSearcher::setTextEdit(QTextEdit *sEdit){
        textEdit=sEdit;
}
void GoogleSearcher::openLink(int index){
    QJsonValue value = searchResults.value(QString("items")).toArray()[index].toObject().value("link");

     QDesktopServices::openUrl(QUrl(value.toString()));

}
void GoogleSearcher::setHintButtons(){
    setHintText("1",hintButtonList.at(0));
    setHintText("2",hintButtonList.at(1));
    setHintText("3",hintButtonList.at(2));
    setHintText("4",hintButtonList.at(3));

}
void GoogleSearcher::setHintText(QString text,ButtonOperator *button){
    QStringList myList;
    myList.append(text);
    myList.append(text);
    myList.append(text);
    myList.append(text);
    myList.append(text);
    button->setDisplayList(myList);
}
