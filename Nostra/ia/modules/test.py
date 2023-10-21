import cv2
import matplotlib.pyplot as plt
from Colorimetry import Colorimetry

image = Colorimetry('image.jpg')

print(image.get_colors())