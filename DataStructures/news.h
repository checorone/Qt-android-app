#ifndef NEWS_H
#define NEWS_H

#include<QString>
#include<QDate>
#include<QPixmap>

class News
{
private:
    QString label;
    QString shortText;
    QString fullText;
    QPixmap picture;
    QDate date;
    QString game;
    QString link;
public:
    News(const QString & label, const QString & shortText,
         const QString & fullText, const QPixmap & picture,
         const QDate & date, const QString & game,
         const QString & link);
    ~News() {}

    QString getShortText() const { return shortText; }
    QString getFullText() const { return fullText; }
    QString getLabel() const { return label; }
    QString getLink() const { return link; }
    QString getGame() const { return game; }
    QPixmap getPic() const { return picture; }
    QDate getDate() const { return date; }
};

#endif // NEWS_H
