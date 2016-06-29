// Get the azimuth and elevation of Jupiter from Dwingeloo at a given time.
// Compile with: g++ azel.cpp -o azel -lcasa_measures -lcasa_casa
// Usage: ./azel

#include <casacore/measures/Measures.h>
#include <casacore/measures/Measures/MEpoch.h>
#include <casacore/measures/Measures/MPosition.h>
#include <casacore/measures/Measures/MDirection.h>
#include <casacore/measures/Measures/MCDirection.h>
#include <casacore/measures/Measures/MeasFrame.h>
#include <casacore/measures/Measures/MeasTable.h>
#include <casacore/casa/Quanta/MVTime.h>

using namespace casacore;
using namespace std;

int main() {
  MPosition myobs;
  MeasTable::Observatory(myobs, "DWL");

  Quantity mytime_q;
  MVTime::read(mytime_q, "2016-06-28 19:54:24");
  MEpoch mytime = MEpoch(mytime_q, MEpoch::UTC);

  MeasFrame myframe(myobs, mytime);

  MDirection mydir = MDirection::makeMDirection("Jupiter");
 
  // Target frame
  MDirection::Ref myref(MDirection::AZEL, myframe);

  // Set up converter and do actual conversion
  MDirection mydirazel = MDirection::Convert(mydir, myref)();

  cout << mydirazel.getAngle("deg") << endl;
}
