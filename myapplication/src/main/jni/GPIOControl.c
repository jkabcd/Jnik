//
// Created by she on 2019/6/27.
//
#include <termios.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <jni.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <errno.h>
#include "dd_sdl_com_myapplication_GPIOControl.h"
#include "android/log.h"
static const char *TAG="GpioDemo";
#define LOGI(fmt, args...) __android_log_print(ANDROID_LOG_INFO,  TAG, fmt, ##args)
#define LOGD(fmt, args...) __android_log_print(ANDROID_LOG_DEBUG, TAG, fmt, ##args)
#define LOGE(fmt, args...) __android_log_print(ANDROID_LOG_ERROR, TAG, fmt, ##args)
JNIEXPORT jint JNICALL Java_dd_sdl_com_myapplication_GPIOControl_nativeReadGpio(JNIEnv *env, jclass thiz, jstring path)
{
  if(path == NULL)
  {
  return -1;
  }
  const char *chars = (*env)->GetStringUTFChars(env, path, NULL);
  int ret = readData(chars);
  (*env)->ReleaseStringUTFChars(env, path, chars);
  return ret;
  }
JNIEXPORT jint JNICALL Java_dd_sdl_com_myapplication_GPIOControl_nativeWriteGpio(JNIEnv *env, jclass thiz, jstring path, jstring value)
  {
  if(path == NULL)
  {
  return -1;
  }
  const char *chars = (*env)->GetStringUTFChars(env, path, NULL);
  const char *valueStr = (*env)->GetStringUTFChars(env, value, NULL);
  int ret = writeData(valueStr, strlen(valueStr), chars);
  (*env)->ReleaseStringUTFChars(env, path, chars);
  (*env)->ReleaseStringUTFChars(env, value, valueStr);
   return ret;
   }
   int readData(const char * filePath)
   {
   int fd;
   int value;
   fd = open(filePath, O_RDWR);
   if(fd < 0)
   {
   return -1;
   }
   char valueStr[32];
   memset(valueStr, 0, sizeof(valueStr));
   read(fd, (void *)valueStr, sizeof(valueStr) - 1);
    char *end;
    if(strncmp(valueStr,"in",2) == 0)
    {
    value = 0;
    } else if(strncmp(valueStr,"out",3) == 0) {
    value = 1;
    } else {
    value = strtol(valueStr, &end, 0);
    if(end == valueStr){
    close(fd); return -1;
    }
    }
    close(fd);
    return value;
    }
    int writeData(const char * data,int count,const char * filePath)
    {
    int fd;
    fd = open(filePath, O_RDWR);
     if(fd < 0)
     {
     return -1;
     }
     int ret = write(fd, data, count);
     close(fd);
      return 0;
      }


