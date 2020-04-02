#ifndef DESKTOPITEM_H_
#define DESKTOPITEM_H_
#include <qfileinfo.h>

#define KEY_COUNT	9

class DesktopItem
{
public:
	DesktopItem();
	~DesktopItem();
	static DesktopItem* createDesktopItemFromFileInfo(const QFileInfo& fileInfo);

	QString getFileName() const;
	QString getValueFromIndex(const int index) const;
	bool setValue(const QString& key, const QString value);
	bool save();

	static int findKeyFromString(const QString key);
	static QString findKeyFromIndex(const int index);
	friend bool operator==(const DesktopItem* item, const QString& fileName)
	{
		return item->getFileName() == fileName;
	}
protected:
	static QString sKeyArray[KEY_COUNT];
	QString	mValueArray[KEY_COUNT];

	QFileInfo	mFileInfo;

	bool readFile();

	bool mAvailable = false;
};

#endif
