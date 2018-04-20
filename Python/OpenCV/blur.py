import cv2
import numpy as np

img = cv2.imread("clouds.jpg")

blurred = cv2.GaussianBlur(img,(31,31),0)

cv2.imshow("Gaussian Blur", blurred)

#blur with custom kernel
kernel = np.ones((5,5),np.float32)/25

blurred2 = cv2.filter2D(img,-1,kernel)

cv2.imshow("Gaussian Blur (Custom Kernel)", blurred2)

cv2.waitKey(0)
cv2.destroyAllWindows()