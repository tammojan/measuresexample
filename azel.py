# Get the azimuth and elevation of Jupiter from Dwingeloo at a given time.
# Usage: python azel.py

from casacore.measures import measures
from casacore.quanta import quantity

dm = measures()

dm.do_frame(dm.observatory("DWL"))
dm.do_frame(dm.epoch("UTC", "2016-06-28 19:54"))

# Do the actual conversion of the named direction
azeldir = dm.measure(dm.direction("Jupiter"), "AZEL")

# Use quanta to convert the returned radians into degrees
print(dm.get_value(azeldir)[0].get("deg"))
print(dm.get_value(azeldir)[1].get("deg"))
