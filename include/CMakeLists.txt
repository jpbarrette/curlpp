
include_directories(${KDE4_INCLUDES} ${KDE4_INCLUDE_DIR} ${QT_INCLUDES} )

add_subdirectory(curlpp)
add_subdirectory(utilspp)


########### install files ###############




#original Makefile.am contents follow:

#SUBDIRS = curlpp utilspp