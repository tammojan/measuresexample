// Get the azimuth and elevation of Jupiter from Dwingeloo at a given time.
// Compile with: g++ azel-taql.cpp -o azel-taql -lcasa_tables -lcasa_casa
// Usage: ./azel-taql

#include <casacore/tables/TaQL/TableParse.h>

using namespace casacore;
using namespace std;

int main() {
  string query = "calc meas.azel('Jupiter',2016-06-28 19:54,'DWL') deg";
  TaQLResult result = tableCommand(query);
  cout<<result.node().getArrayDouble(0)<<endl;
}

