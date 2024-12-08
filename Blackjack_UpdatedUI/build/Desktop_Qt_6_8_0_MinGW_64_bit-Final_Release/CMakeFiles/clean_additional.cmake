# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "Blackjack_autogen"
  "CMakeFiles\\Blackjack_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Blackjack_autogen.dir\\ParseCache.txt"
  "tests\\BlackjackTests_autogen"
  "tests\\CMakeFiles\\BlackjackTests_autogen.dir\\AutogenUsed.txt"
  "tests\\CMakeFiles\\BlackjackTests_autogen.dir\\ParseCache.txt"
  )
endif()
