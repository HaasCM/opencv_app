/*!
  \file opencv_main_window.h
  \brief File to declare the OpenCVWindowClass
*/

#ifndef OPENCV_MAIN_WINDOW_H
#define OPENCV_MAIN_WINDOW_H

#include <QCameraInfo>
#include <QVideoProbe>

#include "ui_opencv_main_window_base.h"
#include "camera_commander.h"

/*
 * Main Window Owns one instance of the Camera Commander
 * The Camera Commander owns one camera thread and one processing thread
 * The Commander Commands and controls the synchronization between the threads
 *
*/

/*!
  \class OpenCVMainWindow
  \brief Class to handle the mainGUI for the application
*/

class OpenCVMainWindow :public QMainWindow, private Ui::OpenCVMainWindowBase {
public:
  explicit OpenCVMainWindow(QWidget *parent=nullptr) noexcept;
  ~OpenCVMainWindow();

private slots:
  void onDeviceSelected(const QAction *action);

private:
  void setActiveCamera(const QCameraInfo &cameraInfo);

  CameraCommander* mCameraCommander; //!< interface to the two camera threads

};
#endif // OPENCV_MAIN_WINDOW_H
