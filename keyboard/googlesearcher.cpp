#include "googlesearcher.h"
#include "const.h"
GoogleSearcher::GoogleSearcher(QWidget *parent): QObject(parent)
{
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(handleNetworkData(QNetworkReply*)));
}

void GoogleSearcher::search(QString searchText, int sSendingState){
    sendingState=sSendingState;
    switch(sendingState){
    case 1:
        //YouTube
        searchText="YouTube "+searchText;
        break;
    case 2:
        //Filmweb
        searchText="Filmweb "+searchText;
        break;
    }

    QString url = QString(GOOGLE_URL).arg(searchText);
    networkManager.get(QNetworkRequest(QString(url)));
}
bool GoogleSearcher::checkNetworkConnection(){
    QNetworkAccessManager nam;
    QNetworkRequest req(QUrl("http://www.google.com"));
    QNetworkReply *reply = nam.get(req);
    QEventLoop loop;
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    if(reply->bytesAvailable()){
        return true;
    }else{
        QMessageBox *mbox = new QMessageBox;
        mbox->setWindowTitle(tr("UWAGA!"));
        mbox->setText("BRAK POŁĄCZENIA Z INTERNETEM!");
        mbox->setStandardButtons(0);
        mbox->show();
        QTimer::singleShot(2000, mbox, SLOT(hide()));
        return false;
    }
}
void GoogleSearcher::handleNetworkData(QNetworkReply *networkReply)
{
    QUrl url = networkReply->url();

    if (!networkReply->error()) {


        QByteArray response(networkReply->readAll());
        QString string = QString(response);

        QJsonDocument jsonDoc = QJsonDocument::fromJson(string.toUtf8());

        searchResults = jsonDoc.object();

        switch(sendingState){
        case 0:
            //Google
            setHintButtons();
            textEdit->clear();
            textEdit->append(setDisplayListElement(0));
            textEdit->append(setDisplayListElement(1));
            textEdit->append(setDisplayListElement(2));
            textEdit->append(setDisplayListElement(3));

            break;
        case 1:
            //YouTube
            for(int i=0;i<searchResults.value(QString("items")).toArray().count();i++){
                QString link = searchResults.value(QString("items")).toArray()[i].toObject().value("link").toString();
                if(link.contains("youtube",Qt::CaseInsensitive)){
                    QDesktopServices::openUrl(QUrl(link));
                    break;
                }
                else{
                    textEdit->setText("Nie znaleziono poszukiwanej frazy!");
                }
            }
            break;
        case 2:
            //Filmweb
            for(int i=0;i<searchResults.value(QString("items")).toArray().count();i++){
                QString link = searchResults.value(QString("items")).toArray()[i].toObject().value("link").toString();
                if(link.contains("www.filmweb.pl/film/",Qt::CaseInsensitive)){
                    QDesktopServices::openUrl(QUrl(link));
                    break;
                }
                else{
                    textEdit->setText("Nie znaleziono poszukiwanej frazy!");
                }
            }

            break;
        }


    }
    networkReply->deleteLater();
}
QString GoogleSearcher::setDisplayListElement( int index){

    return QString::number(index+1)+". "+ searchResults.value(QString("items")).toArray()[index].toObject().value("title").toString()+"\n"+
            searchResults.value(QString("items")).toArray()[index].toObject().value("link").toString();
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
/*    QDesktopWidget dw;
     int x=dw.width()*0.7;
    int y=dw.height();
     Qt::WindowFlags flags = Qt::WindowStaysOnBottomHint;
qApp->activeWindow()->setFixedSize(x,y);
qApp->activeWindow()->setWindowState(Qt::WindowActive);*/

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
    myList.append(text);
    button->setDisplayList(myList);
}
