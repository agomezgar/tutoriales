import cv2
import sys
import serial
import struct
ser=serial.Serial('/dev/ttyUSB0',9600)
cascPath = '/home/antonio/openCV/opencv/data/haarcascades/haarcascade_frontalface_default.xml'
faceCascade = cv2.CascadeClassifier(cascPath)
#La videocamara opera de forma normal a 640x480
video_capture = cv2.VideoCapture(0)
#Intento de cambiar el tamaño del video capturado por mi webcam. No funcionó a la primera
#video_capture.set(3,800)
#video_capture.set(4,600)
#Estas instrucciones me dan las propiedades 3 y 4 (width y height) de mi video
#video_capture.get(3)
#video_capture.get(4)
while True:
    # Capture frame-by-frame
    ret, frame = video_capture.read()
    
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    faces = faceCascade.detectMultiScale(
        gray,
        scaleFactor=1.3,
        minNeighbors=5,
        minSize=(30, 30)
    )

    # Draw a rectangle around the faces
    for (x, y, w, h) in faces:
        cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 0), 2)
        #print ((str)(x)+'\t'+(str)(y))
        #print ((str)(x)+'\t'+(str)(y)+'\t'+(str)(w))
        anguloBase=(int)(x*180)/640
        anguloBrazo1=(int)(y*180)/480
        anguloBrazo2=(int)(w*180)/310
        print ((str)(anguloBase)+'\t'+(str)(anguloBrazo1)+'\t'+(str)(anguloBrazo2))
        #bge.arduino.write(struct.pack('>BBB',45,90,180))
        ser.write(struct.pack('>BBB', anguloBase,anguloBrazo1,anguloBrazo2))
        #print ((str)(anguloBase))
    # Display the resulting frame
    cv2.imshow('Video', frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# When everything is done, release the capture
video_capture.release()
cv2.destroyAllWindows()
