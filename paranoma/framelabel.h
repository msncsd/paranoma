#ifndef FRAMELABEL_H
#define FRAMELABEL_H

#include <QLabel>

class frameLabel : public QLabel
{
Q_OBJECT

public:
    explicit frameLabel( const QString& text ="", QWidget * parent = 0 );
    ~frameLabel();

signals:
    void clicked();

protected:
    void mousePressEvent ( QMouseEvent * event ) ;

};

#endif // FRAMELABEL_H
