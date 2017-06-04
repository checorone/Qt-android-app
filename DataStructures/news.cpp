#include "news.h"

News::News(const QString & label, const QString & shortText,
           const QString & fullText, const QPixmap & picture,
           const QDate & date, const QString & game,
           const QString & link)

    : label(label), shortText(shortText),
      fullText(fullText), picture(picture),
      date(date), game(game), link(link)
{

}

