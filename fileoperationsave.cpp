#include "fileoperationsave.h"

FileOperationSave::FileOperationSave(QObject *parent, QString _fileName, QStringList _dataToSave) : QObject(parent) {
    fileName = _fileName;
    dataToSave = _dataToSave;
}

void FileOperationSave::saveFile() {
    QFile fileToSave(fileName);
    if(fileToSave.open(QIODevice::WriteOnly)) {
        foreach (QString lineToSave, dataToSave) {
            fileToSave << lineToSave;
        }
        fileToSave.close();
        emit sendStatusBarInformation(QString::fromUtf8("Zakończono zapisywanie pliku..."));
    } else {
        emit sendMessageBoxInformation(fileToSave.errorString());
    }
    emit finishSaveFile();
}
