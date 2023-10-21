from sklearn.cluster import KMeans
import matplotlib.pyplot as plt
import matplotlib.colors as mc
import cv2
from collections import Counter

class Colorimetry:
  def __init__(self, image_path):
    image = cv2.imread(image_path)
    image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
    self.image = image
  
  def __convert_rgb_to_hex(self, color):
    return "#{:02x}{:02x}{:02x}".format(int(color[0]), int(color[1]), int(color[2]))
  
  def __convert_hex_to_rgb(self, color):
    return tuple(int(color.lstrip('#')[i:i+2], 16) for i in (0, 2, 4))
  
  def __get_color_name(self, rgb):
    min_colours = {}
    for key, name in mc.CSS4_COLORS.items():
      r_c, g_c, b_c = self.__convert_hex_to_rgb(name)
      rd = (r_c - rgb[0]) ** 2
      gd = (g_c - rgb[1]) ** 2
      bd = (b_c - rgb[2]) ** 2
      min_colours[(rd + gd + bd)] = key
    
    return min_colours[min(min_colours.keys())]

  def get_colors(self, number_of_colors = 3, show_chart = True):
    modified_image = self.image.reshape(self.image.shape[0] * self.image.shape[1], 3)
    
    clf = KMeans(n_clusters = number_of_colors)
    labels = clf.fit_predict(modified_image)
    
    counts = Counter(labels)
    counts = dict(sorted(counts.items()))

    colors = [clf.cluster_centers_[i] for i in counts.keys()]
    hex_colors = [self.__convert_rgb_to_hex(colors[i]) for i in counts.keys()]
    rgb_colors = [colors[i] for i in counts.keys()]
    max_color_value = sum(counts.values())

    formatted_result = [{
      "color": {
        # Maybe handle this on frontend?
        "name": self.__get_color_name(tuple(rgb_colors[c])),
        "hex": color
      },
      "value": round((counts[c] / max_color_value) * 100, 1)
    } for c, color in enumerate(hex_colors)]

    return formatted_result