
set(main_src
  main.cpp
  straylight.h
  outputdefaultlogo.cpp
  outputdefaultlogo.h
  outputcolorlogo.cpp
  outputcolorlogo.h
  outputlogo.h
  outputlogo.cpp
)

add_executable(
  ${PROJECT_NAME}
  ${main_src}
)

target_link_libraries(
  ${PROJECT_NAME}
  ${CURSES_LIBRARIES})

