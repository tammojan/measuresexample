#!/bin/bash

echo "========== Doing conversion with taql"
taql < azel.taql

echo "========== Doing conversion with taql from python"
python azel-taql.py

echo "========== Doing conversion with taql from C++"
g++ azel-taql.cpp -o azel-taql -lcasa_tables -lcasa_casa
./azel-taql
rm ./azel-taql

echo "========== Doing conversion from python with measures"
python azel.py

echo "========== Doing conversion from C++ with measures"
g++ azel.cpp -o azel -lcasa_measures -lcasa_casa
./azel
rm ./azel
