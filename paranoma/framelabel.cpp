#include "framelabel.h"


frameLabel::frameLabel( const QString& text, QWidget * parent ) :
    QLabel(parent)

  {
      setText(text);
  }

  frameLabel::~frameLabel()
  {
  }

  void frameLabel::mousePressEvent ( QMouseEvent * event )

  {
      emit clicked();
  }
