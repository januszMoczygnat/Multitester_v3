#include "fileoperationread.h"

FileOperationRead::FileOperationRead(QObject *parent, QString _fileName) : QObject(parent) {
    fileName = _fileName;
}

void FileOperationRead::readFile() {
    QFile fileToRead(fileName);
    if(fileToRead.open(QIODevice::ReadOnly)) {
        QTextStream readStream(&fileToRead);
        readStream.setAutoDetectUnicode(true);
        readStream.setCodec(QTextCodec::codecForMib(106));
        readStream.setGenerateByteOrderMark(true);
        while(!readStream.atEnd()) {
            dataReaded.append(readStream.readLine());
        }
        fileToRead.close();
        emit sendReadedFile(dataReaded);
        emit sendStatusBarInformation(QString::fromUtf8("Odczytywanie pliku zakończone prawidłowo..."));
    } else {
        emit sendMessageBoxInformation(fileToRead.errorString());
    }
    emit finishReadFile();
}
