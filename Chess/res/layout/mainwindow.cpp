#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow :: MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->widgetGLWidget->setPlayer1camera = true;
    ui->widgetGLWidget->setPlayer2camera = false;
    ui->widgetGLWidget->setCrowdCamera = false;
    ui->widgetGLWidget->setPawnCamera = false;
}

MainWindow :: ~MainWindow()
{
    delete ui;
}

void MainWindow :: updateView()
{
    if (ui->radioButtonPlayer1->isChecked()) {
        ui->widgetGLWidget->setPlayer1camera = true;
        ui->widgetGLWidget->setPlayer2camera = false;
        ui->widgetGLWidget->setCrowdCamera = false;
        ui->widgetGLWidget->setPawnCamera = false;

        ui->doubleSpinBoxEyeX->setEnabled(false);
        ui->doubleSpinBoxEyeY->setEnabled(false);
        ui->doubleSpinBoxEyeZ->setEnabled(false);

        ui->doubleSpinBoxLookAtX->setEnabled(false);
        ui->doubleSpinBoxLookAtY->setEnabled(false);
        ui->doubleSpinBoxLookAtZ->setEnabled(false);

        ui->doubleSpinBoxViewUpX->setEnabled(false);
        ui->doubleSpinBoxViewUpY->setEnabled(false);
        ui->doubleSpinBoxViewUpZ->setEnabled(false);

        ui->horizontalSliderRotationAngle->setEnabled(false);
        ui->spinBoxRotationAngle->setEnabled(false);

        ui->widgetGLWidget->updateGL();
    }
    else if (ui->radioButtonPlayer2->isChecked()) {
        ui->widgetGLWidget->setPlayer1camera = false;
        ui->widgetGLWidget->setPlayer2camera = true;
        ui->widgetGLWidget->setCrowdCamera = false;
        ui->widgetGLWidget->setPawnCamera = false;

        ui->doubleSpinBoxEyeX->setEnabled(false);
        ui->doubleSpinBoxEyeY->setEnabled(false);
        ui->doubleSpinBoxEyeZ->setEnabled(false);

        ui->doubleSpinBoxLookAtX->setEnabled(false);
        ui->doubleSpinBoxLookAtY->setEnabled(false);
        ui->doubleSpinBoxLookAtZ->setEnabled(false);

        ui->doubleSpinBoxViewUpX->setEnabled(false);
        ui->doubleSpinBoxViewUpY->setEnabled(false);
        ui->doubleSpinBoxViewUpZ->setEnabled(false);

        ui->horizontalSliderRotationAngle->setEnabled(false);
        ui->spinBoxRotationAngle->setEnabled(false);

        ui->widgetGLWidget->updateGL();
    }
    else if (ui->radioButtonCrowd->isChecked()) {
        ui->widgetGLWidget->setPlayer1camera = false;
        ui->widgetGLWidget->setPlayer2camera = false;
        ui->widgetGLWidget->setCrowdCamera = true;
        ui->widgetGLWidget->setPawnCamera = false;

        ui->doubleSpinBoxEyeX->setEnabled(true);
        ui->doubleSpinBoxEyeY->setEnabled(true);
        ui->doubleSpinBoxEyeZ->setEnabled(true);

        ui->doubleSpinBoxLookAtX->setEnabled(true);
        ui->doubleSpinBoxLookAtY->setEnabled(true);
        ui->doubleSpinBoxLookAtZ->setEnabled(true);

        ui->doubleSpinBoxViewUpX->setEnabled(true);
        ui->doubleSpinBoxViewUpY->setEnabled(true);
        ui->doubleSpinBoxViewUpZ->setEnabled(true);

        ui->horizontalSliderRotationAngle->setEnabled(true);
        ui->spinBoxRotationAngle->setEnabled(true);

        ui->widgetGLWidget->updateGL();
    }
    else {
        ui->widgetGLWidget->setPlayer1camera = false;
        ui->widgetGLWidget->setPlayer2camera = false;
        ui->widgetGLWidget->setCrowdCamera = false;
        ui->widgetGLWidget->setPawnCamera = true;

        ui->doubleSpinBoxEyeX->setEnabled(false);
        ui->doubleSpinBoxEyeY->setEnabled(false);
        ui->doubleSpinBoxEyeZ->setEnabled(false);

        ui->doubleSpinBoxLookAtX->setEnabled(false);
        ui->doubleSpinBoxLookAtY->setEnabled(false);
        ui->doubleSpinBoxLookAtZ->setEnabled(false);

        ui->doubleSpinBoxViewUpX->setEnabled(false);
        ui->doubleSpinBoxViewUpY->setEnabled(false);
        ui->doubleSpinBoxViewUpZ->setEnabled(false);

        ui->horizontalSliderRotationAngle->setEnabled(false);
        ui->spinBoxRotationAngle->setEnabled(false);

        ui->widgetGLWidget->updateGL();
    }
}

void MainWindow :: updateCamera()
{
    ui->widgetGLWidget->crowdCamera->updateEye(ui->doubleSpinBoxEyeX->value(),
                                               ui->doubleSpinBoxEyeY->value(),
                                               ui->doubleSpinBoxEyeZ->value());
    ui->widgetGLWidget->crowdCamera->updateLookAt(ui->doubleSpinBoxLookAtX->value(),
                                               ui->doubleSpinBoxLookAtY->value(),
                                               ui->doubleSpinBoxLookAtZ->value());
    ui->widgetGLWidget->crowdCamera->updateViewUp(ui->doubleSpinBoxViewUpX->value(),
                                               ui->doubleSpinBoxViewUpY->value(),
                                               ui->doubleSpinBoxViewUpZ->value());

    ui->widgetGLWidget->updateGL();
}

void MainWindow :: updateVisible()
{
    if (ui->checkBoxPieces->isChecked())
        ui->widgetGLWidget->pawn3->setDrawable(true);
    else
        ui->widgetGLWidget->pawn3->setDrawable(false);

    if (ui->checkBoxChessboard->isChecked())
        ui->widgetGLWidget->chessboard->setDrawable(true);
    else
        ui->widgetGLWidget->chessboard->setDrawable(false);

    ui->widgetGLWidget->updateGL();
}

void MainWindow :: rotateCamera(int delta)
{
    ui->widgetGLWidget->setAngle((double) delta);
    ui->widgetGLWidget->updateGL();
}
