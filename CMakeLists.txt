#
# Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
#

# Add scripts in project
AC_ADD_SCRIPT("${CMAKE_CURRENT_LIST_DIR}/src/boss_alice.cpp")
AC_ADD_SCRIPT("${CMAKE_CURRENT_LIST_DIR}/src/instance_smaragdsanktum.cpp")
AC_ADD_SCRIPT("${CMAKE_CURRENT_LIST_DIR}/src/npc_alice_start.cpp")

# Add scripts to script loader
AC_ADD_SCRIPT_LOADER("bloody_raid_modul" "${CMAKE_CURRENT_LIST_DIR}/src/MP_loader.cpp")

# Add config file
AC_ADD_CONFIG_FILE("${CMAKE_CURRENT_LIST_DIR}/conf/my_custom.conf.dist")

