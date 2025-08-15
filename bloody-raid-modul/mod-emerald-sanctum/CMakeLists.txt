cmake_minimum_required(VERSION 3.16)
project(mod_emerald_sanctum)

# Wird nur wirksam, wenn das Modul im AzerothCore-Tree gebaut wird.
add_subdirectory(src)

# Optional: Beispiel-Config installieren (nur im AC-Build relevant)
if (CMAKE_INSTALL_PREFIX)
  install(FILES conf/mod_emerald_sanctum.conf.dist DESTINATION etc)
endif()
