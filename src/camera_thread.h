/*!
  \file camera_thread.h
  \brief File to declare the camera thread
*/

#ifndef CAMERA_THREAD_H
#define CAMERA_THREAD_H

/*!
  \class CameraThread
  \brief Class to handle the camera operations on its own thread
*/

#include <QtCore>
#include <QThread>
#include <QVideoFrame>
#include <QVideoProbe>
#include <QCamera>
#include <QCameraViewfinder>

class CameraThread :  public QThread {
public:
  CameraThread();
  ~CameraThread();
  void setCamera(const QCameraInfo &cameraInfo, QCameraViewfinder *finder);

protected:
  //void run() final;
private:
  typedef QQueue<QVideoFrame> FrameQueue;
  QVideoProbe *mVideoProbe; //!< Pointer to the Video Probe on the camera
  QCamera *mCamera;

private slots:
  void onFrameProbed(const QVideoFrame &frame);
  void onNeedToFlush(); //!< The probe will alert when it needs to be flushed
};
#endif // CAMERA_THREAD_H
