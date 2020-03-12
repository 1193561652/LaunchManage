#include "DesktopItem.h"
#include <QTextStream>
#include <qfile>

QString DesktopItem::sKeyArray[KEY_COUNT] = {
	"Encoding",
	"Name",			//软件名
	"Comment",		//鼠标移动到图标上显示的名称
	"Exec",			//启动路径
	"Icon",			//图标路径
	"Terminal",		//是否使用终端
	"starttupNotify",
	"Type",			//分类
	"Categories"
};

DesktopItem::DesktopItem()
{

}

DesktopItem::~DesktopItem()
{

}


DesktopItem* DesktopItem::createDesktopItemFromFileInfo(const QFileInfo& fileInfo)
{
	DesktopItem* item = new DesktopItem();
	item->mFileInfo = fileInfo;
	if (item->readFile() == false)
	{
		delete item;
		item = nullptr;
	}
	return item;
}

bool DesktopItem::readFile()
{
	QString filePath = mFileInfo.absoluteFilePath();
	QFile f(filePath);
	if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return false;
	}

	QTextStream txtInput(&f);
	QString lineStr;
	while (!txtInput.atEnd())
	{
		lineStr = txtInput.readLine();
		if (lineStr == "[Desktop Entry]")
		{
			mAvailable = true;
		}
		else
		{
			QRegExp rxlen("\\s*([^\\f\\n\\r\\t\\v]+)\\s*=\\s*([^\\f\\n\\r\\t\\v]+)");
			int pos = rxlen.indexIn(lineStr);
			if (pos > -1)
			{
				QString key = rxlen.cap(1);
				QString value = rxlen.cap(2);
				int index = DesktopItem::findKeyFromString(key);
				if (index != -1)
				{
					mValueArray[index] = value;
				}
			}
		}
	}

	f.close();
	return true;
}

int DesktopItem::findKeyFromString(const QString key)
{
	int index = -1;
	for (int i = 0; i < KEY_COUNT; i++)
	{
		if (DesktopItem::sKeyArray[i] == key)
		{
			index = i;
			break;
		}
	}
	return index;
}

QString DesktopItem::findKeyFromIndex(const int index)
{
	if (index < KEY_COUNT)
		return DesktopItem::sKeyArray[index];
	return QString();
}

QString DesktopItem::getFileName() const
{
	return mFileInfo.fileName();
}

QString DesktopItem::getValueFromIndex(const int index) const
{
	if (index < KEY_COUNT)
		return mValueArray[index];
	return QString();
}

bool DesktopItem::setValue(const QString& key, const QString value)
{
	int index = DesktopItem::findKeyFromString(key);
	if (index != -1)
	{
		if (mValueArray[index] != value)
		{
			mValueArray[index] = value;
		}
	}
	return true;
}

bool DesktopItem::save()
{
	QString filePath = mFileInfo.absoluteFilePath();
	QFile f(filePath);
	if (!f.open(QIODevice::ReadWrite | QIODevice::Text))
	{
		return false;
	}

	QList<QString> listContent;
	QTextStream txtInput(&f);
	QString lineStr;
	while (!txtInput.atEnd())
	{
		lineStr = txtInput.readLine();
		QRegExp rxlen("\\s*([^\\f\\n\\r\\t\\v]+)\\s*=\\s*([^\\f\\n\\r\\t\\v]+)");
		int pos = rxlen.indexIn(lineStr);
		if (pos > -1)
		{
			QString key = rxlen.cap(1);
			QString value = rxlen.cap(2);
			int index = DesktopItem::findKeyFromString(key);
			if (index != -1)
			{
				listContent.push_back(key + "=" + mValueArray[index]);
			}
			else
			{
				listContent.push_back(lineStr);
			}
		}
		else
		{
			listContent.push_back(lineStr);
		}
	}

	txtInput.seek(0);
	for (auto it = listContent.begin(); it != listContent.end(); it++)
	{
		txtInput << (*it) << "\n";
	}
	f.flush();
	f.close();
}