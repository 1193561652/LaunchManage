#include "DesktopItemDir.h"
#include <qdir.h>

DesktopItemDir::DesktopItemDir()
{
}
DesktopItemDir::DesktopItemDir(const QString& path)
{
    mPath = path;
}

DesktopItemDir::~DesktopItemDir()
{
    clearItemList();
}

void DesktopItemDir::clearItemList()
{
    for (int i = 0; i < mItemList.count(); i++)
    {
        delete mItemList[i];
    }
    mItemList.clear();
}

void DesktopItemDir::setPath(const QString& path)
{
    mPath = path;
}
QString DesktopItemDir::getPath() const
{
    return mPath;
}

bool DesktopItemDir::reload(int& errcode)
{
    clearItemList();

    QDir dir(mPath);
    if (!dir.exists())
    {
        errcode = 1;
        return false;
    }
    dir.setFilter(QDir::Files);
    QFileInfoList fileList = dir.entryInfoList();
    for (int i = 0; i < fileList.count(); i++)
    {
        const QFileInfo& fileInfo = fileList[i];
        QString fileName = fileInfo.fileName();
        QString suffix = fileInfo.suffix();
        if (QString::compare(suffix, "desktop") == 0)
        {
            DesktopItem* item = DesktopItem::createDesktopItemFromFileInfo(fileInfo);
            if (item != nullptr)
            {
                mItemList.push_back(item);
            }
        }
    }

    return true;
}

QList<DesktopItem*> DesktopItemDir::getItemList() const
{
    return mItemList;
}

bool DesktopItemDir::setValue(const QString& fileName, const QString& key, const QString& value)
{
    QList<DesktopItem*>::iterator it = std::find(mItemList.begin(), mItemList.end(), fileName);
    if (it != mItemList.end())
    {
        DesktopItem* item = *it;
        item->setValue(key, value);
        return true;
    }
    return false;
}

void DesktopItemDir::save(const QString& fileName)
{
    QList<DesktopItem*>::iterator it = std::find(mItemList.begin(), mItemList.end(), fileName);
    if (it != mItemList.end())
    {
        DesktopItem* item = *it;
        item->save();
    }
}
