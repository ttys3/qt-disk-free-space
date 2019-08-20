#include <QStorageInfo>
#include <QDir>
#include <QDebug>
//https://wiki.qt.io/Getting_Started_on_the_Commandline
   
qint64 GiB = 1024*1024*1024;

void printRootDriveInfo(QStorageInfo storage) {
   qDebug() << storage.rootPath();
   if (storage.isReadOnly())
       qDebug() << "isReadOnly:" << storage.isReadOnly();

   qDebug() << "name:" << storage.name();
   qDebug() << "filesystem type:" << storage.fileSystemType();
   qDebug() << "size:" << storage.bytesTotal()/GiB << "GB";
   qDebug() << "free space:" << storage.bytesAvailable()/GiB << "GB";
}

int main(int argc, char *argv[]) {
     qDebug() << "hello beautiful world!" << endl << endl;
    QStorageInfo storage = QStorageInfo::root();
    printRootDriveInfo(storage);

    qDebug() << "\n";

    QStorageInfo home = QStorageInfo(QDir("/downloads/"));
    printRootDriveInfo(home);

    qDebug() << "\n" << "---------------- mountedVolumes: " << "\n";

    QList<QStorageInfo> list = QStorageInfo::mountedVolumes();
    qDebug() << "Volume Num: " << list.size();
    for(QStorageInfo& si : list)
    {
        qDebug() << "Name: " << si.name();
        qDebug() << "Block Size: " << si.blockSize();
        qDebug() << "GB Avaliable: " << si.bytesAvailable()/GiB << "GB";
        qDebug() << "GB Free: " << si.bytesFree()/GiB << "GB";
        qDebug() << "GB Total: " << si.bytesTotal()/GiB << "GB";
        qDebug() << "Display Name: " << si.displayName();
        qDebug() << "File System Type: " << si.fileSystemType();
        qDebug() << "Is ReadOnly: " << si.isReadOnly();
        qDebug() << "Is Root: " << si.isRoot();
	qDebug() << "\n";
    }
    return 0;
}
