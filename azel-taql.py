# Get the azimuth and elevation of Jupiter from Dwingeloo at a given time.
# Usage: python azel-taql.py

from casacore.tables import taql

print taql('calc meas.azel("Jupiter",2016-06-28 19:54,"DWL") deg')
