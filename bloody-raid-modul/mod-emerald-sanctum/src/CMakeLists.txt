# Im reinen Repo-Scan kennt CMake AC_ADD_SCRIPT nicht.
# Mit diesem Guard ist das File "no-op" und bricht NICHT.
if (COMMAND AC_ADD_SCRIPT)
  AC_ADD_SCRIPT("${CMAKE_CURRENT_SOURCE_DIR}/emerald_sanctum.h")
  AC_ADD_SCRIPT("${CMAKE_CURRENT_SOURCE_DIR}/instance_smaragdsanktum.cpp")
  AC_ADD_SCRIPT("${CMAKE_CURRENT_SOURCE_DIR}/boss_alice_the_dreammother.cpp")
  AC_ADD_SCRIPT("${CMAKE_CURRENT_SOURCE_DIR}/npc_emerald_keeper.cpp")
else()
  message(STATUS "AzerothCore macros not found (index-only mode) – skipping AC_ADD_SCRIPT.")
endif()
