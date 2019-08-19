#include <QStorageInfo>
#include <QDir>
#include <QDebug>
//https://wiki.qt.io/Getting_Started_on_the_Commandline

void printRootDriveInfo(QStorageInfo storage) {
   qDebug() << storage.rootPath();
   if (storage.isReadOnly())
       qDebug() << "isReadOnly:" << storage.isReadOnly();

   qDebug() << "name:" << storage.name();
   qDebug() << "filesystem type:" << storage.fileSystemType();
   qDebug() << "size:" << storage.bytesTotal()/1024/1024/1024 << "GB";
   qDebug() << "free space:" << storage.bytesAvailable()/1024/1024/1024 << "GB";
}

int main(int argc, char *argv[]) {
    qDebug() << "hello beautiful world!" << endl << endl;
    QStorageInfo storage = QStorageInfo::root();
    printRootDriveInfo(storage);

    qDebug() << "\n";

    QStorageInfo home = QStorageInfo(QDir("/downloads/"));
    printRootDriveInfo(home);
    return 0;
}