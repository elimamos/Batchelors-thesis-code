#include "dictionary.h"
#include "const.h"
#include <fstream>

Dictionary::Dictionary(QTextEdit *sTextEdit,std::vector<ButtonOperator*> sHintButtonList)
{
    trieTree= (Dictionary:: node *) calloc(1, sizeof(Dictionary::node));
    textEdit=sTextEdit;
    hintButtonList=sHintButtonList;
    //alfabet;
    alfabet[QString::fromUtf8("a")]=0;
    alfabet[QString::fromUtf8("ą")]=1;
    alfabet[QString::fromUtf8("b")]=2;
    alfabet[QString::fromUtf8("c")]=3;
    alfabet[QString::fromUtf8("ć")]=4;
    alfabet[QString::fromUtf8("d")]=5;
    alfabet[QString::fromUtf8("e")]=6;
    alfabet[QString::fromUtf8("ę")]=7;
    alfabet[QString::fromUtf8("f")]=8;
    alfabet[QString::fromUtf8("g")]=9;
    alfabet[QString::fromUtf8("h")]=10;
    alfabet[QString::fromUtf8("i")]=11;
    alfabet[QString::fromUtf8("j")]=12;
    alfabet[QString::fromUtf8("k")]=13;
    alfabet[QString::fromUtf8("l")]=14;
    alfabet[QString::fromUtf8("ł")]=15;
    alfabet[QString::fromUtf8("m")]=16;
    alfabet[QString::fromUtf8("n")]=17;
    alfabet[QString::fromUtf8("ń")]=18;
    alfabet[QString::fromUtf8("o")]=19;
    alfabet[QString::fromUtf8("ó")]=20;
    alfabet[QString::fromUtf8("p")]=21;
    alfabet[QString::fromUtf8("q")]=22;
    alfabet[QString::fromUtf8("r")]=23;
    alfabet[QString::fromUtf8("s")]=24;
    alfabet[QString::fromUtf8("ś")]-25;
    alfabet[QString::fromUtf8("t")]=26;
    alfabet[QString::fromUtf8("u")]=27;
    alfabet[QString::fromUtf8("v")]=28;
    alfabet[QString::fromUtf8("w")]=29;
    alfabet[QString::fromUtf8("x")]=30;
    alfabet[QString::fromUtf8("y")]=31;
    alfabet[QString::fromUtf8("z")]=32;
    alfabet[QString::fromUtf8("ź")]=33;
    alfabet[QString::fromUtf8("ż")]=34;
    reverseAlfabet[0]="a";
    reverseAlfabet[1]=QString::fromUtf8("ą");
    reverseAlfabet[2]="b";
    reverseAlfabet[3]="c";
    reverseAlfabet[4]=QString::fromUtf8("ć");
    reverseAlfabet[5]="d";
    reverseAlfabet[6]="e";
    reverseAlfabet[7]=QString::fromUtf8("ę");
    reverseAlfabet[8]="f";
    reverseAlfabet[9]="g";
    reverseAlfabet[10]="h";
    reverseAlfabet[11]="i";
    reverseAlfabet[12]="j";
    reverseAlfabet[13]="k";
    reverseAlfabet[14]="l";
    reverseAlfabet[15]=QString::fromUtf8("ł");
    reverseAlfabet[16]="m";
    reverseAlfabet[17]="n";
    reverseAlfabet[18]=QString::fromUtf8("ń");
    reverseAlfabet[19]="o";
    reverseAlfabet[20]=QString::fromUtf8("ó");
    reverseAlfabet[21]="p";
    reverseAlfabet[22]="q";
    reverseAlfabet[23]="r";
    reverseAlfabet[24]="s";
    reverseAlfabet[25]=QString::fromUtf8("ś");
    reverseAlfabet[26]="t";
    reverseAlfabet[27]="u";
    reverseAlfabet[28]="v";
    reverseAlfabet[29]="w";
    reverseAlfabet[30]="x";
    reverseAlfabet[31]="y";
    reverseAlfabet[32]="z";
    reverseAlfabet[33]=QString::fromUtf8("ź");
    reverseAlfabet[34]=QString::fromUtf8("ż");


    currentWord="";
    currentPosition=0;
    wholeTxt="";
    currentWordSart=0;

    readDictionaryFile();

}
void Dictionary::moveCursorEnd(QString direction){
    if(direction=="home"){
        wholeTxt.insert(currentWordSart,currentWord);
        currentPosition=0;

        getCurrentWordStart();
        getCurrentWord();

        textEdit->moveCursor (QTextCursor::Start);
    }else{
        wholeTxt.insert(currentWordSart,currentWord);
        currentPosition=wholeTxt.length();
        getCurrentWordStart();
        getCurrentWord();
        textEdit->moveCursor (QTextCursor::End);

    }

}
void Dictionary::moveCursor(QString direction){
    moveCursor(direction,1);
    if(direction=="right"){
        currentPosition++;


    }
    else{currentPosition--;}

    wholeTxt.insert(currentWordSart,currentWord);
    getCurrentWordStart();
    getCurrentWord();
    wholeTxt.remove(currentWordSart,currentWord.length());

}
void Dictionary::readDictionaryFile(){

    QString filename="/home/elisa/Pulpit/gitBoard/slowa.txt";
    QFile file(filename);
    if(!file.exists()){
        qDebug() << "Nie znaleziono pliku ze słownikiem "<<filename;
    }else{
        qDebug() << filename<<" Wczytuję...";
    }
    QString line;
    //ui->textEdit->clear();
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        int index =0;
        while (!stream.atEnd()){
            line = stream.readLine();
            //ui->textEdit->setText(ui->textEdit->toPlainText()+line+"\n");
            insertWord(trieTree,line,index);
            index++;
            //qDebug() << "linea: "<<line;
        }
        QString lines= QString::number(index);
        qDebug()<<lines;
    }
    file.close();

}
void Dictionary::clearTextbox(){
    wholeTxt="";
    currentWord="";
    currentPosition=0;
    currentWordSart=0;
      textEdit->clear();
}
void Dictionary::update(QString chosenLetter){


    currentWord+=chosenLetter;
    QString currentText=wholeTxt;
    currentText.insert(currentWordSart,currentWord);
    currentPosition++;

    textEdit->clear();
    textEdit->insertPlainText(currentText);
    textEdit->moveCursor (QTextCursor::Start);
    moveCursor("right",currentPosition);

    if( chosenLetter==" "){
        wholeTxt=currentText;
        getCurrentWordStart();
        getCurrentWord();
    }
    updateHints();
}

void Dictionary::updateHints(){

    if(currentWord.size()>MIN_HINT_SIZE){

        Dictionary:: node * trieNode =  searchWord(trieTree, currentWord.toLower());
        if(trieNode!=NULL){
            vector<QString> *endings=new vector<QString>();
            getSimilarEndings(trieNode,printUtil,endings);

            int endingsListLength=endings->size();
            if(endingsListLength>hintButtonList.size()){
                endingsListLength=hintButtonList.size();
            }
            for(int i=0;i<endingsListLength;i++){
                setHintText(currentWord+endings->at(i),hintButtonList.at(i));
            }
            for(int a=endingsListLength;a<hintButtonList.size();a++){
                setHintText("",hintButtonList.at(a));
            }

            return;
        }
    }

    clearHints();
}

void Dictionary::useHint(int hintID){
    if(hintButtonList.at(hintID)->getDisplayList().at(0)!=""){
        QString hintText=hintButtonList.at(hintID)->getDisplayList().at(0)+" ";
        wholeTxt.insert(currentWordSart,hintText);
        currentPosition=currentWordSart+hintText.length();
        currentWordSart=currentPosition;
        currentWord="";

        textEdit->clear();
        textEdit->setText(wholeTxt);
        textEdit->moveCursor (QTextCursor::Start);
        moveCursor("right",currentPosition);

        clearHints();
    }

}
void Dictionary::moveCursor(QString direction, int distance ){

    if(direction== "right"){
        for(int i =0;i <distance;i++){
            textEdit->moveCursor (QTextCursor::Right);
        }
        return;
    }
    if(direction=="left"){
        for(int i =0;i <distance;i++){
            textEdit->moveCursor (QTextCursor::Left);
        }
        return;
    }

}
void  Dictionary::getCurrentWordStart(){
    if(wholeTxt!=""){
        if(currentPosition!=0){
            for(int i = currentPosition-1; i>=0;i--){
                QChar character = wholeTxt.at(i);
                if(!(character.isDigit()||character.isLetter())){
                    currentWordSart=i+1;
                    return;
                }
            }
        }
    }
    currentWordSart=0;
}
void Dictionary::getCurrentWord(){
    currentWord=wholeTxt.mid(currentWordSart,currentPosition-currentWordSart);
}

void Dictionary::clearHints(){
    setHintText("",hintButtonList.at(0));
    setHintText("",hintButtonList.at(1));
    setHintText("",hintButtonList.at(2));
    setHintText("",hintButtonList.at(3));
}

void Dictionary::backSpace(){
    if(currentWord!=""){
        currentWord=currentWord.remove(currentWord.size()-1,1);
        QString currentText=wholeTxt;
        currentText.insert(currentWordSart,currentWord);
        currentPosition--;
        textEdit->clear();
        textEdit->insertPlainText(currentText);

    }
    else{
        currentPosition--;

        currentWord.remove(currentPosition,1);
        getCurrentWordStart();
        getCurrentWord();

        textEdit->clear();
        textEdit->insertPlainText(wholeTxt);
        wholeTxt.remove(currentWordSart,currentWord.length());
    }
    textEdit->moveCursor (QTextCursor::Start);
 moveCursor("right",currentPosition);
    updateHints();
}

void Dictionary::setHintText(QString text,ButtonOperator *button){
    QStringList myList;
    myList.append(text);
    myList.append(text);
    myList.append(text);
    myList.append(text);
    myList.append(text);
    button->setDisplayList(myList);
}
// Inserts a word 'text' into the Trie Tree
// 'trieTree' and marks it's occurence as 'index'.
void Dictionary::insertWord(struct node * trieTree, QString word, int index)
{
    struct node * traverse = trieTree;
    for(int l=0;l<word.length();l++){
        // Until there is something to process

        int ind = alfabet[word.at(l)];
        if (traverse->children[ind] == NULL) {
            // There is no node in 'trieTree' corresponding to this alphabet

            // Allocate using calloc(), so that components are initialised
            traverse->children[ind] = (struct node *) calloc(1, sizeof(struct node));
            traverse->children[ind]->parent = traverse;  // Assigning parent
        }

        traverse = traverse->children[ind];
        // The next alphabet

    }

    traverse->occurrences.push_back(index);      // Mark the occurence of the word
}

// Searches for the occurence of a word in 'trieTree',
// if not found, returns NULL,
// if found, returns poniter pointing to the
// last node of the word in the 'trieTree'
// Complexity -> O(length_of_word_to_be_searched)

Dictionary::node * Dictionary::searchWord(struct node * treeNode, QString word)
{
    struct node * traverse =treeNode;
    // Function is very similar to insert() function
    for(int l=0;l<word.length();l++){

        int ind = alfabet[word.at(l)];
        if (traverse ->children[ind] != NULL) {
            traverse = traverse->children[ind];

        } else {
            return NULL;
        }

    }

    return traverse;
}

// Searches the word first, if not found, does nothing
// if found, deletes the nodes corresponding to the word

void Dictionary::removeWord(struct node * trieTree, QString word)
{
    struct node * trieNode = searchWord(trieTree, word);

    if (trieNode == NULL) {
        // Word not found
        return;
    }

    trieNode->occurrences.pop_back();    // Deleting the occurence

    // 'noChild' indicates if the node is a leaf node
    bool noChild = true;

    int childCount = 0;
    // 'childCount' has the number of children the current node
    // has which actually tells us if the node is associated with
    // another word .This will happen if 'childCount' != 0.
    int i;

    // Checking children of current node
    for (i = 0; i < ALPHABETS; ++i) {
        if (trieNode->children[i] != NULL) {
            noChild = false;
            ++childCount;
        }
    }

    if (!noChild) {
        // The node has children, which means that the word whose
        // occurrence was just removed is a Suffix-Word
        // So, logically no more nodes have to be deleted
        return;
    }

    struct node * parentNode;     // variable to assist in traversal

    while (trieNode->occurrences.size() == 0 && trieNode->parent != NULL && childCount == 0) {
        // trieNode->occurrences.size() -> tells if the node is associated with another word
        //
        // trieNode->parent != NULL -> is the base case sort-of condition, we simply ran
        // out of nodes to be deleted, as we reached the root
        //
        // childCount -> does the same thing as explained in the beginning, to every node
        // we reach

        childCount = 0;
        parentNode = trieNode->parent;

        for (i = 0; i < ALPHABETS; ++i) {
            if (parentNode->children[i] != NULL) {
                if (trieNode == parentNode->children[i]) {
                    // the child node from which we reached
                    // the parent, this is to be deleted
                    parentNode->children[i] = NULL;
                    free(trieNode);
                    trieNode = parentNode;
                } else {
                    ++childCount;
                }
            }
        }
    }
}

// Prints the 'trieTree' in a Pre-Order or a DFS manner
// which automatically results in a Lexicographical Order

void Dictionary::getSimilarEndings(struct node * trieTree, vector<QChar> word,vector<QString>*endings)
{
    int i;
    bool noChild = true;

    if (trieTree->occurrences.size() != 0) {
        // Condition trie_tree->occurrences.size() != 0,
        // is a neccessary and sufficient condition to
        // tell if a node is associated with a word or not

        vector<QChar>::iterator charItr = word.begin();
        QString currentEnding="";
        while (charItr != word.end()) {
            //  qDebug<<charItr;
            currentEnding+=*charItr;
            ++charItr;
        }
        //   qDebug<<" -> @ index -> ";
        endings->push_back(currentEnding);
        vector<int>::iterator counter = trieTree->occurrences.begin();
        // This is to print the occurences of the word

        while (counter != trieTree->occurrences.end()) {
            //qDebug<< *counter;
            ++counter;
        }

        //     qDebug<<"\n";
    }

    for (i = 0; i < ALPHABETS; ++i) {
        if (trieTree->children[i] != NULL) {
            noChild = false;
            QString letter=reverseAlfabet[i];
            word.push_back(letter.data()[0]);   // Select a child

            // and explore everything associated with the cild
            getSimilarEndings(trieTree->children[i], word,endings);
            word.pop_back();
            // Remove the alphabet as we dealt
            // everything associated with it
        }
    }

    //  word.pop_back();
}



