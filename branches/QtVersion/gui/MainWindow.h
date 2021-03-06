/*
  Copyright (C) 2008-2010 Laurent Cozic. All right reserved.
  Use of this source code is governed by a GNU/GPL license that can be
  found in the LICENSE file.
*/

#include <stable.h>

#ifndef MainWindow_H
#define MainWindow_H

#include <MainScene.h>
#include <GraphicsWindow.h>

namespace appetizer {

class MainWindow : public GraphicsWindow {

  Q_OBJECT

public:

  MainWindow();
  QPixmap* getWindowPixmap();

public slots:

  void scene_sceneRectChanged(const QRectF& rect);
  void backgroundSprite_mousePressed();
  void backgroundSprite_mouseMoved();

private:

  struct MoveDragData {
    QPoint startMouse;
    QPoint startPos;
  };

  QGraphicsView* view_;
  MainScene* scene_;
  MoveDragData moveDragData_;
  QPixmap* windowPixmap_;

protected:

  void resizeEvent(QResizeEvent* event);
  void closeEvent ( QCloseEvent * event ) ;

};

}
#endif // MainWindow_H
