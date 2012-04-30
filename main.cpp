#include <game.h>
#include <QDesktopWidget>
#include <QApplication>
//main function
using namespace std;

//this function calls the widget and the game class
void center(QWidget &widget)
{
  int x, y;
  int screenWidth;
  int screenHeight;

  int WIDTH = 1000;
  int HEIGHT = 400;


  QDesktopWidget *desktop = QApplication::desktop();

  screenWidth = desktop->width();
  screenHeight = desktop->height();

  x = (screenWidth - WIDTH) / 2;
  y = (screenHeight - HEIGHT) / 2;

  widget.setGeometry(x, y, WIDTH, HEIGHT);
  widget.setFixedSize(WIDTH, HEIGHT);
}

int main(int argc, char *argv[])//int main has two values passed to it, an int and a char pointer
{
  QApplication app(argc, argv);
  game window;
  window.setWindowTitle("Chopper");
  window.show();
  center(window);

  return app.exec();
}
