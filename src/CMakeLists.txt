
include_directories(${KDE4_INCLUDES} ${KDE4_INCLUDE_DIR} ${QT_INCLUDES} )

add_subdirectory(utilspp)
add_subdirectory(curlpp)


########### install files ###############




#original Makefile.am contents follow:

#ACLOCAL_AMFLAGS = -I m4
#SUBDIRS = utilspp curlpp  
