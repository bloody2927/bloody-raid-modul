# Wir hängen alle Skript-CPPs an den Core an.
if (COMMAND AC_ADD_SCRIPT)
  AC_ADD_SCRIPT("${CMAKE_CURRENT_SOURCE_DIR}/mod_loader.cpp")
  # Deine eigentlichen Skripte - einfach hier ergänzen:
  file(GLOB EMERALD_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
  foreach(S IN LISTS EMERALD_SOURCES)
    if (NOT S MATCHES "mod_loader.cpp$")
      AC_ADD_SCRIPT("${S}")
    endif()
  endforeach()
else()
  message(STATUS "AC macros not found - skipping scripts.")
endif()
