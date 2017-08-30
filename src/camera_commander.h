/*!
  \file camera_commander.h
  \brief File to define the CameraCommander Class
*/

#ifndef CAMERA_COMMANDER_H
#define CAMERA_COMMANDER_H

/*!
  \class CameraCommander
  \brief Class to handle the camera buffer thread and processing thread
*/

#include "camera_thread.h"

#include <QtCore>
#include <QCameraInfo>
#include <QCameraViewfinder>

class CameraCommander : public QObject {
  Q_OBJECT
public:
  CameraCommander(QObject *parent=nullptr);
  ~CameraCommander();

  void changeCamera(const QCameraInfo &cameraInfo, QCameraViewfinder *finder);

private:
  CameraThread* mCameraThread;
  //ProcessingThread
};
#endif // CAMERA_COMMANDER_H
