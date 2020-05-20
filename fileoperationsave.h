#ifndef FILEOPERATIONSAVE_H
#define FILEOPERATIONSAVE_H

#include <QObject>
#include <QFile>

class FileOperationSave : public QObject
{
    Q_OBJECT
public:
    explicit FileOperationSave(QObject *parent = nullptr, QString _fileName = QString() ,QStringList _dataToSave = QStringList());

private:
    QStringList dataToSave;
    QString fileName;

public slots:
    void saveFile();

signals:
    void sendStatusBarInformation(QString);
    void sendMessageBoxInformation(QString);
    void finishSaveFile();
};

#endif // FILEOPERATIONSAVE_H
