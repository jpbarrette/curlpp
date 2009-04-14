
include_directories(${KDE4_INCLUDES} ${KDE4_INCLUDE_DIR} ${QT_INCLUDES} )


########### next target ###############

set(example01_SRCS example01.cpp)

kde4_add_executable(example01 ${example01_SRCS})

target_link_libraries(example01 ${KDE4_KDECORE_LIBS})


########### next target ###############

set(example02_SRCS example02.cpp)

kde4_add_executable(example02 ${example02_SRCS})

target_link_libraries(example02 ${KDE4_KDECORE_LIBS})


########### next target ###############

set(example03_SRCS example03.cpp)

kde4_add_executable(example03 ${example03_SRCS})

target_link_libraries(example03 ${KDE4_KDECORE_LIBS})


########### next target ###############

set(example04_SRCS example04.cpp)

kde4_add_executable(example04 ${example04_SRCS})

target_link_libraries(example04 ${KDE4_KDECORE_LIBS})


########### next target ###############

set(example05_SRCS example05.cpp)

kde4_add_executable(example05 ${example05_SRCS})

target_link_libraries(example05 ${KDE4_KDECORE_LIBS})


########### next target ###############

set(example06_SRCS example06.cpp)

kde4_add_executable(example06 ${example06_SRCS})

target_link_libraries(example06 ${KDE4_KDECORE_LIBS})


########### next target ###############

set(example07_SRCS example07.cpp)

kde4_add_executable(example07 ${example07_SRCS})

target_link_libraries(example07 ${KDE4_KDECORE_LIBS})


########### next target ###############

set(example08_SRCS example08.cpp)

kde4_add_executable(example08 ${example08_SRCS})

target_link_libraries(example08 ${KDE4_KDECORE_LIBS})


########### next target ###############

set(example09_SRCS example09.cpp)

kde4_add_executable(example09 ${example09_SRCS})

target_link_libraries(example09 ${KDE4_KDECORE_LIBS})


########### next target ###############

set(example10_SRCS example10.cpp)

kde4_add_executable(example10 ${example10_SRCS})

target_link_libraries(example10 ${KDE4_KDECORE_LIBS})


########### next target ###############

set(example11_SRCS example11.cpp)

kde4_add_executable(example11 ${example11_SRCS})

target_link_libraries(example11 ${KDE4_KDECORE_LIBS})


########### next target ###############

set(example12_SRCS example12.cpp)

kde4_add_executable(example12 ${example12_SRCS})

target_link_libraries(example12 ${KDE4_KDECORE_LIBS})


########### next target ###############

set(example13_SRCS example13.cpp)

kde4_add_executable(example13 ${example13_SRCS})

target_link_libraries(example13 ${KDE4_KDECORE_LIBS})


########### next target ###############

set(example14_SRCS example14.cpp)

kde4_add_executable(example14 ${example14_SRCS})

target_link_libraries(example14 ${KDE4_KDECORE_LIBS})


########### next target ###############

set(example15_SRCS example15.cpp)

kde4_add_executable(example15 ${example15_SRCS})

target_link_libraries(example15 ${KDE4_KDECORE_LIBS})


########### next target ###############

set(example16_SRCS example16.cpp)

kde4_add_executable(example16 ${example16_SRCS})

target_link_libraries(example16 ${KDE4_KDECORE_LIBS})


########### next target ###############

set(example17_SRCS example17.cpp)

kde4_add_executable(example17 ${example17_SRCS})

target_link_libraries(example17 ${KDE4_KDECORE_LIBS})


########### next target ###############

set(example19_SRCS example19.cpp)

kde4_add_executable(example19 ${example19_SRCS})

target_link_libraries(example19 ${KDE4_KDECORE_LIBS})


########### next target ###############

set(example21_SRCS example21.cpp)

kde4_add_executable(example21 ${example21_SRCS})

target_link_libraries(example21 ${KDE4_KDECORE_LIBS})


########### next target ###############

set(example22_SRCS example22.cpp)

kde4_add_executable(example22 ${example22_SRCS})

target_link_libraries(example22 ${KDE4_KDECORE_LIBS})


########### next target ###############

set(${maintener_programs}_SRCS ${CMAKE_CURRENT_BINARY_DIR}/dummy.cpp)

kde4_add_executable(${maintener_programs} ${${maintener_programs}_SRCS})

target_link_libraries(${maintener_programs} ${KDE4_KDECORE_LIBS})


########### next target ###############

set(${boost_programs}_SRCS ${CMAKE_CURRENT_BINARY_DIR}/dummy.cpp)

kde4_add_executable(${boost_programs} ${${boost_programs}_SRCS})

target_link_libraries(${boost_programs} ${KDE4_KDECORE_LIBS})


########### install files ###############




#original Makefile.am contents follow:

#if MAINTENER_CODE
#maintener_programs = 
#endif
#
#if HAVE_BOOST
#boost_programs = example18 example20
#endif
#
#EXTRA_DIST = Makefile.msvc
#
#noinst_PROGRAMS = \
#	example01 \
#	example02 \
#	example03 \
#	example04 \
#	example05 \
#	example06 \
#	example07 \
#	example08 \
#	example09 \
#	example10 \
#	example11 \
#	example12 \
#	example13 \
#	example14 \
#	example15 \
#	example16 \
#	example17 \
#	example19 \
#	example21 \
#	example22 \
#	${maintener_programs} ${boost_programs}
#
#
#
#example01_SOURCES = example01.cpp
#
#example02_SOURCES = example02.cpp
#
#example03_SOURCES = example03.cpp
#
#example04_SOURCES = example04.cpp
#
#example05_SOURCES = example05.cpp
#
#example06_SOURCES = example06.cpp
#
#example07_SOURCES = example07.cpp
#
#example08_SOURCES = example08.cpp
#
#example09_SOURCES = example09.cpp
#
#example10_SOURCES = example10.cpp
#
#example11_SOURCES = example11.cpp
#
#example12_SOURCES = example12.cpp
#
#example13_SOURCES = example13.cpp
#
#example14_SOURCES = example14.cpp
#
#example15_SOURCES = example15.cpp
#
#example16_SOURCES = example16.cpp
#
#example17_SOURCES = example17.cpp
#
#example18_SOURCES = example18.cpp
#
#example19_SOURCES = example19.cpp
#
#example20_SOURCES = example20.cpp
#
#example21_SOURCES = example21.cpp
#
#example22_SOURCES = example22.cpp
#
#AM_LDFLAGS = -L../src/curlpp/ -lcurlpp -static 
#
#INCLUDES = -I$(top_builddir)/include
#
#
#
