#ifndef DESKTOPITEMDIR_H_
#define DESKTOPITEMDIR_H_
#include <QString>
#include <qlist.h>
#include "DesktopItem.h"

class DesktopItemDir
{
public:
	DesktopItemDir();
	DesktopItemDir(const QString& path);
	~DesktopItemDir();

	bool reload(int& errcode);

	void setPath(const QString& path);
	QString getPath() const;

	QList<DesktopItem*> getItemList() const;

	bool setValue(const QString& fileName, const QString& key, const QString& value);
protected:
	QString mPath;

	QList<DesktopItem*> mItemList;

	void clearItemList();


};

#endif