import cv2

faceCascade = cv2.CascadeClassifier("Resources\\haarcascade_frontalface_default.xml")

cap = cv2.VideoCapture(0)

#set dimensions
cap.set(3, 640)
cap.set(4, 480)

#set brightness
cap.set(10, 100)

while True:
    success, img = cap.read()
    imgGray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    faces = faceCascade.detectMultiScale(imgGray, 1.05, 6)
    distance = 0
    xtheta = 0
    ytheta = 0
    for (x, y, w, h) in faces:
        cv2.rectangle(img, (x, y), (x+w, y+h), (255, 0, 0), 2)
        cv2.circle(img, (x + w//3, y + h//3 + 10), 10, (0, 0, 255), 3)
        distance = 743.87 * w ** -1.177
        print('x:', x)
        print('y:', y)
        break

    cv2.imshow("Video", img)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break