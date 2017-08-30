/*!
  \file opencv_main_window.cpp
  \brief File to implement the OpenCVMainWindow Class
*/

#include "opencv_main_window.h"

Q_DECLARE_METATYPE(QCameraInfo)

/*!
  \fn OpenCVMainWindow::OpenCVMainWindow(QWidget)
  \brief Default constructor for OpenCVMainWindow
*/
OpenCVMainWindow::OpenCVMainWindow(QWidget *parent) noexcept :
QMainWindow(parent){
  setupUi(this);
  mCameraCommander = new CameraCommander(this);

  QActionGroup *deviceActionGroup = new QActionGroup(this);

  // iterate through the available devices and add them to the action
  for(const auto &cameraInfo : QCameraInfo::availableCameras()) {
    QAction *cameraAction = new QAction(cameraInfo.description(), deviceActionGroup);
    cameraAction->setCheckable(true);
    cameraAction->setData(QVariant::fromValue(cameraInfo));
    cameraAction->setChecked(cameraInfo == QCameraInfo::defaultCamera());

    menuDevices->addAction(cameraAction);
  }
  // connect action group for camera selection control
  connect(deviceActionGroup, &QActionGroup::triggered,
          this, &OpenCVMainWindow::onDeviceSelected);

  setActiveCamera(QCameraInfo::defaultCamera());
  show();
}

/*!
  \fn OpenCVMainWindow::~OpenCVMainWindow()
  \brief Default destructor for OpenCVMainWindow
*/
OpenCVMainWindow::~OpenCVMainWindow() {

}

/*!
  \fn void OpenCVMainWindow::onDeviceSelected(const QAction *action)
  \brief updates the selected Camera Device from a signal
*/
void OpenCVMainWindow::onDeviceSelected(const QAction *action) {
  // cast the variant into the correct class type and set the camera
  setActiveCamera(qvariant_cast<QCameraInfo>(action->data()));
}

/*!
  \fn void OpenCVMainWindow::setActiveCamera(const QCameraInfo &cameraInfo)
  \brief sets the camera view to the selected camera device
*/
void OpenCVMainWindow::setActiveCamera(const QCameraInfo &cameraInfo) {
  mCameraCommander->changeCamera(cameraInfo, cameraView);
}


