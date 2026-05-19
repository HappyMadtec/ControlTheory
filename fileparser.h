#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <QString>
#include <QVector>
#include <QFile>
#include <QTextStream>


class FileParser
{
public:
    FileParser(const QString &path);

    void parser();
    const QVector<double> getNumerator;
    const QVector<double> getDenumerator ;

    QVector<double> numerator() const;

    QVector<double> denumerator() const;

    QString path() const;

protected:
    QVector<double> m_numerator;
    QVector<double> m_denumerator;
    QString m_path;

};

#endif // FILEPARSER_H
