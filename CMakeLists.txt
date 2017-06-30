cmake_minimum_required(VERSION 2.8)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
  endif()
endif()

project(VitaScreenFlasher)
include("${VITASDK}/share/vita.cmake" REQUIRED)

set(VITA_APP_NAME "ScreenFlasher")
set(VITA_TITLEID  "SCRENFLSH")
set(VITA_VERSION  "01.10")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(VITA_MKSFOEX_FLAGS "${VITA_MKSFOEX_FLAGS} -d PARENTAL_LEVEL=1")

include_directories(
)

link_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
)

add_executable(VitaScreenFlasher
  src/main.c
)

target_link_libraries(VitaScreenFlasher
  vita2d
  SceDisplay_stub
  SceGxm_stub
  SceSysmodule_stub
  SceCtrl_stub
  ScePgf_stub
  SceCommonDialog_stub
  z
  m
)

vita_create_self(VitaScreenFlasher.self VitaScreenFlasher)
vita_create_vpk(VitaScreenFlasher.vpk ${VITA_TITLEID} VitaScreenFlasher.self
  VERSION ${VITA_VERSION}
  NAME ${VITA_APP_NAME}
)
