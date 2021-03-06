#include "glwidget.h"
#include "ui_glwidget.h"

#include <QtGui>
#include <QtCore>
#include <QtOpenGL>

GLWidget::GLWidget(QGLWidget *parent) :
    QGLWidget(parent),
    ui(new Ui::GLWidget)
{
  //  setCaption("The Opengl for Qt Framework");
    ui->setupUi(this);
    fullscreen = false;

}

//???????????????
void GLWidget::initializeGL()
{
    setGeometry(300, 150, 640, 480);//???????????
    glShadeModel(GL_FLAT);//????????
    glClearColor(0.5, 1.0, 0.2, 0);//???????????????????????????
    glClearDepth(1.0);//??????
    glEnable(GL_DEPTH_TEST);//??????
    glDepthFunc(GL_LEQUAL);//????????
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);//??????
}

void GLWidget::paintGL()
{
    //glClear()????????initializeGL()?????????????????
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();//??????????????????
}

//??????opengl????????????????(?????).
void GLWidget::resizeGL(int width, int height)
{
    if(0 == height)
        height = 1;//??????0
    glViewport(0, 0, (GLint)width, (GLint)height);//????????????????????????Qt?????
    glMatrixMode(GL_PROJECTION);//??????
    glLoadIdentity();//??????????
   // gluPerspective(45.0, (GLfloat)width/(GLfloat)height, 0.1, 100.0);//????????
    //glMatirxMode(GL_MODELVIEW);//??2???????????

    glLoadIdentity();


}
void GLWidget::keyPressEvent(QKeyEvent *e)
{
    switch(e->key())
    {
        //F1?????????????
        case Qt::Key_F1:
            fullscreen = !fullscreen;
            if(fullscreen)
                showFullScreen();
            else
            {
                setGeometry(300, 150, 640, 480);
                showNormal();
            }
            updateGL();
            break;
        //Ese??????
        case Qt::Key_Escape:
            close();
    }
}

GLWidget::~GLWidget()
{
    delete ui;
}
