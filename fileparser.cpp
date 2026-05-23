#include "fileparser.h"

FileParser::FileParser(const QString &path) : m_path(path) {
    parser();
}

void FileParser::parser()
{
    QFile file(m_path);
    if (file.exists())
    {
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file);
            while (!in.atEnd()){
                QString line = in.readLine();
                if (line.startsWith(":"))
                {
                    QStringList data = line.mid(1).trimmed().split(" ", Qt::SkipEmptyParts);
                    for(const QString &item : std::as_const(data))
                        m_numerator.append(item.toDouble());
                }

                if (line.startsWith("::"))
                {
                    QStringList data = line.mid(2).trimmed().split(" ", Qt::SkipEmptyParts);
                    for(const QString &item : std::as_const(data))
                        m_denumerator.append(item.toDouble());
                }
            }
        }
    }
}

QVector<double> FileParser::numerator() const
{
    return m_numerator;
}

QVector<double> FileParser::denumerator() const
{
    return m_denumerator;
}

QString FileParser::path() const
{
    return m_path;
}

