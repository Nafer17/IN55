#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "geometryengine.h"

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include <QQuaternion>
#include <QVector2D>
#include <QBasicTimer>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>

#include <QMouseEvent>
#include <QKeyEvent>
#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <QCheckBox>
#include <QGroupBox>
#include <QSignalMapper>
#include <string>
#include <math.h>

#include "structures/structs.h"
#include "globals.h"


class GeometryEngine;

class MainWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget() override;

public slots:
    void redrawMorel(void);
    void setLight(bool state);
    void redrawElements(bool state);

protected:
    void mousePressEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;
    void wheelEvent(QWheelEvent *e) override;
    void timerEvent(QTimerEvent *e) override;
    void keyPressEvent(QKeyEvent *) override;
    void keyReleaseEvent(QKeyEvent *) override;

    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void initShaders();
    void initTextures();

    void drawAll();

    QSlider* addSlider(double value, double min, double max);
    QLabel* addLabel(QString text);
    void addGlobalBox(bool state, QLayout* layout);

private:
    QBasicTimer timer;
    QOpenGLShaderProgram program;
    GeometryEngine *geometries;
    QOpenGLTexture *texture;

    QMatrix4x4 projection;

    QVector2D mousePressPosition;
    QVector3D rotationAxis;
    qreal angularSpeed;
    QQuaternion rotation;

    QVector3D userTranslation;
    bool isZPressed = false;
    bool isQPressed = false;
    bool isSPressed = false;
    bool isDPressed = false;


    QVector<SliderParameters> sliders;
    QVector<QCheckBox*> lightBoxes;
    QVector<QCheckBox*> globalsBoxes;

    QVector2D previousMousePosition;
};

#endif // MAINWIDGET_H
