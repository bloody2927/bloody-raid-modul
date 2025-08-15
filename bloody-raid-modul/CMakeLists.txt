cmake_minimum_required(VERSION 3.16)
project(bloody-raid-modul)

# nur weiter machen, wenn wir im AzerothCore-Tree sind (Makros vorhanden)
if (COMMAND AC_ADD_SCRIPT)
  add_subdirectory(src)
else()
  message(STATUS "AC macros not found - skip module build (outside AzerothCore).")
endif()
