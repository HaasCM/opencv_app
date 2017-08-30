/*!
  \file camera_commander.cpp
  \brief File to implement the camera commander class
*/

#include "camera_commander.h"

/*!
  \fn CameraCommander::CameraCommander(QObject *parent)
  \brief Default constructor for CameraCommander
*/
CameraCommander::CameraCommander(QObject *parent) :
QObject(parent){
  //Create but do not start the camera and processing thread
}

/*!
  \fn CameraCommander::~CameraCommander()
  \brief Default destructor for CameraCommander
*/
CameraCommander::~CameraCommander() {

}

/*!
  \fn void CameraCommander::changeCamera(const QCameraInfo &cameraInfo)
  \brief handles the selection of a new camera
*/
void CameraCommander::changeCamera(const QCameraInfo &cameraInfo, QCameraViewfinder *finder) {
  mCameraThread->setCamera(cameraInfo, finder);
}


