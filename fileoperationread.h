#ifndef FILEOPERATIONREAD_H
#define FILEOPERATIONREAD_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QTextCodec>

class FileOperationRead : public QObject {
    Q_OBJECT
public:
    explicit FileOperationRead(QObject *parent = nullptr, QString _fileName = QString());

private:
    QStringList dataReaded;
    QString fileName;

public slots:
    void readFile();

signals:
    void sendStatusBarInformation(QString);
    void sendMessageBoxInformation(QString);
    void sendReadedFile(QStringList);
    void finishReadFile();
};

#endif // FILEOPERATIONREAD_H
